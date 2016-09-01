/* File Name:    fixed.c
 * Authors:      Justin Nguyen (jhn545)
 * Created:      8/29/2016
 * Last Revised: 9/1/2016
 * Description:  Contains functions for outputting numbers in fixed decimal format.
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
 *          out_buffer is the buffer we are writing to
 *          NUM_OUTPUT_CHARS is the number of characters to write to the buffer
 * Output:  none
 */
void outDecToBuffer(int num, char out_buffer[], int NUM_OUTPUT_CHARS, int DECIMAL_INDEX){
  // Digits in decimal are (digit + 0x30) in ASCII. (Example: '3' --> 0x33).
  static int INT_TO_CHAR_OFFSET = 0x30;
  
  // Write the characters into the buffer.
  for (int write_index = NUM_OUTPUT_CHARS - 1; write_index >= 0; --write_index) {
    if (write_index == DECIMAL_INDEX) { out_buffer[write_index] = '.'; continue; }
    out_buffer[write_index] = num % 10 + INT_TO_CHAR_OFFSET;
    num /= 10;
  }
  
  // Append the null-terminating zero.
  out_buffer[NUM_OUTPUT_CHARS] = 0;
}

/* Summary: Replace any extra leading zeroes with ' ' 
 *          Example: 000.23 -->   0.23
 * Input:   out_buffer is the buffer we are writing to
 *          DECIMAL_INDEX is where we are going to write the decimal point
 * Output:  none
 */
void removeExtraLeadingZeroes(char out_buffer[], int DECIMAL_INDEX) {
  // If the first character is not zero, there will not be any leading zeroes.
  if (out_buffer[0] != '0') { return; }
  
  // Only remove invalid leading zeroes, so walk down the buffer until first_valid_zero_index.
  int first_valid_zero_index = DECIMAL_INDEX - 1;
  for (int i = 0; i < first_valid_zero_index ; ++i) {
    if (out_buffer[i] == '0') {
      out_buffer[i] = ' ';
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
  int num_was_negative = 0;
  if (num < -9999   ||   num > 9999) {
    ST7735_OutString(" *.***\n");
    return;
  } else if (num < 0) {
    num *= -1;
    num_was_negative = 1;
  }
  
  // NUM_OUTPUT_CHARS:   As specified by the function, the number of chars to output is always 6.
  // DECIMAL_INDEX:      Simply indicates where the decimal point will be written
  // out_buffer:         Buffer the output --> call ST7735_OutString() once instead of ST7735_OutChar() multiple times
  const int NUM_OUTPUT_CHARS = 6;
  const int DECIMAL_INDEX = 2;
  char out_buffer[NUM_OUTPUT_CHARS + 1];

  // Write the chars to be displayed to a buffer.
  outDecToBuffer(num, out_buffer, NUM_OUTPUT_CHARS, DECIMAL_INDEX);
  
  // Remove extra leading zeroes. Example: 000.34 --> 0.34
  removeExtraLeadingZeroes(out_buffer, DECIMAL_INDEX);
  
  // Write in the potential negative sign.
  if (num_was_negative) { out_buffer[0] = '-'; }
  
  // Display to the LCD
  ST7735_OutString(out_buffer);
  ST7735_OutChar('\n');
}

/* Summary: Display the unsigned binary fixed point value to the LCD, resolution is 1/256
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
  
  // NUM_OUTPUT_CHARS:   As specified by the function, the number of chars to output is always 6.
  // DECIMAL_INDEX:      Simply indicates where the decimal point will be written
  // out_buffer:         Buffer the output --> call ST7735_OutString() once instead of ST7735_OutChar() multiple times
  const int ONE_OVER_RESOLUTION = 256;
  const int NUM_OUTPUT_CHARS = 6;
  const int DECIMAL_INDEX = 3;
  const int NUM_DECIMAL_PLACES = NUM_OUTPUT_CHARS - DECIMAL_INDEX - 1;
  char out_buffer[NUM_OUTPUT_CHARS + 1];
  
  // Find the number of times to shift num to make scaled_num
  // Num * Resolution should equal (Num >> num_shifts)
  int num_shifts = 0; int find_resolution = 1;
  while (find_resolution != ONE_OVER_RESOLUTION) {
    num_shifts += 1;
    find_resolution = find_resolution << 1;
  }
  
  // Find the scaling factor (dependent on how many decimal places are desired)
  // Loop condition is (i < NUM_DECIMAL_PLACES + 1) to account for rounding
  int scaling_factor = 1;
  for (int i = 0; i < NUM_DECIMAL_PLACES + 1; ++i) {
    scaling_factor *= 10;
  }
  
  // By multiplying by an exra factor of 10, the digit that determines rounding is no longer truncated.
  // If we need to round, simply add one to the original value
  int scaled_num = num * scaling_factor >> num_shifts;
  if (scaled_num % 10 >= 5) { scaled_num = (scaled_num / 10) + 1; } 
  else { scaled_num /= 10; }
  
  // Write the chars to be displayed to a buffer. Append the terminating null zero.
  outDecToBuffer(scaled_num, out_buffer, NUM_OUTPUT_CHARS, DECIMAL_INDEX);
  
  // Format the buffer to include a decimal point and to remove extra leading zeroes.
  removeExtraLeadingZeroes(out_buffer, DECIMAL_INDEX);
  
  // Output to the LCD
  ST7735_OutString(out_buffer);
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
int g_minX, g_maxX, g_minY, g_maxY;
void ST7735_XYplotInit(char *title, int32_t minX, int32_t maxX, int32_t minY, int32_t maxY) {
  // Set the X and Y axes.
  g_minX = minX; g_maxX = maxX;
  g_minY = minY; g_maxY = maxY;
  
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
    if (bufX[i] < g_minX   ||   bufX[i] > g_maxX   ||   bufY[i] < g_minY   ||   bufY[i] > g_maxY) {
      continue;
    } else {      
      int x = (g_maxX - bufX[i]) * 128 / (g_maxX - g_minX);
      int y = (g_maxY - bufY[i]) * 128 / (g_maxY - g_minY) + 32;
      
      ST7735_DrawPixel(x,   y,   ST7735_CYAN);
      ST7735_DrawPixel(x+1, y,   ST7735_CYAN);
      ST7735_DrawPixel(x,   y+1, ST7735_CYAN);
      ST7735_DrawPixel(x+1, y+1, ST7735_CYAN);
    }
  }
}
