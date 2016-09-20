#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "out.h"

void PortE_Init(void) {
  SYSCTL_RCGCGPIO_R |= 0x10;
  while((SYSCTL_PRGPIO_R&0x10) != 0x10){};
  GPIO_PORTE_DIR_R |= 0x02;       // 2) make PE1 output
  GPIO_PORTE_AFSEL_R &= ~0x02;    // 3) enable alternate function on PE1
  GPIO_PORTE_DEN_R |= 0x02;       // 4) enable digital I/O on PE1
    
  GPIO_PORTE_AMSEL_R &= ~0x02;      // 3) disable analog functionality on PE1
  GPIO_PORTE_PCTL_R &= ~0x000000F0; // 4) GPIO
  GPIO_PORTE_CR_R |= 0x02;          // 8) allow changes to PE1
  GPIO_PORTE_IS_R &= ~0x02;         // 8) edge-sensitive
  GPIO_PORTE_IBE_R |= 0x02;        // 9) not both edges
//  GPIO_PORTD_IEV_R |= 0x02;         // 10) rising edge event
//  GPIO_PORTE_ICR_R = 0x02;          // 11) clear flags
//  GPIO_PORTD_IM_R |= 0xFF;          // 12) arm interrupts on PD7-0 
//  NVIC_PRI0_R = (NVIC_PRI0_R&0x00FFFFFF)|0xA0000000; // 13) priority 5
//  NVIC_EN0_R = 0x00000008;          // 13) enable interrupt 3 in NVIC
}

void GPIOArm_PortE(void)
{
  GPIO_PORTE_ICR_R = 0x02;          // 11) clear flags
  GPIO_PORTE_IM_R |= 0x02;          // 12) arm interrupts on PB7-0 
  NVIC_PRI1_R = (NVIC_PRI1_R&0xFFFFFF00)|0x000000A0; // 13) priority 5
  NVIC_EN0_R = 1<<4;                // 13) enable interrupt 4 in NVIC
}

// Initialization will enable two GPIO pins
// one digital out for operating the speaker
// one digital out for operating the on-board LED

void out_Init(void) {
  PortE_Init();
  GPIOArm_PortE();
}

void out_Speaker(uint32_t value){}
void out_LED(uint32_t value){}
