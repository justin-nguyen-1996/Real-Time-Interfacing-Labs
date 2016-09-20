#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "ST7735.h"
#include "draw.h"

#define CLOCK_FACE_CENTER_X 63
#define CLOCK_FACE_CENTER_Y 96

// Initialization will initialize the ST7735 display and
// set up a coordinate plot for future use
void draw_Init(void)
{
  ST7735_InitR(INITR_REDTAB);
}

void _Line_h(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{

	typedef struct vector { int32_t x, y; } Vector;
	Vector pixel1, pixel2;
	pixel1.x = x1;
	pixel1.y = y1;

	pixel2.x = x2;
	pixel2.y = y2;
	
	Vector range = {pixel2.x - pixel1.x, pixel2.y - pixel1.y};
	Vector absv_range = { (range.x < 0) ? -range.x : range.x,
			      (range.y < 0) ? -range.y : range.y };
	
	if (absv_range.x <= 1 && absv_range.y <= 1)
	{
	    ST7735_DrawPixel(pixel1.x>>3,   pixel1.y>>3,   color);
	    ST7735_DrawPixel(pixel2.x>>3,   pixel2.y>>3,   color);
	    return;
	}

	else 
	{ 
	    _Line_h(x1, y1, x1 + (range.x>>1), y1 + (range.y>>1), color); 
	    _Line_h(x1 + (range.x>>1), y1 + (range.y>>1), x2, y2, color); 
	}
}
void _Line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
	_Line_h(x1<<3, y1<<3, x2<<3, y2<<3, color);
}

void _draw_Circle(uint8_t radius, uint32_t color)
{
  int x0 = CLOCK_FACE_CENTER_X; 
  int y0 = CLOCK_FACE_CENTER_Y;

  int x = radius;
  int y = 0;
  int err = 0; //for pixel approximation

  while (x >= y)
  {
// draw 8 octants at once
    ST7735_DrawPixel(x0 + x, y0 + y, color);
    ST7735_DrawPixel(x0 + y, y0 + x, color);
    ST7735_DrawPixel(x0 - y, y0 + x, color);
    ST7735_DrawPixel(x0 - x, y0 + y, color);
    ST7735_DrawPixel(x0 - x, y0 - y, color);
    ST7735_DrawPixel(x0 - y, y0 - x, color);
    ST7735_DrawPixel(x0 + y, y0 - x, color);
    ST7735_DrawPixel(x0 + x, y0 - y, color);

    y += 1;
    err += 1 + (y<<1); 
    if ( ((err-x)<<1) + 1 > 0)
    {
      x -= 1;
      err += 1 - (x<<1);
    }
  }
}

void _draw_Numbers(uint32_t color)
{
  // all numbers precalculated with calculator for maximum prettiness
  ST7735_DrawCharS(59, 41, 0x31, color, color, 1); // one of "12"
  ST7735_DrawCharS(64, 41, 0x32, color, color, 1); // two of "12"
  ST7735_DrawCharS(91, 50, 0x31, color, color, 1); // "1"
  ST7735_DrawCharS(109, 70, 0x32, color, color, 1); // "2"
  ST7735_DrawCharS(115, 93, 0x33, color, color, 1); // "3"
  ST7735_DrawCharS(109, 116, 0x34, color, color, 1); // "4"
  ST7735_DrawCharS(91, 136, 0x35, color, color, 1); // "5"
  ST7735_DrawCharS(61, 146, 0x36, color, color, 1); // "6"
  ST7735_DrawCharS(33, 136, 0x37, color, color, 1); // "7"
  ST7735_DrawCharS(15, 116, 0x38, color, color, 1); // "8"
  ST7735_DrawCharS(9, 93, 0x39, color, color, 1); // "9"
  ST7735_DrawCharS(15, 70, 0x31, color, color, 1); // one of "10"
  ST7735_DrawCharS(20, 70, 0x30, color, color, 1); // zero of "10"
  ST7735_DrawCharS(33, 50, 0x31, color, color, 1); // one of "11"
  ST7735_DrawCharS(38, 50, 0x31, color, color, 1); // one of "11"

}

uint32_t _getNameLength(char * name)
{
  int i = 0;
  while ( name[i] ) { i++; }
  return i;
}

Point calcRadialPixel(uint16_t x0, uint16_t y0, uint16_t d, uint8_t radius)
{
  int x = radius;
  int y = 0;
  int err = 0; //for pixel approximation

  int count = 0;
  Point arr[100];
	arr[0].x = x; 
	arr[0].y = 0;
  while (x >= y)
  {
		count += 1;

    y += 1;
    err += 1 + (y<<1); 
    if ( ((err-x)<<1) + 1 > 0)
    {
      x -= 1;
      err += 1 - (x<<1);
    }

		Point p = {x, y};
    arr[count] = p;
  }
  uint16_t degrees;
  // Convert the input degrees so that it lies between 0 and 45 degrees
  if      (d >= 0    &&  d <= 45)  { degrees = d;       }
  else if (d > 45   &&  d <= 90)  { degrees = 90 - d;  }
  else if (d > 90   &&  d <= 135) { degrees = d - 90;  } 
  else if (d > 135  &&  d <= 180) { degrees = 180 - d; } 
  else if (d > 180  &&  d <= 225) { degrees = d - 180; } 
  else if (d > 225  &&  d <= 270) { degrees = 270 - d; } 
  else if (d > 270  &&  d <= 315) { degrees = d - 270; } 
  else if (d > 315  &&  d <= 360) { degrees = 360 - d; } 
  else if (d > 360)               { degrees = d - 360; }

  int i = (((45 << 5) / (count + 1)) * degrees ) >> 5;

  Point ret_point;
  if      (d >= 0   &&  d <= 45)  { ret_point.x = x0 + arr[i].x;	ret_point.y = y0 - arr[i].y; }
  else if (d > 45   &&  d <= 90)  { ret_point.x = x0 + arr[i].y;	ret_point.y = y0 - arr[i].x; }
  else if (d > 90   &&  d <= 135) { ret_point.x = x0 - arr[i].y;	ret_point.y = y0 - arr[i].x; } 
  else if (d > 135  &&  d <= 180) { ret_point.x = x0 - arr[i].x;	ret_point.y = y0 - arr[i].y; } 
  else if (d > 180  &&  d <= 225) { ret_point.x = x0 - arr[i].x;	ret_point.y = y0 + arr[i].y; } 
  else if (d > 225  &&  d <= 270) { ret_point.x = x0 - arr[i].y;	ret_point.y = y0 + arr[i].x; } 
  else if (d > 270  &&  d <= 315) { ret_point.x = x0 + arr[i].y;	ret_point.y = y0 + arr[i].x; } 
  else if (d > 315  &&  d <= 360) { ret_point.x = x0 + arr[i].x;	ret_point.y = y0 + arr[i].y; } 
  else if (d > 360)               { ret_point.x = x0 + arr[i].x;	ret_point.y = y0 - arr[i].y; }


  return ret_point;
  
//  Point badPointValue = {-1,-1};
//  return badPointValue;
}

void draw_ClockFace(uint32_t circleColor, uint32_t numbersColor)
{
  _draw_Circle(60, circleColor); 
  _draw_Circle(61, circleColor);
  _draw_Circle(4, circleColor);
  _draw_Circle(3, circleColor);
  _draw_Numbers(numbersColor);
}
void draw_MinuteHand(uint32_t time, uint32_t color)
{
	uint32_t minutes = (time % 3600) / 10;
	int32_t degrees = 90 - (minutes);
	if (degrees < 0) { degrees += 360; }
	Point minute = calcRadialPixel(CLOCK_FACE_CENTER_X, CLOCK_FACE_CENTER_Y, degrees, 45);
	_Line(CLOCK_FACE_CENTER_X, CLOCK_FACE_CENTER_Y, minute.x, minute.y, color);
}
void draw_HourHand(uint32_t time, uint32_t color){}
void draw_Mode(char * name, uint32_t color)
{
  uint32_t nameLength = _getNameLength(name);
  ST7735_SetCursor( (21 - nameLength)>>1, 0 ); // centers the string 
  ST7735_SetTextColor(color);
  ST7735_OutString(name);
}
void draw_DigitalTime(uint32_t time, uint32_t color)
{
  ST7735_SetCursor(8,2);
  ST7735_SetTextColor(color);
  uint32_t hour = time / 3600;
  uint32_t minute = (time % 3600) / 60;
	if (hour < 10) {ST7735_OutUDec(0);}
  ST7735_OutUDec(hour);
  ST7735_OutString(":");
	if (minute < 10) {ST7735_OutUDec(0);}
  ST7735_OutUDec(minute);
}
void draw_DigitalDigit(uint8_t position, uint32_t value, uint32_t color){}
void draw_CursorBox(uint8_t position, uint32_t color){}
void draw_CursorUnderscore(uint8_t position, uint32_t color){}

void draw_main(void)
{
  draw_Init();
  ST7735_SetRotation(2);
  draw_ClockFace(ST7735_BLUE, ST7735_RED);
  draw_Mode("this is a clock", ST7735_WHITE);
  draw_DigitalTime(44640, ST7735_WHITE);

  /*
  ST7735_SetCursor(10,4);
  ST7735_OutString("12");
  ST7735_SetCursor(15,5);
  ST7735_OutString("1");
  ST7735_SetCursor(18,7);
  ST7735_OutString("2");
  ST7735_SetCursor(19,9);
  ST7735_OutString("3");
  ST7735_SetCursor(18,11);
  ST7735_OutString("4");

  ST7735_SetCursor(15,13);
  ST7735_OutString("5");
  ST7735_SetCursor(10,14);
  ST7735_OutString("6");
  ST7735_SetCursor(5,13);
  ST7735_OutString("7");
  ST7735_SetCursor(2,11);
  ST7735_OutString("8");
  ST7735_SetCursor(1,9);
  ST7735_OutString("9");
  */
}
