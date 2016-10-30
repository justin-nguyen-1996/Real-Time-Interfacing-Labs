#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "Buttons.h"
#include "Debug.h"

void Buttons_Init(void) {
  GPIO_PORTD_LOCK_R = 0x4C4F434B;   // unlock GPIO Port D
  GPIO_PORTD_CR_R = 0xF0;           // allow changes to PD 7
  GPIO_PORTD_DIR_R &= ~0xF0;        // make PD 7,6,5,4 input
  GPIO_PORTD_AFSEL_R &= ~0xF0;      // disable alternate function on PD 7,6,5,4
  GPIO_PORTD_DEN_R |= 0xF0;         // enable digital I/O on PD 7,6,5,4
  GPIO_PORTD_AMSEL_R &= ~0xF0;      // disable analog functionality on PD 7,6,5,4
  
  GPIO_PORTE_DIR_R &= ~0x38;        // make PE 5,4,3 input
  GPIO_PORTE_AFSEL_R &= ~0x38;      // disable alternate function on PE 5,4,3
  GPIO_PORTE_DEN_R |= 0x38;         // enable digital I/O on PE 5,4,3
  GPIO_PORTE_AMSEL_R &= ~0x38;      // disable analog functionality on PE 5,4,3
}

#ifdef DEBUG
#include "ST7735.h"   // TODO: remove me when done testing
#include "PortInit.h" // TODO: remove me when done testing
void Buttons_Test(void) {
  uint8_t counter = 0;
  ST7735_SetCursor(0,0); ST7735_OutString("Counter:    "); ST7735_SetCursor(9,0); ST7735_OutUDec(counter);
  ST7735_OutString("\nPush TStick_1 button"); while(PD4 == 0){}; counter += 1;
  ST7735_SetCursor(0,0); ST7735_OutString("Counter:    "); ST7735_SetCursor(9,0); ST7735_OutUDec(counter);
  ST7735_OutString("\nPush TStick_2 button"); while(PD5 == 0){}; counter += 1;
  ST7735_SetCursor(0,0); ST7735_OutString("Counter:    "); ST7735_SetCursor(9,0); ST7735_OutUDec(counter);
  ST7735_OutString("\nPush 'A' button"); while(PD6 == 0){}; counter += 1;
  ST7735_SetCursor(0,0); ST7735_OutString("Counter:    "); ST7735_SetCursor(9,0); ST7735_OutUDec(counter);
  ST7735_OutString("\nPush 'B' button"); while(PD7 == 0){}; counter += 1;
  ST7735_SetCursor(0,0); ST7735_OutString("Counter:    "); ST7735_SetCursor(9,0); ST7735_OutUDec(counter);
  ST7735_OutString("\nPush Start button"); while(PE5 == 0){}; counter += 1;
  ST7735_SetCursor(0,0); ST7735_OutString("Counter:    "); ST7735_SetCursor(9,0); ST7735_OutUDec(counter);
  ST7735_OutString("\nPush the IDK button"); while(PE4 == 0){}; counter += 1;
  ST7735_SetCursor(0,0); ST7735_OutString("Counter:    "); ST7735_SetCursor(9,0); ST7735_OutUDec(counter);
}
#endif
// TODO: test for debouncing --> maybe increment counter in the ISR and print out counter after each button press

