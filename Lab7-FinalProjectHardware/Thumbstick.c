#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

void Thumbstick_Init(void) {
  SYSCTL_RCGCADC_R |= 0x0001;     // activate ADC0 
  GPIO_PORTD_DIR_R &= ~0x0F;      // make PD 3,2,1,0 input
  GPIO_PORTD_AFSEL_R |= 0x0F;     // enable alternate function on PD 3,2,1,0
  GPIO_PORTD_DEN_R &= ~0x0F;      // disable digital I/O on PD 3,2,1,0
  GPIO_PORTD_AMSEL_R |= 0x0F;     // enable analog functionality on PD 3,2,1,0

  ADC0_PC_R &= ~0xF;              // clear max sample rate field
  ADC0_PC_R |= 0x1;               // configure for 125K samples/sec
  ADC0_SSPRI_R = 0x0123;          // Sequencer 3 is highest priority
  ADC0_ACTSS_R &= ~0x0008;        // disable sample sequencer 3
  ADC0_EMUX_R &= ~0xF000;         // seq3 is software trigger
  ADC0_SSMUX3_R &= ~0x000F;       // clear SS3 field
  ADC0_SSMUX3_R += 9;             // set channel
  ADC0_SSCTL3_R = 0x0006;         // no TS0 D0, yes IE0 END0
  ADC0_IM_R &= ~0x0008;           // disable SS3 interrupts
  ADC0_ACTSS_R |= 0x0008;         // enable sample sequencer 3
}
