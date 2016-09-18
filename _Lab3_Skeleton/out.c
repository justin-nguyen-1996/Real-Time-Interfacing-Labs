#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "out.h"

// Initialization will enable two GPIO pins
// one digital out for operating the speaker
// one digital out for operating the on-board LED
void out_Init(void) {}

void out_Speaker(uint32_t value){}
void out_LED(uint32_t value){}
