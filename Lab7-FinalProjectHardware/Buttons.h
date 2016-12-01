#ifndef BUTTONS_H
#define BUTTONS_H

#define SW_TSTICK_1   (*((volatile uint32_t *)0x40007040)) // SW = switch
#define SW_TSTICK_2   (*((volatile uint32_t *)0x40007080))
#define SW_A          (*((volatile uint32_t *)0x40007100))
#define SW_B          (*((volatile uint32_t *)0x40007200))
  
#define SW_MISC       (*((volatile uint32_t *)0x40024040)) // miscellaneous button
#define SW_START      (*((volatile uint32_t *)0x40024080)) // start button

void Buttons_Init(void);
void Buttons_Test(void);
void Timer2_Arm(void);
void PortD_Arm(void);
void PortE_Arm(void);
void GPIOPortD_Handler(void);
void GPIOPortE_Handler(void);
void Timer2A_Handler(void);

#endif
