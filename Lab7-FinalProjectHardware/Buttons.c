#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

void Buttons_Init(void) {
  GPIO_PORTD_LOCK_R = 0x4C4F434B;   // unlock GPIO Port D
  GPIO_PORTD_CR_R = 0xF0;           // allow changes to PD 7
  GPIO_PORTD_DIR_R &= ~0xF0;        // make PD 7,6,5,4 input
  GPIO_PORTD_AFSEL_R &= ~0xF0;      // disable alternate function on PD 7,6,5,4
  GPIO_PORTD_DEN_R |= 0xF0;         // enable digital I/O on PD 7,6,5,4
  GPIO_PORTD_AMSEL_R &= ~0xF0;      // disable analog functionality on PD 7,6,5,4
  
  GPIO_PORTE_DIR_R &= ~0x38;        // make PE 5,4,3 input
  GPIO_PORTE_AFSEL_R &= ~0x38;      // disable alternate function on PE 5,4,3
  GPIO_PORTE_DEN_R |= 0x38;         // enable digital I/O on PE 5,4,3
  GPIO_PORTE_AMSEL_R &= ~0x38;      // disable analog functionality on PE 5,4,3
}

