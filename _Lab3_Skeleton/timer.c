#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "timer.h"
#include "FIFO.h"

#define ORIGIN_TIMER 1

// Initialize SysTick with busy wait running at bus clock.
void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
  NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;  // maximum reload value
  NVIC_ST_CURRENT_R = 0;                // any write to current clears it
                                        // enable SysTick with core clock
  NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC;
}

void Timer0A_Init(void){}
void Timer1A_Init(void){}

// Initialization will need to enable timers
// 0A, 1A, and SysTick
// Interrupts are enabled for each
// Timers 0A and 1A are disabled until alarm sounds or 
// blinking cursor is requested, respectively.
void Timer_Init(void)
{
  SysTick_Init();
  Timer0A_Init();
  Timer1A_Init();
}

void Timer0A_Handler(void){}
void Timer1A_Handler(void){}

