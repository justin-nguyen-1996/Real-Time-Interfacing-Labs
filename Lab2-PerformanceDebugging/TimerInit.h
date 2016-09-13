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

/* Summary: Initialize Timer0A
 * Input:   Frequency in Hz
 * Output:  None
 */
void Timer0_Init(uint32_t freq);

/* Summary: Initialize Timer1A
 * Input: Timer reload value (in clock ticks)
 * Output: None
 */
void Timer1_Init(uint32_t reloadVal);

/* Summary: Initialize Timer2A
 * Input:   Frequency in Hz
 * Output:  None
 */
void Timer2_Init(uint32_t freq);
