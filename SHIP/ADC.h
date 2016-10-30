// ADC.h
// Runs on LM4F120/TM4C123
// Provide functions that initialize ADC0

// TREVOR
// MODIFIED TODAY

#include <stdint.h>


// ADC initialization function 
// Input: none
// Output: none
void ADC_Init(void);

//------------ADC_In(N)------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 12-bit result of ADC conversion, ADC0, SEQUENCER (N)
void ADC_In(int *x0,int *y0,int *x1,int *y1);

void AverageADCIn(void);

void ConvertRawADC(void);


