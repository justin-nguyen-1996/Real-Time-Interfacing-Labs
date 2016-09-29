#ifndef __switchh
#define __switchh

//Initialize GPIO ports and timer
void Switch_Init(void);

//get which switch was pushed
uint8_t Switch_GetStatus(void);

//Used to debounce switches
void GPIOArm_PortD(void);
void Timer2Arm(void);

#endif
