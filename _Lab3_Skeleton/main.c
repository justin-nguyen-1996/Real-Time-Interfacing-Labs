// Runs on TM4C123

#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "PLL.h"
#include "Timer.h"
#include "Keypad.h"
#include "draw.h"
#include "out.h"
#include "FIFO.h"
#include "ST7735.h"

#define ORIGIN_MAIN 0

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

typedef enum modeType {
	MODE_RUN = 0,
	MODE_SET_TIME = 1,
	MODE_SET_ALARM = 2,
} modeType;
char * modeNames[3] = {"Run","Set Time", "Set Alarm"};

uint32_t time = 0;
uint32_t alarmEnable = 0;
uint32_t alarmTime = 0;
uint32_t cursorLocation = 0;
uint16_t circleColor = ST7735_BLUE;
uint16_t numberColor = ST7735_RED;
uint16_t handColor = ST7735_BLUE;
uint16_t cursorColor = ST7735_YELLOW; 
uint16_t modeColor = ST7735_WHITE;
uint16_t backgroundColor = ST7735_BLACK;
modeType currentMode = MODE_RUN;

typedef enum actionType {
  SETTING = 0,
  DISPLAY = 1,
  OUT = 2
} actionType;

void draw_Cursor(uint16_t position, uint16_t color)
{
  switch (position)
	{
		case 0:
			_Line(0,11,128,11,color);	
			break;
		case 1:
			_Line(48,30,52,30,color);
			break;
		case 2:
			_Line(54,30,58,30,color);
			break;
		case 3:
			_Line(66,30,70,30,color);
			break;
		case 4:
			_Line(72,30,76,30,color);
			break;
		case 5:
			_Line(79,30,87,30,color);
			break;
	}
}


actionType detectActionType(rxDataType Action) 
{
	switch (Action.origin)
	{
		case 0: //main
			break;
		case 1: //timer
			break;
		case 2: //keypad
			switch (Action.id)
			{
				case NUMBER_0:
					if (cursorLocation) {}
					break;
				case NUMBER_1:
					if (cursorLocation) {}
					break;
				case NUMBER_2:
					if (cursorLocation) {}
					break;
				case NUMBER_3:
					if (cursorLocation) {}
					break;
				case NUMBER_4:
					if (cursorLocation) {}
					break;
				case NUMBER_5:
					if (cursorLocation) {}
					break;
				case NUMBER_6:
					if (cursorLocation) {}
					break;
				case NUMBER_7:
					if (cursorLocation) {}
					break;
				case NUMBER_8:
					if (cursorLocation) {}
					break;
				case NUMBER_9:
					if (cursorLocation) {}
					break;
				case DIR_UP:
					if (cursorLocation) {}
					break;
				case DIR_DOWN:
					if (cursorLocation) {}
					break;

				case DIR_RIGHT:
					if (cursorLocation)
					{
						draw_Cursor(cursorLocation,backgroundColor);
						if (cursorLocation == 5) {cursorLocation = 1;}
						else {cursorLocation ++;}
						draw_Cursor(cursorLocation,cursorColor);
					}
					else 
					{
						if (currentMode == MODE_SET_ALARM){ currentMode = MODE_RUN; }
						else {currentMode++;}
						draw_Mode(modeNames[currentMode], modeColor);
					}
					break;

				case DIR_LEFT:
					if (cursorLocation)
					{
						draw_Cursor(cursorLocation,backgroundColor);
						if (cursorLocation == 1) {cursorLocation = 5;}
						else {cursorLocation --;}
						draw_Cursor(cursorLocation,cursorColor);
					}
					else 
					{
						if (currentMode == MODE_RUN){ currentMode = MODE_SET_ALARM; }
						else {currentMode --;}
						draw_Mode(modeNames[currentMode], modeColor);
					}
					break;

				case MENU_SELECT:
					draw_Cursor(cursorLocation,backgroundColor);
					if (cursorLocation) {cursorLocation = 0;}
					else {cursorLocation = 1;}
					draw_Cursor(cursorLocation,cursorColor);
					break;
			}
		break;
	}
}
  
void updateSetting(rxDataType Action){}
void updateDisplay(rxDataType Action)
{
	}	
void updateOut(rxDataType Action){} 
void InitRoutines(void)
{
	draw_ClockFace(circleColor, numberColor);
	//draw_MinuteHand(time, handColor);
  draw_MinuteHand(time, handColor, 0);
	draw_HourHand(time, handColor);
	draw_Cursor(cursorLocation, cursorColor);
	draw_Mode("Run", modeColor);
	draw_DigitalTime(time, modeColor);
}

void initAll (void) 
{
  PLL_Init(Bus80MHz);
  RxFifo_Init();

  // Initialize output modules 
  // These will not push routines on the FIFO
//  out_Init();
  draw_Init();
	ST7735_SetRotation(2);

  // initial routines for the program (configure setting values)
  InitRoutines();

  // Initialize input modules which use interrupts 
  // These may push additional initial routines on FIFO (drawing first screen)
  Keypad_Init();
//  Timer_Init();
}

int main_CRAP (void) 
{
  initAll();
//  draw_main();
//	keypad_main();
	uint32_t time = 0;
  while(1)
	{
		if (time < 86400) 
		{ 
			ST7735_SetCursor(0,0);
			ST7735_OutUDec(time);
			draw_MinuteHand_CRAP(time-1, ST7735_BLACK);
			draw_MinuteHand_CRAP(time,ST7735_BLUE); 
			draw_DigitalTime(time, ST7735_WHITE);
			time += 1;
		}
		else {time = 0;}
		
    rxDataType nextAction;
    int fifoGetStatus = RxFifo_Get(&nextAction);
    if (fifoGetStatus)
    {
      actionType type = detectActionType(nextAction);
      switch (type)
      {
        case SETTING:  updateSetting(nextAction); break;
        case DISPLAY:  updateDisplay(nextAction); break;
        case OUT:      updateOut(nextAction);     break;
      }
    }
  }
}

int main (void) {
  initAll();
//  draw_main();
//	keypad_main();
	uint32_t time = 0;

  while(1)
	{
    if (time < 86400) 
      { 
        // Start at one because init drew the first minute hand
        static uint8_t minuteHandBufferIndex = 1;
        
        ST7735_SetCursor(0,0);
        ST7735_OutUDec(time);
        
        // Separate the mod and increment minuteHandBufferIndex steps so we
        //   can plot (BufferIndex - 1) when BufferIndex = MINUTE_HAND_RESOLUTION.
        // Otherwise, the minute hand at BufferIndex = 0 won't be erased.
        draw_MinuteHand(time - 1, ST7735_BLACK, (minuteHandBufferIndex - 1));
        minuteHandBufferIndex %= MINUTE_HAND_RESOLUTION;
        draw_MinuteHand(time, ST7735_BLUE, minuteHandBufferIndex); 
        minuteHandBufferIndex += 1;
        draw_DigitalTime(time, ST7735_WHITE);
        
        time += 1;
      }
    else { time = 0; }
  }
  
  rxDataType nextAction;
  int fifoGetStatus = RxFifo_Get(&nextAction);
  if (fifoGetStatus)
  {
    actionType type = detectActionType(nextAction);
    switch (type)
    {
      case SETTING:  updateSetting(nextAction); break;
      case DISPLAY:  updateDisplay(nextAction); break;
      case OUT:      updateOut(nextAction);     break;
    }
  }
}

