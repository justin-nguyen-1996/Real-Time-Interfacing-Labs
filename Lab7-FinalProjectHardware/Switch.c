#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

//volatile static unsigned long Last;      // previous
//void (*TouchTask)(void);    // user function to be executed on touch
//void (*ReleaseTask)(void);  // user function to be executed on release

// allow interrupts on Timer2
static void Timer2_Arm(void){
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
static void PortD_Arm(void){
  GPIO_PORTD_ICR_R = 0xF0;      // clear flags on PD 7,6,5,4
  GPIO_PORTD_IM_R |= 0xF0;      // arm interrupt on PD 7,6,5,4
  NVIC_PRI0_R = (NVIC_PRI0_R&0x00FFFFFF)|0xA0000000; // priority 5
  NVIC_EN0_R = 1<<3;      // enable interrupt 3 in NVIC  
}

// allow interrupts on PortE
static void PortE_Arm(void){
  GPIO_PORTE_ICR_R = 0x30;      // clear flags on PE 5,4
  GPIO_PORTE_IM_R |= 0x30;      // arm interrupt on PE 5,4
  NVIC_PRI1_R = (NVIC_PRI1_R&0xFFFFFF0F)|0x000000A0; // priority 5
  NVIC_EN0_R = 1<<4;      // enable interrupt 4 in NVIC  
}

// Interrupt on rising edges of PD 7,6,5,4
void GPIOPortD_Handler(void){
  GPIO_PORTD_IM_R &= ~0xF0;     // disarm interrupt on PD 7,6,5,4
  
  // TODO: arrange these in order of priority to decide what happens if more than one button is pressed at the same time
  // TODO: fill these out based on action desired
  // TODO: assign proper priorities to buttons on Port D & E
  if      (SW_TSTICK_1) {} 
  else if (SW_TSTICK_2) {}
  else if (SW_A)        {}
  else if (SW_B)        {}
    
  Timer2_Arm(); // start one shot debouncing
}

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
  PortD_Arm();                  // re-enable button interrupts
  PortE_Arm();
}
