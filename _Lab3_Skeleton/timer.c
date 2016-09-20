#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "Timer.h"
#include "FIFO.h"

#define ORIGIN_TIMER              1
#define UPDATE_HANDS              0
#define SECONDS_INCREMENT_VALUE   1

#define BUS_80MHZ      80000000
#define TEMP_FREQ      10000

void DisableInterrupts(void);
void EnableInterrupts(void);

//static void (*PeriodicTask)(void);   // user function

// Initialize SysTick with busy wait running at bus clock.
// Period is in seconds
void SysTick_Init(uint32_t period){
  NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
  NVIC_ST_RELOAD_R = BUS_80MHZ * period;// reload value
  NVIC_ST_CURRENT_R = 0;                // any write to current clears it
                                        // enable SysTick with core clock
  NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC;
}

void SysTick_Handler() {
  rxDataType updateClockHands = 
    {ORIGIN_TIMER, UPDATE_HANDS, SECONDS_INCREMENT_VALUE};
  RxFifo_Put(updateClockHands);
}

/* Summary: Initialize Timer0A
 * Input:   Frequency in Hz
 * Output:  None
 */
//void Timer0A_Init(void (*task)(void), uint32_t freq){
void Timer0A_Init(uint32_t freq){
  long sr;
  sr = StartCritical(); 
  volatile uint32_t delay;
  DisableInterrupts();
  SYSCTL_RCGCTIMER_R |= 0x01;        // activate timer0
  delay = SYSCTL_RCGCTIMER_R;        // allow time to finish activating
  TIMER0_CTL_R &= ~TIMER_CTL_TAEN;   // disable timer0A during setup
  TIMER0_CFG_R = 0;                  // configure for 32-bit timer mode
  TIMER1_TAPR_R = 0;                 // bus clock resolution
  TIMER0_TAMR_R = TIMER_TAMR_TAMR_PERIOD; // configure for periodic mode
  TIMER0_TAILR_R = BUS_80MHZ / freq - 1;  // start value for XXX Hz interrupts
  TIMER0_IMR_R |= TIMER_IMR_TATOIM;  // enable timeout (rollover) interrupt
  TIMER0_ICR_R = TIMER_ICR_TATOCINT; // clear timer0A timeout flag
  TIMER0_CTL_R |= TIMER_CTL_TAEN;  // enable timer0A 32-b, periodic, interrupts
  NVIC_PRI4_R = (NVIC_PRI4_R&0x00FFFFFF)|0x40000000; // priority 2
  NVIC_EN0_R = 1<<19;                // enable interrupt 19 in NVIC
  EndCritical(sr);
}

/* Summary: Initialize Timer1A
 * Input: Timer reload value (in clock ticks)
 * Output: None
 */
//void Timer1A_Init(void (*task) void, uint32_t freq){
void Timer1A_Init(uint32_t freq){
  long sr;
  sr = StartCritical(); 
  volatile uint32_t delay;
  SYSCTL_RCGCTIMER_R |= 0x02;   // activate TIMER1
  delay = SYSCTL_RCGCTIMER_R;   // allow time to finish activating
  //PeriodicTask = task;        // user function
  TIMER1_CTL_R = 0x00000000;    // disable TIMER1A during setup
  TIMER1_CFG_R = 0x00000000;    // configure for 32-bit mode
  TIMER1_TAMR_R = 0x00000002;   // configure for periodic mode, default down-count settings
  TIMER0_TAILR_R = BUS_80MHZ / freq - 1;  // start value for XXX Hz interrupts
  TIMER1_TAPR_R = 0;            // bus clock resolution
  TIMER1_ICR_R = 0x00000001;    // clear TIMER1A timeout flag
  TIMER1_IMR_R = 0x00000001;  // arm timeout interrupt
  NVIC_PRI5_R = (NVIC_PRI5_R&0xFFFF00FF)|0x00008000; // priority 4
  NVIC_EN0_R = 1<<21;           // enable IRQ 21 in NVIC
  TIMER1_CTL_R = 0x00000001;    // enable TIMER1A
  EndCritical(sr);
}

// Initialization will need to enable timers
// 0A, 1A, and SysTick
// Interrupts are enabled for each
// Timers 0A and 1A are disabled until alarm sounds or 
// blinking cursor is requested, respectively.
void Timer_Init(void)
{
  Timer0A_Init(TEMP_FREQ);
  Timer1A_Init(TEMP_FREQ);
}

