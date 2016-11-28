//Music.h
//Dung Nguyen
//Wally Guzman

#define NUM_CHANNEL  4
#define NUM_CHORD    4

struct Song{
	const unsigned char *channel[NUM_CHANNEL];
	unsigned int length;     //total length of song in samples
	unsigned int sampleRate; //sample rate of song
};

//defines all possible notes (implement a weird music frequency theory here!)
enum SongNotes{
	A0=0,As0,Bb0=As0,B0,
	C1,Cs1,Db1=Cs1,D1,Ds1,Eb1=Ds1,E1,F1,Fs1,Gb1=Fs1,G1,Gs1,Ab1=Gs1,A1,As1,Bb1=As1,B1,
	C2,Cs2,Db2=Cs2,D2,Ds2,Eb2=Ds2,E2,F2,Fs2,Gb2=Fs2,G2,Gs2,Ab2=Gs2,A2,As2,Bb2=As2,B2,
	C3,Cs3,Db3=Cs3,D3,Ds3,Eb3=Ds3,E3,F3,Fs3,Gb3=Fs3,G3,Gs3,Ab3=Gs3,A3,As3,Bb3=As3,B3,
	C4,Cs4,Db4=Cs4,D4,Ds4,Eb4=Ds4,E4,F4,Fs4,Gb4=Fs4,G4,Gs4,Ab4=Gs4,A4,As4,Bb4=As4,B4,
	C5,Cs5,Db5=Cs5,D5,Ds5,Eb5=Ds5,E5,F5,Fs5,Gb5=Fs5,G5,Gs5,Ab5=Gs5,A5,As5,Bb5=As5,B5,
	C6,Cs6,Db6=Cs6,D6,Ds6,Eb6=Ds6,E6,F6,Fs6,Gb6=Fs6,G6,Gs6,Ab6=Gs6,A6,As6,Bb6=As6,B6,
	C7,Cs7,Db7=Cs7,D7,Ds7,Eb7=Ds7,E7,F7,Fs7,Gb7=Fs7,G7,Gs7,Ab7=Gs7,A7,As7,Bb7=As7,B7,
	C8,RS
};

//intended to create a flexible system to write music in a compact way (and maybe easier)
enum SongCommands{
	setVolume=RS+1, //next byte sets volume (min=0:silent to max=?)
	setEnvelope, //next byte sets envelope
	setWaveform, //next byte sets waveform
	setInstrument, //special instruments, likely special functions
	setDelta,    //next 2 bytes sets length of single note in samples
	longNote,    //next byte defines note length; by default note length is 1 (shortest)
	longRest,    //next byte defines rest length
	chord,       //next byte defines number of chords; can be chained with longNote
	songEnd=0xFF,//end of array
};

//possible waveforms
enum SongWaveforms{
	square=0,
	triangle,
	sawtooth,
	sine,
	piano,
	violin
};

//sets sampling frequency (as well as 
void Music_Init(void);

//main control functions
void Music_Play(void);
void Music_Stop(void);
void Music_Pause(void);

void Music_SetSong(struct Song song);

void Music_SetSampleRate(unsigned int rate);

void Music_ChangeWave(void);

