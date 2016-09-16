/* File Name:    ADCTestMain.c
 * Authors:      Justin Nguyen (jhn545), Trevor Murdock (ttm436)
 *               (with much sample code belonging to Dr. Valvano)
 * Created:      9/10/2016
 * Last Revised: 9/13/2016
 * Description:  Contains functions for calculating a probability mass 
 *               function (pmf) and time jitter (all inputs came from 
 *               ADC sampling). Allowed us to learn about critical sections,
 *               debugging techniques, interrupts, Central Limit Theorem, etc.
 * 
 * Class Info: EE 445L, Section 16630
 * Lab Number: 2
 * TA: Dylan Zika
 *
 * Hardware Configurations:
 * ST7735R LCD:
 *     Backlight    (pin 10) connected to +3.3 V
 *     MISO         (pin 9) unconnected
 *     SCK          (pin 8) connected to PA2 (SSI0Clk)
 *     MOSI         (pin 7) connected to PA5 (SSI0Tx)
 *     TFT_CS       (pin 6) connected to PA3 (SSI0Fss)
 *     CARD_CS      (pin 5) unconnected
 *     Data/Command (pin 4) connected to PA6 (GPIO)
 *     RESET        (pin 3) connected to PA7 (GPIO)
 *     VCC          (pin 2) connected to +3.3 V
 *     Gnd          (pin 1) connected to ground
 */

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2015

 Copyright 2015 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

// center of X-ohm potentiometer connected to PE3/AIN0
// bottom of X-ohm potentiometer connected to ground
// top of X-ohm potentiometer connected to +3.3V 
#include <stdint.h>
#include "ADCSWTrigger.h"
#include "../inc/tm4c123gh6pm.h"
#include "PLL.h"
#include "fixed.h"
#include "ST7735.h"

#define PF4             (*((volatile uint32_t *)0x40025040))
#define PF3             (*((volatile uint32_t *)0x40025020))
#define PF2             (*((volatile uint32_t *)0x40025010))
#define PF1             (*((volatile uint32_t *)0x40025008))
	
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

#define NUM_ADC_SAMPLES 1000
static uint32_t AdcValueBuffer[NUM_ADC_SAMPLES];
static uint16_t AdcIndex = 0;

#define MAX_PMF_DOMAIN 4096
static uint32_t pmf[MAX_PMF_DOMAIN];
static uint8_t averaging = 0;

void PortF_Init() {
  GPIO_PORTF_DIR_R |= 0x06;             // make PF2, PF1 out (built-in LED)
  GPIO_PORTF_AFSEL_R &= ~0x16;          // disable alt funct on PF2, PF1
  GPIO_PORTF_PUR_R |= 0x10;             // 5) pullup for PF4
  GPIO_PORTF_DEN_R |= 0x16;             // enable digital I/O on PF2, PF1
                                        // configure PF2 as GPIO
  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF00F)+0x00000000;
  GPIO_PORTF_AMSEL_R = 0;               // disable analog functionality on PF
}
void DelayWait10ms(uint32_t n){uint32_t volatile time;
  while(n){
    time = 727240*2/91;  // 10msec
    while(time){
	  	time--;
    }
    n--;
  }
}
void Pause(void){
  while(PF4==0x00){ 
    DelayWait10ms(10);
  }
	if (averaging < 6) {averaging ++;}
	else {averaging = 0;}
	ADC0_SAC_R = averaging;
  while(PF4==0x10){
    DelayWait10ms(10);
  }
}
void Timer0A_Init100HzInt(void){
  volatile uint32_t delay;
  DisableInterrupts();
  // **** general initialization ****
  SYSCTL_RCGCTIMER_R |= 0x01;      // activate timer0
  delay = SYSCTL_RCGCTIMER_R;      // allow time to finish activating
  TIMER0_CTL_R &= ~TIMER_CTL_TAEN; // disable timer0A during setup
  TIMER0_CFG_R = 0;                // configure for 32-bit timer mode
  // **** timer0A initialization ****
                                   // configure for periodic mode
  TIMER0_TAMR_R = TIMER_TAMR_TAMR_PERIOD;
  TIMER0_TAILR_R = 399999;         // start value for 100 Hz interrupts
  TIMER0_IMR_R |= TIMER_IMR_TATOIM;// enable timeout (rollover) interrupt
  TIMER0_ICR_R = TIMER_ICR_TATOCINT;// clear timer0A timeout flag
  TIMER0_CTL_R |= TIMER_CTL_TAEN;  // enable timer0A 32-b, periodic, interrupts
  // **** interrupt initialization ****
                                   // Timer0A=priority 2
  NVIC_PRI4_R = (NVIC_PRI4_R&0x00FFFFFF)|0x40000000; // top 3 bits
  NVIC_EN0_R = 1<<19;              // enable interrupt 19 in NVIC
}


void Timer0A_Handler(void){
  TIMER0_ICR_R = TIMER_ICR_TATOCINT;    // acknowledge timer0A timeout
  if (AdcIndex >= 1000) {return;} 
  PF2 ^= 0x04;                   // profile
  PF2 ^= 0x04;                   // profile
  AdcValueBuffer[AdcIndex++] = ADC0_InSeq3();
  PF2 ^= 0x04;                   // profile
}

/* Summary: countdown until AdcValueBuffer is full
 *          not to be called by the client
 * Input:   none
 * Output:  none
 */
static void countDown() {
  uint32_t previousCountdown = 0;
  uint32_t countdown = ((AdcIndex>>5)/3);
  if (countdown != previousCountdown) {
    previousCountdown = countdown;
    ST7735_SetCursor(17,0);
    ST7735_OutUDec(10 - countdown);
  }
}

/* Summary: Initialize the pmf plot
 * Input:   minAdcValue, maxAdcValue
 * Output:  none
 */
static void pmfInit(int32_t minAdcValue, int32_t maxAdcValue) {
  uint16_t maxPmfValue = 0;
  
  // Fill the pmf
  for (int i = 0; i < NUM_ADC_SAMPLES; i++) {
    uint32_t adcValue = AdcValueBuffer[i];
    uint32_t pmfIndex = adcValue - minAdcValue;
    uint32_t pmfValue = pmf[pmfIndex] ++;
    if (pmfValue > maxPmfValue) { maxPmfValue = pmfValue; }
  }
  
  // Draw the title and helpful variable values
  // (minAdcValue, maxAdcValue, maxPmfValue)
  char * title = "PMF\nMinAdc MaxAdc  MaxPM";
  ST7735_XYplotInit(title, minAdcValue, maxAdcValue, 0, maxPmfValue);
  ST7735_SetCursor(6,0);
  ST7735_OutUDec(1 << averaging);
  ST7735_OutString("xAvg");
  ST7735_SetCursor(1, 2);
  ST7735_OutUDec(minAdcValue);
  ST7735_SetCursor(9, 2);
  ST7735_OutUDec(maxAdcValue);
  ST7735_SetCursor(17,2);
  ST7735_OutUDec(maxPmfValue);
  
  // Depricated, since MAX_PMF_DOMAIN uses the full adc range
//  if ((maxAdcValue - minAdcValue) > MAX_PMF_DOMAIN) { 
//    char * OOBError = "Range too large";
//    ST7735_SetCursor(0, 7);
//    ST7735_OutString(OOBError);
//  } else{	// Plot the pmf function
//  }
}

/* Summary: perform all of the initialization
 * Input: none
 * Output: none
 */
static void initAll() {
  PLL_Init(Bus80MHz);
  SYSCTL_RCGCGPIO_R |= 0x20;    // activate port F
  ADC0_InitSWTriggerSeq3_Ch9(); // allow time to finish activating
  Timer0A_Init100HzInt();       // set up Timer0A for 100 Hz interrupts
  PortF_Init();
  PF2 = 0;
  ST7735_InitR(INITR_REDTAB);
}

/* Summary: reset the screen and values used for the pmf calculations
 * Input: none
 * Output: none
 */
static void resetPmf() {
  Pause();
  for (int i = 0; i < MAX_PMF_DOMAIN; i++) { pmf[i] = 0; }
  AdcIndex = 0;
}

/* Summary: draw the line as prep for lab 3
 * Input: none
 * Output: none
 */
static void drawLine() {
  for (int i = 0; i < 130; i += 4) {
		Output_Clear();
		ST7735_Line(20, i+30, 100, 129-i+30);
	} 
  DelayWait10ms(10);
}

int main(void){
  initAll();
  EnableInterrupts();
  drawLine(); // Test the line function in fixed.c  
  
  while(1) {
    PF1 ^= 0x02; // heart beat
    countDown(); // countdown until AdcValueBuffer is full
    
    int32_t minAdcValue = AdcValueBuffer[0];
    int32_t maxAdcValue = AdcValueBuffer[0];
    
    if (AdcIndex >= NUM_ADC_SAMPLES) { // Wait until AdcValueBuffer is full      
      // Find max & min ADC values
      for (int i = 1; i < NUM_ADC_SAMPLES; i++) {
        if (AdcValueBuffer[i] > maxAdcValue) { maxAdcValue = AdcValueBuffer[i]; }
        if (AdcValueBuffer[i] < minAdcValue) { minAdcValue = AdcValueBuffer[i]; }
      }

      pmfInit(minAdcValue, maxAdcValue);
      ST7735_Xcount_Yplot(maxAdcValue - minAdcValue, pmf); // plot pmf
      resetPmf();
    }
  }
}


