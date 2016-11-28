//ADC.c
//Dung Nguyen
//Wally Guzman

#include "tm4c123gh6pm.h"
#include "ADC.h"
#include <stdint.h>
#include "Settings.h"

#define ADC_BUFFER_SIZE	1024
#define ADC_DEFAULT			1024

// Circular buffer with median ADC value
int ADCBuffer[ADC_BUFFER_SIZE] = {ADC_DEFAULT}; 
int ADCPutIndex = 0;
int ADCGetIndex = 0;
int ADCvalue = ADC_DEFAULT;

//------------ADC_Init------------
// Initialize ADC on PB4 for MAX4466
// Input: none
// Output: none
void ADC_Init(int period){
	volatile int delay;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
	delay = SYSCTL_RCGCGPIO_R;      // 2) allow time for clock to stabilize
	delay = SYSCTL_RCGCGPIO_R;

	GPIO_PORTB_DIR_R &= ~0x10;  // 3.10) make PB4 input
	GPIO_PORTB_AFSEL_R |= 0x10; // 4.10) enable alternate function on PB4
	GPIO_PORTB_DEN_R &= ~0x10;  // 5.10) disable digital I/O on PB4
	GPIO_PORTB_AMSEL_R |= 0x10; // 6.10) enable analog functionality on PB4

	SYSCTL_RCGCADC_R |= 0x01;     // activate ADC0 
	SYSCTL_RCGCTIMER_R |= 0x04;   // activate timer2 
	delay = SYSCTL_RCGCTIMER_R;   // allow time to finish activating
	TIMER2_CTL_R = 0x00000000;    // disable timer0A during setup
	TIMER2_CTL_R |= 0x00000020;   // enable timer0A trigger to ADC
	TIMER2_CFG_R = 0;             // configure for 32-bit timer mode
	TIMER2_TAMR_R = 0x00000002;   // configure for periodic mode, default down-count settings
	TIMER2_TAPR_R = 0;            // prescale value for trigger
	TIMER2_TAILR_R = period-1;    // start value for trigger
	TIMER2_IMR_R = 0x00000000;    // disable all interrupts
	TIMER2_CTL_R |= 0x00000001;   // enable timer0A 32-b, periodic, no interrupts
	ADC0_PC_R = 0x01;         // configure for 125K samples/sec
	ADC0_SSPRI_R = 0x3210;    // sequencer 0 is highest, sequencer 3 is lowest
	ADC0_ACTSS_R &= ~0x08;    // disable sample sequencer 3
	ADC0_EMUX_R = (ADC0_EMUX_R&0xFFFF0FFF)+0x5000; // timer trigger event
	ADC0_SSMUX3_R = 10; //************
	ADC0_SSCTL3_R = 0x06;          // set flag and end                       
	ADC0_IM_R |= 0x08;             // enable SS3 interrupts
	
	//hardware averaging 3 => 2^3 times
	ADC0_SAC_R += 3;
	
	ADC0_ACTSS_R |= 0x08;          // enable sample sequencer 3
	NVIC_PRI4_R = (NVIC_PRI4_R&0xFFFF00FF)|0x00004000; //priority 2
	NVIC_EN0_R = 1 << 17;              // enable interrupt 17 in NVIC
}

//------------ADCSeq3_Handler------------
// Put new ADC value in buffer
// Input: none
// Output: none
void ADC0Seq3_Handler(void){
  ADC0_ISC_R = 0x08;          							// acknowledge ADC sequence 3 completion
	ADCBuffer[ADCPutIndex] = ADC0_SSFIFO3_R;  // 12-bit result
	ADCPutIndex++;
	if(ADCPutIndex >= ADC_BUFFER_SIZE)
		ADCPutIndex = 0;
}

//------------ADC_GetValue------------
// Get new ADC value from buffer
// Input: none
// Output: 12-bit ADC result
int ADC_GetValue(void){
	if(ADCGetIndex == ADCPutIndex)
		return BADVALUE;
	ADCGetIndex++;
	if(ADCGetIndex >= ADC_BUFFER_SIZE) {
		ADCGetIndex = 0;
		return ADCBuffer[ADC_BUFFER_SIZE - 1];
	}
	return ADCBuffer[ADCGetIndex - 1]; 
}

//------------ADC_PeekValue------------
// Get newest ADC value without modifying buffer
// Input: none
// Output: 12-bit ADC result
int ADC_PeekValue(void) {
	return ADCBuffer[ADCPutIndex];
}

//------------ADC_ResetGet------------
// Reset GetIndex to newest ADC value
// Input: none
// Output: none
void ADC_ResetGet(void) {
	ADCGetIndex = ADCPutIndex;
}
