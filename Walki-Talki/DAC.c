//DAC.c
//Driver for TLV5616
//Dung Nguyen
//Wally Guzman

#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "DAC.h"

//---TLV5616---//
/*
PIN        TM4C123  OTHER
1   DIN    PD3
2   SCLK   PD0
3   CS              GND
4   FS     PD1
5   AGND            GND
6   REFIN           +1.2V SHUNT DIODE (LM4041)
7   OUT             AMP (IN- TPA731)
8   VDD             +3.3V
*/
/*
The DAC produces a voltage range, AGND < OUT < REFIN*2
with 12-bit resolution.

Using the shunt diode, the output range is 0 V < OUT < 2.4 V.
With precision: .586 mV
*/

//------------DAC_Init------------
// Initialize SSI1 on PD0-3 for TLV5616
// Input: none
// Output: none
void DAC_Init(void){
	volatile int delay;
	SYSCTL_RCGCSSI_R |= 0x02;        //enable clock for SSI1
	SYSCTL_RCGCGPIO_R |= 0x08;       //enable clock for PortD
	delay = SYSCTL_RCGCGPIO_R;
	delay = SYSCTL_RCGCGPIO_R;
	delay = SYSCTL_RCGCGPIO_R;
	delay = SYSCTL_RCGCGPIO_R;
	
	//PORT D INIT
	GPIO_PORTD_AFSEL_R |= 0x0B;      //turn on alternate function for PD0,PD1,PD3
	GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & 0xFFFF0F00) + 0x00002022;//set pins to use SSI1
	GPIO_PORTD_DIR_R |= 0x0B;        //1 = out
	GPIO_PORTD_DEN_R |= 0x0B;
	
	//SSI1 INIT
	SSI1_CR1_R &= ~SSI_CR1_SSE;      //disable SSI1 & set as master
	SSI1_CR1_R &= ~SSI_CR1_MS;       //0 = master mode
	SSI1_CC_R &= ~0x0F;              //use system clock
	SSI1_CPSR_R = (SSI1_CPSR_R & ~SSI_CPSR_CPSDVSR_M) + 80;//80MHz/80 = 1MHz
	                                 //SSIClk (baud) = SysClk / (CPSDVSR * (1 + SCR))
	                                 //TLV5616 can use max 20MHz so 10MHz => CPSDVSR=8 and SCR=0
	//SCR=0 | SPH=0 | SPO=1 | Freescale SPI Mode | 16bit frame size
	SSI1_CR0_R &= ~(SSI_CR0_SCR_M | SSI_CR0_SPH | SSI_CR0_FRF_M | SSI_CR0_DSS_M);
	SSI1_CR0_R |= (SSI_CR0_SPO | SSI_CR0_FRF_MOTO | SSI_CR0_DSS_16);
	SSI1_CR1_R |= SSI_CR1_SSE;       //enable SSI1
}

//------------DAC_Out------------
// Output value to TLV5616
// Input: 12-bit value
// Output: none
void DAC_Out(int value){
	while((SSI1_SR_R&SSI_SR_TNF) == 0){};
	SSI1_DR_R = value & 0x0FFF; 	//only send 12 bits
}
