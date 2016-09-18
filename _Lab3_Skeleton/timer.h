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

#endif
