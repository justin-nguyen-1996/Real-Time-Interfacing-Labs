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
 
#ifndef __musich
#define __musich

#include <stdint.h>

typedef struct {
	uint16_t freqency;
	uint16_t length;
	uint8_t volume;
} Note;

#endif
