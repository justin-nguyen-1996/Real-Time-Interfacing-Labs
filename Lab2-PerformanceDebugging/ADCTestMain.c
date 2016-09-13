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
#include "TimerInit.h"

#define PF4 (*((volatile uint32_t *)0x40025040))
#define PF3 (*((volatile uint32_t *)0x40025020))
#define PF2 (*((volatile uint32_t *)0x40025010))
#define PF1 (*((volatile uint32_t *)0x40025008))

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

// Change this if you want a different number of samples.
static const uint32_t NUM_ADC_SAMPLES = 1000;

// Used to capture value of ADC and when it was sampled.
static uint32_t AdcTimeBuffer[1000]; 
static int32_t AdcValueBuffer[1000];
static uint16_t AdcBufferIndex = 0;

// Used for plotting points on the pmf function
static int32_t AdcOutputRangeBuffer[1000];  // x-axis
static int32_t AdcOutputCountBuffer[1000]; // y-axis

/* Summary: Delay 10 ms
 * Input:   Number of times to wait 10 ms
 * Output:  None
 */
void DelayWait10ms(uint32_t n){
  uint32_t volatile time;
  while(n){
    time = 727240*2/91;  // 10msec
    while(time){
	  	time--;
    }
    n--;
  }
}


/* Summary: Pause until SW1 is not pressed 
 *          (uses simple delay for switch debouncing)
 * Input:   None
 * Output:  None
 */
void Pause(void) {
  while(PF4==0x10){ // while SW1 not pressed
    DelayWait10ms(10);
  }
  while(PF4==0x00){ // while SW1 pressed
    DelayWait10ms(10);
  }
}


/* Summary: Pause and reset to default screen
 * Input:   None
 * Output:  None
 */
void PauseReset(void){
  Pause();
  ST7735_FillScreen(0x0000); // set screen to black
  ST7735_SetCursor(0, 0);
}

/* Summary: Initialize PortF
 * Input:   None
 * Output:  None
 */
void PortF_Init() {
  SYSCTL_RCGCGPIO_R |= 0x20;            // activate port F
  while((SYSCTL_PRGPIO_R&0x20)==0){};   // allow time for clock to start
  GPIO_PORTF_PUR_R |= 0x10;             // pullup for PF4
  GPIO_PORTF_DIR_R |= 0x0E;             // make PF3, PF2, PF1 out (built-in LED)
  GPIO_PORTF_AFSEL_R &= ~0x1F;          // disable alt funct on PortF
  GPIO_PORTF_DEN_R |= 0x1F;             // enable digital I/O on PortF
                                        // configure PF2 as GPIO
  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF00F)+0x00000000;
  GPIO_PORTF_AMSEL_R = 0;               // disable analog functionality on PF
}

/* Summary: Record ADC readings (both value and time).
 *          Toggles PF2 (blue light) to profile how long the ISR takes.
 *          Also tells us how often Timer0A interrupts.
 * Input:   None
 * Output:  None
*/
void Timer0A_Handler(void){
  TIMER0_ICR_R = TIMER_ICR_TATOCINT;    // acknowledge timer0A timeout
  PF2 ^= 0x04;
  PF2 ^= 0x04;
  
  // Record the ADC reading and when it was taken
  if (AdcBufferIndex < 1000) {
    AdcTimeBuffer[AdcBufferIndex] = TIMER1_TAR_R;
    AdcValueBuffer[AdcBufferIndex] = ADC0_InSeq3();
    AdcBufferIndex += 1;
  }
  
  PF2 ^= 0x04;
}

/* Summary: Only used for playing with time jitter value
 * Input:   None
 * Output:  None
 */
void Timer2A_Handler(void){
  TIMER2_ICR_R = TIMER_ICR_TATOCINT;// acknowledge TIMER2A timeout
  const int ARBITRARY_VALUE = 10;
  for (int i = 0; i < ARBITRARY_VALUE; ++i) {}
}

/* Summary: Calculate the probality mass function from the ADC data
 * Input:   Minimum ADC value recorded
 * Output:  None
 */
void CalculatePmfFunction(int32_t minAdcValue) {
  for (int i = 0; i < 4096; ++i) {
    AdcOutputCountBuffer[i] = 0;
  }
  
  for (int i = 0; i < NUM_ADC_SAMPLES; ++i) {
    uint32_t key = AdcValueBuffer[i] - minAdcValue;
    AdcOutputCountBuffer[key] += 1;
  }
  
  ST7735_XYplotInit("pmf plot", 0, NUM_ADC_SAMPLES, 0, NUM_ADC_SAMPLES);
  ST7735_XYplot(4096, AdcValueBuffer, AdcOutputCountBuffer);
}

/* Summary: Calculate the time jitter 
 *          (difference between smallest and largest time difference)
 * Input:   None
 * Output:  a 32 bit number representing the time jitter
 */
uint32_t calculateTimeJitter() {
  uint32_t minTimeDifference = AdcTimeBuffer[0] - AdcTimeBuffer[1];
  uint32_t maxTimeDifference = AdcTimeBuffer[0] - AdcTimeBuffer[1];
    
  for (int i = 0; i < NUM_ADC_SAMPLES - 1; ++i) {
    uint32_t timeDiff = AdcTimeBuffer[i] - AdcTimeBuffer[i+1];
    if (timeDiff < minTimeDifference) {
      minTimeDifference = timeDiff;
    } else if (timeDiff > maxTimeDifference) {
      maxTimeDifference = timeDiff;
    }  
  }
  
  return maxTimeDifference - minTimeDifference;
}

int main(void){
  // Change these to choose timer interrupt frequencies.
  const uint32_t MAX_RELOAD_VAL = 0xFFFFFFFF;
  const uint32_t TIMER0_FREQ = 1000;  // 1kHz
  const uint32_t TIMER2_FREQ = 10101; // ~10kHz
  
  // Initialization
  PLL_Init(Bus80MHz);
  PortF_Init();
  ADC0_InitSWTriggerSeq3_Ch9();
  Timer0_Init(TIMER0_FREQ);
  Timer1_Init(MAX_RELOAD_VAL);
  Timer2_Init(TIMER2_FREQ);
  PF2 = 0; // Turn off blue LED
  ST7735_InitR(INITR_REDTAB);
  EnableInterrupts();
  
  // Main loop
  while(1){
    PF1 ^= 0x02;
    
    // This line causes jitter (takes 2 to 12 clock cycles)
    PF1 = (PF1*12345678)/1234567+0x02;
    
    if (AdcBufferIndex >= NUM_ADC_SAMPLES) {
      uint32_t minAdcValue = AdcValueBuffer[0];
      uint32_t maxAdcValue = AdcValueBuffer[0];
        
      for (int i = 0; i < NUM_ADC_SAMPLES; ++i) {
        if (AdcValueBuffer[i] < minAdcValue) {
          minAdcValue = AdcValueBuffer[i];
        } else if (AdcValueBuffer[i] > maxAdcValue) {
          maxAdcValue = AdcValueBuffer[i];
        }
      }
      
      for (int i = 0; i < NUM_ADC_SAMPLES; i++) {
	      AdcOutputCountBuffer[AdcValueBuffer[i] - minAdcValue] += 1; 
      }
	
      for (int i = 0; i < (maxAdcValue - minAdcValue); i++) {
	      AdcOutputRangeBuffer[i] = minAdcValue + i;
	    }
      
      uint32_t timeJitter = calculateTimeJitter();
      ST7735_OutString("Time Jitter: ");
      ST7735_OutUDec(timeJitter);
      PauseReset();
      
      char* title = "PMF";
      ST7735_XYplotInit(title, minAdcValue, maxAdcValue, 0, NUM_ADC_SAMPLES);
      if ((maxAdcValue - minAdcValue) > NUM_ADC_SAMPLES) {
        char* OOBError = "Range too large";
        ST7735_SetCursor(0, 7);
        ST7735_OutString(OOBError);
      } else{	
        ST7735_XYplot(maxAdcValue - minAdcValue, AdcOutputRangeBuffer, AdcOutputCountBuffer);
      }
      ST7735_SetCursor(0, 1);
      ST7735_OutString("MinAdc: "); ST7735_OutUDec(minAdcValue);
      ST7735_SetCursor(0, 2); 
      ST7735_OutString("MaxAdc: "); ST7735_OutUDec(maxAdcValue);

      //free(pmf);
      //free(AdcOutputRangeBuffer);
      //  ST7735_OutUDec(timeJitter); ST7735_SetCursor(0,1);
      //  ST7735_OutUDec(minAdcValue); ST7735_SetCursor(0,2);
      //  ST7735_OutUDec(maxAdcValue); ST7735_SetCursor(0,3);
      
      AdcBufferIndex = 0;
      PauseReset();
      
    //  CalculatePmfFunction(minAdcValue);
    //  int32_t* pmf = (int32_t*) malloc(4096 * sizeof(int32_t));
    }
  }
}


