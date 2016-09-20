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

typedef enum actionType {
  SETTING = 0,
  DISPLAY = 1,
  OUT = 2
} actionType;

actionType detectActionType(rxDataType Action) {
  return DISPLAY;
}
  
void updateSetting(rxDataType Action){}
void updateDisplay(rxDataType Action)
{
	Output_Clear();
	ST7735_SetCursor(0,0);
	switch (Action.id)
	{
		case NUMBER_0:
			ST7735_OutString("Pressed 0");
			break;
		case NUMBER_1:
			ST7735_OutString("Pressed 1");
			break;
		case NUMBER_2:
			ST7735_OutString("Pressed 2");
			break;
		case NUMBER_3:
			ST7735_OutString("Pressed 3");
			break;
		case NUMBER_4:
			ST7735_OutString("Pressed 4");
			break;
		case NUMBER_5:
			ST7735_OutString("Pressed 5");
			break;
		case NUMBER_6:
			ST7735_OutString("Pressed 6");
			break;
		case NUMBER_7:
			ST7735_OutString("Pressed 7");
			break;
		case NUMBER_8:
			ST7735_OutString("Pressed 8");
			break;
		case NUMBER_9:
			ST7735_OutString("Pressed 9");
			break;
		case DIR_UP:
			ST7735_OutString("Pressed up");
			break;
		case DIR_DOWN:
			ST7735_OutString("Pressed down");
			break;
		case DIR_RIGHT:
			ST7735_OutString("Pressed right");
			break;
		case DIR_LEFT:
			ST7735_OutString("Pressed left");
			break;
		case MENU_SELECT:
			ST7735_OutString("Pressed menu");
			break;
	}
}	
void updateOut(rxDataType Action){} 
void InitRoutines(void)
{
	draw_ClockFace(ST7735_BLUE, ST7735_RED);
};

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

int main (void) 
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
			draw_MinuteHand(time-1, ST7735_BLACK);
			draw_MinuteHand(time,ST7735_BLUE); 
			draw_DigitalTime(time, ST7735_WHITE);
			time += 1;
		}
		else {time = 0;}
		/*
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
		*/
  }
}

