// HeartBeat.c
// February 10, 2016
// Dung Nguyen
// Wally Guzman

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "HeartBeat.h"
#include "LED.h"

#define PF3       (*((volatile uint32_t *)0x40025020))

//------------HeartBeat------------
// Toggle PF3 as a system heartbeat
// Input: none
// Output: none	
void HeartBeat(void) {
	PF3 ^= 0x08;
}
