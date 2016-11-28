//Audio.c
//Dung Nguyen
//Wally Guzman

#include <stdint.h>
#include "Music.h"
#include "LED.h"
#include "DAC.h"
#include "ADC.h"
#include "Timer0.h"
#include "Audio.h"

#define BUFFER_SIZE 1024
char AudioInBuffer[BUFFER_SIZE];
char AudioOutBuffer[BUFFER_SIZE];
uint32_t AudioInIndex = 0;
uint32_t AudioOutIndex = 0;

void Audio_Init(void) {
	DAC_Init();
	//ADC_Init();
}

void Audio_In(uint32_t TXsample) {
	AudioInBuffer[AudioInIndex] = TXsample >> 4;
	AudioInIndex++;
	AudioInIndex %= BUFFER_SIZE;
}

void Audio_Out(char RXsample) {
	AudioOutBuffer[AudioOutIndex] = RXsample << 4;
	AudioOutIndex++;
	AudioOutIndex %= BUFFER_SIZE;
}
