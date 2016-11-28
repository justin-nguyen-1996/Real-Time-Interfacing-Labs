#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "PLL.h"
#include "LED.h"
#include "Timer0.h"
#include "Timer1.h"
#include "UART0.h"
#include "UART1.h"
#include "Audio.h"
#include "Button.h"
#include "Draw.h"
#include "ESP8266.h"
#include "Button.h"
#include "Menu.h"
#include "ST7735.h"
#include "HeartBeat.h"
#include <stdlib.h>
#include "ADC.h"
#include "DAC.h"
#include "Settings.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

char *audioData;
int audioData0;
int audioData1;
int audioFlag = 0;
int audioCount = 0;
int audioReady = 0;
int audioPlaying = 0;
int audioTimeout = 0;

void sendPacket(void){
	ESP8266_SendPacket(".");
}

void Button_ISR(void){
	Button_Update();
}

int ADCvals = 0;
void sendADCValue(void) {
	if(ADCvals == 0) {
		ADC_ResetGet();
		DelayMs(25); 
		LED_Yellow_Toggle();
		ESP8266_StartSend(800);
		//DelayMs(10);
	}
	int value = ADC_GetValue();
	if(value == -1)
		return;
	value >>= 4;
	UART1_OutChar(value & 0xFF);
	ADCvals++;
	if(ADCvals >= 800)
		ADCvals = 0;
}

void sendDefaultADC(void) {
	for(int i = ADCvals; i < 800; i++) {
		UART1_OutChar(128);
	}
	ADCvals = 0;
}

void playAudio(void) {
	audioTimeout++;
	if(audioPlaying) {
		audioTimeout = 0;
		if(audioFlag) {
			DAC_Out(audioData[(audioData1 + audioCount) % BUFFER_SIZE]);
			audioCount++;
			if(audioCount == 400)  {
				LED_Green_On();
				audioReady = 0;
			}
			if(audioCount == 800) {
				LED_Green_Off();
				audioCount = 0;
				audioPlaying = 0;
				audioFlag = 0;
			}
		} else {
			DAC_Out(audioData[(audioData0 + audioCount) % BUFFER_SIZE]);
			audioCount++;
			if(audioCount == 400) {
				LED_Green_On();
				audioReady = 0;
			}
			if(audioCount == 800) {
				LED_Green_Off();
				audioCount = 0;
				audioPlaying = 0;
				audioFlag = 1;
			}
		} 
	} 
	else {
		if(audioReady) {
			audioPlaying = 1;
			audioCount = 0;
			if(audioFlag)
				DAC_Out(audioData[audioData0]);
			else
				DAC_Out(audioData[audioData1]);
			audioCount++;
		}
	}
}


void mainTestADCtoESP(void) {
	int readyTransmit = 0;
	int drawConnect = 0;
	
	PLL_Init(Bus80MHz);
	UART1_Init(BAUDRATE);
	ADC_Init(10000);
	ST7735_InitR(INITR_REDTAB);
	ST7735_FillScreen(ST7735_BLACK);
	Menu_Init();
	ESP8266_Init();
	LED_Init();
	Button_Init();
	Timer0_Init(&Button_ISR, 8000000);//.25 seconds

	Timer0_Enable();
	
	while(1) {
		if(!readyTransmit){
			readyTransmit = ESP8266_CheckConnection();
		} else {
			if(!drawConnect) {
					drawConnect = 1;
					ST7735_DrawString(0, 0, "Connected", ST7735_CYAN);
				}
			}
		if(readyTransmit && Button_Transmit()) {
			sendADCValue();
		}
		else if(readyTransmit && !Button_Transmit() && ADCvals > 0) {
			sendADCValue();
		}
		Menu_Update();
	}
}

void mainTestESPtoDAC(void) {
	int index = -1;
	PLL_Init(Bus80MHz);
	UART1_Init(BAUDRATE);
	LED_Init();
	DAC_Init();
	Button_Init();
	ST7735_InitR(INITR_REDTAB);
	ST7735_FillScreen(ST7735_BLACK);
	Menu_Init();
	ESP8266_Init();
	Timer0_Init(&Button_ISR, 8000000);//.25 seconds
	Timer1_Init(&playAudio, 10000);
	
	audioData = ESP8266_GetRXBuffer();
	Timer1_Enable();
	Timer0_Enable();
	
	while(1) {
		index = ESP8266_GetAudio();
		if(index != -1) {
			audioReady = 1;
			if(!audioFlag)
				audioData1 = index;
			else
				audioData0 = index;
		}
		Menu_Update();
	}
}

void mainServer(void) {
	int readyTransmit = 0;
	int drawConnect = 0;
	int index = -1;
	PLL_Init(Bus80MHz);
	UART1_Init(BAUDRATE);
	ADC_Init(10000);
	DAC_Init();
	ST7735_InitR(INITR_REDTAB);
	ST7735_FillScreen(ST7735_BLACK);
	Menu_Init();
	ESP8266_Init();
	LED_Init();
	Button_Init();
	Timer0_Init(&Button_ISR, 8000000);//.25 seconds
	Timer1_Init(&playAudio, 10000);
	audioData = ESP8266_GetRXBuffer();
	
	Timer0_Enable();
	Timer1_Enable();
	
	while(1) {
		index = ESP8266_GetAudio();
		if(index != -1) {
			audioReady = 1;
			if(!audioFlag)
				audioData1 = index;
			else
				audioData0 = index;
		}
		if(!readyTransmit){
			readyTransmit = ESP8266_CheckConnection();
		} else {
			if(!drawConnect) {
					drawConnect = 1;
					ST7735_DrawString(0, 0, "Connected", ST7735_CYAN);
				}
			}
		if(readyTransmit && Button_Transmit() && audioTimeout > 1200) {
			sendADCValue();
		}
		/* else if(readyTransmit && !Button_Transmit() && ADCvals > 0) {
			sendADCValue();
		} */
		Menu_Update();
	}
}

void mainClient(void) {
	int index = -1;
	int drawConnect = 0;
	PLL_Init(Bus80MHz);
	UART1_Init(BAUDRATE);
	LED_Init();
	ADC_Init(10000);
	DAC_Init();
	Button_Init();
	ST7735_InitR(INITR_REDTAB);
	ST7735_FillScreen(ST7735_BLACK);
	Menu_Init();
	ESP8266_Init();
	Timer0_Init(&Button_ISR, 8000000);//.25 seconds
	Timer1_Init(&playAudio, 10000);
	
	audioData = ESP8266_GetRXBuffer();
	Timer1_Enable();
	Timer0_Enable();

	while(1) {
		index = ESP8266_GetAudio();
		if(index != -1) {
			audioReady = 1;
			if(!audioFlag)
				audioData1 = index;
			else
				audioData0 = index;
		}
		if(Button_Transmit() && audioTimeout > 1200) {
			sendADCValue();
		}
		Menu_Update();
	}
}


int main(void) {
	int index = -1;
	int drawConnect = 0;
	int readyTransmit = 0;
	PLL_Init(Bus80MHz);
	UART1_Init(BAUDRATE);
	LED_Init();
	ADC_Init(10000);
	DAC_Init();
	Button_Init();
	ST7735_InitR(INITR_REDTAB);
	ST7735_FillScreen(ST7735_BLACK);
	Menu_Init();
	ESP8266_Init();
	Timer0_Init(&Button_ISR, 8000000);//.25 seconds
	Timer1_Init(&playAudio, 10000);
	
	audioData = ESP8266_GetRXBuffer();
	Timer1_Enable();
	Timer0_Enable();
	
	while(1) {
		index = ESP8266_GetAudio();
		if(index != -1) {
			audioReady = 1;
			if(!audioFlag)
				audioData1 = index;
			else
				audioData0 = index;
		}
		if(SERVER) {
			if(!readyTransmit){
				readyTransmit = ESP8266_CheckConnection();
			} else {
				if(!drawConnect) {
						drawConnect = 1;
						ST7735_DrawString(0, 0, "Connected", ST7735_CYAN);
					}
				}
		}
		if((readyTransmit || !SERVER) && Button_Transmit() && audioTimeout > 1200) {
			sendADCValue();
		}
		Menu_Update();
	}
}


void mainTestADC(void){
	PLL_Init(Bus80MHz);
	ST7735_InitR(INITR_REDTAB);
	ST7735_FillScreen(ST7735_GREEN);
	Timer0_Init(&Button_ISR, 80000);//1000Hz
	ADC_Init(80000);
	Timer0_Enable();
	
	int y_ = 0;
	
	while(1){
		if(1){
			ST7735_DrawFastHLine(0,(y_+1)%160,128,ST7735_BLACK);
			ST7735_DrawPixel((ADC_GetValue()*128)>>12,y_%160,ST7735_BLUE);
			y_++;
		}
	}
}

int main1(void) {
	//mainTestADC();
	//mainTestADCtoESP();
	//mainTestESPtoDAC();
	mainClient();
	//mainServer();
}
