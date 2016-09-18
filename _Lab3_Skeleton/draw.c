#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "ST7735.h"
#include "draw.h"

// Initialization will initialize the ST7735 display and
// set up a coordinate plot for future use
void draw_Init(void)
{
  ST7735_InitR(INITR_REDTAB);
}

void draw_ClockFace(uint32_t color){}
void draw_MinuteHand(uint32_t time, uint32_t color){}
void draw_HourHand(uint32_t time, uint32_t color){}
void draw_Mode(char * name, uint32_t color){}
void draw_DigitalTime(uint32_t time, uint32_t color){}
void draw_DigitalDigit(uint8_t position, uint32_t value, uint32_t color){}
void draw_CursorBox(uint8_t position, uint32_t color){}
void draw_CursorUnderscore(uint8_t position, uint32_t color){}
