#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "PLL.h"
#include "Init.h"
#include "Buttons.h"
#include "DAC.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

int main(void) {
  PortA_Init();
  PortB_Init();
  PortC_Init();
  PortD_Init();
  PortE_Init();
  PortF_Init();
  
  PLL_Init(Bus80MHz);
  Buttons_Init();
  DAC_Init();
}
