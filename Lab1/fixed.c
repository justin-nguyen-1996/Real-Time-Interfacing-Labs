/* File Name:    fixed.c
 * Authors:      Justin Nguyen (jhn545), Trevor Murdock (
 * Created:      8/29/2016
 * Last Revised: 9/6/2016
 * Description:  Contains functions for outputting in fixed decimal format.
 *               Also contains functions for plotting points.
 * 
 * Class Info: EE 445L, Section 16630
 * Lab Number: 1
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
 *
 */

#include <stdint.h>
#include "../h/fixed.h"
#include "../h/ST7735.h"

/* Summary: Write the given decimal number to the buffer.
 * Input:   num is the decimal number to write to the buffer
 *          outBuffer is the buffer we are writing to
 *          NUM_OUTPUT_CHARS is the number of characters to write to the buffer
 * Output:  none
 */
static void outDecToBuffer(int32_t num, char outBuffer[], 
        const uint8_t NUM_OUTPUT_CHARS, const uint8_t DECIMAL_INDEX) {

  // Digits in decimal are (digit + 0x30) in ASCII. 
  // (Example: '3' --> 0x33 in ASCII).
  const int8_t INT_TO_CHAR_OFFSET = 0x30;

  // Write the characters into the buffer.
  int8_t writeIndex;
  for (writeIndex = NUM_OUTPUT_CHARS - 1; 
       writeIndex > DECIMAL_INDEX; --writeIndex) 
  {
    outBuffer[writeIndex] = num % 10 + INT_TO_CHAR_OFFSET;
    num /= 10;
  }
  
  for (writeIndex = DECIMAL_INDEX - 1; writeIndex >= 0; --writeIndex) {
    outBuffer[writeIndex] = num % 10 + INT_TO_CHAR_OFFSET;
    num /= 10;
    if (num == 0) { return; } // avoids adding extra leading zeroes 
  }
}

/* Summary: Display the fixed point value to the LCD, resolution is 0.001
 *          Display *.*** to represent input outside the range -9999 to 9999.
 *          Displays values within the range -9.999 to +9.999, *.***
 *          Always outputs 6 characters.
 * Input:   num is the signed 32-bit integer part of the fixed point number.
 * Output:  none
 * Example:
 *   Input    LCD Display
 *   12345    " *.***"
 *    2345    " 2.345"
 *   -8100    "-8.100"
 *    -102    "-0.102"
 *      31    " 0.031"
 *  -12345    " *.***"
 */
void ST7735_sDecOut3(int32_t num) {
  // Take care of invalid input
  uint8_t numWasNegative = 0;
  if (num < -9999   ||   num > 9999) {
    ST7735_OutString(" *.***");
    return;
  } 
  
  // Change these if you want to display a different number of characters.
  // Or if you want to put the fixed decimal point at some other index.
  const uint8_t NUM_OUTPUT_CHARS = 6;
  const uint8_t DECIMAL_INDEX = 2;

  // Initialize the output buffer to contain these values by default.
  // Using spaces makes it easier to remove extra leading zeroes.
  char outBuffer[NUM_OUTPUT_CHARS + 1]; uint8_t i;
  for (i = 0; i < NUM_OUTPUT_CHARS; ++i) {
    outBuffer[i] = ' ';
  }
  outBuffer[DECIMAL_INDEX] = '.';
  outBuffer[i] = 0; // null termination

  // Take care of negative numbers
  if (num < 0) {
    num *= -1;
    outBuffer[0] = '-';
  }

  // Write the chars to a buffer and display to the LCD.
  outDecToBuffer(num, outBuffer, NUM_OUTPUT_CHARS, DECIMAL_INDEX);
  ST7735_OutString(outBuffer);
}

/* Summary: Display the unsigned binary fixed point value to the LCD.
 *          The resolution is 1/256.
 *          Display ***.** to represent input outside the range 0 to 255,999
 *          Displays values within the range 0 to 999.99, ***.**
 *          Always outputs 6 characters.
 * Input:   num is the unsigned 32-bit integer part of the fixed point number.
 * Output:  none
 * Example:
 *   Input    LCD Display
 *       0    "  0.00"
 *       2    "  0.01"
 *      64    "  0.25"
 *     100    "  0.39"
 *     500    "  1.95"
 *     512    "  2.00"
 *    5000    " 19.53"
 *   30000    "117.19"
 *  255997    "999.99"
 *  256000    "***.**"
 */
void ST7735_uBinOut8(uint32_t num) {
  // Take care of invalid input
  if (num > 255999) {
    ST7735_OutString("***.**");
    return;
  }

  // Change these if you want to display a different number of characters.
  // Or if you want to put the fixed decimal point at some other index.
  const uint32_t ONE_OVER_RESOLUTION = 256;
  const uint8_t NUM_OUTPUT_CHARS = 6;
  const uint8_t DECIMAL_INDEX = 3;
  const uint8_t NUM_DECIMAL_PLACES = NUM_OUTPUT_CHARS - DECIMAL_INDEX - 1;

  // Initialize the output buffer to contain these values by default.
  // Using spaces makes it easier to remove extra leading zeroes.
  char outBuffer[NUM_OUTPUT_CHARS + 1]; uint8_t i;
  for (i = 0; i < NUM_OUTPUT_CHARS; ++i) {
    outBuffer[i] = ' ';
  }
  outBuffer[DECIMAL_INDEX] = '.';
  outBuffer[i] = 0; // null termination

  // Find the number of times to shift num to make scaledNum
  // Num * Resolution should equal (Num >> numShifts)
  uint8_t numShifts = 0; uint32_t findResolution = 1;
  while (findResolution != ONE_OVER_RESOLUTION) {
    numShifts += 1;
    findResolution = findResolution << 1;
  }

  // Find the scaling factor (dependent on how many decimal places are desired)
  // Loop condition is (i < NUM_DECIMAL_PLACES + 1) to account for rounding
  uint32_t scalingFactor = 1;
  for (uint8_t i = 0; i < NUM_DECIMAL_PLACES + 1; ++i) {
    scalingFactor *= 10;
  }

  // By multiplying by an exra factor of 10, 
  //   the digit that determines rounding is no longer truncated.
  // If we need to round, simply add one to the original value.
  int32_t scaledNum = num * scalingFactor >> numShifts;
  if (scaledNum % 10 >= 5) { scaledNum = (scaledNum / 10) + 1; }
  else { scaledNum /= 10; }

  // Write the chars to be displayed to a buffer. 
  outDecToBuffer(scaledNum, outBuffer, NUM_OUTPUT_CHARS, DECIMAL_INDEX);

  // Output to the LCD
  ST7735_OutString(outBuffer);
}

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
int32_t MinX, MaxX, MinY, MaxY;
void ST7735_XYplotInit(char *title, int32_t minX, int32_t maxX, 
                       int32_t minY, int32_t maxY) {
    
  // Set the X and Y axes.
  MinX = minX; MaxX = maxX;
  MinY = minY; MaxY = maxY;

  // Clear the plot area and draw the title
  ST7735_FillScreen(0);
  ST7735_OutString(title);
}

/* Summary: Plots an array of (x,y) data.
 *          Assumes ST7735_XYplotInit has been previously called.
 *          Neglects any points outside the minX maxY minY maxY bounds.
 * Input:   num    number of data points in the two arrays
 *          bufX   array of 32-bit fixed-point data, resolution= 0.001
 *          bufY   array of 32-bit fixed-point data, resolution= 0.001
 * Output:  none
 */
void ST7735_XYplot(uint32_t num, int32_t bufX[], int32_t bufY[]) {
  for (int32_t i = 0; i < num; ++i) {
    if (bufX[i] < MinX   ||   bufX[i] > MaxX   ||   
        bufY[i] < MinY   ||   bufY[i] > MaxY) { continue; } 
    else {
      int32_t x = (MaxX - bufX[i]) * 128 / (MaxX - MinX);
      int32_t y = (MaxY - bufY[i]) * 128 / (MaxY - MinY) + 32;

      ST7735_DrawPixel(x,   y,   ST7735_CYAN);
      ST7735_DrawPixel(x+1, y,   ST7735_CYAN);
      ST7735_DrawPixel(x,   y+1, ST7735_CYAN);
      ST7735_DrawPixel(x+1, y+1, ST7735_CYAN);
    }
  }
}
