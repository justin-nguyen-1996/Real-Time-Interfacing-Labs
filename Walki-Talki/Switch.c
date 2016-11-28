//Switch.c
//Dung Nguyen
//Wally Guzman

/*Initializes Port E and allow to read switch states*/
//Switch.c utilizes polling

#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "switch.h"
#include "timer1.h"

#define NUM_BUTTONS 4

uint8_t state[NUM_BUTTONS];
uint16_t timePress[NUM_BUTTONS];
uint16_t timeLastPress[NUM_BUTTONS];

//calibrate these values for smoother operation
const uint32_t doublePressTime = 400;
const uint32_t longPressTime = 750;
const uint32_t doubleTimeWindow = 500;

void Switch_Update(void);

void Switch_Init(void){
	volatile int delay;
	SYSCTL_RCGCGPIO_R |= 0x10;       //enable port e
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTE_DIR_R &= ~0x0F;       //input = 0, set PE3-0 as input;
	GPIO_PORTE_AMSEL_R &= ~0x0F;     //disable analog
	GPIO_PORTE_PCTL_R &= 0xFFFF0000; //set as digital
	GPIO_PORTE_AFSEL_R &= ~0x0F;     //disable alternate function
	GPIO_PORTE_DEN_R |= 0x0F;        //enable digital

	//init timer interrupts
	Timer1_Init(&Switch_Update,80000); //SYSCLK / SAMPLE_RATE = 80MHz/1KHz = 80000 cycles
}

//updates currentState
//timer1 isr will call this function
void Switch_Update(void){
	uint32_t input = (~GPIO_PORTE_DATA_R) & 0x0F;//change to positive logic
	for(int k=0; k<NUM_BUTTONS; k++){
		timeLastPress[k]++;
		if(input&(1<<k)){//if pressed
			timePress[k]++;
			switch(state[k]){
				case noPress:
					if(timePress[k]>doubleTimeWindow)
						state[k] = shortPress;
					else
						state[k] = doublePress;
					timePress[k] = 0;
					break;
				case shortPress:
					if(timePress[k]>longPressTime)
						state[k] = longPress;
					break;
				case longPress:
					break;
				case doublePress:
					if(timePress[k]>doublePressTime)
						state[k] = longPress;
					break;
			}
		}
		else{
			switch(state[k]){
				case noPress:
					break;
				case shortPress:
				case longPress:
				case doublePress:
					state[k] = noPress;
					timeLastPress[k] = timePress[k];
					break;
			}
		}
	}
}

int Switch_State(int k){
	return state[k];
}
