#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "PortInit.h"

void PortA_Init(void){} // see commonInit() in ST7735.c

void PortB_Init(void) {
  SYSCTL_RCGCGPIO_R |= 0x02;
  while((SYSCTL_PRGPIO_R&0x02)==0){};
}

void PortC_Init(void) {
  SYSCTL_RCGCGPIO_R |= 0x04;
  while((SYSCTL_PRGPIO_R&0x04)==0){};
}

void PortD_Init(void) {
  SYSCTL_RCGCGPIO_R |= 0x08;
  while((SYSCTL_PRGPIO_R&0x08)==0){};
}

void PortE_Init(void) {
  SYSCTL_RCGCGPIO_R |= 0x10;
  while((SYSCTL_PRGPIO_R&0x10)==0){};
}

void PortF_Init(void) {
  SYSCTL_RCGCGPIO_R |= 0x20;
  while((SYSCTL_PRGPIO_R&0x20)==0){};
}
