// Switch.c
// Runs on LM4F120/TM4C123
// Provide functions that initialize a GPIO as an input pin and
// allow reading of two negative logic switches on PF0 and PF4
// and an external switch on PA5.
// Use bit-banded I/O.
// Daniel and Jonathan Valvano
// September 12, 2013

/* This example accompanies the book
   "Embedded Systems: Introduction to ARM Cortex M Microcontrollers",
   ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2015
   Section 4.2    Program 4.2

  "Embedded Systems: Real Time Interfacing to ARM Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2015
   Example 2.3, Program 2.9, Figure 2.36

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

// negative logic switches connected to PF0 and PF4 on the Launchpad
// red LED connected to PF1 on the Launchpad
// blue LED connected to PF2 on the Launchpad
// green LED connected to PF3 on the Launchpad
// NOTE: The NMI (non-maskable interrupt) is on PF0.  That means that
// the Alternate Function Select, Pull-Up Resistor, Pull-Down Resistor,
// and Digital Enable are all locked for PF0 until a value of 0x4C4F434B
// is written to the Port F GPIO Lock Register.  After Port F is
// unlocked, bit 0 of the Port F GPIO Commit Register must be set to
// allow access to PF0's control registers.  On the LM4F120, the other
// bits of the Port F GPIO Commit Register are hard-wired to 1, meaning
// that the rest of Port F can always be freely re-configured at any
// time.  Requiring this procedure makes it unlikely to accidentally
// re-configure the JTAG and NMI pins as GPIO, which can lock the
// debugger out of the processor and make it permanently unable to be
// debugged or re-programmed.
#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "SysTick.h"
#include "Switch.h"
#define PF0                     (*((volatile uint32_t *)0x40025004))
#define PF4                     (*((volatile uint32_t *)0x40025040))

void Switch_Init(void){        
  SYSCTL_RCGC2_R |= 0x00000020; // (a) activate clock for port F
  while((SYSCTL_PRGPIO_R & 0x20)!=0x20){}; // wait to finish activating     
//  GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;// 2a) unlock GPIO Port F Commit Register
//  GPIO_PORTF_CR_R = 0x1F;        // 2b) enable commit for PF4-PF0     
  GPIO_PORTF_DIR_R &= ~0x11;    // (c) make PF4 in (built-in button)
  GPIO_PORTF_AFSEL_R &= ~0x11;  //     disable alt funct on PF4
  GPIO_PORTF_DEN_R |= 0x11;     //     enable digital I/O on PF4
  GPIO_PORTF_AMSEL_R &= ~0x11;  //    disable analog functionality on PF4
  GPIO_PORTF_PUR_R |= 0x11;     //     enable weak pull-up on PF4
    
  GPIO_PORTF_IS_R &= ~0x11;     // (d) PF4 is edge-sensitive
  GPIO_PORTF_IBE_R &= ~0x11;    //     PF4 is not both edges
  GPIO_PORTF_IEV_R &= ~0x11;    //     PF4 falling edge event
  GPIO_PORTF_ICR_R = 0x11;      // (e) clear flag4
  GPIO_PORTF_IM_R |= 0x11;      // (f) arm interrupt on PF4
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; // (g) priority 5
  NVIC_EN0_R = 0x40000000;      // (h) enable interrupt 30 in NVIC
}
 
static uint16_t setSpeed = 50;

void GPIOPortF_Handler(void)
{
	GPIO_PORTF_ICR_R = 0x10;
 if ((PF4 & 0x10) == 0 && setSpeed > 5) 
{ setSpeed -= 5; } 
	else //if ((PF0 & 0x01) == 0 && setSpeed < 50) 
{ setSpeed +=5; }
	int i = 0;
	while (i<1000){i++;}
}

void Switch2_Init(void){        
  SYSCTL_RCGC2_R |= 0x00000010; // (a) activate clock for port F
  while((SYSCTL_PRGPIO_R & 0x10)!=0x10){}; // wait to finish activating     
  GPIO_PORTE_DIR_R &= ~0x1;    // (c) make PF4 in (built-in button)
  GPIO_PORTE_AFSEL_R &= ~0x1;  //     disable alt funct on PF4
  GPIO_PORTE_DEN_R |= 0x1;     //     enable digital I/O on PF4
  GPIO_PORTE_AMSEL_R &= ~0x1;  //    disable analog functionality on PF4
    
  GPIO_PORTE_IS_R &= ~0x1;     // (d) PF4 is edge-sensitive
  GPIO_PORTE_IBE_R &= ~0x1;    //     PF4 is not both edges
  GPIO_PORTE_IEV_R &= ~0x1;    //     PF4 falling edge event
  GPIO_PORTE_ICR_R = 0x1;      // (e) clear flag4
  GPIO_PORTE_IM_R |= 0x1;      // (f) arm interrupt on PF4
  NVIC_EN0_R = 1 << 4;      // (h) enable interrupt 30 in NVIC
}
 
void GPIOPortE_Handler(void)
{
	GPIO_PORTE_ICR_R = 0x10;
  setSpeed += 5;
	int i = 0;
	while (i<1000){i++;}
}


uint16_t getSetSpeed(void)
{
	return setSpeed;
}
