#include <stdint.h>
#include <stdbool.h>
#include "../inc/tm4c123gh6pm.h"
#include "keypad.h"
#include "FIFO.h"
#include "ST7735.h"

#define ORIGIN_KEYPAD 2

/* Summary: Initialize Port B with rising edge triggered interrupts
 * Input:   None
 * Output:  None
 */
void PortB_Init(void) 
{
  SYSCTL_RCGCGPIO_R |= 0x02;        // 1) activate port B
  while((SYSCTL_PRGPIO_R&0x02)==0){};   // 2) allow time for clock to stabilize
  GPIO_PORTB_AMSEL_R &= ~0xFF;      // 3) disable analog functionality on PB7-0
  GPIO_PORTB_PCTL_R &= ~0xFFFFFFFF; // 4) GPIO
  GPIO_PORTB_DIR_R &= ~0xFF;         // 5) make PB7-0 in
  GPIO_PORTB_AFSEL_R &= ~0xFF;      // 6) regular port function
  GPIO_PORTB_DEN_R |= 0xFF;         // 7) enable digital I/O on PB7-0
  GPIO_PORTB_IS_R &= ~0xFF;         // 8) edge-sensitive
  GPIO_PORTB_IBE_R |= 0xFF;        // 9) not both edges
//  GPIO_PORTB_IEV_R |= 0xFF;         // 10) rising edge event
  GPIO_PORTB_ICR_R = 0xFF;          // 11) clear flags
//  GPIO_PORTB_IM_R |= 0xFF;          // 12) arm interrupts on PB7-0 
//  NVIC_PRI0_R = (NVIC_PRI0_R&0xFFFF00FF)|0x0000A000; // 13) priority 5
//  NVIC_EN0_R = 0x00000002;          // 13) enable interrupt 1 in NVIC
}

/* Summary: Initialize Port D with rising edge triggered interrupts
 * Input:   None
 * Output:  None
 */
void PortD_Init(void) 
{
  SYSCTL_RCGCGPIO_R |= 0x08;        // 1) activate port D
  while((SYSCTL_PRGPIO_R&0x08)==0){};   // allow time for clock to stabilize
  
  GPIO_PORTD_AMSEL_R &= ~0xCF;      // 3) disable analog functionality on PD7-0
  GPIO_PORTD_PCTL_R &= ~0xFFFFFFFF; // 4) GPIO
  GPIO_PORTD_DIR_R &= ~0xCF;         // 5) make PD7-0 in
  GPIO_PORTD_AFSEL_R &= ~0xCF;      // 6) regular port function
  GPIO_PORTD_LOCK_R = 0x4C4F434B ;  // 7) unlock Port D
  GPIO_PORTD_CR_R |= 0xCF;          // 8) allow changes to PD7-0 (except 4,5)
  GPIO_PORTD_DEN_R |= 0xCF;         // 7) enable digital I/O on PD7-0
  GPIO_PORTD_IS_R &= ~0xCF;         // 8) edge-sensitive
  GPIO_PORTD_IBE_R |= 0xCF;         // 9)  both edges
//  GPIO_PORTD_IEV_R |= 0xCF;         // 10) rising edge event
  GPIO_PORTD_ICR_R = 0xCF;          // 11) clear flags
//  GPIO_PORTD_IM_R |= 0xCF;          // 12) arm interrupts on PD7-0 
//  NVIC_PRI0_R = (NVIC_PRI0_R&0x00FFFFFF)|0xA0000000; // 13) priority 5
//  NVIC_EN0_R = 0x00000008;          // 13) enable interrupt 3 in NVIC
}

void PortA_Init(void)
{
	SYSCTL_RCGCGPIO_R |= 0x01; // activate port A
  while((SYSCTL_PRGPIO_R&0x01)==0){}; // allow time for clock to start
  GPIO_PORTA_AMSEL_R &= ~0x10;          // disable analog functionality on PA4
                                        // configure PA3,6,7 as GPIO
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFF0FFFF)+0x00000000;
  GPIO_PORTA_DIR_R &= ~0x10;             // make PA4 in
  GPIO_PORTA_AFSEL_R &= ~0x10;          // disable alt funct on PA4
  GPIO_PORTA_DEN_R |= 0x10;             // enable digital I/O on PA4
	GPIO_PORTA_IS_R &= ~0x10;
	GPIO_PORTA_IBE_R |= 0x10;
	GPIO_PORTA_ICR_R = 0x10;
//	GPIO_PORTA_IM_R |= 0x10;
//	NVIC_PRI0_R = (NVIC_PRI0_R&0xFFFFFFFF1F)+0x000000A0; //priority 5
//	NVIC_EN0_R = 1<<16;
}

//Arming functions for debouncing
void Timer2Arm(void)
{
	SYSCTL_RCGCTIMER_R |= 0x04;   // 0) activate timer2
  TIMER2_CTL_R = 0x00000000;    // 1) disable TIMER2A during setup
  TIMER2_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
  TIMER2_TAMR_R = 0x0000001;    // 3) 1-SHOT mode
  TIMER2_TAILR_R = 160000;      // 4) 10ms reload value
  TIMER2_TAPR_R = 0;            // 5) bus clock resolution
  TIMER2_ICR_R = 0x00000001;    // 6) clear TIMER2A timeout flag
  TIMER2_IMR_R = 0x00000001;    // 7) arm timeout interrupt
  NVIC_PRI5_R = (NVIC_PRI5_R&0x00FFFFFF)|0x80000000; // 8) priority 4
// interrupts enabled in the main program after all devices initialized
// vector number 35, interrupt number 19
  NVIC_EN0_R = 1<<23;           // 9) enable IRQ 19 in NVIC
  TIMER2_CTL_R = 0x00000001;    // 10) enable TIMER0A
}

void GPIOArm_PortA(void)
{
	GPIO_PORTA_ICR_R = 0x10;
	GPIO_PORTA_IM_R |= 0x10;
	NVIC_PRI0_R = (NVIC_PRI0_R&0xFFFFFFF1F)|0x000000A0; //priority 5
	NVIC_EN0_R = 1;
}
void GPIOArm_PortB(void)
{
  GPIO_PORTB_ICR_R = 0xFF;          // 11) clear flags
  GPIO_PORTB_IM_R |= 0xFF;          // 12) arm interrupts on PB7-0 
  NVIC_PRI0_R = (NVIC_PRI0_R&0xFFFF00FF)|0x0000A000; // 13) priority 5
//  NVIC_PRI0_R = (NVIC_PRI0_R&0x00FFFFFF)|0xA0000000; // 13) priority 5
  NVIC_EN0_R = 0x00000002;          // 13) enable interrupt 1 in NVIC
}
void GPIOArm_PortD(void)
{
  GPIO_PORTD_ICR_R = 0xCF;          // 11) clear flags
  GPIO_PORTD_IM_R |= 0xCF;          // 12) arm interrupts on PD7-0 
  NVIC_PRI0_R = (NVIC_PRI0_R&0x00FFFFFF)|0xA0000000; // 13) priority 5
  NVIC_EN0_R = 0x00000008;          // 13) enable interrupt 3 in NVIC
}

/* Summary: Initialize ports B and D for a total of 16 pins.
 *          Interrupts will be enabled on rising edges.
 *          Inputs are positive logic.
 * Input:   None
 * Output:  None
 */
void Keypad_Init(void)
{
	PortA_Init();
  PortB_Init();
  PortD_Init();
  Timer2Arm();
}

uint32_t LastA, LastB, LastD;
int TimerCount = 0;
int ButtonCount = 0;
void Timer2A_Handler(void)
{
  TIMER2_IMR_R = 0;
  TimerCount++;
	LastA = GPIO_PORTA_DATA_R & 0x10;
  LastB = GPIO_PORTB_DATA_R;
  LastD = GPIO_PORTD_DATA_R & 0xCF;
	GPIOArm_PortA();
  GPIOArm_PortB();
  GPIOArm_PortD();
}

void GPIOPortA_Handler(void)
{
	GPIO_PORTA_IM_R &= ~0x10;
	if(LastA)
	{
		rxDataType sig = { ORIGIN_KEYPAD, 65536, 1 };
		bool putResult = RxFifo_Put(sig);
		if (!putResult) { ST7735_OutString("FIFO FULL"); }
	}
	Timer2Arm();
}

void GPIOPortB_Handler(void)
{
  GPIO_PORTB_IM_R &= ~0xFF;
  if(LastB)
  {
		rxDataType sig = { ORIGIN_KEYPAD, LastB, 1 };
		bool putResult = RxFifo_Put(sig);
		if (!putResult) { ST7735_OutString("FIFO FULL"); }
  } 
  Timer2Arm();
}

void GPIOPortD_Handler(void)
{
  GPIO_PORTD_IM_R &= ~0xCF;
	if(LastD)
	{
		rxDataType sig = { ORIGIN_KEYPAD, LastD<<8, 1 };
		bool putResult = RxFifo_Put(sig);
		if (!putResult) { ST7735_OutString("FIFO FULL"); }
	}
  Timer2Arm();
}

void keypad_main(void)
{
  ST7735_InitR(INITR_REDTAB);
	ST7735_SetRotation(2);
  Keypad_Init();
	RxFifo_Init();
  while(1)
  {
		rxDataType sig;
		bool getResult = RxFifo_Get(&sig);
		if (getResult)
		{
			Output_Clear();
			ST7735_SetCursor(0,0);
			ST7735_OutUDec(sig.id);
			
		}
  //  ST7735_SetCursor(0,0);
  //  ST7735_OutUDec(ButtonCount);
  //  ST7735_SetCursor(0,1);
  //  ST7735_OutUDec(TimerCount);
  }
}
