#include <stdint.h>
#include "DAC.h"
#include "Switch.h"
#include "Music.h"
#include "../inc/tm4c123gh6pm.h"
#include "PLL.h"

int main(void) {
  DAC_Init();
  for (int i = 0; i < 100; ++i) {
    //DAC_Out(i);
    SSI3_DR_R = i;
  }
}
