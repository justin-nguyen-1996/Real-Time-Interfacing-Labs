#ifndef ADC_H
#define ADC_H

#include <stdint.h>
void ADC_Init(void);
void ADC_In(uint16_t tstick[4], uint16_t accel[3]);
void ADC_Test(void);

#endif
