#ifndef __drawh
#define __drawh

#include <stdint.h>

typedef struct Point {
  int16_t x;
  int16_t y;
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
void _Line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void draw_main(void);

static const Point MINUTE_POINT_VAL[60] = {
  { 44,  4},
  { 44,  9},
  { 42,  13},
  { 41,  18},
  { 38,  22},
  { 36,  26},
  { 33,  30},
  { 30,  33},
  { 26,  36},
  { 22,  38},
  { 18,  41},
  { 13,  42},
  { 9,   44},
  { 4,   44},
  { 0,   45},
  {-5,   44},
  {-10,  44},
  {-14,  42},
  {-19,  41},
  {-23,  38},
  {-27,  36},
  {-31,  33},
  {-34,  30},
  {-37,  26},
  {-39,  22},
  {-42,  18},
  {-43,  13},
  {-45,  9},
  {-45,  4},
  {-45,  0},
  {-45, -5},
  {-45, -10},
  {-43, -14},
  {-42, -19},
  {-39, -23},
  {-37, -27},
  {-34, -31},
  {-31, -34},
  {-27, -37},
  {-23, -39},
  {-19, -42},
  {-14, -43},
  {-10, -45},
  { -5, -45},
  { -1, -45},
  {  4, -45},
  {  9, -45},
  { 13, -43},
  { 18, -42},
  { 22, -39},
  { 26, -37},
  { 30, -34},
  { 33, -31},
  { 36, -27},
  { 38, -23},
  { 41, -19},
  { 42, -14},
  { 44, -10},
  { 44, -5},
  { 45, -1}
};

#endif
