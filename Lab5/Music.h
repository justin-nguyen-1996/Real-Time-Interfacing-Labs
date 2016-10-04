/* File Name:    DAC.c
 * Authors:      Justin Nguyen (jhn545), Trevor Murdock (ttm436)
 * Created:      10/1/2016
 * Last Revised: 10/4/2016
 * Description:  Contains functions for interfacing with the DAC.
 * 
 * Class Info: EE 445L, Section 16630
 * Lab Number: 5
 * TA: Dylan Zika
 *
 * Hardware Configurations:
 * ST7735R LCD:
 *     Backlight    (pin 10) connected to +3.3 V
 *     MISO         (pin 9)  unconnected
 *     SCK          (pin 8)  connected to PA2 (SSI0Clk)
 *     MOSI         (pin 7)  connected to PA5 (SSI0Tx)
 *     TFT_CS       (pin 6)  connected to PA3 (SSI0Fss)
 *     CARD_CS      (pin 5)  unconnected
 *     Data/Command (pin 4)  connected to PA6 (GPIO)
 *     RESET        (pin 3)  connected to PA7 (GPIO)
 *     VCC          (pin 2)  connected to +3.3 V
 *     Gnd          (pin 1)  connected to ground
 * TLV5616:
 *     DIN          (pin 1)  connected to PD3 (SSI3Tx)
 *     SCLK         (pin 2)  connected to PD0 (SSI3Clk)
 *     CS           (pin 3)  connected to GND
 *     FS           (pin 4)  connected to PD1 (SSI3Fss)
 *     AGND         (pin 5)  connected to GND
 *     REFIN        (pin 6)  connected to +1.5 V
 *     OUT          (pin 7)  connected to IN- of the amp (TPA731D)
 *     VDD          (pin 8)  connected to +3.3 V
 * TPA731D:
 *     SHUTDOWN     (pin 1)  unconnected
 *     BYPASS       (pin 2)  connected to positive terminal of CapB (3.3 uF), which is connected to ground
 *     IN+          (pin 3)  connected to positive terminal of CapB (3.3 uF), which is connected to ground
 *     IN-          (pin 4)  connected to RI (1k ohm) and RF (2.2k ohm)
 *     VO+          (pin 5)  connected to RF (2.2k ohm) and the speaker
 *     VDD          (pin 6)  connected to +5V
 *     GND          (pin 7)  connected to GND
 *     VO-          (pin 8)  connected to the speaker
 * LM4041:
 *     (looking at the flat edge on the bottom)
 *     FB           (pin 1)  connected to R1 (10k ohm) and R2 (220 ohm)
 *     +terminal    (pin 2)  connected to RS (20k ohm), R1 (10k ohm), and REFIN (1.5 V) of the TLV5616
 *     -terminal    (pin 3)  connected to R2 (220 ohm) and GND
 */
 
#ifndef __musich
#define __musich

#include <stdint.h>

typedef struct {
	uint16_t frequency;
	uint16_t length;
	uint8_t volume;
} Note;

#define SINE_GRANULARITY 64

//sine wave for generating sound
const unsigned short Sinewave[SINE_GRANULARITY] = {  
  1024,1122,1215,1302,1378,1440,1486,1514,1524,1514,1486,
  1440,1378,1302,1215,1122,1024,926,833,746,670,608,
  562,534,524,534,562,608,670,746,833,926
};
 
// Trumpet
const unsigned short Trumpetwave[SINE_GRANULARITY]={
  987, 1049, 1090, 1110, 1134, 1160, 1139, 1092, 1070, 1042, 1035, 1029, 1008, 1066, 1150, 1170, 1087, 915, 679, 372, 151, 
  558, 1014, 1245, 1260, 1145, 1063, 984, 934, 960, 1027, 1077, 1081, 1074, 1064, 1042, 1010, 974, 968, 974, 994, 1039, 
  1094, 1129, 1125, 1092, 1056, 1056, 1082, 1059, 1046, 1058, 1061, 1045, 1034, 1050, 1094, 1112, 1092, 1063, 1053, 1065, 1052, 992};

const uint16_t envelope[256] = { 
  16, 32, 64, 96, 128, 160, 192, 224, 256, 255, 254, 252, 250, 248,
  246, 244, 242, 240, 238, 237, 236, 235, 234, 233, 232, 231, 230, 229,
  228, 227, 226, 225, 224, 223, 222, 221, 220, 219, 218, 217, 216, 215,
  214, 213, 212, 211, 210, 209, 208, 207, 206, 205, 204, 203, 202, 201,
  200, 199, 198, 197, 196, 195, 194, 193, 192, 191, 190, 189, 188, 187,
  186, 185, 184, 183, 182, 181, 180, 179, 178, 177, 176, 175, 174, 173,
  172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159,
  158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148, 147, 146, 145,
  144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131,
  130, 129, 128, 127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117,
  116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103,
  102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86,
  85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68,
  67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50,
  49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32,
  31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14,
  13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 
};


// frequencies of notes 0th octave in clock ticks
// reference 20MHz clock speed
// to get the nth octave take (note >> n)
// value of zero defined as a rest
#define C  (4892966  / SINE_GRANULARITY)
#define Cs (4618937  / SINE_GRANULARITY)
#define Db (4618937  / SINE_GRANULARITY)
#define D  (4359673  / SINE_GRANULARITY)
#define Ds (4113110  / SINE_GRANULARITY)
#define Eb (4113110  / SINE_GRANULARITY)
#define E  (3883495  / SINE_GRANULARITY)
#define F  (3755868  / SINE_GRANULARITY)
#define Fs (3460207  / SINE_GRANULARITY)
#define Gb (3265306  / SINE_GRANULARITY)
#define G  (3265306  / SINE_GRANULARITY)
#define Gs (3081664  / SINE_GRANULARITY)
#define Ab (2909091  / SINE_GRANULARITY)
#define A  (2909091  / SINE_GRANULARITY)
#define As (2745367  / SINE_GRANULARITY)
#define Bb (2745367  / SINE_GRANULARITY)
#define B  (2591512  / SINE_GRANULARITY)



#define R  0

// lengths of notes in terms of 256th beats
// assume 4/4 time
// value of zero defined as a tempo change, defined in tempo array
#define W		 256	// whole
#define Hd	 192	// dotted half
#define H		 128	// half
#define Qd	 96	// dotted quarter
#define Q		 64	// quarter
#define Ethd 48	  // dotted eighth
#define Eth  32   // eighth
#define Sd	 24 	// dotted sixteenth
#define S		 16 	// sixteenth
#define Ht	 43 	// halfnote tripplet
#define Qt	 22	  // quarternote tripplet

#define Ch	 0

// volumes left shift values to the sine wave
// value of zero defined as previous declaration of volume
#define fForte	1
#define Forte   2
#define mForte  3
#define mPiano	4
#define Piano		5
#define pPiano	6

#define P			  0

const Note Song_Pirates[] = 
	{ 
// measures 1-6, Con bravura Q=168, The Black Perl
		{D>>5, Eth, mForte}, {R, Eth, P}, {D>>5, Eth, P}, {Eb>>5, Eth, P}, {D>>5, Eth, P}, {Eb>>5, Eth, P},
		{D>>5, Eth, P}, {R, Eth, P}, {D>>5, Eth, P}, {Eb>>5, Eth, mPiano}, {D>>5, Eth, P}, {Eb>>5, Eth, P},
		{D>>5, Eth, Piano}, {R, Eth, P}, {D>>5, Eth, P}, {Eb>>5, Eth, P}, {D>>5, Eth, P}, {Eb>>5, Eth, P},
		{D>>5, Eth, P}, {R, Eth, P}, {D>>5, Eth, P}, {Eb>>5, Eth, mPiano}, {F>>5, Eth, P}, {Eb>>5, Eth, P},
		{D>>5, Eth, mForte}, {R, Eth, P}, {D>>5, Eth, P}, {Eb>>5, Eth, P}, {D>>5, Eth, P}, {Eb>>5, Eth, P},
		{D>>5, Eth, P}, {R, Eth, P}, {D>>5, Eth, P}, {Eb>>5, Eth, P}, {D>>5, Eth, P}, {Eb>>5, Eth, P},

// measures 7-11
		{D>>5, Eth, P}, {R, Eth, P}, {D>>5, Eth, P}, {Eb>>5, Eth, P}, {D>>5, Eth, P}, {Eb>>5, Eth, P},
		{D>>5, Eth, P}, {R, Eth, P}, {D>>5, Eth, P}, {Eb>>5, Eth, P}, {F>>5, Eth, P}, {Eb>>5, Eth, P},
		{D>>5, Eth, P}, {R, Eth, P}, {D>>5, Eth, P}, {R, Eth, P}, {D>>5, Eth, P}, {R, Eth, P},
		{D>>6, Q, P}, {D>>6, Qt, P}, {D>>6, Qt, P}, {D>>6, Qt, P}, {D>>6, Qt, P}, {D>>6, Qt, P}, {D>>6, Qt, P},
		{E>>6, Q, P}, {E>>6, Qt, P}, {E>>6, Qt, P}, {E>>6, Qt, P}, {E>>6, Qt, P}, {E>>6, Qt, P}, {E>>6, Qt, P},

// measures 12-15.1
		{F>>6, Q, P}, {F>>6, Qt, P}, {F>>6, Qt, P}, {F>>6, Qt, P}, {F>>6, Qt, P}, {F>>6, Qt, P}, {F>>6, Qt, P},
		{G>>6, Q, P}, {A>>6, Q, P}, {Bb>>6, Q, P}, 
		{A>>6, Q, P}, {Bb>>6, Q, P}, {Cs>>7, Q, P}, 
		{D>>7, Q, P}, 

// measures 15.2-18, Q=196
		{R, Ch, Forte}, {D>>5, Eth, P}, {E>>5, Eth, P}, {F>>5, Eth, P}, {D>>5, Eth, P},
		{E>>5, Eth, P}, {R, Eth, P}, {D>>5, Eth, P}, {R, Eth, P}, {C>>5, Eth, P}, {R, Eth, P},
		{D>>5, Eth, P}, {R, Eth, P}, {D>>5, Eth, P}, {E>>5, Eth, P}, {F>>5, Eth, P}, {D>>5, Eth, P},
		{E>>5, Eth, P}, {R, Eth, P}, {F>>5, Eth, P}, {R, Eth, P}, {G>>5, Eth, P}, {R, Eth, P}, 

// measures 19-22
		{G>>5, Eth, P}, {R, Eth, P}, {G>>5, Eth, P}, {A>>5, Eth, P}, {Bb>>5, Eth, P}, {D>>5, Eth, P}, 
		{F>>5, Q, P}, {E>>5, Q, P}, {D>>5, Q, P}, 
		{E>>5, Q, P}, {D>>5, Q, P}, {C>>5, Q, P}, 
		{D>>5, Q, P}, {F>>5, Q, P}, {A>>5, Q, P}, 

// measures 23-26, Q=184
		{R, Ch, P}, {D>>6, Q, fForte}, {D>>6, Eth, P}, {E>>6, Eth, P}, {F>>6, Eth, P}, {D>>6, Eth, P}, 
		{E>>6, Q, P}, {D>>6, Q, P}, {C>>6, Q, P}, 
		{D>>6, Q, P}, {D>>6, Eth, P}, {E>>6, Eth, P}, {F>>6, Eth, P}, {D>>6, Eth, P}, 
		{E>>6, Q, P}, {F>>6, Q, P}, {G>>6, Q, P}, 
		
// measures 27-33
		{G>>6, Q, P}, {G>>6, Eth, P}, {A>>6, Eth, P}, {Bb>>6, Eth, P}, {G>>6, Eth, P}, 
	  {F>>6, Q, P}, {E>>6, Q, P}, {D>>6, Q, P}, 
		{E>>6, Q, P}, {D>>6, Q, P}, {C>>6, Q, P}, 
		{D>>6, Q, P}, {F>>6, Q, P}, {A>>6, Q, P}, 
		{A>>5, Hd, P}, 
		{Bb>>5, Hd, P}, 
		{A>>5, Eth, P}, {R, Eth, P}, {A>>5, Eth, P}, {R, Eth, P}, {A>>5, Eth, P}, {R, Eth, P}, 

// measures 34-39
		{A>>5, Eth, P}, {G>>5, Eth, P}, {G>>5, H, P}, 
		{G>>5, Q, P}, {G>>4, Eth, P}, {Bb>>4, Eth, P}, {D>>5, Eth, P}, {F>>5, Eth, P}, 
		{F>>5, Q, P}, {F>>4, Eth, P}, {C>>5, Eth, P}, {D>>5, Eth, P}, {F>>5, Eth, P}, 
		{E>>5, Eth, P}, {R, Eth, P}, {F>>5, Eth, P}, {R, Eth, P}, {E>>5, Eth, P}, {R, Eth, P}, 
		{D>>5, Q, P}, {A>>4, Qt, P}, {D>>5, Qt, P}, {F>>5, Qt, P}, {A>>5, Qt, P}, {D>>6, Qt, P}, {F>>6, Qt, P}, 
		{A>>6, Hd, P}, 
		
// measures 40-44		
		{Bb>>6, Hd, P}, 
		{A>>6, Eth, P}, {R, Eth, P}, {A>>6, Eth, P}, {R, Eth, P}, {A>>6, Eth, P}, {R, Eth, P}, 
		{A>>6, Eth, P}, {G>>6, Eth, P}, {G>>6, H, P}, 
		{A>>4, Eth, mPiano}, {A>>4, Eth, P}, {B>>4, Eth, P}, {B>>4, Eth, P}, {Cs>>5, Eth, P}, {Cs>>5, Eth, P}, 
		{D>>5, Eth, P}, {D>>5, Eth, P}, {E>>5, Eth, P}, {E>>5, Eth, P}, {F>>5, Eth, P}, {F>>5, Eth, P}, 
		
// measures 45-46
		{D>>5, Eth, mForte}, {D>>5, Eth, P}, {E>>5, Eth, P}, {E>>5, Eth, P}, {F>>5, Eth, P}, {F>>5, Eth, P},
		{Gb>>5, Eth, P}, {Gb>>5, Eth, P}, {G>>5, Eth, P}, {G>>5, Eth, P}, {Ab>>5, Eth, P}, {Ab>>5, Eth, P}, 

// measures 47-49, Q=164
	  {R, Ch, Forte}, {A>>5, Qd, P}, {B>>5, Eth, P}, {Cs>>6, Eth, P}, {D>>6, Eth, P}, {Ds>>6, Eth, P}, {E>>6, Eth, P}, 
		{F>>6, Qd, P}, {G>>6, Eth, P}, {G>>6, Q, P}, 
		{G>>6, Qd, P}, {F>>6, Eth, P}, {E>>6, Q, P}, 

// measures 50-55
		{F>>6, Q, P}, {G>>6, Q, P}, {A>>6, Q, P}, 
		{G>>6, H, P}, {F>>6, Eth, P}, {G>>6, Eth, P}, 
		{A>>6, Qd, P}, {G>>6, Eth, P}, {F>>6, Q, P}, 
		{E>>6, Eth, P}, {R, Eth, P}, {F>>6, Eth, P}, {R, Eth, P}, {E>>6, Eth, P}, {R, Eth, P}, 
		{D>>6, Ethd, P}, {R, Ethd, P}, {E>>6, Eth, P}, {Cs>>6, Eth, P}, {R, Eth, P}, 
		{D>>6, Hd, P},

// Stop
		{R, Ch, P}

	};

// tempos in terms of clock ticks (80MHz) 
// Zero tells program to stop
 const uint32_t Tempo_Pirates[] = { 446428, 382653, 407608, 457317, 0 }; // 168, 196, 184, 164 BPM

// tempos in terms of clock ticks (20MHz) 
// Zero tells program to stop
// const uint32_t Tempo_Pirates[] = { 111607, 95663, 101902, 114329, 0 }; // 168, 196, 184, 164 BPM



#endif

