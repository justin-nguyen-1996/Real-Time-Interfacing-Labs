// ADCTestMain.c
// Runs on TM4C123
// This program periodically samples ADC channel 0 and stores the
// result to a global variable that can be accessed with the JTAG
// debugger and viewed with the variable watch feature.
// Daniel Valvano
// September 5, 2015

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

// volatile uint32_t ADCvalue;
// This debug function initializes Timer0A to request interrupts
// at a 100 Hz frequency.  It is similar to FreqMeasure.c.
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
  TIMER0_TAILR_R = 799999;         // start value for 100 Hz interrupts
  TIMER0_IMR_R |= TIMER_IMR_TATOIM;// enable timeout (rollover) interrupt
  TIMER0_ICR_R = TIMER_ICR_TATOCINT;// clear timer0A timeout flag
  TIMER0_CTL_R |= TIMER_CTL_TAEN;  // enable timer0A 32-b, periodic, interrupts
  // **** interrupt initialization ****
                                   // Timer0A=priority 2
  NVIC_PRI4_R = (NVIC_PRI4_R&0x00FFFFFF)|0x40000000; // top 3 bits
  NVIC_EN0_R = 1<<19;              // enable interrupt 19 in NVIC
}

static uint32_t AdcTimeBuffer[1000];
static int32_t AdcValueBuffer[1000];
static uint16_t AdcIndex = 0;

void Timer0A_Handler(void){
  TIMER0_ICR_R = TIMER_ICR_TATOCINT;    // acknowledge timer0A timeout
  PF2 ^= 0x04;                          // profile
  PF2 ^= 0x04;                          // profile
  if (AdcIndex < 1000) {
    AdcTimeBuffer[AdcIndex] = TIMER1_TAR_R;
    AdcValueBuffer[AdcIndex] = ADC0_InSeq3();
    AdcIndex += 1;
  }
  PF2 ^= 0x04;                          // profile
}

// ***************** TIMER1_Init ****************
// Activate TIMER1 interrupts to run user task periodically
// Inputs:  task is a pointer to a user function
//          period in units (1/clockfreq)
// Outputs: none
//void (*PeriodicTask)(void);   // user function
//void Timer1_Init(void(*task)(void), uint32_t period){
void Timer1_Init(){
  volatile uint32_t delay;
  SYSCTL_RCGCTIMER_R |= 0x02;   // 0) activate TIMER1
  delay = SYSCTL_RCGCTIMER_R;   // allow time to finish activating
//PeriodicTask = task;          // user function
  TIMER1_CTL_R = 0x00000000;    // 1) disable TIMER1A during setup
  TIMER1_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
  TIMER1_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
  TIMER1_TAILR_R = 0xFFFFFFFF;  // 4) reload value
  TIMER1_TAPR_R = 0;            // 5) bus clock resolution
  TIMER1_ICR_R = 0x00000001;    // 6) clear TIMER1A timeout flag
//TIMER1_IMR_R = 0x00000001;    // 7) arm timeout interrupt
  NVIC_PRI5_R = (NVIC_PRI5_R&0xFFFF00FF)|0x00008000; // 8) priority 4
//interrupts enabled in the main program after all devices initialized
//vector number 37, interrupt number 21

//NVIC_EN0_R = 1<<21;           // 9) enable IRQ 21 in NVIC
  TIMER1_CTL_R = 0x00000001;    // 10) enable TIMER1A
}

void pmfCalculate(int32_t minAdcValue) {
  int32_t pmf[4096];
  for (int i = 0; i < 4096; ++i) {
    pmf[i] = 0;
  }
  for (int i = 0; i < 10000; ++i) {
    uint32_t key = AdcValueBuffer[i] - minAdcValue;
    pmf[key] += 1;
  }
  
  ST7735_XYplotInit("pmf plot", 0, 10000, 0, 10000);
  ST7735_XYplot(4096, AdcValueBuffer, pmf);
}

int32_t pmf[1000];
int32_t count[1000];

void Pause(void){
  while(PF4==0x10){ // while SW1 not pressed
    //DelayWait10ms(10);
  }
  while(PF4==0x00){ // while SW1 pressed
    //DelayWait10ms(10);
  }
}

int32_t calculateTimeJitter() {
  uint32_t minTimeDifference = AdcTimeBuffer[0] - AdcTimeBuffer[1];
  uint32_t maxTimeDifference = AdcTimeBuffer[0] - AdcTimeBuffer[1];
    
  for (int i = 0; i < 999; ++i) {
    uint32_t timeDiff = AdcTimeBuffer[i] - AdcTimeBuffer[i+1];
    
    if (timeDiff < minTimeDifference) {
      minTimeDifference = timeDiff;
    } else if (timeDiff > maxTimeDifference) {
      maxTimeDifference = timeDiff;
    }  
  }
  
  return maxTimeDifference - minTimeDifference;
}

void PortF_Init() {
  SYSCTL_RCGCGPIO_R |= 0x20;            // activate port F
  GPIO_PORTF_DIR_R |= 0x0E;             // make PF3, PF2, PF1 out (built-in LED)
  GPIO_PORTF_AFSEL_R &= ~0x1F;          // disable alt funct on PortF
  GPIO_PORTF_DEN_R |= 0x1F;             // enable digital I/O on PortF
                                        // configure PF2 as GPIO
  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF00F)+0x00000000;
  GPIO_PORTF_AMSEL_R = 0;               // disable analog functionality on PF
}

int main(void){
  PLL_Init(Bus80MHz);                   // 80 MHz
  PortF_Init();
  ADC0_InitSWTriggerSeq3_Ch9();         // allow time to finish activating
  PF2 = 0;                              // turn off LED
  ST7735_InitR(INITR_REDTAB);
  Timer1_Init();
  Timer0A_Init100HzInt();               // set up Timer0A for 100 Hz interrupts
  EnableInterrupts();

  while(1){
    PF1 ^= 0x02;  // toggles when running in main
    PF1 = (PF1*12345678)/1234567+0x02;  // this line causes jitter
    if (AdcIndex >= 1000) {
      uint32_t minAdcValue = AdcValueBuffer[0];
      uint32_t maxAdcValue = AdcValueBuffer[0];
        
      for (int i = 0; i < 1000; ++i) {
        if (AdcValueBuffer[i] < minAdcValue) {
          minAdcValue = AdcValueBuffer[i];
        } else if (AdcValueBuffer[i] > maxAdcValue) {
          maxAdcValue = AdcValueBuffer[i];
        }
      }
      
      for (int i = 0; i < 1000; i++) {
	      pmf[AdcValueBuffer[i] - minAdcValue] += 1; 
      }
	
//      for (int i = 0; i < (maxAdcValue - minAdcValue); i++) {
//	      count[i] = minAdcValue + i;
//	    }
      
      int32_t timeJitter = calculateTimeJitter();
      ST7735_OutUDec(timeJitter);
      Pause();
      
      ST7735_SetCursor(0, 0);
      char* title = "PMF";
      ST7735_XYplotInit(title, minAdcValue, maxAdcValue, 0, 1000);
      if ((maxAdcValue - minAdcValue) > 1000) {
        char* OOBError = "Range too large";
        ST7735_SetCursor(0, 7);
        ST7735_OutString(OOBError);
      } else{	
        ST7735_XYplot(maxAdcValue - minAdcValue, count, pmf);
      }
      ST7735_SetCursor(0, 1);
      ST7735_OutString("MinAdc: "); ST7735_OutUDec(minAdcValue);
      ST7735_SetCursor(0, 2); 
      ST7735_OutString("MaxAdc: "); ST7735_OutUDec(maxAdcValue);

      //free(pmf);
      //free(count);
      //  ST7735_OutUDec(timeJitter); ST7735_SetCursor(0,1);
      //  ST7735_OutUDec(minAdcValue); ST7735_SetCursor(0,2);
      //  ST7735_OutUDec(maxAdcValue); ST7735_SetCursor(0,3);
      
      AdcIndex = 0;
      
    //  pmfCalculate(minAdcValue);
    //  int32_t* pmf = (int32_t*) malloc(4096 * sizeof(int32_t));
    }
  }
}


