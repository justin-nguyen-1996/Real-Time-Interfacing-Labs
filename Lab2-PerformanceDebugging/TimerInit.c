/* File Name:    ADCTestMain.c
 * Authors:      Justin Nguyen (jhn545), Trevor Murdock (ttm436)
 *               (with much sample code belonging to Dr. Valvano)
 * Created:      9/13/2016
 * Last Revised: 9/13/2016
 * Description:  Contains functions for initializing timers.
 * 
 * Class Info: EE 445L, Section 16630
 * Lab Number: 2
 * TA: Dylan Zika
 *
 * Hardware Configurations:
 * ST7735R LCD:
 *     Backlight    (pin 10) connected to +3.3 V
 *     MISO         (pin 9) unconnected
 *     SCK          (pin 8) connected to PA2 (SSI0Clk)
 *     MOSI         (pin 7) connected to PA5 (SSI0Tx)
 *     TFT_CS       (pin 6) connected to PA3 (SSI0Fss)
 *     CARD_CS      (pin 5) unconnected
 *     Data/Command (pin 4) connected to PA6 (GPIO)
 *     RESET        (pin 3) connected to PA7 (GPIO)
 *     VCC          (pin 2) connected to +3.3 V
 *     Gnd          (pin 1) connected to ground
 */


#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

void DisableInterrupts(void);
void EnableInterrupts(void);

static const uint32_t BUS_80MHZ = 80000000; // clock speed is 80 MHz

/* Summary: Initialize Timer0A
 * Input:   Frequency in Hz
 * Output:  None
 */
void Timer0_Init(uint32_t freq){
  volatile uint32_t delay;
  DisableInterrupts();
  SYSCTL_RCGCTIMER_R |= 0x01;        // activate timer0
  delay = SYSCTL_RCGCTIMER_R;        // allow time to finish activating
  TIMER0_CTL_R &= ~TIMER_CTL_TAEN;   // disable timer0A during setup
  TIMER0_CFG_R = 0;                  // configure for 32-bit timer mode
  TIMER0_TAMR_R = TIMER_TAMR_TAMR_PERIOD; // configure for periodic mode
  TIMER0_TAILR_R = BUS_80MHZ / freq; // start value for XXX Hz interrupts
  TIMER0_IMR_R |= TIMER_IMR_TATOIM;  // enable timeout (rollover) interrupt
  TIMER0_ICR_R = TIMER_ICR_TATOCINT; // clear timer0A timeout flag
  TIMER0_CTL_R |= TIMER_CTL_TAEN;  // enable timer0A 32-b, periodic, interrupts
  NVIC_PRI4_R = (NVIC_PRI4_R&0x00FFFFFF)|0x40000000; // priority 2
  NVIC_EN0_R = 1<<19;                // enable interrupt 19 in NVIC
}

/* Summary: Initialize Timer1A
 * Input: Timer reload value (in clock ticks)
 * Output: None
 */
void Timer1_Init(uint32_t reloadVal){
  volatile uint32_t delay;
  SYSCTL_RCGCTIMER_R |= 0x02;   // 0) activate TIMER1
  delay = SYSCTL_RCGCTIMER_R;   // allow time to finish activating
  //PeriodicTask = task;        // user function
  TIMER1_CTL_R = 0x00000000;    // 1) disable TIMER1A during setup
  TIMER1_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
  TIMER1_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
  TIMER1_TAILR_R = reloadVal;   // 4) reload value
  TIMER1_TAPR_R = 0;            // 5) bus clock resolution
  TIMER1_ICR_R = 0x00000001;    // 6) clear TIMER1A timeout flag
  //TIMER1_IMR_R = 0x00000001;  // 7) arm timeout interrupt
  NVIC_PRI5_R = (NVIC_PRI5_R&0xFFFF00FF)|0x00008000; // 8) priority 4
  //interrupts enabled in the main program after all devices initialized
  //vector number 37, interrupt number 21
  //NVIC_EN0_R = 1<<21;         // 9) enable IRQ 21 in NVIC
  TIMER1_CTL_R = 0x00000001;    // 10) enable TIMER1A
}

/* Summary: Initialize Timer2A
 * Input:   Frequency in Hz
 * Output:  None
 */
void Timer2_Init(uint32_t freq){
  SYSCTL_RCGCTIMER_R |= 0x04;   // 0) activate timer2
  TIMER2_CTL_R = 0x00000000;    // 1) disable timer2A during setup
  TIMER2_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
  TIMER2_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
  TIMER2_TAILR_R = freq;    // 4) reload value
  TIMER2_TAPR_R = 0;            // 5) bus clock resolution
  TIMER2_ICR_R = 0x00000001;    // 6) clear timer2A timeout flag
  TIMER2_IMR_R = 0x00000001;    // 7) arm timeout interrupt
  NVIC_PRI5_R = (NVIC_PRI5_R&0x00FFFFFF)|0x20000000; // 8) priority 1
// interrupts enabled in the main program after all devices initialized
// vector number 39, interrupt number 23
  NVIC_EN0_R = 1<<23;           // 9) enable IRQ 23 in NVIC
  TIMER2_CTL_R = 0x00000001;    // 10) enable timer2A
}
