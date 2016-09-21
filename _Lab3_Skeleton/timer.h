
#include <stdint.h>

#ifndef __timerh
#define __timerh

typedef enum Timer_ID {
  CLOCK_TICK = 0,
  CURSOR_BLINK = 1,
  ALARM_SOUND = 2,
  ALARM_LED = 3,
  ALARM_FLASH = 4,
} Timer_ID;

void Timer_Init(void);

/* Summary: Initialize Timer0A
 * Input:   Frequency in Hz
 * Output:  None
 */
//void Timer0A_Init(void (*task)(void), uint32_t freq){
void Timer0A_Init(uint32_t freq);
  
/* Summary: Initialize Timer1A
 * Input: Timer reload value (in clock ticks)
 * Output: None
 */
//void Timer1A_Init(void (*task) void, uint32_t freq){
void Timer1A_Init(uint32_t freq);

// Initialize SysTick with busy wait running at bus clock.
// Period is in seconds
void SysTick_Init(void);

#endif
