// fixed.c
// Implements fixed.h
// Runs on LM4F120/TM4C123
// Mid-level drivers for the ST7735 160x128 LCD for printing to the 
//		ST7735 display
//    16-bit color, 128 wide by 160 high LCD
// Trevor Murdock - ttm436
// 8/30/2016

#include <stdint.h>
#include "ST7735.h"
#include "Graphics.h"

typedef struct vector {
  int32_t x; 
  int32_t y; 
} Vector;

/* Summary: Recursive helper function for ST7735_Line().
            This function is not called by the client.
 * Input:   (x1,y1) is the start point
 *          (x2,y2) is the end point
 * Output: none
 */
static void ST7735_LineHelper(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
  
	Vector pixel1, pixel2;
	pixel1.x = x1; pixel1.y = y1;
	pixel2.x = x2; pixel2.y = y2;
	
	Vector range = {pixel2.x - pixel1.x, pixel2.y - pixel1.y};
	Vector absRange = { (range.x < 0) ? -range.x : range.x,
                      (range.y < 0) ? -range.y : range.y 
  };
	// break case
	if (absRange.x <= 1 && absRange.y <= 1) {
    // Draw pixel one (un-scale values)
	  ST7735_DrawPixel(pixel1.x>>3, pixel1.y>>3, ST7735_BLUE);
    // Draw pixel two = (un-scale values)
	  ST7735_DrawPixel(pixel2.x>>3, pixel2.y>>3, ST7735_BLUE);

  }	
  
  //call recursively
  else { 
	  ST7735_LineHelper(x1, y1, x1 + (range.x>>1), y1 + (range.y>>1)); 
	  ST7735_LineHelper(x1 + (range.x>>1), y1 + (range.y>>1), x2, y2); 
	}
}

/* Summary: Draws one line on the ST7735 color LCD
 * Input:   (x1,y1) is the start point
 *          (x2,y2) is the end point
 *          color is 16-bits and be produced by ST7735_Color565() 
 * Output: none
 */
void ST7735_Line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
  // scale values x8 to hold precision when right shifting
	ST7735_LineHelper(x1<<3, y1<<3, x2<<3, y2<<3);
}

//-----------------------ConvertDec-----------------------
// Output a 32-bit number in unsigned decimal format
// Input: 32-bit number to be transferred
// Output: none
// Variable format 1-10 digits with no space before or after
static char converted[12];
static uint32_t convertedIndex;

void clearConvertedIndex ( void ) {
	convertedIndex = 0;
}

void convertDec(uint32_t n){
// This function uses recursion to convert decimal number
//   of unspecified length as an ASCII string
  if(n >= 10){
    convertDec(n/10);
    n = n%10;
  }
  converted[convertedIndex] = (n+'0'); /* n is between 0 and 9 */
  if(convertedIndex<11)convertedIndex++;
	
}


#define MIN_sDecOut3 -10000
#define MAX_sDecOut3 10000
void ST7735_sDecOut3(int32_t n){
	
	char sOut[7];
  //exeeding bounds is an error	
	if (n >= MAX_sDecOut3 || n <= MIN_sDecOut3) { 
		sOut[0] = ' ';
		sOut[1] = '*';
		sOut[2] = '.';
		sOut[3] = '*';
		sOut[4] = '*';
		sOut[5] = '*';
	}
	else {
		if (n < 0) {
			sOut[0] = '-';
			convertDec( -n );
		}
		else {
			sOut[0] = ' ';
			convertDec( n );
		}
		int localConvertedIndex = 0;
		sOut[1] = (convertedIndex >= 4) ? converted[localConvertedIndex++] : '0';
		sOut[2] = '.';
		sOut[3] = (convertedIndex >= 3) ? converted[localConvertedIndex++] : '0';
		sOut[4] = (convertedIndex >= 2) ? converted[localConvertedIndex++] : '0';
		sOut[5] = (convertedIndex >= 1) ? converted[localConvertedIndex++] : '0';
			
	}
	sOut[6] = 0;
	ST7735_OutString(sOut);	
	clearConvertedIndex();
}

#define MAX_uBinOut8 256000
void ST7735_uBinOut8(uint32_t n){
	char sOut[7];
	//exeeding bound is an error
	if (n >= MAX_uBinOut8) {
		sOut[0] = '*';
		sOut[1] = '*';
		sOut[2] = '*';
		sOut[3] = '.';
		sOut[4] = '*';
		sOut[5] = '*';
	}
	else {
		int localConvertedIndex = 0;
		convertDec( n >> 8 ); // remove fractional
		sOut[0] = (convertedIndex >= 3) ? converted[localConvertedIndex++] : ' ';
		sOut[1] = (convertedIndex >= 2) ? converted[localConvertedIndex++] : ' ';
		sOut[2] = (convertedIndex >= 1) ? converted[localConvertedIndex++] : '0';
		sOut[3] = '.';
		clearConvertedIndex();
		localConvertedIndex = 0;
		convertDec( (100 * (n & 0xFF)) >> 8 ); //only fractional part
		sOut[4] = (convertedIndex >= 2) ? converted[localConvertedIndex++] : '0';
		sOut[5] = (convertedIndex >= 1) ? converted[localConvertedIndex++] : '0';
	}
	sOut[6] = 0;
	ST7735_OutString(sOut);	
	clearConvertedIndex();
}



#define MINIMUM_X_PIXEL 0
#define MAXIMUM_X_PIXEL 128
#define MINIMUM_Y_PIXEL 32
#define MAXIMUM_Y_PIXEL 160
static int32_t rangeX, rangeY;
static int32_t setMinX, setMaxX, setMinY, setMaxY;

void ST7735_XYplotInit(char *title, int32_t minX, int32_t maxX, int32_t minY, int32_t maxY){
//	ST7735_InitR(INITR_REDTAB);
	ST7735_FillRect(0, 0, 128, 160, ST7735_Color565(0,0,0)); // light grey
	ST7735_SetCursor(0,0);
	ST7735_OutString(title);
	setMinX = minX;
	setMaxX = maxX;
	setMinY = minY;
	setMaxY = maxY;
	rangeX = maxX - minX;
	rangeY = maxY - minY;
	ST7735_FillRect(MINIMUM_X_PIXEL, MINIMUM_Y_PIXEL, MAXIMUM_X_PIXEL, MAXIMUM_Y_PIXEL, ST7735_Color565(228,228,228)); // light grey
//ST7735_PlotClear(32,127);
}


void ST7735_XYplot(uint32_t num, int32_t bufX[], int32_t bufY[]) {
  for (int k = 0; k < num ; k++) {
		int32_t X = bufX[k];
		int32_t Y = bufY[k];

		if(Y<setMinY) { Y=setMinY; }
		if(Y>setMaxY) { Y=setMaxY; }
		if(X<setMinX) { X=setMinX; }
		if(X>setMaxX) { X=setMaxX; }
    
		// X goes from 0 to 127
		// j goes from 159 to 32
		// x=Xmax maps to i=127
		// x=Xmin maps to i=0
		// y=Ymax maps to j=32
		// y=Ymin maps to j=159
    
		int32_t i, j;
		i = ((MAXIMUM_X_PIXEL - MINIMUM_X_PIXEL - 1) * (X - setMinX)) / rangeX;
		j = ((MAXIMUM_Y_PIXEL - MINIMUM_Y_PIXEL - 1) * (setMaxY - Y)) / rangeY + MINIMUM_Y_PIXEL;
		
		// subtract 1 on maximums because 2 pixel plot width
		if(i<MINIMUM_X_PIXEL) i = MINIMUM_X_PIXEL;
		if(i>MAXIMUM_X_PIXEL - 1) i = MAXIMUM_X_PIXEL - 1;
		if(j<MINIMUM_Y_PIXEL) j = MINIMUM_Y_PIXEL;
		if(j>MAXIMUM_Y_PIXEL - 1) j = MAXIMUM_Y_PIXEL - 1;
		
		ST7735_DrawPixel(i,   j,   ST7735_BLUE);
		ST7735_DrawPixel(i+1, j,   ST7735_BLUE);
		ST7735_DrawPixel(i,   j+1, ST7735_BLUE);
		ST7735_DrawPixel(i+1, j+1, ST7735_BLUE);
	}
}

void ST7735_Xcount_Yplot(uint32_t num, uint32_t bufY[]){
  for (int k = 0; k < num ; k++) {
		uint32_t Y = bufY[k];

		if(Y<setMinY) Y=setMinY;
		if(Y>setMaxY) Y=setMaxY;
    
		// X goes from 0 to 127
		// j goes from 159 to 32
		// x=Xmax maps to i=127
		// x=Xmin maps to i=0
		// y=Ymax maps to j=32
		// y=Ymin maps to j=159
    
		int32_t i, j;
		i = ((MAXIMUM_X_PIXEL - MINIMUM_X_PIXEL - 1) * k) / num;
		j = ((MAXIMUM_Y_PIXEL - MINIMUM_Y_PIXEL - 1) * (setMaxY - Y)) / rangeY + MINIMUM_Y_PIXEL;
		
		// subtract 1 on maximums because 2 pixel plot width
		if(i<MINIMUM_X_PIXEL) i = MINIMUM_X_PIXEL;
		if(i>MAXIMUM_X_PIXEL - 1) i = MAXIMUM_X_PIXEL - 1;
		if(j<MINIMUM_Y_PIXEL) j = MINIMUM_Y_PIXEL;
		if(j>MAXIMUM_Y_PIXEL - 1) j = MAXIMUM_Y_PIXEL - 1;
		
//		ST7735_DrawPixel(i,   j,   ST7735_BLUE);
//		ST7735_DrawPixel(i+1, j,   ST7735_BLUE);
//		ST7735_DrawPixel(i,   j+1, ST7735_BLUE);
//		ST7735_DrawPixel(i+1, j+1, ST7735_BLUE);
		
		ST7735_Line(i, j, i, 159);
		
	}
}

void ST7735_Test() {
  ST7735_OutString((char*) "Trevor murCOCK\n");
}

void drawShip(void);
void drawAsteroid(void);
void drawLaser(void);
void drawMissile(void);
