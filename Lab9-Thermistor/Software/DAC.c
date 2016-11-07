/* File Name:    DAC.c
 * Authors:      Justin Nguyen (jhn545), Trevor Murdock (ttm436)
 * Created:      10/1/2016
 * Last Revised: 10/4/2016
 * Description:  Contains functions for interfacing with the DAC.
 * 
 * Class Info: EE 445L, Section 16630
 * Lab Number: 5
 * TA: Dylan Zika
 *
 * Hardware Configurations:
 * ST7735R LCD:
 *     Backlight    (pin 10) connected to +3.3 V
 *     MISO         (pin 9)  unconnected
 *     SCK          (pin 8)  connected to PA2 (SSI0Clk)
 *     MOSI         (pin 7)  connected to PA5 (SSI0Tx)
 *     TFT_CS       (pin 6)  connected to PA3 (SSI0Fss)
 *     CARD_CS      (pin 5)  unconnected
 *     Data/Command (pin 4)  connected to PA6 (GPIO)
 *     RESET        (pin 3)  connected to PA7 (GPIO)
 *     VCC          (pin 2)  connected to +3.3 V
 *     Gnd          (pin 1)  connected to ground
 * TLV5616:
 *     DIN          (pin 1)  connected to PD3 (SSI3Tx)
 *     SCLK         (pin 2)  connected to PD0 (SSI3Clk)
 *     CS           (pin 3)  connected to GND
 *     FS           (pin 4)  connected to PD1 (SSI3Fss)
 *     AGND         (pin 5)  connected to GND
 *     REFIN        (pin 6)  connected to +1.5 V
 *     OUT          (pin 7)  connected to IN- of the amp (TPA731D)
 *     VDD          (pin 8)  connected to +3.3 V
 * TPA731D:
 *     SHUTDOWN     (pin 1)  unconnected
 *     BYPASS       (pin 2)  connected to positive terminal of CapB (3.3 uF), which is connected to ground
 *     IN+          (pin 3)  connected to positive terminal of CapB (3.3 uF), which is connected to ground
 *     IN-          (pin 4)  connected to RI (1k ohm) and RF (2.2k ohm)
 *     VO+          (pin 5)  connected to RF (2.2k ohm) and the speaker
 *     VDD          (pin 6)  connected to +5V
 *     GND          (pin 7)  connected to GND
 *     VO-          (pin 8)  connected to the speaker
 * LM4041:
 *     (looking at the flat edge on the bottom)
 *     FB           (pin 1)  connected to R1 (10k ohm) and R2 (220 ohm)
 *     +terminal    (pin 2)  connected to RS (20k ohm), R1 (10k ohm), and REFIN (1.5 V) of the TLV5616
 *     -terminal    (pin 3)  connected to R2 (220 ohm) and GND
 */

#include <stdint.h>
#include "DAC.h"
#include "../inc/tm4c123gh6pm.h"

void DAC_Init(void) {
  SYSCTL_RCGCGPIO_R |= 0x02;        // activate Port B
  while((SYSCTL_PRGPIO_R&0x02)==0){};
  SYSCTL_RCGCSSI_R |= 0x04;         // activate SSI2
  GPIO_PORTB_AMSEL_R &= ~0xFF;      // disable analog functionality on PB7-0
  GPIO_PORTB_AFSEL_R |= 0xB0;       // alternate function on PB 7,5,4
  GPIO_PORTB_DEN_R |= 0xB0;         // enable digital I/O on PB 7,5,4
  GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R & 0x0F00FFFF) + 0x20220000; // 4) PB 7,5,4 = DAC,SSIO
  
  SSI2_CR1_R = 0x00000000;        // disable SSI, master mode
  SSI2_CPSR_R = 0x04;             // 20 MHz SSIClk 
  SSI2_CR0_R |= 0x04F;            // DSS = 16-bit data, SPO = 1, SPH = 0
  SSI2_CR1_R |= 0x00000002;       // enable SSI
}

/* Summary: Send data to DAC, uses SSI3
 * Input:   voltage output (0 to 4095)
 * Output:  none
 */
void DAC_Out(uint16_t code){   
  //while((SSI3_SR_R&0x00000002)==0){};// SSI Transmit FIFO Not Full
  while ((SSI_SR_TNF & SSI2_SR_R) == 0) {}
  SSI2_DR_R = code & 0x0FFF;                  // data out
  //while((SSI2_SR_R&0x00000004)==0){};// SSI Receive FIFO Not Empty
}

const unsigned short SinewaveDAC[32] = {  
  1024,1122,1215,1302,1378,1440,1486,1514,1524,1514,1486,
  1440,1378,1302,1215,1122,1024,926,833,746,670,608,
  562,534,524,534,562,608,670,746,833,926
}; 

// ***************** TIMER1_Init ****************
// Activate TIMER1 interrupts to run user task periodically
// Inputs:  task is a pointer to a user function
//          period in units (1/clockfreq)
// Outputs: none
void Timer1_Init(uint32_t period) {
  SYSCTL_RCGCTIMER_R |= 0x02;   // 0) activate TIMER1
  TIMER1_CTL_R = 0x00000000;    // 1) disable TIMER1A during setup
  TIMER1_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
  TIMER1_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
  TIMER1_TAILR_R = period-1;    // 4) reload value
  TIMER1_TAPR_R = 0;            // 5) bus clock resolution
  TIMER1_ICR_R = 0x00000001;    // 6) clear TIMER1A timeout flag
  TIMER1_IMR_R = 0x00000001;    // 7) arm timeout interrupt
  NVIC_PRI5_R = (NVIC_PRI5_R&0xFFFF00FF)|0x00008000; // 8) priority 4
  NVIC_EN0_R = 1<<21;           // 9) enable IRQ 21 in NVIC
  TIMER1_CTL_R = 0x00000001;    // 10) enable TIMER1A	
}

static uint16_t sineIndex = 0;
void Timer1A_Handler(void) {
  TIMER0_ICR_R = TIMER_ICR_TATOCINT;// acknowledge timer0A timeout
	uint16_t value = SinewaveDAC[sineIndex] << 2 ;
	sineIndex = (sineIndex+1) & 0x1F;
	DAC_Out(value);
}

