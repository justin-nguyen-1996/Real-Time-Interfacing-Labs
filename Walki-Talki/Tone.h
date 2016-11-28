//Tone.h
//Dung Nguyen
//Wally Guzman

//Defines all possible notes
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

//------------Tone_GetSample------------
// Returns next sample in sine wave table
// Input: none
// Output: 8-bit sample
char Tone_GetSample(void);

//------------Tone_SetFrequency------------
// Set frequency note for sampling
// Input: none
// Output: none
void Tone_SetFrequency(int note);
