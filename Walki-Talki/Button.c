//Button.c
//Dung Nguyen
//Wally Guzman

#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "Button.h"
#include "Settings.h"
#include "HeartBeat.h"

#define PE0       (*((volatile uint32_t *) 0x40024004))
#define PE1       (*((volatile uint32_t *) 0x40024008))
#define PE2       (*((volatile uint32_t *) 0x40024010))
#define PE3      	(*((volatile uint32_t *) 0x40024020))
#define PF0       (*((volatile uint32_t *) 0x40025004))
#define PF4      	(*((volatile uint32_t *) 0x40025020))

// Stores button state as follows
// PF4 PF0 PE3 PE2 PE1 PE0
// B 	 A   U   R   D   L

uint32_t prevState = 0;			// Button state since last update
uint32_t currState = 0;			// Current button state
uint32_t checked = 1;				// Read/unread data

//------------Button_Init------------
// Initialize PE0-3 and PF0, PF4 for switch input
// Input: none
// Output: none	
void Button_Init(void){
	volatile int delay;
	SYSCTL_RCGCGPIO_R |= 0x10;       	//enable port E 
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTE_AMSEL_R &= ~0x0F;     	//disable analog
	GPIO_PORTE_PCTL_R &= 0xFFFF0000; 	//set as digital
	GPIO_PORTE_DIR_R &= ~0x0F;       	//input = 0, set PE3-0 as input;
	GPIO_PORTE_AFSEL_R &= ~0x0F;     	//disable alternate function
	GPIO_PORTE_DEN_R |= 0x0F;        	//enable digital
	
	SYSCTL_RCGCGPIO_R |= 0x20;     		// 1) activate Port F
  delay = SYSCTL_RCGCGPIO_R;    
  GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;// 2a) unlock GPIO Port F Commit Register
  GPIO_PORTF_CR_R |= 0x11;        	// 2b) enable commit for PF4-PF0     
  GPIO_PORTF_AMSEL_R &= ~0x11;   		// 3) disable analog functionality on PF4-PF0     
  GPIO_PORTF_PCTL_R &= 0xFFF0FFF0;	// 4) configure PF0 & PF4 as GPIO
  GPIO_PORTF_DIR_R &= ~0x11;       	// 5) make PF0 and PF4, 0 = input                       
  GPIO_PORTF_AFSEL_R &= ~0x011;     // 6) disable alt funct on PF0 and PF4
	
  if (LAUNCHPAD)
		GPIO_PORTF_PUR_R = 0x11;       	// enable weak pull-up on PF0 and PF4 for Launchpad
	
  GPIO_PORTF_DEN_R |= 0x11;       	// 7) enable digital I/O on PF0 and PF4

	prevState = 0;										// Initialize button states
	currState = 0;
}

//------------Button_Update------------
// Update internal switch state
// Input: none
// Output: none	
void Button_Update(void){
	int temp = (~GPIO_PORTF_DATA_R) & 0x11;
	temp = ((temp << 4) & 0x10) | ((temp << 1) & 0x20);
	prevState = currState;
	currState = temp | ((~GPIO_PORTE_DATA_R) & 0x0F);	// Create bit vector of PF4, PF0, PE3-0
	checked = 0;
	HeartBeat();	// Blink PF3 at switch update rate
}

//------------Button_Pressed------------
// Return switches pressed since last update
// Input: none
// Output: Bit vector, 1 is pressed
uint32_t Button_Pressed(void){
	checked = 1;
	return currState & (~prevState);
}

//------------Button_Unpressed------------
// Return switches not pressed since last update
// Input: none
// Output: Bit vector, 1 is not pressed
uint32_t Button_Unpressed(void){
	return (~currState) & prevState;
}
 
//------------Button_NewState------------
// Return flag for new switch state
// Input: none
// Output: 1 if new state
uint32_t Button_NewState(void) {
	return !checked;
}

//------------Button_Transmit------------
// Return state of transmit button, A = PF0
// Input: none
// Output: 1 if transmit button pressed
int Button_Transmit(void) {
	return currState & A;
}

//------------Button_Display------------
// Return state of display button, B = PF4
// Input: none
// Output: 1 if display button pressed
int Button_Display(void) {
	return currState & B;
}
