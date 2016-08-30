/*
 * Author:  Justin Nguyen (jhn545)
 * Created: 8/29/2016
 * Description: Contains functions for outputting numbers in fixed decimal format.
 *              Also contains functions for plotting data.
 */
 
#include <stdint.h>
#include "../h/fixed.h"
#include "../h/ST7735.h" 

/* Input:
 * 		num is the decimal number to write to the buffer
 * 		out_buffer is the buffer we are writing to
 * 		NUM_OUTPUT_CHARS is the number of characters to write to the buffer
 * Output: none
 * Description: write the given decimal number to the buffer
 */
void outDecToBuffer(int num, char out_buffer[], int NUM_OUTPUT_CHARS){
	// Start writing at (NUM_OUTPUT_CHARS - 1) because we need room for the null terminator
	int write_index = NUM_OUTPUT_CHARS - 1;
	
	// Digits in decimal are (digit + 0x30) in ASCII. (Example: '3' --> 0x33).
	static int INT_TO_CHAR_OFFSET = 0x30;
	
	// Loop condition is (count > 1) because we need room for the decimal point
	for (int count = NUM_OUTPUT_CHARS; count > 1; --count) {
		out_buffer[write_index] = num % 10 + INT_TO_CHAR_OFFSET;
		num /= 10;
		write_index -= 1;
	}
}

/* Input:
 * 		out_buffer is the buffer we are writing to
 * 		DECIMAL_INDEX is where we are going to write the decimal point
 * Output: none
 * Description: 
 * 		Format the buffer to include the decimal point in the write location.
 *		Also remove any extra leading zeroes (Example: 000.23 --> 0.23, 0.23 --> 0.23)
 */
void formatBuffer(char out_buffer[], int DECIMAL_INDEX) {
	// Shift the characters in the buffer to make room for the decimal point.
	for (int i = 0; i < DECIMAL_INDEX; ++i) {
		out_buffer[i] = out_buffer[i + 1];
	}
	
	// Write in the decimal point.
	out_buffer[DECIMAL_INDEX] = '.';
	
	// Replace extraneous leading zeroes with ' '
	int first_valid_zero_index = DECIMAL_INDEX - 1;
	for (int i = 0; i < first_valid_zero_index ; ++i) {
		if (out_buffer[i] == '0') {
			out_buffer[i] = ' ';
		}
	}
}

/* Input: signed 32-bit integer part of the fixed point number
 * Output: none
 * Resolution: 0.001
 * Output Range: -9.999 to +9.999, *.***
 * Description: output the fixed point value to the LCD
 *              output *.*** to represent input outside the range -9999 to 9999
 *              always outputs 6 characters
 *
 * 	   Input	LCD Display
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

	// Write the chars to be displayed to a buffer. Append the terminating null zero.
	outDecToBuffer(num, out_buffer, NUM_OUTPUT_CHARS);
	out_buffer[NUM_OUTPUT_CHARS] = 0;
	
	// Format the buffer to include a decimal point and to remove extra leading zeroes.
	formatBuffer(out_buffer, DECIMAL_INDEX);
	
	// Write in the potential negative sign.
	if (num_was_negative) { out_buffer[0] = '-'; }
	
	// Write out the buffer.
	ST7735_OutString(out_buffer);
	ST7735_OutChar('\n');
}

/* Input: unsigned 32-bit integer part of the fixed point number
 * Output: none
 * Resolution: 1/256
 * Output Range: 0 to 999.99, *.***
 * Description: output the unsigned binary fixed point value to the LCD
 *              output *.*** to represent input outside the range 0 to 255,999
 *              always outputs 6 characters
 *
 * 	    Input     LCD Display
		    0	  "  0.00"
		    2	  "  0.01"
		   64	  "  0.25"
	      100	  "  0.39"
	      500	  "  1.95"
	      512	  "  2.00"
	     5000	  " 19.53"
	    30000	  "117.19"
	   255997	  "999.99"
       256000	  "***.**"
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
	int num_shifts = 0; int temp = 1;
	while (temp != ONE_OVER_RESOLUTION) {
		num_shifts += 1;
		temp = temp << 1;
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
	outDecToBuffer(scaled_num, out_buffer, NUM_OUTPUT_CHARS);
	
	// Format the buffer to include a decimal point and to remove extra leading zeroes.
	formatBuffer(out_buffer, DECIMAL_INDEX);
	
	// Output to the LCD
	ST7735_OutString(out_buffer);
	ST7735_OutChar('\n');
}

// This function will configure the plot and clear the drawing area
void ST7735_XYplotInit() {
	
}

// Actually plot the X-Y scatter plot
void ST7735_XYplot() {
 
}
