#ifndef BUTTONS_H
#define BUTTONS_H

void Buttons_Init(void);
void Buttons_Test(void);
void Timer2_Arm(void);
void PortD_Arm(void);
void PortE_Arm(void);
void GPIOPortD_Handler(void);
void GPIOPortE_Handler(void);
void Timer2A_Handler(void);

#endif
