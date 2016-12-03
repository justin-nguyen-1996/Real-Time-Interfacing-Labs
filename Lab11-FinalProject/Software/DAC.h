#ifndef __dach
#define __dach

#include <stdint.h>

/* Summary: initialize DAC
 * Input:   none
 * Output:  none
 * Assumes: system clock rate less than 20 MHz
 */
void DAC_Init(void);

/* Summary: Send data to DAC
 * Input:   voltage output (0 to 4095)
 * Output:  none
 */
void DAC_Out(uint16_t code);
void Timer0A_Init(uint32_t period);
void DAC_Test(int testNumber);
void disableSound(void);
void enableSound(void);

#endif
