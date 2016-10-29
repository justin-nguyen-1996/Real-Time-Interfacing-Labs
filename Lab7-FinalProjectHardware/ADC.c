#include "../inc/tm4c123gh6pm.h"
#include "ADC.h"
#include "Accel.h"
#include "Thumbstick.h"

// 125k max sampling
// SS2 triggering event: software trigger, busy-wait sampling
void ADC_Init(void) {
  ADC0_PC_R &= ~0xF;              // 8) clear max sample rate field
  ADC0_PC_R |= 0x1;               //    configure for 125K samples/sec
  ADC0_SSPRI_R = 0x3210;          // 9) Sequencer 3 is lowest priority
  ADC0_ACTSS_R &= ~0x0001;        // 10) disable sample sequencer 0
  ADC0_EMUX_R &= ~0x000F;         // 11) seq0 is software trigger
  ADC0_SSMUX0_R = 0x01234567;     // 12) set channels for SS0
  ADC0_SSCTL0_R = 0x60000000;     // 13) IE7 END7
  ADC0_IM_R &= ~0x0001;           // 14) disable SS0 interrupts
  ADC0_ACTSS_R |= 0x0001;         // 15) enable sample sequencer 0
}

//------------ADC_Out------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 7 12-bit results of ADC conversions
// Samples ADC8 and ADC9 
// 125k max sampling
// software trigger, busy-wait sampling
// data returned by reference
// data[0] is ADC7 (PD0) 0 to 4095
// data[1] is ADC6 (PD1) 0 to 4095
// data[2] is ADC5 (PD2) 0 to 4095
// data[3] is ADC4 (PD3) 0 to 4095
// data[4] is ADC3 (PE0) 0 to 4095
// data[5] is ADC2 (PE1) 0 to 4095
// data[6] is ADC1 (PE2) 0 to 4095
void ADC_Out(uint16_t tstick[4], uint16_t accel[3]) { 
  ADC0_PSSI_R = 0x0001;            // 1) initiate SS0
  while((ADC0_RIS_R&0x01)==0){};   // 2) wait for conversion done
  tstick[TSTICK1_V] = ADC0_SSFIFO0_R&0xFFF;  // 3) read ADC conversions on thumbsticks
  tstick[TSTICK1_H] = ADC0_SSFIFO0_R&0xFFF;  
  tstick[TSTICK2_V] = ADC0_SSFIFO0_R&0xFFF;  
  tstick[TSTICK1_H] = ADC0_SSFIFO0_R&0xFFF;  
  accel[ACCEL_X]    = ADC0_SSFIFO0_R&0xFFF;  // 4) read ADC conversions on accelerometers
  accel[ACCEL_Y]    = ADC0_SSFIFO0_R&0xFFF;
  accel[ACCEL_Z]    = ADC0_SSFIFO0_R&0xFFF;  
  ADC0_ISC_R = 0x0001;             // 4) acknowledge completion
}
