extern "C" {
	#include <stdint.h>
	#include "../inc/tm4c123gh6pm.h"
	#include "PLL.h"
	#include "DAC.h"
  //#include "Switch.h" // TODO: probably combine switch.c into buttons.c
  #include "LED.h"
	#include "esp8266.h"
  #include "ST7735.h"
	#include "Buttons.h"
  //#include "UART.h"
	#include "Thumbstick.h"
	#include "Accel.h"
	#include "Graphics.h"
	#include "ADC.h"
  #include "GameRules.h"
	#include "PortInit.h"
}
//#include "GameRules.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

static const int BAUD_RATE = 115200;
static uint16_t tstick[4]; static uint16_t accel[3];

void waitForTouch() {
  while (RIGHTSWITCH == 0x01) {}
}

int main(void) {
  
  PortA_Init();
  PortB_Init();
  PortC_Init();
  PortD_Init();
  PortE_Init();
  PortF_Init();
  
  PLL_Init(Bus80MHz);
  DAC_Init();
  //Switch_Init();
  LED_Init();
//  ESP8266_Init(BAUD_RATE);
  ST7735_InitR(INITR_REDTAB);
//  Buttons_Init();
  Thumbstick_Init();
  Accel_Init();
  ADC_Init();
  
//  ST7735_Test();  waitForTouch(); Output_Clear();
//  DAC_Test(2);    waitForTouch(); Output_Clear();
//  Buttons_Test(); waitForTouch(); Output_Clear();
  ADC_Test();     waitForTouch(); Output_Clear();
  
}
