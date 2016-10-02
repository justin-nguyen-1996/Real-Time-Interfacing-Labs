#ifndef __switchh
#define __switchh

#include <stdint.h>

// Initialize GPIO ports and timer
void Switch_Init(void);

// Get which switch was pushed
uint8_t Switch_GetStatus(void);

// Used to debounce switches
void GPIOArm_PortD(void);
void Timer2Arm(void);

#endif
