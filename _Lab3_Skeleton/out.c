#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "out.h"
#include "Timer.h"



void DelayWait10ms(uint32_t n){uint32_t volatile time;
  while(n){
    time = 727240*2/91;  // 10msec
    while(time){
	  	time--;
    }
    n--;
  }
}

void PortE_Init(void) {
  SYSCTL_RCGCGPIO_R |= 0x10;
  while((SYSCTL_PRGPIO_R&0x10) != 0x10){};
  GPIO_PORTE_DIR_R |= 0x02;       // 2) make PE1 output
  GPIO_PORTE_AFSEL_R &= ~0x02;    // 3) enable alternate function on PE1
  GPIO_PORTE_DEN_R |= 0x02;       // 4) enable digital I/O on PE1
    
  GPIO_PORTE_AMSEL_R &= ~0x02;      // 3) disable analog functionality on PE1
  GPIO_PORTE_PCTL_R &= ~0x000000F0; // 4) GPIO
//  GPIO_PORTE_CR_R |= 0x03;          // 8) allow changes to PE1
//  GPIO_PORTE_IS_R &= ~0x03;         // 8) edge-sensitive
//  GPIO_PORTE_IBE_R |= 0x03;        // 9) not both edges
}

//void GPIOArm_PortE(void)
//{
//  GPIO_PORTE_ICR_R = 0x03;          // 11) clear flags
//  GPIO_PORTE_IM_R |= 0x03;          // 12) arm interrupts on PB7-0 
//  NVIC_PRI1_R = (NVIC_PRI1_R&0xFFFFFF00)|0x000000A0; // 13) priority 5
//  NVIC_EN0_R = 1<<4;                // 13) enable interrupt 4 in NVIC
//}

// Initialization will enable two GPIO pins
// one digital out for operating the speaker
// one digital out for operating the on-board LED

void PortF_Init() {
  SYSCTL_RCGCGPIO_R |= 0x20;
  while((SYSCTL_PRGPIO_R&0x20) != 0x20){};
  GPIO_PORTF_DIR_R |= 0x02;             // make PF1 out (built-in LED)
  GPIO_PORTF_AFSEL_R &= ~0x02;          // disable alt funct on PF1
  GPIO_PORTF_DEN_R |= 0x02;             // enable digital I/O on PF1
  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFFF0F); // GPIO
  GPIO_PORTF_AMSEL_R = 0;               // disable analog functionality on PF
}

void out_Init(void) {
  PortE_Init();
  PortF_Init();
//  GPIOArm_PortE();
}

void Timer0A_Handler(void){
  TIMER0_ICR_R = TIMER_ICR_TATOCINT; // acknowledge timer0A timeout
  PE1 ^= 0x02;
	PF1 ^= 0x02;
}

void out_Speaker(uint32_t value) {
  Timer0A_Init(value);  
}
void out_SpeakerDisable(void)
{
  SYSCTL_RCGCTIMER_R &= ~(0x01);        // deactivate timer0
	PF1 = 0;
	PE1 = 0;
}

