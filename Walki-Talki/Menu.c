//Menu.c
//Dung Nguyen
//Wally Guzman

#include <stdint.h>
#include <string.h>
#include "Menu.h"
#include "ST7735.h"
#include "ESP8266.h"
#include "UART1.h"
#include "LED.h"
#include "Button.h"
#include "Settings.h"
#include "ADC.h"
#include "Tone.h"

#define MAX_MENU_ITEMS 		 10
#define MENU_Y_OFFSET  		 22
#define MENU_BG_COLOR      ST7735_BLACK
#define MENU_TEXT_COLOR    ST7735_WHITE
#define MENU_SELECT_COLOR  ST7735_BLUE

menu_t *menuHistory[MAX_MENU_ITEMS];
int menuPosition[MAX_MENU_ITEMS];
int menuHistoryIndex;

menu_t *currentMenu;
int menuCursor;
int drawConnect = 1;
uint32_t DACValue = 128;
int sendVoice = 1;

menu_t nullMenu = {0,0};
void Blink(uint32_t cursor_pos);
void Tone(uint32_t cursor_pos);
void Main(uint32_t cursor_pos);
void Settings(uint32_t cursor_pos);

// List of Menus
menu_t mainMenu, toneMenu, settingsMenu, blinkMenu;

// List of Menu Items
menuItem_t mainItems[4] = {{"Blink", &blinkMenu},
													 {"Send Tone", &toneMenu},
													 {"Send Voice"},
													 {"Settings", &settingsMenu}};
menuItem_t toneItems[8] = {{"C4"}, 
													 {"D4"},
													 {"E4"},
													 {"F4"},
													 {"G4"},
													 {"A4"},
													 {"B4"},
													 {"C5"}};
menuItem_t settingsItems[5] = {{"Volume"},
															 {"Reset ESP8266"},
															 {"Restore ESP8266"},
															 {"Disconnect"},
															 {"Reconnect"}};
menuItem_t blinkItems[3] = {{"Yellow"}, {"Green"}, {"Red"}};

//------------Menu_Init------------
// Initialize menus with menu items and screen
// Changes cursor position
// Input: none
// Output: none
void Menu_Init(void){//reset/init all menu parameters
	mainMenu = (menu_t){4, mainItems, &Main};
	toneMenu = (menu_t) {8, toneItems, &Tone};
	settingsMenu = (menu_t){5, settingsItems, &Settings};
	blinkMenu = (menu_t) {3, blinkItems, &Blink};
	
	for(int k=0; k<MAX_MENU_ITEMS; k++){
		menuHistory[k] = &nullMenu;
		menuPosition[k] = 0;
	}
	menuHistoryIndex = 0;
	
	Menu_Set(&mainMenu);
	ST7735_InitR(INITR_REDTAB);
	ST7735_FillScreen(ST7735_BLACK);
	Menu_Draw();
}

//------------Menu_Set------------
// Set current menu and resets cursor position
// Input: none
// Output: none
void Menu_Set(struct menu_t *menu){
	currentMenu = menu;
	menuCursor = 0;
}

//------------ST7735_DrawStringCenter------------
// Draw menu items at center of screen
// Changes cursor position
// Input: none
// Output: none
void ST7735_DrawStringCenter(int y, char *pt, int16_t textColor, int16_t bgColor){
	int strSize = strlen(pt);
	int strWidth = strSize*6 - 1;
	int x = (128-strWidth)>>1;
	for(int k=0; k<strSize; k++)
		ST7735_DrawChar(x+k*6,y,pt[k],textColor,bgColor,1);
}

//------------Menu_Drawselect------------
// Draw current cursor position
// Changes cursor position
// Input: none
// Output: none
void Menu_DrawSelect(int position){
	ST7735_FillRect(0,MENU_Y_OFFSET-2+11*position,128,11,MENU_SELECT_COLOR);
	ST7735_DrawStringCenter(MENU_Y_OFFSET+11*position,currentMenu->items[position].name,MENU_TEXT_COLOR,MENU_SELECT_COLOR);
}

//------------Menu_DrawUnselect------------
// Erase cursor from previous positions
// Changes cursor position
// Input: none
// Output: none
void Menu_DrawUnselect(int position){
	ST7735_FillRect(0,MENU_Y_OFFSET-2+11*position,128,11,MENU_BG_COLOR);
	ST7735_DrawStringCenter(MENU_Y_OFFSET+11*position,currentMenu->items[position].name,MENU_TEXT_COLOR,MENU_BG_COLOR);
}

//------------Menu_Draw------------
// Display current menu
// Changes cursor position
// Input: none
// Output: none
void Menu_Draw(void){
	ST7735_FillRect(0, MENU_Y_OFFSET, 128, 160 - MENU_Y_OFFSET, MENU_BG_COLOR);
	if(currentMenu->numItems == 0)
		return;
	
	for(int k=0; k<menuCursor; k++)
		Menu_DrawUnselect(k);
	
	Menu_DrawSelect(menuCursor);
	
	for(int k=menuCursor+1; k<currentMenu->numItems; k++)
		Menu_DrawUnselect(k);
}

//------------Menu_Up------------
// Navigate menu on up press
// Changes cursor position
// Input: none
// Output: none
void Menu_Up(void){
	if(currentMenu->numItems <= 1)
		return;
	
	Menu_DrawUnselect(menuCursor);
	menuCursor -= 1;
	if(menuCursor<0)
		menuCursor = currentMenu->numItems - 1;
	Menu_DrawSelect(menuCursor);
}

//------------Menu_Down------------
// Navigate menu on down press
// Changes cursor position
// Input: none
// Output: none
void Menu_Down(void){
	if(currentMenu->numItems <= 1)
		return;
	
	Menu_DrawUnselect(menuCursor);
	menuCursor += 1;
	if(menuCursor>=currentMenu->numItems)
		menuCursor = 0;
	Menu_DrawSelect(menuCursor);
}

//------------Menu_Back------------
// Navigate menu on back press
// Changes currentMenu
// Input: none
// Output: none
void Menu_Back(void){//go back to last menu
	if(menuHistoryIndex == 0)
		return;
	menuHistoryIndex--;
	currentMenu = menuHistory[menuHistoryIndex];
	menuCursor = menuPosition[menuHistoryIndex];
	Menu_Draw();
}

//------------Menu_Select------------
// Navigate menu on select press and execute menu function
// Changes currentMenu
// Input: none
// Output: none
void Menu_Select(void){		//go to next menu or call function
	if(currentMenu->numItems == 0)
		return;
	
	menu_t *nextMenu = currentMenu->items[menuCursor].nextMenu;
	if((currentMenu->task))	// Return if no task
		(*currentMenu->task)(menuCursor);	
	if(!nextMenu) { // Call function in menu item
		return;
	}
	menuHistory[menuHistoryIndex] = currentMenu;
	menuPosition[menuHistoryIndex] = menuCursor;
	currentMenu = nextMenu;
	menuCursor = 0;
	menuHistoryIndex++;
	
	Menu_Draw();
}

//------------Menu_SendState------------
// Return voice/tone transmission
// Input: none
// Output: 1 if voice, 0 if tone
int Menu_SendState(void) {
	return sendVoice;
}

//------------Menu_Display------------
// Display current microphone and speaker input/output
// Input: none
// Output: none
void Menu_Display(void) {
	static int count = 0;
	static int x_ = 0;
	if(!(count & 127)) {
		ST7735_DrawFastVLine((x_ + 1) & 127, 0, 160, ST7735_BLACK);
		ST7735_DrawPixel(x_ & 127, (ADC_PeekValue() * 80) >> 12, ST7735_BLUE);
		ST7735_DrawPixel(x_ & 127, ((DACValue * 80) >> 8) + 80, ST7735_RED);
		x_++;
	}
	count++;
}

//------------Menu_UpdateDACValue------------
// Used for drawing DAC output to display
// Input: none
// Output: none
void Menu_UpdateDACValue(int newDACValue) {
	DACValue = newDACValue & 0xFF;
}

//------------Menu_Update------------
// Navigate menu based on switch input
// Input: none
// Output: none
void Menu_Update(void) {
	static int display = 0;
	if(Button_NewState()) {
		switch(Button_Pressed()){
			case U:
				Menu_Up();
				break;
			case D:
				Menu_Down();
				break;
			case R:
				Menu_Select();
				break;
			case L:
				Menu_Back();
				break;
			case B:
				if(display) { // Toggle display with switch
					display = 0;
					Menu_Draw();
				}
				else {
					display = 1;
					ST7735_FillScreen(ST7735_BLACK);
				}
			default:
				// Error case
				break;
		}
	}
	if(display)
		Menu_Display();
}

/**************MENU FUNCTIONS******************/
//------------Blink------------
// Toggle LEDs based on cursor position
// Input: none
// Output: none
void Blink(uint32_t cursor) {
	switch(cursor) {
		case 0:
			LED_Yellow_Toggle();
			break;
		case 1:
			LED_Green_Toggle();
			break;
		case 2:
			LED_Red_Toggle();
			break;
		default:
			break;
		}
}

//------------Main------------
// Set tone or voice transmission
// Input: none
// Output: none
void Main(uint32_t cursor_pos) {
	switch(cursor_pos) {
		case 1:
			sendVoice = 0;
			break;
		case 2:
			sendVoice = 1;
			break;
		default:
			break;
	}
}

//------------Tone------------
// Set tone based on cursor position
// Input: none
// Output: none
void Tone(uint32_t cursor_pos) {
	switch(cursor_pos) {
		case 0:
			Tone_SetFrequency(C4);
			break;
		case 1:
			Tone_SetFrequency(D4);
			break;
		case 2:
			Tone_SetFrequency(E4);
			break;
		case 3:
			Tone_SetFrequency(F4);
			break;
		case 4:
			Tone_SetFrequency(G4);
			break;
		case 5:
			Tone_SetFrequency(A4);
			break;
		case 6:
			Tone_SetFrequency(B4);
			break;
		case 7:
			Tone_SetFrequency(C5);
			break;
		default:
			// ERROR!
			break;
	}
}

//------------Settings------------
// Menu functions based on cursor position
// Input: none
// Output: none
void Settings(uint32_t cursor_pos) {
	switch(cursor_pos) {
		case 1:
			ESP8266_Reset();
			break;
		case 2:
			ESP8266_Restore();
			break;
		case 3:
			if(!SERVER)
				ESP8266_QuitAccessPoint();
			else
				ESP8266_CIPClose();
			break;
		case 4:
			if(!SERVER) {
				ESP8266_JoinAccessPoint(""SSID, ""PASSKEY);
				ESP8266_MakeTCPConnection();
			} 	
			break;
		default:
			break;
	}
}
