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
	// Take care of invalid input and negative numbers.
	if (num < -9999   ||   num > 9999) {
		ST7735_OutString(" *.***\n");
		return;
	} else if (num < 0) {
		ST7735_OutChar('-');
		num *= -1;
	}
	
	// INT_TO_CHAR_OFFSET: Digits in decimal are (digit + 0x30) in ASCII (e.g. '3' --> 0x33).
	// NUM_OUTPUT_CHARS:   As specified by the function, the number of chars to output is always 6.
	// divisor:            The initial divisor will always be 1000.
	// out_buffer:         There will be an output buffer containing 6 chars.
	// count:              Count keeps track of how many chars have been written to the buffer.
	// 		               Start at one to save a spot for the decimal point.
	static int INT_TO_CHAR_OFFSET = 0x30;
	static int NUM_OUTPUT_CHARS = 6;
	int divisor = 1000;
	int out_buffer[NUM_OUTPUT_CHARS];
	int count = 1;

	// Write the chars to be displayed to a buffer.
	while (count < NUM_OUTPUT_CHARS) { // save one spot to write in the decimal point
		out_buffer[count] = num / divisor + INT_TO_CHAR_OFFSET);
		num %= divisor;
		divisor /= 10;
		NUM_OUTPUT_CHARS -= 1;
	}
	
	ST7735_OutChar('\n'); // output a new line
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
	int num_shifts = 
	
	// output the most significant digit first, then the decimal point
	ST7735_OutChar(num / divisor + INT_TO_CHAR_OFFSET);
	num %= divisor;
	divisor /= 10;
	ST7735_OutChar('.');
	
	// output the rest of the digits
	while (num > 0) {
			ST7735_OutChar(num / divisor + INT_TO_CHAR_OFFSET);
			num %= divisor;
			divisor /= 10;
	}
	
	ST7735_OutChar('\n'); // output a new line
}

// This function will configure the plot and clear the drawing area
void ST7735_XYplotInit() {
 
}

// Actually plot the X-Y scatter plot
void ST7735_XYplot() {
 
}
