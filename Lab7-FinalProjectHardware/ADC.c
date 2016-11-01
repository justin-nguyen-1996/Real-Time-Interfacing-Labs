#include "../inc/tm4c123gh6pm.h"
#include "ADC.h"
#include "Accel.h"
#include "Thumbstick.h"
#include "Debug.h"

// 125k max sampling
// SS2 triggering event: software trigger, busy-wait sampling
void ADC_Init(void) {
  SYSCTL_RCGCADC_R |= 0x0001;     // activate ADC0 
  while ((SYSCTL_RCGCADC_R & 0x0001) == 0) {}
  for (int delay = 0; delay < 1; ++delay) {} // for some reason needs extra delay ... magic unicorns
  ADC0_PC_R &= ~0xF;              // clear max sample rate field
  ADC0_PC_R |= 0x1;               // configure for 125K samples/sec
  ADC0_SSPRI_R = 0x3210;          // Sequencer 3 is lowest priority
  ADC0_ACTSS_R &= ~0x0001;        // disable sample sequencer 0
  ADC0_EMUX_R &= ~0x000F;         // seq0 is software trigger
  ADC0_SSMUX0_R &= ~0x0FFFFFFF;   // clear SSMUX0 fields
  ADC0_SSMUX0_R += 0x01234567;    // set channels for SS0
  ADC0_SSCTL0_R = 0x06000000;     // IE6 END6
  ADC0_IM_R &= ~0x0001;           // disable SS0 interrupts
  ADC0_ACTSS_R |= 0x0001;         // enable sample sequencer 0
}

//------------ADC_Out------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 7 12-bit results of ADC conversions
// Samples ADC8 and ADC9 
// 125k max sampling
// software trigger, busy-wait sampling
// data returned by reference
// TSTICK1_V is ADC7 (PD0) 0 to 4095
// TSTICK1_H is ADC6 (PD1) 0 to 4095
// TSTICK2_V is ADC5 (PD2) 0 to 4095
// TSTICK2_H is ADC4 (PD3) 0 to 4095
// ACCEL_X   is ADC3 (PE0) 0 to 4095
// ACCEL_Y   is ADC2 (PE1) 0 to 4095
// ACCEL_Z   is ADC1 (PE2) 0 to 4095
void ADC_Out(uint16_t tstick[4], uint16_t accel[3]) { 
  ADC0_PSSI_R = 0x0001;            // 1) initiate SS0
  while((ADC0_RIS_R&0x01)==0){};   // 2) wait for conversion done
  tstick[TSTICK1_V] = ADC0_SSFIFO0_R&0xFFF;  // 3) read ADC conversions on thumbsticks
  tstick[TSTICK1_H] = ADC0_SSFIFO0_R&0xFFF;  
  tstick[TSTICK2_V] = ADC0_SSFIFO0_R&0xFFF;
  tstick[TSTICK2_H] = ADC0_SSFIFO0_R&0xFFF;
  accel[ACCEL_X]    = ADC0_SSFIFO0_R&0xFFF;  // 4) read ADC conversions on accelerometers
  accel[ACCEL_Y]    = ADC0_SSFIFO0_R&0xFFF;
  accel[ACCEL_Z]    = ADC0_SSFIFO0_R&0xFFF;  
  ADC0_ISC_R = 0x0001;             // 4) acknowledge completion
}

#ifdef DEBUG
#include "ST7735.h"
#include "PortInit.h"
void ADC_Test() {
  uint16_t tstick[4] = {0,0,0,0}; uint16_t accel[3] = {0,0,0};
  while (1) {

    ADC_Out(tstick, accel);
    PE3 = 0x00; // Self-Test is disabled
    
    ST7735_SetCursor(0,0);
    ST7735_OutString("TStick_1 Y:     "); ST7735_SetCursor(12,0); ST7735_OutUDec(tstick[TSTICK1_V]); ST7735_OutChar('\n');
    ST7735_OutString("TStick_1 X:     "); ST7735_SetCursor(12,1); ST7735_OutUDec(tstick[TSTICK1_H]); ST7735_OutChar('\n');
    ST7735_OutString("TStick_2 Y:     "); ST7735_SetCursor(12,2); ST7735_OutUDec(tstick[TSTICK2_V]); ST7735_OutChar('\n');
    ST7735_OutString("TStick_2 X:     "); ST7735_SetCursor(12,3); ST7735_OutUDec(tstick[TSTICK2_H]); ST7735_OutChar('\n');
    ST7735_OutString("Accelrom X:     "); ST7735_SetCursor(12,4);  ST7735_OutUDec(accel[ACCEL_X]); ST7735_OutChar('\n');
    ST7735_OutString("Accelrom Y:     "); ST7735_SetCursor(12,5);  ST7735_OutUDec(accel[ACCEL_Y]); ST7735_OutChar('\n');
    ST7735_OutString("Accelrom Z:     "); ST7735_SetCursor(12,6);  ST7735_OutUDec(accel[ACCEL_Z]); ST7735_OutChar('\n');
    
    ST7735_OutChar('\n');
    ST7735_OutString("Keep sampling?\n");
    ST7735_OutString("Yes --> press L_SW\n");
    ST7735_OutString("No  --> press R_SW\n");
//    while (LEFTSWITCH == 0x10   &&   RIGHTSWITCH == 0x01) {}
//    if (RIGHTSWITCH == 0x00) { break; }
  }
}
#endif
