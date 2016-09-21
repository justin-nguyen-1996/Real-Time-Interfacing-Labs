#ifndef __outh
#define __outh

#include <stdint.h>
#define PF4  (*((volatile uint32_t *)0x40025040))
#define PF3  (*((volatile uint32_t *)0x40025020))
#define PF2  (*((volatile uint32_t *)0x40025010))
#define PF1  (*((volatile uint32_t *)0x40025008))
  
#define PE1  (*((volatile uint32_t *)0x40024008))

void out_Init(void);

void out_Speaker(uint32_t value);
void out_SpeakerDisable(void);
void out_LED(uint32_t value);
#endif
