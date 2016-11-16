// PWMtest.c
// Runs on TM4C123
// Use PWM0/PB6 and PWM1/PB7 to generate pulse-width modulated outputs.

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2015
   Program 6.8, section 6.3.2

   "Embedded Systems: Real-Time Operating Systems for ARM Cortex M Microcontrollers",
   ISBN: 978-1466468863, Jonathan Valvano, copyright (c) 2015
   Program 8.4, Section 8.3

 Copyright 2015 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */
 
#include "../inc/tm4c123gh6pm.h"
#include <stdint.h>
#include "PLL.h"
#include "Motor.h"
#include "Switch.h"
#include "Tach.h"
#include "Graphics.h"
#include "SysTick.h"
#include "Switch.h"
#include "ST7735.h"

void WaitForInterrupt(void);  // low power mode
void EnableInterrupts(void);

#define PWM_CLOCK_PERIOD 40000

uint16_t getDuty(uint32_t speed, uint16_t setSpeed, uint16_t currDuty)
{
	int16_t difference = setSpeed - (speed / 100);
	if (difference < 0 && (-difference > currDuty)) { return 2; } // minimum value
	currDuty += (3*difference)>>8;
	if (currDuty > PWM_CLOCK_PERIOD - 1) { return PWM_CLOCK_PERIOD - 1; }
	else return currDuty;
}

#define SIZE_ARRAY 64
static uint16_t speedArr[SIZE_ARRAY];	
static int speedi;
uint16_t avgSpeed(uint16_t inSpeed)
{
	if (speedi < SIZE_ARRAY) {speedArr[speedi++] = inSpeed;}
	else {speedArr[speedi = 0] = inSpeed;}
	uint32_t total = 0; 
	for (int i = 0; i < SIZE_ARRAY; i++)	{ total += speedArr[i]; }
	return (total >> 8);
}

void printSet(uint16_t setSpeed)
{
	ST7735_SetCursor(12,0);
	ST7735_OutString("Set:");
	ST7735_OutUDec(setSpeed);
}

int main(void){
  PLL_Init(Bus80MHz);               // bus clock at 80 MHz
  Tach_Init ();
//  Switch_Init();
	SysTick_Init();
	Switch_Init();
  ST7735_InitR(INITR_REDTAB);
  SweepingGraph_Init();
	EnableInterrupts();

//  PWM0A_Init(40000, 30000);         // initialize PWM0, 1000 Hz, 75% duty
  //PWM0B_Init(40000, 20000);         // initialize PWM0, 1000 Hz 50% dooty
  PWM0B_Init(PWM_CLOCK_PERIOD, 39999);         // initialize PWM0, 1000 Hz
//  PWM0_Duty(4000);    // 10%
//  PWM0_Duty(10000);   // 25%
//  PWM0_Duty(30000);   // 75%

//  PWM0_Init(4000, 2000);         // initialize PWM0, 10000 Hz, 50% duty
//  PWM0_Init(1000, 900);          // initialize PWM0, 40000 Hz, 90% duty
//  PWM0_Init(1000, 100);          // initialize PWM0, 40000 Hz, 10% duty
//  PWM0_Init(40, 20);             // initialize PWM0, 1 MHz, 50% duty

	int count = 0;
	uint32_t speed = 0;
	ST7735_SetCursor(0,0);
	ST7735_OutUDec(speed);
//	int delay = 0;
	uint16_t setDuty = 30000;
  while(1)
	{
		uint16_t setSpeed = getSetSpeed();
		if (setSpeed || count >= 3) 
		{
			printSet(setSpeed);
			uint16_t newSpeed = Tach_GetSpeed();
			speed = avgSpeed(newSpeed); 
			SweepingGraph_Print(speed);
			setDuty = getDuty(speed, setSpeed, setDuty);
			PWM0B_Duty(setDuty);
			SysTick_Wait10ms(1);
			count = 0;
		}
		else {count++;}

	}
}

