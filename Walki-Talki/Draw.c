// Draw.c
// Runs on TM4C123
// Uses ST7735.c LCD.
// Jonathan Valvano
// August 5, 2015
// Dung Nguyen
// Wally Guzman

#include <stdio.h>
#include <stdint.h>
#include "Draw.h"
#include "ST7735.h"
#include "PLL.h"
#include "tm4c123gh6pm.h"

int invert = 0;

//------------DrawInit------------
// Initialize the ST7735 LCD screen for drawing
// Input: none
// Output: none
void Draw_Init(void) {
	ST7735_InitR(INITR_REDTAB);
	ST7735_FillScreen(ST7735_BLACK);
	ST7735_SetCursor(0,0);
}

//------------DrawInit------------
// Initialize the ST7735 LCD screen for drawing
// Input: none
// Output: none
void DrawClear(void) {
	ST7735_FillScreen(ST7735_BLACK);
}

//------------DrawMenu------------
// Draw Main Menu on ST7735
// Input: none
// Output: none
void DrawMenu(void) {
	ST7735_DrawString(5, 1, "Main Menu", ST7735_WHITE);
	ST7735_DrawString(5, 6, "Set Clock", ST7735_WHITE);
	ST7735_DrawString(5, 8, "Set Alarm", ST7735_WHITE);
	ST7735_DrawString(5, 10, "Change Display", ST7735_WHITE);
}

//------------DrawCursor------------
// Draw cursor on menu option
// Input: none
// Output: none
void DrawCursor(int cursor_pos) {
	ST7735_DrawString(2, 6, "->", ST7735_BLACK);	// Erase previous cursors
	ST7735_DrawString(2, 8, "->", ST7735_BLACK);
	ST7735_DrawString(2, 10, "->", ST7735_BLACK);
	
}

//------------DrawSet------------
// Draw Set Menu for Clock Time or Alarm Time
// Input: none
// Output: none
void DrawSet(int type) {
}

//------------DrawDisp------------
// Draw Display Settings Menu
// Input: none
// Output: none
void DrawDisp(void) {
	ST7735_DrawString(4, 1, "Display Menu", ST7735_WHITE);
	ST7735_DrawString(5, 6, "Analog", ST7735_WHITE);
	ST7735_DrawString(5, 8, "Digital", ST7735_WHITE);
}

//------------DrawInvert------------
// Invert Display
// Input: none
// Output: none
void DrawInvert(void) {
	invert ^= 1;
	
	ST7735_InvertDisplay(invert);
}
