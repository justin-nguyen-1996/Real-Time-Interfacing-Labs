//main.c
//Dung Nguyen
//Wally Guzman

#include "tm4c123gh6pm.h"
#include <stdint.h>
#include <stdlib.h>
#include "PLL.h"
#include "LED.h"
#include "Timer0.h"
#include "Timer1.h"
#include "UART1.h"
#include "Button.h"
#include "ESP8266.h"
#include "Menu.h"
#include "ADC.h"
#include "DAC.h"
#include "Settings.h"
#include "Tone.h"

char *audioData;
int audioData0 = 0;
int audioData1 = 0;
int audioFlag = 0;
int audioCount = 0;
int audioReady = 0;
int audioPlaying = 0;
int audioTimeout = 0;
int ADCvals = 0;

//------------sendValue------------
// Send 8-bit value to ESP8266 over UART 
// Input: none
// Output: none
void sendValue(void) {
	if(ADCvals == 0) {
		ADC_ResetGet();
		DelayMs(25); 
		LED_Yellow_Toggle();
		ESP8266_StartSend(800);
	}
	int value = ADC_GetValue();
	if(value == -1)
		return;
	value >>= 4;
	if(Menu_SendState())
		UART1_OutChar(value & 0xFF);
	else
		UART1_OutChar(Tone_GetSample());
	ADCvals++;
	if(ADCvals >= 800)
		ADCvals = 0;
}

//------------sendDefaultADC------------
// Fill remaining space in buffer with default ADC value
// Input: none
// Output: none
void sendDefaultADC(void) {
	for(int i = ADCvals; i < 800; i++) {
		UART1_OutChar((char) 128);
	}
	ADCvals = 0;
}

//------------playAudio------------
// Play audio from buffer
// Input: none
// Output: none
void playAudio(void) {
	audioTimeout++;
	if(audioPlaying) {
		char DACValue = 0;
		audioTimeout = 0;
		(audioFlag) ? (DACValue = audioData[(audioData1 + audioCount) & (BUFFER_SIZE - 1)]) : 
		              (DACValue = audioData[(audioData0 + audioCount) & (BUFFER_SIZE - 1)]);
		Menu_UpdateDACValue(DACValue);
		DAC_Out(DACValue << 4);
		audioCount++;
		if(audioCount == 400)  {
			LED_Green_On();
			audioReady = 0;
		} else if(audioCount == 800) {
			LED_Green_Off();
			audioCount = 0;
			audioPlaying = 0;
			audioFlag = !audioFlag;
		}
	} 
	else
		if(audioReady)
			audioPlaying = 1;
}

//------------Transmit_Init------------
// Initialize the ADC to 8kHz
// Input: none
// Output: none
void Transmit_Init(void) {
	ADC_Init(10000);	// 80MHz/10kHz = 8kHz
}

//------------Receive_Init------------
// Initialize DAC and timer to play audio data
// Input: none
// Output: none
void Receive_Init(void) {
	DAC_Init();
	Timer1_Init(&playAudio, 10000);
	audioData = ESP8266_GetRXBuffer();
	Timer1_Enable();
}

//------------canTransmit------------
// Return whether the current Walkie-Talkie can start transmitting
// Transmit button must be pressed, more than 150 ms since the last reception,
// and connected to other Walkie-Talkie
// Input: none
// Output: 1 if yes, 0 if no
int canTransmit(void) {
	static int readyTransmit = 0;
	if(SERVER) {
		if(!readyTransmit)
			readyTransmit = ESP8266_CheckConnection();
	}
	if(!Button_Transmit() && ADCvals > 0)
		sendDefaultADC();
	return ((readyTransmit || !SERVER) && Button_Transmit() && audioTimeout > 1200);
}

//------------Transmit------------
// Send value to ESP8266 over UART
// Input: none
// Output: none
void Transmit(void) {
	sendValue();
}

//------------canReceive------------
// Check if packet of 800 audio samples exists in buffer
// Input: none
// Output: 1 if new data
int canReceive(void) {
	return ESP8266_GetAudio();
}

//------------Receive------------
// Set audio buffer for output and indicate new audio data
// Input: none
// Output: none
void Receive(int newIndex) {
	audioReady = 1;
	if(!audioFlag)
		audioData1 = newIndex;
	else
		audioData0 = newIndex;
}

int main(void) {
	PLL_Init(Bus80MHz);
	UART1_Init(BAUDRATE);
	LED_Init();
	Button_Init();
	Menu_Init();
	ESP8266_Init();
	Timer0_Init(&Button_Update, 8000000);	//.25 seconds
	Transmit_Init();
	Receive_Init();
	Timer0_Enable();
	
	int index = NORESPONSE;
	while(1) {
		index = canReceive();
		if(index != NORESPONSE) // Only start reception if we received a packet
			Receive(index);
		if(canTransmit())
			Transmit();
		Menu_Update();
	}
}
