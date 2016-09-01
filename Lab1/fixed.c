/* File Name:    fixed.c
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

#include <stdint.h>
#include "../h/fixed.h"
#include "../h/ST7735.h"

/* Summary: Write the given decimal number to the buffer.
 * Input:   num is the decimal number to write to the buffer
 *          outBuffer is the buffer we are writing to
 *          numOutputChars is the number of characters to write to the buffer
 * Output:  none
 */
void outDecToBuffer(int num, char outBuffer[],
                    int numOutputChars, int decimalIndex) {

  // Digits in decimal are (digit + 0x30) in ASCII. (Example: '3' --> 0x33).
  const static int INT_TO_CHAR_OFFSET = 0x30;

  // Write the characters into the buffer.
  for (int writeIndex = numOutputChars - 1; writeIndex >= 0; --writeIndex) {
    if (writeIndex == decimalIndex) { outBuffer[writeIndex] = '.'; continue; }
    outBuffer[writeIndex] = num % 10 + INT_TO_CHAR_OFFSET;
    num /= 10;
  }

  // Append the null-terminating zero.
  outBuffer[numOutputChars] = 0;
}

/* Summary: Replace any extra leading zeroes with ' '
 *          Example: 000.23 -->   0.23
 * Input:   outBuffer is the buffer we are writing to
 *          decimalIndex is where we are going to write the decimal point
 * Output:  none
 */
void removeExtraLeadingZeroes(char outBuffer[], int decimalIndex) {
  // If the first character is not zero, there will not be any leading zeroes.
  if (outBuffer[0] != '0') { return; }

  int firstValidZeroIndex = decimalIndex - 1;
  for (int i = 0; i < firstValidZeroIndex ; ++i) {
    if (outBuffer[i] == '0') {
      outBuffer[i] = ' ';
    }
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
     12345    " *.***"
      2345    " 2.345"
     -8100    "-8.100"
      -102    "-0.102"
        31    " 0.031"
    -12345    " *.***"
 */
void ST7735_sDecOut3(int32_t num) {
  // Take care of invalid input and negative numbers
  int numWasNegative = 0;
  if (num < -9999   ||   num > 9999) {
    ST7735_OutString(" *.***\n");
    return;
  } else if (num < 0) {
    num *= -1;
    numWasNegative = 1;
  }

  // Change these if you want to display a different number of characters.
  // Or if you want to put the fixed decimal point at some other index.
  int numOutputChars = 6;
  int decimalIndex = 2;

  // Initialize the output buffer to contain these values by default.
  // Using spaces makes it easier to remove extra leading zeroes.
  char outBuffer[numOutputChars + 1]; int i;
  for (i = 0; i < numOutputChars; ++i) {
    outBuffer[i] = ' ';
  }
  outBuffer[decimalIndex] = '.'
  outBuffer[i] = 0; // null termination

  // Write the chars to be displayed to a buffer.
  outDecToBuffer(num, outBuffer, numOutputChars, decimalIndex);

  // Remove extra leading zeroes. Example: 000.34 --> 0.34
  removeExtraLeadingZeroes(outBuffer, decimalIndex);

  // Write in the potential negative sign.
  if (numWasNegative) { outBuffer[0] = '-'; }

  // Display to the LCD
  ST7735_OutString(outBuffer);
  ST7735_OutChar('\n');
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
void ST7735_uBinOut8(uint32_t num) {
  // Take care of invalid input
  if (num > 255999) {
    ST7735_OutString("***.**\n");
    return;
  }

  // Change these if you want to display a different number of characters.
  // Or if you want to put the fixed decimal point at some other index.
  int oneOverResolution = 256;
  int numOutputChars = 6;
  int decimalIndex = 3;
  int numDecimalPlaces = numOutputChars - decimalIndex - 1;

  // Initialize the output buffer to contain these values by default.
  // Using spaces makes it easier to remove extra leading zeroes.
  char outBuffer[numOutputChars + 1]; int i;
  for (i = 0; i < numOutputChars; ++i) {
    outBuffer[i] = ' ';
  }
  outBuffer[decimalIndex] = '.'
  outBuffer[i] = 0; // null termination

  // Find the number of times to shift num to make scaledNum
  // Num * Resolution should equal (Num >> numShifts)
  int numShifts = 0; int findResolution = 1;
  while (findResolution != oneOverResolution) {
    numShifts += 1;
    findResolution = findResolution << 1;
  }

  // Find the scaling factor (dependent on how many decimal places are desired)
  // Loop condition is (i < numDecimalPlaces + 1) to account for rounding
  int scalingFactor = 1;
  for (int i = 0; i < numDecimalPlaces + 1; ++i) {
    scalingFactor *= 10;
  }

  // By multiplying by an exra factor of 10, 
  //   the digit that determines rounding is no longer truncated.
  // If we need to round, simply add one to the original value.
  int scaledNum = num * scalingFactor >> numShifts;
  if (scaledNum % 10 >= 5) { scaledNum = (scaledNum / 10) + 1; }
  else { scaledNum /= 10; }

  // Write the chars to be displayed to a buffer. 
  // Append the terminating null zero.
  outDecToBuffer(scaledNum, outBuffer, numOutputChars, decimalIndex);

  // Format the buffer to include a decimal point.
  // Also remove extra leading zeroes.
  removeExtraLeadingZeroes(outBuffer, decimalIndex);

  // Output to the LCD
  ST7735_OutString(outBuffer);
  ST7735_OutChar('\n');
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
int MinX, MaxX, MinY, MaxY;
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
  for (int i = 0; i < num; ++i) {
    if (bufX[i] < MinX   ||   bufX[i] > MaxX   ||   
        bufY[i] < MinY   ||   bufY[i] > MaxY) { continue; } 
    else {
      int x = (MaxX - bufX[i]) * 128 / (MaxX - MinX);
      int y = (MaxY - bufY[i]) * 128 / (MaxY - MinY) + 32;

      ST7735_DrawPixel(x,   y,   ST7735_CYAN);
      ST7735_DrawPixel(x+1, y,   ST7735_CYAN);
      ST7735_DrawPixel(x,   y+1, ST7735_CYAN);
      ST7735_DrawPixel(x+1, y+1, ST7735_CYAN);
    }
  }
}
