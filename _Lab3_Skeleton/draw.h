#ifndef __drawh
#define __drawh

#include <stdint.h>

typedef struct Point {
  int8_t x;
  int8_t y;
} Point;

uint16_t getNumPixelsToDraw(uint8_t radius, uint16_t degrees);

void draw_Init(void);
void draw_ClockFace(uint32_t circleColor, uint32_t numbersColor);
void draw_MinuteHand_CRAP(uint32_t time, uint32_t color);
void draw_MinuteHand(uint32_t time, uint32_t color);
void draw_HourHand(uint32_t time, uint32_t color);
void draw_Mode(char * name, uint32_t color);
void draw_DigitalTime(uint32_t time, uint32_t color);
void draw_DigitalDigit(uint8_t position, uint32_t value, uint32_t color);
void draw_CursorBox(uint8_t position, uint32_t color);
void draw_CursorUnderscore(uint8_t position, uint32_t color);
void _Line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void draw_main(void);

#define MINUTE_HAND_RESOLUTION 61
#define HOUR_HAND_RESOLUTION   49

static const Point MINUTE_HAND_BUFFER[MINUTE_HAND_RESOLUTION] = {
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
  //{ 45, -1},
  { 45,   0},
  { 44,   4},
  { 44,   9},
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
  {-45,   9},
  {-45,   4},
  {-45,   0},
  {-45,  -5},
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
};


static const Point HOUR_HAND_BUFFER[HOUR_HAND_RESOLUTION] = {
  {  -1, -30 },
  {   3, -30 },
  {   7, -29 },
  {  11, -28 },
  {  15, -26 },
  {  18, -24 },
  {  21, -22 },
  {  23, -19 },
  {  25, -15 },
  {  27, -12 },
  {  28,  -8 },
  {  29,  -4 },
  {  30,   0 },
  {  29,   3 },
  {  28,   7 },
  {  27,  11 },
  {  25,  15 },
  {  23,  18 },
  {  21,  21 },
  {  18,  23 },
  {  15,  25 },
  {  11,  27 },
  {   7,  28 },
  {   3,  29 },
  {   0,  30 },
  {  -4,  29 },
  {  -8,  28 },
  { -12,  27 },
  { -15,  25 },
  { -19,  23 },
  { -22,  21 },
  { -24,  18 },
  { -26,  15 },
  { -28,  11 },
  { -29,   7 },
  { -30,   3 },
  { -30,   0 },
  { -30,  -4 },
  { -29,  -8 },
  { -28, -12 },
  { -26, -15 },
  { -24, -19 },
  { -22, -22 },
  { -19, -24 },
  { -15, -26 },
  { -12, -28 },
  {  -8, -29 },
  {  -4, -30 },
};
#endif
