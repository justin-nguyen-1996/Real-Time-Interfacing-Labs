#include <stdint.h>
#include "DAC.h"
#include "Switch.h"
#include "Music.h"
#include "../inc/tm4c123gh6pm.h"
#include "PLL.h"

#define PF0   (*((volatile uint32_t *)0x40025004))
#define PF1   (*((volatile uint32_t *)0x40025008))
#define PF2   (*((volatile uint32_t *)0x40025010))
#define PF3   (*((volatile uint32_t *)0x40025020))
#define PF4   (*((volatile uint32_t *)0x40025040))

void PortF_Init(void){ 
  SYSCTL_RCGCGPIO_R |= 0x20;        // 1) activate clock for Port F
  while((SYSCTL_PRGPIO_R&0x20)==0){}; // allow time for clock to start
                                    // 2) no need to unlock PF2, PF4
  GPIO_PORTF_PCTL_R &= ~0x000F0F00; // 3) regular GPIO
  GPIO_PORTF_AMSEL_R &= ~0x14;      // 4) disable analog function on PF2, PF4
  GPIO_PORTF_PUR_R |= 0x10;         // 5) pullup for PF4
  GPIO_PORTF_DIR_R |= 0x0E;         // 5) set direction to output
  GPIO_PORTF_AFSEL_R &= ~0x14;      // 6) regular port function
  GPIO_PORTF_DEN_R |= 0x1E;         // 7) enable digital port
}

//const uint16_t wave[32] = {
//  2048*2,2448*2,2832*2,3186*2,3496*2,3751*2,3940*2,4057*2,4095*2,4057*2,3940*2,
//  3751*2,3496*2,3186*2,2832*2,2448*2,2048*2,1648*2,1264*2,910*2,600*2,345*2,
//  156*2,39*2,0*2,39*2,156*2,345*2,600*2,910*2,1264*2,1648*2
//};

const uint16_t wave[32] = {
  2048,2448,2832,3186,3496,3751,3940,4057,4095,4057,3940,
  3751,3496,3186,2832,2448,2048,1648,1264,910,600,345,
  156,39,0,39,156,345,600,910,1264,1648
};

int main(void) {
  PortF_Init();
  PLL_Init(Bus80MHz);
  DAC_Init();
  
  //DAC_Test();
  
  uint32_t i = 0;
  while (1) {
    PF1 ^= 0x02;
    //for (int i = 0; i < 1000000; ++i) {}
    DAC_Out(wave[i & 0x1F]);
    i += 1;
    for (int j = 0; j < 1000; ++j) {}
  }
}
