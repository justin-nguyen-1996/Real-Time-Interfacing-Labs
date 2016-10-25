#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "Switch.h"

//Arming functions for debouncing
void Timer2Arm(void)
{
	SYSCTL_RCGCTIMER_R |= 0x04;   // 0) activate timer2
  TIMER2_CTL_R = 0x00000000;    // 1) disable TIMER2A during setup
  TIMER2_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
  TIMER2_TAMR_R = 0x0000001;    // 3) 1-SHOT mode
  TIMER2_TAILR_R = 160000;      // 4) 10ms reload value
  TIMER2_TAPR_R = 0;            // 5) bus clock resolution
  TIMER2_ICR_R = 0x00000001;    // 6) clear TIMER2A timeout flag
  TIMER2_IMR_R = 0x00000001;    // 7) arm timeout interrupt
  NVIC_PRI5_R = (NVIC_PRI5_R&0x00FFFFFF)|0x80000000; // 8) priority 4
// interrupts enabled in the main program after all devices initialized
// vector number 35, interrupt number 19
  NVIC_EN0_R = 1<<23;           // 9) enable IRQ 19 in NVIC
  TIMER2_CTL_R = 0x00000001;    // 10) enable TIMER0A
}

void GPIOArm_PortB(void)
{
  GPIO_PORTB_ICR_R = 0x03;          // 11) clear flags
  GPIO_PORTB_IM_R |= 0x03;          // 12) arm interrupts on PB7-0 
  NVIC_PRI0_R = (NVIC_PRI0_R&0xFFFF00FF)|0x0000A000; // 13) priority 5
//  NVIC_PRI0_R = (NVIC_PRI0_R&0x00FFFFFF)|0xA0000000; // 13) priority 5
  NVIC_EN0_R = 0x00000002;          // 13) enable interrupt 1 in NVIC
}

static uint32_t LastB;
static uint32_t ValueB;
void Timer2A_Handler(void)
{
  TIMER2_IMR_R = 0;
  LastB = GPIO_PORTB_DATA_R;
  GPIOArm_PortB();
}

void GPIOPortB_Handler(void)
{
  GPIO_PORTB_IM_R &= ~0x03;
  if(LastB)
  {
		ValueB = LastB;
  } 
  Timer2Arm();
}

void Switch_Init(void)
{
	PortB_Init();	
	Timer2Arm();
}

uint8_t Switch_GetStatus(void)
{
	if (ValueB & 0x1) {ValueB = 0; return 1;}
	else if (ValueB & 0x2) {ValueB = 0; return 2;}
	else {return 0;}
}


