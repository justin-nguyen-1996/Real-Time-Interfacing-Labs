//LED.h
//Dung Nguyen
//Wally Guzman

#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "LED.h"

#define PF1       (*((volatile uint32_t *)0x40025008))
#define PF2       (*((volatile uint32_t *)0x40025010))
#define PF3       (*((volatile uint32_t *)0x40025020))

//------------LED_Init------------
// Initialize PF1-3 for LEDs
// Input: none
// Output: none
void LED_Init(void){
	volatile int delay;
	SYSCTL_RCGCGPIO_R |= 0x20;     			// 1) activate Port F
  delay = SYSCTL_RCGCGPIO_R;   
  GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;	// 2a) unlock GPIO Port F Commit Register
  GPIO_PORTF_CR_R |= 0x0E;        		// 2b) enable commit for PF4-PF0     
  GPIO_PORTF_AMSEL_R &= ~0x0E;   			// 3) disable analog functionality on PF1-PF3     
  GPIO_PORTF_PCTL_R &= 0xFFFF000F;		// 4) configure PF1-PF3 as GPIO
  GPIO_PORTF_DIR_R |= 0x0E;       		// 5) make PF1-PF3-1 output                        
  GPIO_PORTF_AFSEL_R &= ~0x0E;        // 6) disable alt funct on PF1-PF3
  GPIO_PORTF_DEN_R |= 0x0E;       		// 7) enable digital I/O on PF1-PF3
}

void LED_Yellow_On(void)     {PF1 |= 0x02;}
void LED_Yellow_Off(void)    {PF1 &= ~0x02;}
void LED_Yellow_Toggle(void) {PF1 ^= 0x02;}

void LED_Green_On(void)     {PF2 |= 0x04;}
void LED_Green_Off(void)    {PF2 &= ~0x04;}
void LED_Green_Toggle(void) {PF2 ^= 0x04;}

void LED_Red_On(void)     {PF3 |= 0x08;}
void LED_Red_Off(void)    {PF3 &= ~0x08;}
void LED_Red_Toggle(void) {PF3 ^= 0x08;}
