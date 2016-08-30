/*
 * Author:  Justin Nguyen
 * Created: 8/29/2016
 * Description: Contains functions for outputting numbers in fixed decimal format.
 *              Also contains functions for plotting data.
 */
 
#include <stdint.h>

// Input: signed 32-bit integer
// Output: the input represented as a decimal fixed point number
//         (outputs *.*** to represent input outside the range -9999 to 9999)
//	        (resolution is 0.001)
void ST7735_sDecOut3(int32_t num);

// Input: unsigned 32-bit integer
// Output: the input represented as a binary fixed point number
//         (outputs ***.** to represent input outside the range 0 to 255999)
//	        (resolution is 1/256)
void ST7735_uBinOut8(uint32_t num);

// This function will configure the plot and clear the drawing area
void ST7735_XYplotInit(void);

// Actually plot the X-Y scatter plot
void ST7735_XYplot(void); 
