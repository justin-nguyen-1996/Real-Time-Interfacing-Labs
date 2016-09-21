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

uint32_t prevTime = 0;
uint32_t time = 0;
uint32_t alarmEnable = 1;
uint32_t alarmTime = 0;
uint8_t  alarmed = 0;
uint32_t cursorLocation = 0;
uint16_t circleColor = ST7735_BLUE;
uint16_t numberColor = ST7735_RED;
uint16_t handColor = ST7735_BLUE;
uint16_t hourColor = ST7735_CYAN;
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

void updateTime() {
  draw_MinuteHand(prevTime, backgroundColor); // erase previous hand
  draw_MinuteHand(time, handColor);         // draw new hand
  draw_HourHand(prevTime, backgroundColor);
  draw_HourHand(time, hourColor);
  if (currentMode == MODE_SET_ALARM) {draw_DigitalTime(alarmTime, ST7735_RED);}
	else {draw_DigitalTime(time, ST7735_WHITE);}     // update digital time
	if (alarmEnable && !alarmed && (time >= alarmTime && time < alarmTime + 60)) { out_Speaker(0x10000); }
  if (time % 900 == 0) { 
    draw_HourHand(time, hourColor); 
  }
}
void detectActionType(rxDataType Action) 
{
	switch (Action.origin)
	{
		case 0: //main
			break;
		case 1: //timer
			switch (Action.id)
			{
				case 0:
					if (time < 86400){
						prevTime = time;
            time++;
            updateTime();
//            if (time == 60) {
//            }
					}
					else {time = 0;}
					break;
			}
			break;
		case 2: //keypad
			if (alarmed) {out_SpeakerDisable(); alarmed = 0;} // disable alarm if button press
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
						if ( currentMode == MODE_SET_TIME )
						{
							prevTime = time;
							switch (cursorLocation)
							{
								case 0:
									break;
								case 1: // change tens hour digit
									if (time >= 72000){ time -= 72000; } //twenty hours
									else {time += 36000;} //ten hour's worth of seconds
									break;
								case 2: // change ones hour digit
									if (time >= 82800){ time -= 10800; } //twenty three hours and three hours
//									else if ((time % 36000) >= 32400) { time -= 32400;} //remove tens hours, larger than 9 hours
//									else {time += 3600;}
                  else { time += 3600; }
									break;
								case 3: // change tens minute digit
									if ((time % 3600) >= 3000) { time -= 3000;} //fifty minutes
									else {time += 600;}
                  //time += 600;
									break;
								case 4: // change ones minute digit
                  if (time >= 86340 && time < 86400) { time = 0; }
                  else { time += 60; }
									break;
							}
						}
						if ( currentMode == MODE_SET_ALARM )
						{
							switch (cursorLocation)
							{
								case 0:
									break;
								case 1: // change tens hour digit
									if (alarmTime >= 72000){ alarmTime -= 72000; } //twenty hours
									else {alarmTime += 36000;} //ten hour's worth of seconds
									break;
								case 2: // change ones hour digit
									if (alarmTime >= 82800){ alarmTime -= 10800; } //twenty three hours and three hours
									else if ((alarmTime % 36000) >= 32400) { alarmTime -= 32400;} //remove tens hours, larger than 9 hours
									else {alarmTime += 3600;}
									break;
								case 3: // change tens minute digit
									if ((alarmTime % 3600) >= 3000) { alarmTime -= 3000;} //fifty minutes
									else {alarmTime += 600;}
									break;
								case 4: // change ones minute digit
									//if ((alarmTime % 600) >= 540) { alarmTime -= 540; }
									//else { alarmTime += 60; }
                  alarmTime += 60;
									break;
							}
						}
						updateTime();
					break;
				case DIR_DOWN:
          draw_MinuteHand(time, backgroundColor);
					if (currentMode == MODE_SET_TIME)
					{
						prevTime = time;
						switch (cursorLocation)
            {
              case 0:
                break;
              case 1:
                if (time <= 35999){ time += 72000; } //twenty hours
                else {time -= 36000;} //ten hour's worth of seconds
                break;
              case 2:
                if ((time / 36000) == 2 && (time % 36000) <= 3600){ time += 10800; } //twenty three hours and three hours
                else if ((time % 36000) <= 32399) { time += 32400;} //remove tens hours, 0 hours 
                else {time -= 3600;}
                break;
              case 3:
                if ((time % 3600) <= 599) { time += 3000;} //fifty minutes
                else {time -= 600;}
                break;
              case 4:
                if (time < 60) { time = 0; } // Loop back to 9 if time is 00:00
                else { time -= 60; }
                break;
            }
					}
					if (currentMode == MODE_SET_TIME)
					{
						switch (cursorLocation)
            {
              case 0:
                break;
              case 1:
								if (alarmTime <= 35999){ alarmTime += 72000; } //twenty hours
                else {alarmTime -= 36000;} //ten hour's worth of seconds
                break;
              case 2:
                if ((alarmTime / 36000) == 2 && (alarmTime % 36000) <= 3600){ alarmTime += 10800; } //twenty three hours and three hours
                else if ((alarmTime % 36000) <= 32399) { alarmTime += 32400;} //remove tens hours, 0 hours 
                else {alarmTime -= 3600;}
                break;
              case 3:
                if ((alarmTime % 3600) <= 599) { alarmTime += 3000;} //fifty minutes
                else {alarmTime -= 600;}
                break;
              case 4:
                if ((alarmTime % 600) <= 59) { alarmTime += 540; }
                else { alarmTime -= 60; }
                break;
            }
					}
					updateTime();
          break;
				case DIR_RIGHT:
					if (cursorLocation)
					{
						draw_Cursor(cursorLocation,backgroundColor); //erase
						if (cursorLocation == 4) {cursorLocation = 1;}
						else {cursorLocation ++;}
						draw_Cursor(cursorLocation,cursorColor);
					}
					else 
					{
						if (currentMode == MODE_SET_ALARM){ currentMode = MODE_RUN; }
						else {currentMode++;}
						draw_Mode(modeNames[currentMode], modeColor);
					}
					if (currentMode == MODE_SET_ALARM) { draw_DigitalTime(alarmTime, ST7735_RED); }
					break;

				case DIR_LEFT:
					if (cursorLocation)
					{ //change mode
						draw_Cursor(cursorLocation,backgroundColor); //erase
						if (cursorLocation == 1) {cursorLocation = 4;}
						else {cursorLocation --;}
						draw_Cursor(cursorLocation,cursorColor);
					}
					else 
					{ 
						if (currentMode == MODE_RUN){ currentMode = MODE_SET_ALARM; }
						else {currentMode --;}
						draw_Mode(modeNames[currentMode], modeColor);
					}
					if (currentMode == MODE_SET_ALARM) { draw_DigitalTime(alarmTime, ST7735_RED); }
					break;

				case MENU_SELECT:
					draw_Cursor(cursorLocation,backgroundColor);
					if (cursorLocation) {cursorLocation = 0;} //move cursor to mode select
					else if (currentMode != MODE_RUN) {cursorLocation = 1;} //move cursor to edit mode
					draw_Cursor(cursorLocation,cursorColor);
					break;
			}
		break;
	}
}
  
void updateSetting(rxDataType Action){}
void updateDisplay(rxDataType Action){}	
void updateOut(rxDataType Action){} 
void InitRoutines(void)
{
	draw_ClockFace(circleColor, numberColor);
	//draw_MinuteHand(time, handColor);
  draw_MinuteHand(time, handColor);
	draw_HourHand(time, hourColor);
	draw_Cursor(cursorLocation, cursorColor);
	draw_Mode("Run", modeColor);
	draw_DigitalTime(time, modeColor);
}

void initAll (void) 
{
  //PLL_Init(Bus80MHz);
  PLL_Init(Bus16MHz);
  RxFifo_Init();

  // Initialize output modules 
  // These will not push routines on the FIFO
  out_Init();
  draw_Init();
	ST7735_SetRotation(2);

  // initial routines for the program (configure setting values)
  InitRoutines();

  // Initialize input modules which use interrupts 
  // These may push additional initial routines on FIFO (drawing first screen)
  Keypad_Init();
  SysTick_Init();
}

int main (void) {
  initAll();  
  EnableInterrupts();

  
//  draw_main();
//	keypad_main();
  
//  while (1) {
//    out_Speaker(0);
//  }

  while(1)
	{
//    if (time < 86400) 
//      { 
//        ST7735_SetCursor(0,0);
//        ST7735_OutUDec(time);
//        draw_DigitalTime(time, ST7735_WHITE);
//      }
//    else { time = 0; }
  
  rxDataType nextAction;
  int fifoGetStatus = RxFifo_Get(&nextAction);
  if (fifoGetStatus)
  {
    detectActionType(nextAction);
  }
	}
}

