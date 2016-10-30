#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "Thumbstick.h"

void Thumbstick_Init(void){ 
  GPIO_PORTD_DIR_R &= ~0x0F;      // make PD 3,2,1,0 input
  GPIO_PORTD_AFSEL_R |= 0x0F;     // enable alternate function on PD 3,2,1,0
  GPIO_PORTD_DEN_R &= ~0x0F;      // disable digital I/O on PD 3,2,1,0
  GPIO_PORTD_AMSEL_R |= 0x0F;     // enable analog functionality on PD 3,2,1,0  
  //GPIO_PORTD_PCTL_R = GPIO_PORTD_PCTL_R&0xFFFF0000;
}

