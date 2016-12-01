#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "Buttons.h"
#include "Debug.h"

volatile unsigned long Last;      // previous button state

void Buttons_Init(void) {
  GPIO_PORTD_LOCK_R = 0x4C4F434B;   // unlock GPIO Port D
  GPIO_PORTD_CR_R = 0xF0;           // allow changes to PD 7
  GPIO_PORTD_DIR_R &= ~0xF0;        // make PD 7,6,5,4 input
  GPIO_PORTD_AFSEL_R &= ~0xF0;      // disable alternate function on PD 7,6,5,4
  GPIO_PORTD_DEN_R |= 0xF0;         // enable digital I/O on PD 7,6,5,4
  GPIO_PORTD_AMSEL_R &= ~0xF0;      // disable analog functionality on PD 7,6,5,4
  GPIO_PORTD_PDR_R |= 0xF0;
  
  GPIO_PORTD_IS_R &= ~0xF0;         // PD 7,6,5,4 are edge-sensitive
  GPIO_PORTD_IBE_R &= ~0xF0;        // disable trigger on both edges
  GPIO_PORTD_IEV_R |= 0xF0;         // only trigger on rising edges
  
  GPIO_PORTE_DIR_R &= ~0x38;        // make PE 5,4,3 input
  GPIO_PORTE_AFSEL_R &= ~0x38;      // disable alternate function on PE 5,4,3
  GPIO_PORTE_DEN_R |= 0x38;         // enable digital I/O on PE 5,4,3
  GPIO_PORTE_AMSEL_R &= ~0x38;      // disable analog functionality on PE 5,4,3
  
  GPIO_PORTE_IS_R &= ~0x30;         // PE 5,4 are edge-sensitive
  GPIO_PORTE_IBE_R &= ~0x30;
  GPIO_PORTE_IEV_R |= 0x30;         // only trigger on rising edges
  
  PortD_Arm(); PortE_Arm();
  SYSCTL_RCGCTIMER_R |= 0x04;       // activate timer2
  while ((SYSCTL_RCGCTIMER_R & 0x04) == 0) {}
  Last = 1;
}

// allow interrupts on Timer2
void Timer2_Arm(void){
  TIMER2_CTL_R = 0x00000000;    // disable TIMER2A during setup
  TIMER2_CFG_R = 0x00000000;    // configure for 32-bit mode
  TIMER2_TAMR_R = 0x0000001;    // 1-SHOT mode
  TIMER2_TAILR_R = 800000;      // 10ms reload value
  TIMER2_TAPR_R = 0;            // bus clock resolution
  TIMER2_ICR_R = 0x00000001;    // clear TIMER2A timeout flag
  TIMER2_IMR_R = 0x00000001;    // arm timeout interrupt
  NVIC_PRI5_R = (NVIC_PRI5_R&0x00FFFFFF)|0x80000000; // priority 4
  NVIC_EN0_R = 1<<23;           // enable IRQ 23 in NVIC
  TIMER2_CTL_R = 0x00000001;    // enable TIMER2A
}

// allow interrupts on PortD
void PortD_Arm(void){
  GPIO_PORTD_ICR_R = 0xF0;      // clear flags on PD 7,6,5,4
  GPIO_PORTD_IM_R |= 0xF0;      // arm interrupt on PD 7,6,5,4
  NVIC_PRI0_R = (NVIC_PRI0_R&0x00FFFFFF)|0xA0000000; // priority 5
  NVIC_EN0_R = 1<<3;      // enable interrupt 3 in NVIC  
}

// allow interrupts on PortE
void PortE_Arm(void){
  GPIO_PORTE_ICR_R = 0x30;      // clear flags on PE 5,4
  GPIO_PORTE_IM_R |= 0x30;      // arm interrupt on PE 5,4
  NVIC_PRI1_R = (NVIC_PRI1_R&0xFFFFFF0F)|0x000000A0; // priority 5
  NVIC_EN0_R = 1<<4;      // enable interrupt 4 in NVIC  
}

//// Interrupt on rising edges of PD 7,6,5,4
//void GPIOPortD_Handler(void){
//  GPIO_PORTD_IM_R &= ~0xF0;     // disarm interrupt on PD 7,6,5,4
//  
//  // SW_A --> PD6,   SW_B --> PD7
//  if (Last) {
//    if      (SW_TSTICK_1) { } 
//    else if (SW_TSTICK_2) { }
//    else if (SW_A)        { fireMissile(); }
//    else if (SW_B)        { }
//  }
//    
//  Timer2_Arm(); // start one shot debouncing
//}

// Interrupt on rising edges of PE 5,4
void GPIOPortE_Handler(void){
  GPIO_PORTE_IM_R &= ~0x30;     // disarm interrupt on PE 5,4
  
  // TODO: arrange these in order of priority to decide what happens if more than one button is pressed at the same time
  // TODO: fill these out based on action desired
  // TODO: assign proper priorities to buttons on Port D & E
  if      (SW_MISC)  {} 
  else if (SW_START) {}
    
  Timer2_Arm(); // start one shot debouncing
}

// Interrupt 10 ms after rising edge of a button trigger
void Timer2A_Handler(void){
  TIMER2_IMR_R = 0x00000000;    // disarm timeout interrupt
  Last = SW_TSTICK_1 | SW_TSTICK_2 | SW_A | SW_B | SW_MISC | SW_START;
  PortD_Arm();                  // re-enable button interrupts
  PortE_Arm();
}

#ifdef DEBUG
#include "ST7735.h"   // TODO: remove me when done testing
#include "PortInit.h" // TODO: remove me when done testing
static int counter = 0;
void Buttons_Test(void) {
//  ST7735_SetCursor(0,0); ST7735_OutString("Counter:    "); ST7735_SetCursor(9,0); ST7735_OutUDec(counter);
//  ST7735_OutString("\nPush TStick_1 button"); while(PD4 == 0){}; counter += 1;
//  ST7735_SetCursor(0,0); ST7735_OutString("Counter:    "); ST7735_SetCursor(9,0); ST7735_OutUDec(counter);
//  ST7735_OutString("\nPush TStick_2 button"); while(PD5 == 0){}; counter += 1;
  while (1) {
    ST7735_SetCursor(0,0); ST7735_OutString("Counter:    "); ST7735_SetCursor(9,0); ST7735_OutUDec(counter);
    ST7735_OutString("\nPush 'A' button"); while(PD6 == 0){};
  }
//  ST7735_SetCursor(0,0); ST7735_OutString("Counter:    "); ST7735_SetCursor(9,0); ST7735_OutUDec(counter);
//  ST7735_OutString("\nPush Start button"); while(PE5 == 0){}; counter += 1;
//  ST7735_SetCursor(0,0); ST7735_OutString("Counter:    "); ST7735_SetCursor(9,0); ST7735_OutUDec(counter);
//  ST7735_OutString("\nPush the IDK button"); while(PE4 == 0){}; counter += 1;
//  ST7735_SetCursor(0,0); ST7735_OutString("Counter:    "); ST7735_SetCursor(9,0); ST7735_OutUDec(counter);
}
#endif
// TODO: test for debouncing --> maybe increment counter in the ISR and print out counter after each button press

