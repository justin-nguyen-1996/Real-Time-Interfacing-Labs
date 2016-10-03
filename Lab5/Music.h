#ifndef __musich
#define __musich

#include <stdint.h>

typedef struct {
	uint16_t freqency;
	uint16_t length;
	uint8_t volume;
} Note;

#define SINE_GRANULARITY 32

//sine wave for generating sound
const unsigned short Sinewave[32] = {  
  1024,1122,1215,1302,1378,1440,1486,1514,1524,1514,1486,
  1440,1378,1302,1215,1122,1024,926,833,746,670,608,
  562,534,524,534,562,608,670,746,833,926
}; 

// frequencies of notes 0th octave in clock ticks
// reference 80MHz clock speed
// to get the nth octave take (note >> n)
// value of zero defined as a rest
#define C  (4892966 / SINE_GRANULARITY)
#define Cs (4618937 / SINE_GRANULARITY)
#define D  (4359673 / SINE_GRANULARITY)
#define Eb (4113110 / SINE_GRANULARITY)
#define E  (3883495 / SINE_GRANULARITY)
#define F  (3755868 / SINE_GRANULARITY)
#define Fs (3460207 / SINE_GRANULARITY)
#define G  (3265306 / SINE_GRANULARITY)
#define Gs (3081664 / SINE_GRANULARITY)
#define A  (2909091 / SINE_GRANULARITY)
#define Bb (2745367 / SINE_GRANULARITY)
#define B  (2591512 / SINE_GRANULARITY)

#define R  0

// lengths of notes in terms of 64th beats
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
		{D>>3, Eth, mForte}, {R, Eth, P}, {D>>3, Eth, P}, {Eb>>3, Eth, P}, {D>>3, Eth, P}, {Eb>>3, Eth, P},
		{D>>3, Eth, P}, {R, Eth, P}, {D>>3, Eth, P}, {Eb>>3, Eth, mPiano}, {D>>3, Eth, P}, {Eb>>3, Eth, P},
		{D>>3, Eth, Piano}, {R, Eth, P}, {D>>3, Eth, P}, {Eb>>3, Eth, P}, {D>>3, Eth, P}, {Eb>>3, Eth, P},
		{D>>3, Eth, P}, {R, Eth, P}, {D>>3, Eth, P}, {Eb>>3, Eth, mPiano}, {F>>3, Eth, P}, {Eb>>3, Eth, P},
		{D>>3, Eth, mForte}, {R, Eth, P}, {D>>3, Eth, P}, {Eb>>3, Eth, P}, {D>>3, Eth, P}, {Eb>>3, Eth, P},
		{D>>3, Eth, P}, {R, Eth, P}, {D>>3, Eth, P}, {Eb>>3, Eth, P}, {D>>3, Eth, P}, {Eb>>3, Eth, P},

// measures 7-11
		{D>>3, Eth, P}, {R, Eth, P}, {D>>3, Eth, P}, {Eb>>3, Eth, P}, {D>>3, Eth, P}, {Eb>>3, Eth, P},
		{D>>3, Eth, P}, {R, Eth, P}, {D>>3, Eth, P}, {Eb>>3, Eth, P}, {F>>3, Eth, P}, {Eb>>3, Eth, P},
		{D>>3, Eth, P}, {R, Eth, P}, {D>>3, Eth, P}, {R, Eth, P}, {D>>3, Eth, P}, {R, Eth, P},
		{D>>4, Q, P}, {D>>4, Qt, P}, {D>>4, Qt, P}, {D>>4, Qt, P}, {D>>4, Qt, P}, {D>>4, Qt, P}, {D>>4, Qt, P},
		{E>>4, Q, P}, {E>>4, Qt, P}, {E>>4, Qt, P}, {E>>4, Qt, P}, {E>>4, Qt, P}, {E>>4, Qt, P}, {E>>4, Qt, P},

// measures 12-15.1
		{F>>4, Q, P}, {F>>4, Qt, P}, {F>>4, Qt, P}, {F>>4, Qt, P}, {F>>4, Qt, P}, {F>>4, Qt, P}, {F>>4, Qt, P},
		{G>>4, Q, P}, {A>>4, Q, P}, {Bb>>4, Q, P}, 
		{A>>4, Q, P}, {Bb>>4, Q, P}, {Cs>>5, Q, P}, 
		{D>>5, Q, P}, 

// measures 15.2-18, Q=196
		{C, Ch, Forte}, {D>>3, Eth, P}, {E>>3, Eth, P}, {F>>3, Eth, P}, {D>>3, Eth, P},
		{E>>3, Eth, P}, {R, Eth, P}, {D>>3, Eth, P}, {R, Eth, P}, {C>>3, Eth, P}, {R, Eth, P},
		{D>>3, Eth, P}, {R, Eth, P}, {D>>3, Eth, P}, {E>>3, Eth, P}, {F>>3, Eth, P}, {D>>3, Eth, P},
		{E>>3, Eth, P}, {R, Eth, P}, {F>>3, Eth, P}, {R, Eth, P}, {G, Eth, P}, {R, Eth, P}, 

// measures 19-22
		{G>>3, Eth, P}, {R, Eth, P}, {G>>3, Eth, P}, {A>>3, Eth, P}, {Bb>>3, Eth, P}, {D>>3, Eth, P}, 
		{F>>3, Q, P}, {E>>3, Q, P}, {D>>3, Q, P}, 
		{E>>3, Q, P}, {D>>3, Q, P}, {C>>3, Q, P}, 
		{D>>3, Q, P}, {F>>3, Q, P}, {A>>3, Q, P}, 

// measures 23-26, Q=184
		{D>>4, Q, fForte}, {D>>4, Eth, P}, {E>>4, Eth, P}, {F>>4, Eth, P}, {D>>4, Eth, P}, 
		{E>>4, Q, P}, {D>>4, Q, P}, {C>>4, Q, P}, 
		{D>>4, Q, P}, {D>>4, Eth, P}, {E>>4, Eth, P}, {F>>4, Eth, P}, {D>>4, Eth, P}, 
		{E>>4, Q, P}, {F>>4, Q, P}, {G>>4, Q, P}, 
		
// measures 27-33
		{G>>4, Q, P}, {G>>4, Eth, P}, {A>>4, Eth, P}, {Bb>>4, Eth, P}, {G>>4, Eth, P}, 
	  {F>>4, Q, P}, {E>>4, Q, P}, {D>>4, Q, P}, 
		{E>>4, Q, P}, {D>>4, Q, P}, {C>>4, Q, P}, 
		{D>>4, Q, P}, {F>>4, Q, P}, {A>>4, Q, P}, 
		{A>>3, Hd, P}, 
		{Bb>>3, Hd, P}, 
		{A>>3, Eth, P}, {R, Eth, P}, {A>>3, Eth, P}, {R, Eth, P}, {A>>3, Eth, P}, {R, Eth, P}, 

// measures 34-39
		{A>>3, Eth, P}, {G>>3, Eth, P}, {G>>3, H, P}, 
		{G>>3, Q, P}, {G>>2, Eth, P}, {Bb>>2, Eth, P}, {D>>3, Eth, P}, {F>>3, Eth, P}, 
		{F>>3, Q, P}, {F>>2, Eth, P}, {C>>3, Eth, P}, {D>>3, Eth, P}, {F>>3, Eth, P}, 
		{E>>3, Eth, P}, {R, Eth, P}, {F>>3, Eth, P}, {R, Eth, P}, {E>>3, Eth, P}, {R, Eth, P}, 
		{D>>3, Q, P}, {A>>2, Qt, P}, {D>>3, Qt, P}, {F>>3, Qt, P}, {A>>3, Qt, P}, {D>>4, Qt, P}, {F>>4, Qt, P}, 
		{A>>4, Hd, P}, 
		
// measures 40-44		
		{Bb>>4, Hd, P}, 
		{A>>4, Eth, P}, {R, Eth, P}, {A>>4, Eth, P}, {R, Eth, P}, {A>>4, Eth, P}, {R, Eth, P}, 
		{A>>4, Eth, P}, {G>>4, Eth, P}, {G>>4, H, P}, 
		{A>>2, Eth, mPiano}, {A>>2, Eth, P}, {B>>2, Eth, P}, {B>>2, Eth, P}, {Cs>>3, Eth, P}, {Cs>>3, Eth, P}, 
		{D>>3, Eth, P}, {D>>3, Eth, P}, {E>>3, Eth, P}, {E>>3, Eth, P}, {F>>3, Eth, P}, {F>>3, Eth, P}, 
		
// measures 45-46
		{D>>3, Eth, mForte}, {D>>3, Eth, P}, {E>>3, Eth, P}, {E>>3, Eth, P}, {F>>3, Eth, P}, {F>>3, Eth, P},
		{Gb>>3, Eth, P}, {Gb>>3, Eth, P}, {G>>3, Eth, P}, {G>>3, Eth, P}, {Ab>>3, Eth, P}, {Ab>>3, Eth, P}, 

// measures 47-49, Q=164
	  {R, Ch, Forte}, {A>>3, Qd, P}, {B>>3, Eth, P}, {Cs>>4, Eth, P}, {D>>4, Eth, P}, {Ds>>4, Eth, P}, {E>>4, Eth, P}, 
		{F>>4, Qd, P}, {G>>4, Eth, P}, {G>>4, Q, P}, 
		{G>>4, Qd, P}, {F>>4, Eth, P}, {E>>4, Q, P}, 

// measures 50-55
		{F>>4, Q, P}, {G>>4, Q, P}, {A>>4, Q, P}, 
		{G>>4, H, P}, {F>>4, Eth, P}, {G>>4, Eth, P}, 
		{A>>4, Qd, P}, {G>>4, Eth P}, {F>>4, Q, P}, 
		{E>>4, Eth, P}, {R, Eth, P}, {F>>4, Eth, P}, {R, Eth, P}, {E>>4, Eth, P}, {R, Eth, P}, 
		{D>>4, Ethd, P}, {R, Ethd, P}, {E>>4, Eth, P}, {Cs>>4, Eth, P}, {R, Eth, P}, 
		{D>>4, Hd, P},

// Stop
		{R, Ch, P}

	};

// tempos in terms of clock ticks (80MHz) 
// Zero tells program to stop
const uint32_t Tempo_Pirates[] = { 446428, 382653, 407608, 457317, 0 }; // 168, 196, 184, 164 BPM



#endif
