#ifndef __drawh
#define __drawh

#include <stdint.h>

typedef struct Point {
  uint16_t x;
  uint16_t y;
} Point;

uint16_t getNumPixelsToDraw(uint8_t radius, uint16_t degrees);

void draw_Init(void);
void draw_ClockFace(uint32_t circleColor, uint32_t numbersColor);
void draw_MinuteHand(uint32_t time, uint32_t color);
void draw_HourHand(uint32_t time, uint32_t color);
void draw_Mode(char * name, uint32_t color);
void draw_DigitalTime(uint32_t time, uint32_t color);
void draw_DigitalDigit(uint8_t position, uint32_t value, uint32_t color);
void draw_CursorBox(uint8_t position, uint32_t color);
void draw_CursorUnderscore(uint8_t position, uint32_t color);

void draw_main(void);

#endif
