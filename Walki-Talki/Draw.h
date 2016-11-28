// Draw.h
// Runs on TM4C123
// Uses ST7735.c LCD.
// Jonathan Valvano
// August 5, 2015
// Dung Nguyen
// Wally Guzman

//------------DrawInit------------
// Initialize the ST7735 LCD screen for drawing
// Input: none
// Output: none
void Draw_Init(void);

//------------DrawInit------------
// Initialize the ST7735 LCD screen for drawing
// Input: none
// Output: none
void DrawClear(void);

//------------DrawMenu------------
// Draw Main Menu on ST7735
// Input: none
// Output: none
void DrawMenu(void);

//------------DrawCursor------------
// Draw cursor on menu option
// Input: none
// Output: none
void DrawCursor(int cursor_pos);

//------------DrawSet------------
// Draw Digital Clock to set Clock Time
// Input: none
// Output: none
void DrawSet(int type);

//------------DrawDisp------------
// Draw Display Settings Menu
// Input: none
// Output: none
void DrawDisp(void);

//------------DrawInvert------------
// Invert Display
// Input: none
// Output: none
void DrawInvert(void);
