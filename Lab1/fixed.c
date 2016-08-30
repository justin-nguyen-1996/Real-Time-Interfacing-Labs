/*
 * Author:  Justin Nguyen (jhn545)
 * Created: 8/29/2016
 * Description: Contains functions for outputting numbers in fixed decimal format.
 *              Also contains functions for plotting data.
 */
 
#include <stdint.h>
#include "../h/fixed.h"
#include "../h/ST7735.h" 

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
	// Take care of invalid input
	int was_negative = 0;
	if (num < -9999   ||   num > 9999) {
		ST7735_OutString(" *.***\n");
		return;
	} else if (num < 0) {
		num *= -1;
		was_negative = 1;
	}
	
	// INT_TO_CHAR_OFFSET: Digits in decimal are (digit + 0x30) in ASCII (e.g. '3' --> 0x33).
	// NUM_OUTPUT_CHARS:   As specified by the function, the number of chars to output is always 6.
	// out_buffer:         There will be an output buffer containing 7 chars (6 values to output, 1 null character)
	// count:              Count keeps track of how many chars have been written to the buffer.
	// 		               Decrement count until greater than one to save a spot for the decimal point.
	static int INT_TO_CHAR_OFFSET = 0x30;
	static int NUM_OUTPUT_CHARS = 6;
	char out_buffer[NUM_OUTPUT_CHARS + 1];
	int count = NUM_OUTPUT_CHARS;
	int write_index = NUM_OUTPUT_CHARS - 1;
	
	// Append the null zero.
	out_buffer[NUM_OUTPUT_CHARS + 1] = 0;

	// Write the chars to be displayed to a buffer.
	// Write the LSB into the buffer but make sure to save two spots for the decimal point and negative sign
	// Write the LSB into the buffer until only one spot left for the decimal point.
	while (count > 2) {
		out_buffer[write_index] = num % 10 + INT_TO_CHAR_OFFSET;
		num /= 10;
		count -= 1; write_index -= 1;
	}
//	out_buffer[5] = 18 % 10 + INT_TO_CHAR_OFFSET;
//	out_buffer[4] = '3';
//	out_buffer[3] = '2';
//	out_buffer[2] = '1';
//	out_buffer[1] = '1';
//	out_buffer[0] = '1';
//	ST7735_OutString(out_buffer);
//	ST7735_OutChar(out_buffer[5]);
//	ST7735_OutChar(out_buffer[4]);
//	ST7735_OutChar(out_buffer[3]);
//	ST7735_OutChar(out_buffer[2]);
	
	// Shift the characters in the buffer to make room for the decimal point.
	int DECIMAL_INDEX = 2;
	for (int i = 0; i < DECIMAL_INDEX; ++i) {
		out_buffer[i] = out_buffer[i + 1];
	}
	
	// Write the decimal point and potential negative sign in.
	out_buffer[DECIMAL_INDEX] = '.';
	if (was_negative) { out_buffer[0] = '-'; }
	else { out_buffer[0] = num; }
	
	// Replace extraneous leading zeroes with ' '
	int first_valid_zero_index = DECIMAL_INDEX - 1;
	for (int i = 0; i < first_valid_zero_index ; ++i) {
		if (out_buffer[i] == '0') {
			out_buffer[i] = ' ';
		}
	}
	
	// Write out the buffer.
	ST7735_OutString(out_buffer);
//	char out_buffer2[6] = {3 + 0x30,'b','c','d','e','f'};
//	ST7735_OutString(out_buffer2);
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
	if (num > 255999) {
		ST7735_OutString("***.**");
	} else if (num == 0) {
		ST7735_OutString("0.00");
	}
	
	// digits in decimal are (digit + 0x30) in ASCII (e.g. '3' --> 0x33)
	// the initial divisor will always be 1000
	static int INT_TO_CHAR_OFFSET = 0x30;
//	int num_shifts = 
	
	// output the most significant digit first, then the decimal point
//	ST7735_OutChar(num / divisor + INT_TO_CHAR_OFFSET);
//	num %= divisor;
//	divisor /= 10;
//	ST7735_OutChar('.');
	
	// output the rest of the digits
	while (num > 0) {
//			ST7735_OutChar(num / divisor + INT_TO_CHAR_OFFSET);
//			num %= divisor;
//			divisor /= 10;
	}
	
	ST7735_OutChar('\n'); // output a new line
}

// This function will configure the plot and clear the drawing area
void ST7735_XYplotInit() {
 
}

// Actually plot the X-Y scatter plot
void ST7735_XYplot() {
 
}
