#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "Accel.h"

void Accel_Init(void) {
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

//------------ADC0_InSeq3------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 12-bit result of ADC conversion
uint32_t ADC0_InSeqXX(void){  uint32_t result; // TODO: fix my name
  ADC0_PSSI_R = 0x0008;            // 1) initiate SS3
  while((ADC0_RIS_R&0x08)==0){};   // 2) wait for conversion done
    // if you have an A0-A3 revision number, you need to add an 8 usec wait here
  result = ADC0_SSFIFO3_R&0xFFF;   // 3) read result
  ADC0_ISC_R = 0x0008;             // 4) acknowledge completion
  return result;
}
