/* File Name:    fixed.h
 * Authors:      Justin Nguyen (jhn545)
 * Created:      8/29/2016
 * Last Revised: 9/1/2016
 * Description:  Contains functions for outputting in fixed decimal format.
 *               Also contains functions for plotting data.
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
 *
 * Class Info: EE 445L, Section 16630
 * Lab Number: 1
 * TA: Dylan Zika
 */
 
 #ifndef FIXED_H
 #define FIXED_H
 
#include <stdint.h>

/* Summary: Display the fixed point value to the LCD, resolution is 0.001
 *          Display *.*** to represent input outside the range -9999 to 9999.
 *          Displays values within the range -9.999 to +9.999, *.***
 *          Always outputs 6 characters.
 * Input:   num is the signed 32-bit integer part of the fixed point number.
 * Output:  none
 * Example:
 *   Input    LCD Display
     12345    " *.***"
      2345    " 2.345"
     -8100    "-8.100"
      -102    "-0.102"
        31    " 0.031"
    -12345    " *.***"
 */
void ST7735_sDecOut3(int32_t num);

/* Summary: Display the unsigned binary fixed point value to the LCD.
 *          The resolution is 1/256.
 *          Display ***.** to represent input outside the range 0 to 255,999
 *          Displays values within the range 0 to 999.99, ***.**
 *          Always outputs 6 characters.
 * Input:   num is the unsigned 32-bit integer part of the fixed point number.
 * Output:  none
 * Example:
 *   Input    LCD Display
         0    "  0.00"
         2    "  0.01"
        64    "  0.25"
       100    "  0.39"
       500    "  1.95"
       512    "  2.00"
      5000    " 19.53"
     30000    "117.19"
    255997    "999.99"
    256000    "***.**"
 */
void ST7735_uBinOut8(uint32_t num);

/* Summary: Specifies the X and Y axes for an x-y scatter plot.
 *          Draws the title and clears the plot area.
 *          Assumes minX < maxX, and miny < maxY.
 * Input:   title   ASCII string to label the plot, null-terminated
 *          minX    smallest X data value allowed, resolution = 0.001
 *          maxX    largest X data value allowed, resolution = 0.001
 *          minY    smallest Y data value allowed, resolution = 0.001
 *          maxY    largest Y data value allowed, resolution = 0.001
 * Output:  none
 */
void ST7735_XYplotInit(char *title, int32_t minX, int32_t maxX, int32_t minY, int32_t maxY);

/* Summary: Plots an array of (x,y) data.
 *          Assumes ST7735_XYplotInit has been previously called.
 *          Neglects any points outside the minX maxY minY maxY bounds.
 * Input:   num    number of data points in the two arrays
 *          bufX   array of 32-bit fixed-point data, resolution= 0.001
 *          bufY   array of 32-bit fixed-point data, resolution= 0.001
 * Output:  none
 */
void ST7735_XYplot(uint32_t num, int32_t bufX[], int32_t bufY[]);

#endif
