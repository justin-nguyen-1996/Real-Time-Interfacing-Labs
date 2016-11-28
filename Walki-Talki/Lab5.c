// PeriodicTimer0AInts.c
// Runs on LM4F120/TM4C123
// Use Timer0A in periodic mode to request interrupts at a particular
// period.
// Daniel Valvano
// September 11, 2013

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2015
  Program 7.5, example 7.6

 Copyright 2015 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

// oscilloscope or LED connected to PF3-1 for period measurement
// When using the color wheel, the blue LED on PF2 is on for four
// consecutive interrupts then off for four consecutive interrupts.
// Blue is off for: dark, red, yellow, green
// Blue is on for: light blue, blue, purple, white
// Therefore, the frequency of the pulse measured on PF2 is 1/8 of
// the frequency of the Timer0A interrupts.

#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "PLL.h"
#include "DAC.h"
//#include "Switch.h"
#include "LED.h"
#include "Timer0.h"
#include "Timer1.h"
#include "Music.h"
#include "Button.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode
void menuISR(void);

const unsigned char sineWave2[256] = {
127,130,133,136,139,143,146,149,152,155,158,161,164,167,170,173,176,178,181,184,187,190,192,195,198,200,203,205,208,210,212,215,
217,219,221,223,225,227,229,231,233,234,236,238,239,240,242,243,244,245,247,248,249,249,250,251,252,252,253,253,253,254,254,254,
254,254,254,254,253,253,253,252,252,251,250,249,249,248,247,245,244,243,242,240,239,238,236,234,233,231,229,227,225,223,221,219,
217,215,212,210,208,205,203,200,198,195,192,190,187,184,181,178,176,173,170,167,164,161,158,155,152,149,146,143,139,136,133,130,
127,124,121,118,115,111,108,105,102, 99, 96, 93, 90, 87, 84, 81, 78, 76, 73, 70, 67, 64, 62, 59, 56, 54, 51, 49, 46, 44, 42, 39,
 37, 35, 33, 31, 29, 27, 25, 23, 21, 20, 18, 16, 15, 14, 12, 11, 10,  9,  7,  6,  5,  5,  4,  3,  2,  2,  1,  1,  1,  0,  0,  0,
  0,  0,  0,  0,  1,  1,  1,  2,  2,  3,  4,  5,  5,  6,  7,  9, 10, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 27, 29, 31, 33, 35,
 37, 39, 42, 44, 46, 49, 51, 54, 56, 59, 62, 64, 67, 70, 73, 76, 78, 81, 84, 87, 90, 93, 96, 99,102,105,108,111,115,118,121,124,
};

unsigned char output[44100] = {0};

const unsigned char Mary[] = {
setVolume,255,setWaveform,sine,setDelta,24000>>8,24000%256,
B4, A4, G4, A4,  B4, B4, longNote, 2, B4,  A4, A4, longNote, 2, A4,  B4, D5, longNote, 2, D5,
B4, A4, G4, A4,  B4, B4, B4, B4,           A4, A4, B4, A4,           longNote, 4, G4,
B4, A4, G4, A4,  B4, B4, longNote, 2, B4,  A4, A4, longNote, 2, A4,  B4, D5, longNote, 2, D5,
B4, A4, G4, A4,  B4, B4, B4, B4,           A4, A4, B4, A4,           longNote, 3, G4, D5,
B4, A4, G4, A4,  B4, B4, longNote, 2, B4,  A4, A4, longNote, 2, A4,  B4, D5, D5, D5,
B4, A4, G4, A4,  B4, B4, B4, B4,           A4, A4, B4, A4,           longNote, 3, G4, D5,
B4, A4, G4, A4,  B4, B4, longNote, 2, B4,  A4, A4, longNote, 2, A4,  B4, D5, D5, D5,
B4, A4, G4, A4,  B4, B4, B4, B4,           A4, A4, B4, A4,           longNote, 4, G4,
songEnd
};

const unsigned char BumbleBee[] = {
setVolume,255,
setWaveform,square,
setDelta,3600>>8,3600%256,
A6, Gs6, G6, Fs6, 	G6, Fs6, F6, E6, 	F6, E6, Eb6, D6, 	Cs6, C6, B5, Bb5, 
A5, Gs5, G5, Fs5, 	G5, Fs5, F5, E5, 	F5, E5, Ds5, D5, 	Cs5, C5, B4, Bb4, 
A4, Gs4, G4, Fs4, 	G4, Fs4, F4, E4, 	A4, Gs4, G4, Fs4, 	G4, Fs4, F4, E4, 
A4, Gs4, G4, Fs4, 	F4, Bb4, A4, Gs4, 	A4, Gs4, G4, Fs4, 	F4, Fs4, G4, Gs4, /* Start here again */
A4, Gs4, G4, Fs4, 	F4, Bb4, A4, Gs4, 	A4, Gs4, G4, Fs4, 	F4, Fs4, G4, Gs4,
A4, Gs4, G4, Fs4, 	G4, Fs4, F4, E4, 	F4, Fs4, G4, Gs4, 	A4, Bb4, A4, Gs4, 
A4, Gs4, G4, Fs4, 	G4, Fs4, F4, E4, 	F4, Fs4, G4, Gs4, 	A4, B4, C5, Cs5,
D5, Cs5, C5, B4, 	Bb4, Eb5, D5, Cs5, 	D5, Cs5, C5, B4, 	Bb4, B4, C5, Cs5, 
D5, Cs5, C5, B4, 	Bb4, Eb5, D5, Cs5, 	D5, Cs5, C5, B4, 	Bb4, B4, C5, Cs5,
D5, Cs5, C5, B4, 	C5, B4, Bb4, A4, 	Bb4, B4, C5, Cs5, 	D5, Eb5, D5, Cs5, 
D5, Cs5, C5, B4, 	C5, B4, Bb4, A4, 	Bb4, B4, C5, Cs5, 	D5, Eb5, D5, Cs5, 
D5, D4, D4, D4, 	D4, D4, D4, D4, 	chord, 2, Cs4, Eb4, D4, chord, 2, Cs4, Eb4, Eb5, 	chord, 2, Cs4, Eb4, D4, chord, 2, Cs4, Eb4, Eb5, 
chord, 2, D4, D5, D5, D5, D5, 	D5, D5, D5, D5, 	chord, 2, Cs5, Eb5, D5, chord, 2, Cs5, Eb5, Eb6, 	chord, 2, Cs5, Eb5, D5, chord, 2, Cs5, Eb5, Eb6, /* End of Measure 26 */
chord, 2, D5, D6, Eb5, D5, Cs5, 	D5, Eb5, D5, Cs5, 	D5, Eb5, D5, Cs5, 	D5, Eb5, D5, Cs5, 
chord, 2, Fs4, D5, chord, 2, D4, Eb5, chord, 2, Fs4, E5, chord, 2, D4, F5, 	chord, 2, Fs4, Fs5, chord, 2, D4, F5, chord, 2, Fs4, E5, chord, 2, D4, Eb5, 	chord, 2, Fs4, D5, chord, 2, D4, Eb5, chord, 2, Fs4, E5, chord, 2, D4, F5, 	chord, 2, Fs4, Fs5, chord, 2, D4, F5, chord, 2, Fs4, E5, chord, 2, D4, Eb5, 
D5, G4, G4, G4, 	G4, G4, G4, G4, 	chord, 2, Fs4, Ab4, G4, chord, 2 ,Fs4, Ab4, Ab5, 	chord, 2, Fs4, Ab4, G4, chord, 2, Fs4, Ab4, Ab5, 
chord, 2, G4, G4, G5, G5, G5, 	G5, G5, G5, G5, 	chord, 2, Fs5, Ab5, G5, chord, 2, Fs5, Ab5, Ab6, 	chord, 2, Fs5, Ab5, G5, chord, 2, Fs5, Ab5, Ab6, /* End of Measure 34 */
chord, 2, G5, G6, Ab5, G5, Fs5, 	G5, Ab5, G5, Fs5, 	G5, Ab5, G5, Fs5, 	G5, Ab5, G5, Fs5,  /* End of Measure 36 */
chord, 2, B4, G5, chord, 2, G4, Ab5, chord, 2, B4, A5, chord, 2, G4, Bb5, 	chord, 2, B4, B5, chord, 2, G4, Bb5, chord, 2, B4, A5, chord, 2, G4, Ab5, 	chord, 2, B4, G5, chord, 2, G4, Ab5, chord, 2, B4, A5, chord, 2, G4, Bb5, 	chord, 2, B4, B5, chord, 2, G4, Bb5, chord, 2, B4, A5, chord, 2, G4, Ab5, 
chord, 5, C4, Eb4, G4, C5, G5, Fs5, F5, E5, 	Eb5, Ab5, G5, Fs5, 	G5, Fs5, F5, E5, 	Eb5, E5, F5, Fs5, /* End of Measure 40 */
G5, Fs5, F5, E5, 	F5, E5, Eb5, D5, 	Eb5, E5, F5, Fs5, 	F5, Fs5, G5, Gs5, 
A5, Gs5, G5, Fs5, 	G5, Fs5, F5, E5, 	F5, E5, Eb5, D5, 	Cs5, C5, B4, Bb4, 
A4, Bb4, A4, Gs4, 	A4, Bb4, A4, Gs4, 	A4, Bb4, A4, Gs4, 	A4, Bb4, A4, Gs4, 
A4, Bb4, A4, Gs4, 	A4, Bb4, A4, Gs4, 	A4, Bb4, A4, Gs4, 	A4, Bb4, A4, Gs4, 
A4, Gs4, G4, Fs4, 	G4, Fs4, F4, E4, 	F4, E4, Eb4, D4, 	Cs4, C4, B3, Bb3, 
A3, Bb3, A3, Gs3, 	A3, Bb3, A3, Gs3, 	A3, Bb3, A3, Gs3, 	A3, Bb3, A3, Gs3, 
A3, Bb3, A3, Gs3, 	A3, Bb3, A3, Gs3, 	A3, Bb3, A3, Gs3, 	A3, Bb3, A3, Gs3, 
A3, Bb3, B3, C4, 	Cs4, D4, Ds4, E4, 	F4, Fs4, G4, Gs4, 	A4, Bb4, B4, C5, 
Cs5, D5, Ds5, E5, 	F5, Fs5, G5, Gs5, 	A5, Bb5, A5, Gs5, 	A5, Bb5, A5, Gs5, /* Jump back here */
chord, 3, D5, F5, A5, Gs5, G5, Fs5, 	F5, Bb5, A5, Gs5, 	A5, Gs5, G5, Fs5, 	F5, Fs5, G5, Gs5, 
chord, 3, D5, F5, A5, Gs5, G5, Fs5, 	F5, Bb5, A5, Gs5, 	A5, Gs5, G5, Fs5, 	F5, Fs5, G5, Gs5, /* Measure 61 */
A5, Gs5, G5, Fs5, 	G5, Fs5, F5, E5, 	F5, Fs5, G5, Gs5, 	A5, Bb5, A5, Gs5, 
A5, Gs5, G5, Fs5, 	G5, Fs5, F5, E5, 	F5, Fs5, G5, Gs5, 	A5, B5, C6, Cs6, 
D6, Cs6, C6, B5, 	Bb5, Eb6, D6, Cs6, 	D6, Cs6, C6, B5, 	Bb5, B5, C6, Cs6, /* Measure 68 */
D6, Cs6, C6, B5, 	Bb5, Eb6, D6, Cs6, 	D6, Cs6, C6, B5, 	Bb5, B5, C6, Cs6, 
D6, Cs6, C6, B5, 	C6, B5, Bb5, A5, 	Bb5, B5, C6, Cs6, 	D6, Eb6, D6, Cs6, 
D6, Cs6, C6, B5, 	Bb5, B5, C6, Cs6, 	D6, E6, F6, G6, 	A6, Bb6, A6, Gs6, /* 8va section */
A6, Gs6, G6, Fs6, 	F6, Bb6, A6, Gs6, 	A6, Gs6, G6, Fs6, 	F6, Fs6, G6, Gs6, /* Measure 78 */
A6, Gs6, G6, Fs6, 	F6, Bb6, A6, Gs6, 	A6, Gs6, G6, Fs6, 	F6, Fs6, G6, Gs6, 
longNote, 2, A6, Cs6, D6, 	Eb6, E6, F6, Fs6, 	G6, Fs6, F6, E6,	F6, E6, Eb6, D6, 
Cs6, D6, Ds6, E6, 	F6, Fs6, G6, Gs6, 	A6, Bb6, A6, Gs6, 	A6, Bb6, A6, Gs6, 
longNote, 2, A7, Cs5, D5,	Eb5, E5, F5, Fs5, 	G5, Fs5, F5, E5,	F5, E5, Eb5, D5, /* Measure 84 */
Cs5, D5, Ds5, E5, 	F5, Fs5, G5, Gs5, 	A5, Bb5, A5, Gs5, 	A5, B5, C6, Cs6, 
D6, Cs6, C6, B5, 	C6, B5, Bb5, A5, 	Bb5, A5, Gs5, G5, 	Fs5, F5, E5, Eb5, 
D5, Cs5, C5, B4, 	C5, B4, Bb4, A4, 	Bb4, A4, Gs4, G4, 	Fs4, F4, E4, Eb4, /* Measure 90 */
chord, 4, D3, F3, A3, D4, Eb4, D4, Cs4, 	chord, 2, Cs4, Eb4, D4, chord, 2, Cs4, Eb4, Eb5, 	D4, Eb4, chord, 2, Cs4, D4, E4, 	chord, 2, C4, D4, F4, chord, 2, Bb4, D4, G4, /* End of 92 */
chord, 4, D3, F3, A3, A4, Bb4, A4, Gs4, 	chord, 2, Gs4, Bb4, chord, 2, A4, A5, chord, 2, Gs4, Bb4, Bb5, 	chord, 2, A4, A5, Bb4, chord, 2, G4, A4, chord, 2, B4, B5, 	chord, 2, F4, A4, chord, 2, C5, C6, chord, 3, E4, G4, A4, chord, 2, Cs5, Cs6, 
longNote, 2, chord, 2, D5, D6, RS, RS, 	A3, Bb3, B3, C4, 	Cs4, D4, Eb4, E4, 	F4, Fs4, G4, Gs4, 
A4, Bb4, B4, C5, 	Cs5, D5, Eb5, E5, 	F5, Fs5, G5, Gs5, 	A5, B5, C6, Cs6, 
longNote, 8, chord, 3, F5, A5, D6,	longNote, 8, chord, 4, D6, F6, A6, D7, 	longNote, 4, chord, 2, D4, D5, RS, RS, RS, RS,
songEnd
};

const unsigned char BumbleBee2[] = {
setVolume,255,
setWaveform,square,
setDelta, 7200>>8, 7200%256,
chord, 4, A3, Cs4, E4, A4, longRest, 3, longRest, 4, 
chord, 4, A2, E3, G3, A3, longRest, 3, longRest, 4,
longRest, 4, longRest, 4, /* End of Measure 6 */
chord, 3, D3, F3, A3, longRest, 3, chord, 3, D3, F3, A3, RS, chord, 3, D3, G3, B3, RS,
chord, 3, D3, F3, A3, longRest, 3, chord, 3, D3, F3, A3, RS, chord, 3, D3, G3, B3, RS, /* End of Measure 10 */
chord, 3, D3, F3, A3, RS, chord, 3, D3, G3, Bb3, RS, chord, 3, D3, F3, A3, RS, chord, 4, Cs3, E3, G3, A3, RS,
chord, 3, D3, F3, A3, RS, chord, 3, D3, G3, Bb3, RS, chord, 3, D3, F3, A3, RS, chord, 4, E3, G3, A3, Cs4, RS, 
chord, 3, D3, Fs3, Cs4, RS, chord, 3, D3, G3, Bb3, RS, chord, 3, G3, Bb3, D4, RS, chord, 3, G3, C4, E4, RS, /* End of Measure 16 */
chord, 3, G3, Bb3, D4, longRest, 3, chord, 3, G3, Bb3, D4, RS, chord, 3, G3, C4, E4, RS, 
chord, 3, G3, Bb3, D4, RS, chord, 3, G3, C4, Eb4, RS, chord, 3, G3, Bb3, D4, RS, chord, 3, A3, C4, D4, RS, 
chord, 3, G3, Bb3, D4, RS, chord, 3, G3, C4, Eb4, RS, chord, 3, G3, Bb3, D4, RS, chord, 3, Fs3, C4, D4, RS, /* End of Measure 22 */ 
chord, 2, G3, Bb3, longRest, 3, longRest, 4, /* End of Measure 24 */
longRest, 4, longRest, 4, 
longRest, 4, D4, chord, 2, Cs4, Eb4, chord, 2, C4, E4, chord, 2, B4, F4, /* End of Measure 28 */
longNote, 4, Bb3, longNote, 4, Bb3, 
chord, 3, B4, D4, G4, longRest, 3, longRest, 4, 
longRest, 4, longRest, 4, /* End of Measure 34 */
longRest, 4, G4, chord, 2, Fs4, Ab4, chord, 2, F4, A4, chord, 2, E4, Bb4, 
longNote, 4, Eb3, longNote, 4, Eb3, /* End of Measure 38 */
longRest, 4, chord, 3, Eb4, G4, C5, RS, chord, 3, F4, Ab4, C5, RS, 
chord, 3, Eb4, G4, C5, RS, chord, 3, B3, F4, Ab4, RS, chord, 3, C4, Eb4, G4, RS, chord, 2, Bb3, D4, RS, /* End of Measure 42 */
chord, 3, A3, Cs4, G4, RS, longNote, 2, A4, longNote, 2, A4, A4, RS, 
A4, RS, A4, F4, D4, Bb3, D4, F4, 
A4, RS, chord, 2, A3, A4, chord, 2, F3, F4, chord, 2, D3, D4, chord, 2, Bb2, Bb3, chord, 2, D3, D4, chord, 2, F3, F4, 
chord, 2, A3, A4, longRest, 3, longRest, 4, /* End of Measure 50 */
longRest, 2, chord, 2, A2, A3, chord, 2, F2, F3, chord, 2, D2, D3, chord, 2, Bb1, Bb2, chord, 2, D2, D3, chord, 2, F2, F3, 
longNote, 2, chord, 2, A2, A3, A4, F4, D4, Bb3, D4, F4, 
longNote, 4, A4, longNote, 4, chord, 2, A4, A5, /* End of Measure 56 */
longNote, 2, chord, 2, A4, A5, longNote, 2, chord, 2, A3, A4, longNote, 4, A3, /* End of Repeat */
chord, 2, D2, D3, longRest, 3, chord, 2, D2, D3, RS, chord, 3, G3, B3, D4, RS, 
chord, 2, D2, D3, longRest, 3, chord, 2, D2, D3, RS, chord, 3, G3, B3, D4, RS, /* End of Measure 62 */
chord, 3, D3, F3, A3, RS, chord, 3, Bb2, D3, G3, RS, chord, 3, A2, D3, F3, RS, chord, 4, Cs3, E3, G3, A3, RS, 
chord, 3, D3, F3, A3, RS, chord, 3, Bb2, D3, G3, RS, chord, 3, A2, D3, F3, RS, chord, 4, Cs3, E3, G3, A3, RS, /* End of Measure 66 */
chord, 3, D3, Fs3, C4, RS, chord, 2, G3, D4, RS, chord, 3, G3, Bb3, D4, RS, chord, 3, E3, G3, C4, RS, 
chord, 3, G3, Bb3, D4, longRest, 3, chord, 3, G3, Bb3, D4, RS, chord, 3, E3, G3, C4, RS, /* End of Measure 70 */
chord, 3, G3, Bb3, D4, RS, chord, 3, Eb3, G3, C4, RS, chord, 3, D3, G3, Bb3, RS, chord, 4, C3, D3, Fs3, A3, RS, 
chord, 3, Bb2, D3, G3, RS, chord, 3, G3, Bb3, D4, RS, chord, 3, F4, Bb4, D5, RS, chord, 3, E4, G4, Cs5, RS, /* 8va section */
chord, 3, D4, F4, A4, chord, 3, F4, A4, D5, longRest, 2, chord, 3, D4, F4, A4, RS, chord, 3, B3, D4, G4, RS, 
chord, 3, D4, F4, A4, chord, 3, F4, A4, D5, longRest, 2, chord, 3, D4, F4, A4, RS, chord, 3, B3, D4, G4, RS, /* End of Measure 78 */
chord, 3, D4, F4, A4, RS, D6, Bb5, G5, E5, G5, B5, 
D6, longRest, 3, chord, 4, A4, Cs5, G5, A5, longRest, 3, /* End of Measure 82 */
chord, 2, D5, F5, RS, D7, Bb6, G6, E6, G6, Bb6, 
D7, longRest, 3, chord, 4, A3, Cs4, G4, A4, longRest, 3, 
chord, 3, D4, F4, A4, RS, chord, 4, D4, Fs4, C5, D5, RS, chord, 3, D4, G4, Bb4, longRest, 3, /* End of Measure 88 */
chord, 3, D3, F3, A3, RS, chord, 3, D3, Fs3, A3, RS, chord, 3, D3, G3, Bb3, longRest, 3, 
chord, 3, D3, F3, A3, longRest, 3, longRest, 4, 
longRest, 4, longRest, 4, /* End of Measure 94 */
chord, 3, D4, F4, A4, longRest, 3, longRest, 4, 
chord, 3, D4, F4, A4, longRest, 3, chord, 3, A4, D5, A5, longRest, 3, /* End of Measure 98 */
chord, 2, F4, A4, longRest, 3, longNote, 2, chord, 3, D4, F4, A4, RS, RS, longNote, 2, chord, 2, Bb3, Bb4, RS, RS,
songEnd
};

const unsigned char Test[] = {
setVolume,255,
setWaveform,square,
setDelta,12000>>8,12000%256,
C3,D3,E3,G3, C4,D4,E4,G4, C5,D5,E5,G5, C6,D6,E6,G6, C7,D7,E7,G7,
E7,D7,C7,G6, E6,D6,C6,G5, E5,D5,C5,G4, E4,D4,C4,G3, E3,D3,C3,G2,
songEnd
};

const unsigned char Test2[] = {
setVolume,127,
setWaveform,square,
setDelta,6000>>8,6000%256,
RS,
setDelta,12000>>8,12000%256,
C3,D3,E3,G3, C4,D4,E4,G4, C5,D5,E5,G5, C6,D6,E6,G6, C7,D7,E7,G7,
E7,D7,C7,G6, E6,D6,C6,G5, E5,D5,C5,G4, E4,D4,C4,G3, E3,D3,C3,G2,
songEnd
};

unsigned char noSong[] = {songEnd};

struct Song BeeSong = {.channel[0] = &BumbleBee[0], .channel[1] = &BumbleBee2[0], .sampleRate = 48000};
struct Song MarySong = {.channel[0] = &Mary[0], .length = 144*24000, .sampleRate = 48000};
struct Song TestSong = {.channel[0] = &Test[0], .channel[1] = &Test2[0], .length = 144*24000, .sampleRate = 48000};

//test functions
void testDAC(void);
uint32_t countDAC=0;

int main(void){ 
  PLL_Init(Bus80MHz);
	LED_Init();
	DAC_Init();
	Button_Init();
	Timer1_Init(&menuISR,80000);//80MHz/1kHz = 80,000
	//Switch_Init();
	//Timer0_Init(&testDAC,800000);// 80MHz/44.1kHz
	//Timer0_Enable();
	LED_Red_On();
	
	Music_Init();
	Music_SetSong(BeeSong);
	//Music_Play();
	
	while(1);
/*	
	while(1){
		while(bPlay){
			if(!bPlay){
				if(playPause){
					Music_Pause();
					playPause=0;
				}
				else{
					Music_Play();
					playPause=1;
				}
			}
		}
		while(bStop){
			if(!bStop)
			{
				Music_Stop();
				playPause=0;
			}
		}
		while(bWave){
			if(!bWave)
			{
				Music_ChangeWave();
			}
		}
			
	}
	*/
}

#define bPlay   (Button_Pressed()&0x04)
#define bStop   (Button_Pressed()&0x08)
#define bSong   (Button_Pressed()&0x01)
#define bWave   (Button_Pressed()&0x02)
int playPause = 0; //0=pause, 1=play
void menuISR(void){
	Button_Update();
	if(bPlay){
		if(playPause){
			Music_Pause();
			playPause=0;
		}
		else{
			Music_Play();
			playPause=1;
		}
	}
	else if(bStop){
		Music_Stop();
		playPause=0;
	}
	else if(bWave){
		Music_ChangeWave();
	}
}

//unsigned int rate = (20<<8)*12/44100;
const unsigned int value[] = {0,1,2,4,8,16,32,64,128,256,512,1024,2048};
void testDAC(void){
	LED_Red_Toggle();
	LED_Red_Toggle();
	//unsigned int index = (countDAC*rate>>8)%12;
	//DAC_Out(sineWave2[index]<<2);
	DAC_Out(value[countDAC%13]);
	if(countDAC%13==0){
		LED_Blue_On();
	}
	if(countDAC%13==1){
		LED_Blue_Off();
	}
	/*
	DAC_Out(value);
	if(value == 0)
		value = 1;
	else if(value == (1<<11))
		value = 0;
	else
		value = value << 1;
		*/
		
	LED_Red_Toggle();
	countDAC++;
}

