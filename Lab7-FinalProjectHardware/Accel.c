#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "Accel.h"

void Accel_Init(void) {
  GPIO_PORTE_DIR_R &= ~0x07;      // make PE 2,1,0 input
  GPIO_PORTE_AFSEL_R |= 0x07;     // enable alternate function on PE 2,1,0
  GPIO_PORTE_DEN_R &= ~0x07;      // disable digital I/O on PE 2,1,0
  GPIO_PORTE_AMSEL_R |= 0x07;     // enable analog functionality on PE 2,1,0  
  //GPIO_PORTE_PCTL_R = GPIO_PORTE_PCTL_R&0xFFFFF000;
}

