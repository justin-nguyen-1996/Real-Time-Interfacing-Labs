//Music.c
//Dung Nguyen
//Wally Guzman

#include <stdint.h>
#include "Music.h"
#include "LED.h"
#include "DAC.h"
#include "Timer0.h"

//------------------PRIVATE FUNCTIONS---------------------------//
void ProcessChannels(void);

void ProcessCommands(unsigned int k);
int GenerateWave(unsigned int k);
int GeneratePiano(unsigned int k);
int GenerateViolin(unsigned int k);

//------------------CONTROL VARIABLES---------------------------//
unsigned char *channel[NUM_CHANNEL];
unsigned int chanIndex[NUM_CHANNEL];  //index for parser
unsigned int chanVolume[NUM_CHANNEL];
unsigned int chanCount[NUM_CHANNEL];  //counts how long a note was played
unsigned char chanReady[NUM_CHANNEL]; //indicates whether next byte should be processed or not
unsigned char chanEnd[NUM_CHANNEL];   //indicates end of array reached

unsigned char noteFreq[NUM_CHANNEL];
unsigned char noteWaveform[NUM_CHANNEL]; //waveform such as square
unsigned char noteLength[NUM_CHANNEL];
unsigned int noteDelta[NUM_CHANNEL];
unsigned int noteRate[NUM_CHANNEL];

unsigned char chordFreq[NUM_CHANNEL][NUM_CHORD];
unsigned int chordRate[NUM_CHANNEL][NUM_CHORD];
unsigned char chordPlay[NUM_CHANNEL];//0 = normal; 1 = play chord

unsigned int length;
unsigned int count;
unsigned int sampleRate;

unsigned int numChord;

//-------------------FREQUENCY MAP------------------------------//
//every frequency is decimal fixed-point * 10
const unsigned short freqMap[88] = {
  275,   291,   309, 
  327,   346,   367,   389,   412,   437,   462,   490,   519,   550,   583,   617, 
  654,   693,   734,   778,   824,   873,   925,   980,  1038,  1100,  1165,  1235, 
 1308,  1386,  1468,  1556,  1648,  1746,  1850,  1960,  2077,  2200,  2331,  2469, 
 2616,  2772,  2937,  3111,  3296,  3492,  3700,  3920,  4153,  4400,  4662,  4939, 
 5233,  5544,  5873,  6223,  6593,  6985,  7400,  7840,  8306,  8800,  9323,  9878, 
10465, 11087, 11747, 12445, 13185, 13969, 14800, 15680, 16612, 17600, 18647, 19755, 
20930, 22175, 23493, 24890, 26370, 27938, 29600, 31360, 33224, 35200, 37293, 39511, 
41860
};

//-------------------WAVEFORMS----------------------------------//
const unsigned char squareWave[2] = {
  0,255
};

const unsigned char triangleWave[256] = {
  0,  2,  4,  6,  8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62,
 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,
128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,
192,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,
254,252,250,248,246,244,242,240,238,236,234,232,230,228,226,224,222,220,218,216,214,212,210,208,206,204,202,200,198,196,194,192,
190,188,186,184,182,180,178,176,174,172,170,168,166,164,162,160,158,156,154,152,150,148,146,144,142,140,138,136,134,132,130,128,
126,124,122,120,118,116,114,112,110,108,106,104,102,100, 98, 96, 94, 92, 90, 88, 86, 84, 82, 80, 78, 76, 74, 72, 70, 68, 66, 64,
 62, 60, 58, 56, 54, 52, 50, 48, 46, 44, 42, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10,  8,  6,  4,  2,  0,
};

const unsigned char sineWave[256] = {
127,130,133,136,139,143,146,149,152,155,158,161,164,167,170,173,176,178,181,184,187,190,192,195,198,200,203,205,208,210,212,215,
217,219,221,223,225,227,229,231,233,234,236,238,239,240,242,243,244,245,247,248,249,249,250,251,252,252,253,253,253,254,254,254,
254,254,254,254,253,253,253,252,252,251,250,249,249,248,247,245,244,243,242,240,239,238,236,234,233,231,229,227,225,223,221,219,
217,215,212,210,208,205,203,200,198,195,192,190,187,184,181,178,176,173,170,167,164,161,158,155,152,149,146,143,139,136,133,130,
127,124,121,118,115,111,108,105,102, 99, 96, 93, 90, 87, 84, 81, 78, 76, 73, 70, 67, 64, 62, 59, 56, 54, 51, 49, 46, 44, 42, 39,
 37, 35, 33, 31, 29, 27, 25, 23, 21, 20, 18, 16, 15, 14, 12, 11, 10,  9,  7,  6,  5,  5,  4,  3,  2,  2,  1,  1,  1,  0,  0,  0,
  0,  0,  0,  0,  1,  1,  1,  2,  2,  3,  4,  5,  5,  6,  7,  9, 10, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 27, 29, 31, 33, 35,
 37, 39, 42, 44, 46, 49, 51, 54, 56, 59, 62, 64, 67, 70, 73, 76, 78, 81, 84, 87, 90, 93, 96, 99,102,105,108,111,115,118,121,124,
};
/*
const unsigned char expEnvelope[512] = {
255,254,253,252,251,250,248,247,246,245,244,243,242,241,240,239,238,237,236,235,234,233,232,231,230,229,228,227,226,225,224,223,
222,221,220,219,218,217,216,215,214,213,212,211,211,210,209,208,207,206,205,204,203,202,202,201,200,199,198,197,196,196,195,194,
193,192,191,191,190,189,188,187,186,186,185,184,183,182,182,181,180,179,178,178,177,176,175,175,174,173,172,172,171,170,169,169,
168,167,166,166,165,164,164,163,162,161,161,160,159,159,158,157,157,156,155,155,154,153,153,152,151,151,150,149,149,148,147,147,
146,145,145,144,144,143,142,142,141,140,140,139,139,138,137,137,136,136,135,134,134,133,133,132,132,131,130,130,129,129,128,128,
127,126,126,125,125,124,124,123,123,122,122,121,121,120,119,119,118,118,117,117,116,116,115,115,114,114,113,113,112,112,111,111,
110,110,109,109,109,108,108,107,107,106,106,105,105,104,104,103,103,103,102,102,101,101,100,100, 99, 99, 99, 98, 98, 97, 97, 96,
 96, 96, 95, 95, 94, 94, 94, 93, 93, 92, 92, 91, 91, 91, 90, 90, 90, 89, 89, 88, 88, 88, 87, 87, 86, 86, 86, 85, 85, 85, 84, 84,
 83, 83, 83, 82, 82, 82, 81, 81, 81, 80, 80, 80, 79, 79, 78, 78, 78, 77, 77, 77, 76, 76, 76, 75, 75, 75, 74, 74, 74, 73, 73, 73,
 73, 72, 72, 72, 71, 71, 71, 70, 70, 70, 69, 69, 69, 68, 68, 68, 68, 67, 67, 67, 66, 66, 66, 66, 65, 65, 65, 64, 64, 64, 64, 63,
 63, 63, 62, 62, 62, 62, 61, 61, 61, 61, 60, 60, 60, 59, 59, 59, 59, 58, 58, 58, 58, 57, 57, 57, 57, 56, 56, 56, 56, 55, 55, 55,
 55, 54, 54, 54, 54, 54, 53, 53, 53, 53, 52, 52, 52, 52, 51, 51, 51, 51, 51, 50, 50, 50, 50, 49, 49, 49, 49, 49, 48, 48, 48, 48,
 48, 47, 47, 47, 47, 46, 46, 46, 46, 46, 45, 45, 45, 45, 45, 44, 44, 44, 44, 44, 43, 43, 43, 43, 43, 43, 42, 42, 42, 42, 42, 41,
 41, 41, 41, 41, 40, 40, 40, 40, 40, 40, 39, 39, 39, 39, 39, 39, 38, 38, 38, 38, 38, 38, 37, 37, 37, 37, 37, 37, 36, 36, 36, 36,
 36, 36, 35, 35, 35, 35, 35, 35, 35, 34, 34, 34, 34, 34, 34, 33, 33, 33, 33, 33, 33, 33, 32, 32, 32, 32, 32, 32, 32, 31, 31, 31,
 31, 31, 31, 31, 30, 30, 30, 30, 30, 30, 30, 30, 29, 29, 29, 29, 29, 29, 29, 28, 28, 28, 28, 28, 28, 28, 28, 27, 27, 27, 27, 27,
};
*/
const unsigned char expEnvelope[256] = {
255,250,244,239,234,229,224,219,214,210,205,201,196,192,188,184,180,176,172,169,165,161,158,155,151,148,145,142,139,136,133,130,
127,124,122,119,116,114,111,109,107,104,102,100, 98, 96, 94, 91, 90, 88, 86, 84, 82, 80, 78, 77, 75, 73, 72, 70, 69, 67, 66, 64,
 63, 62, 60, 59, 58, 56, 55, 54, 53, 52, 51, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 40, 39, 38, 37, 36, 35, 35, 34, 33, 32, 32,
 31, 30, 30, 29, 28, 28, 27, 26, 26, 25, 25, 24, 24, 23, 23, 22, 22, 21, 21, 20, 20, 19, 19, 18, 18, 18, 17, 17, 16, 16, 16, 15,
 15, 15, 14, 14, 14, 13, 13, 13, 12, 12, 12, 12, 11, 11, 11, 11, 10, 10, 10, 10,  9,  9,  9,  9,  9,  8,  8,  8,  8,  8,  7,  7,
  7,  7,  7,  6,  6,  6,  6,  6,  6,  6,  5,  5,  5,  5,  5,  5,  5,  5,  4,  4,  4,  4,  4,  4,  4,  4,  4,  3,  3,  3,  3,  3,
  3,  3,  3,  3,  3,  3,  3,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
};

//-------------------CONTROL FUNCTIONS--------------------------//
void Music_Init(void){
	DAC_Init();
	Timer0_Init(&ProcessChannels,1667);
}

void Music_SetSong(struct Song song){
	Music_SetSampleRate(song.sampleRate);
	length = song.length;
	sampleRate = song.sampleRate;
	for(int k=0; k<NUM_CHANNEL;k++){
		channel[k] = (unsigned char*) song.channel[k];
		chanIndex[k] = 0;
		chanVolume[k] = 255;
		chanCount[k] = 0;
		chanReady[k] = 0;
		chanEnd[k] = 0;
	}
};

void Music_SetSampleRate(unsigned int rate){
	Timer0_Reload(80000000/rate);
};

void Music_Play(void){
	Timer0_Enable();
}

void Music_Pause(void){
	Timer0_Disable();
}

void Music_Stop(void){
	Timer0_Disable();
	for(int k=0; k<NUM_CHANNEL;k++){
		chanIndex[k] = 0;
		chanVolume[k] = 255;
		chanCount[k] = 0;
		chanReady[k] = 0;
		chanEnd[k] = 0;
	}
}

void Music_ChangeWave(void){
	noteWaveform[0]=(noteWaveform[0]+1)%(violin+1);
}

//-------------------MUSIC INTERPRETER-------------------------//
void ProcessChannels(void){
	int out = 0;
	
	if(chanEnd[0]){
		Music_Stop();
		DAC_Out(1<<11);
	}
	
	for(int k=0; k<2; k++){
		if(chanCount[k]>noteDelta[k]*noteLength[k]){
			ProcessCommands(k);
			LED_Green_Toggle();
		}
		out += GenerateWave(k);
	}
	count++;
	out += 1023;//set base line to middle
	DAC_Out(out);
};

//interprets commands from channel array
void ProcessCommands(unsigned int k){
	if(chanEnd[k]) //can be checked depending on logic before function call
		return;
	unsigned char command = channel[k][chanIndex[k]];
	if(command == songEnd){
		noteFreq[k] = RS;
		chanReady[k] = 1;
		chanEnd[k] = 1;
		return;
	}
	noteLength[k] = 1; //default length
	chanCount[k] = 0;
	chanReady[k] = 0;
	chordPlay[k] = 0;
	while(command > RS && command != songEnd && !chanReady[k]){ //will read all commands before a note, chord, or end
		switch(command){
			case setVolume: //next byte sets volume (min=0:silent to max=255)
				chanVolume[k] = channel[k][chanIndex[k]+1];
				chanIndex[k] += 2;
				break;
			case setEnvelope: //next byte sets envelope
				chanIndex[k] += 2; //todo
				break;
	    case setWaveform: //next byte sets waveform
				noteWaveform[k] = channel[k][chanIndex[k]+1];
				chanIndex[k] += 2;
				break;
	    case setInstrument: //special instruments, likely special functions
				chanIndex[k] += 2; //todo
				break;
	    case setDelta:    //next 2 bytes sets length of single note in samples
				noteDelta[k] = ((channel[k][chanIndex[k]+1]<<8) + channel[k][chanIndex[k]+2]);
				chanIndex[k] += 3;
				break;
			case longNote:    //next byte defines note length; by default note length is 1 (shortest)
				noteLength[k] = channel[k][chanIndex[k]+1];
				chanIndex[k] += 2;
				break;
			case longRest:    //next byte defines rest length
				noteFreq[k] = RS;
				noteLength[k] = channel[k][chanIndex[k]+1];
				chanIndex[k] += 2;
				chanReady[k] = 1;
				break;
			case chord:   //next byte defines number of chords; can be chained with longNote
				numChord = channel[k][chanIndex[k]+1];
				for(int i=0; i<numChord; i++){
					chordFreq[k][i] = channel[k][chanIndex[k]+2+i];
					chordRate[k][i] = (freqMap[chordFreq[k][i]]<<8)*256/10/sampleRate;
				}
				chanIndex[k] += numChord+2;
				chordPlay[k] = 1;
				chanReady[k] = 1;
				break;
			case songEnd:     //end of array
				noteFreq[k] = RS;
				chanReady[k] = 1;
				chanEnd[k] = 1;
				break;
			default:
				break;
		};
		command = channel[k][chanIndex[k]];
	}
	
	if(!chanReady[k]){
		noteFreq[k] = command;
		noteRate[k] = (freqMap[noteFreq[k]]<<8)*256/10/sampleRate;
		chanIndex[k] += 1;
		//chanReady[k] = 1;
	}
}

int GenerateWave(unsigned int k){
	unsigned int out=0;
	if(chordPlay[k]){
		for(int i=0; i<numChord; i++){
			switch(noteWaveform[k]){
				case square:
					out += squareWave[(chanCount[k]*freqMap[chordFreq[k][i]]*2/sampleRate/10)%2]-127;
					break;
				case triangle:
					out += triangleWave[(chanCount[k]*chordRate[k][i]>>8)%256]-127;
					break;
				case sawtooth:
					out += (chanCount[k]*chordRate[k][i]>>8)%256-127;
					break;
				case sine:
					out += sineWave[(chanCount[k]*chordRate[k][i]>>8)%256]-127;
					break;
				case piano:
					out = GeneratePiano(k);
					break;
				case violin:
					out = GenerateViolin(k);
					break;
				default:
					return 0;
			}
		}
		chanCount[k]++;
		out = out*(chanVolume[k]+1)>>8;
		out = out*(expEnvelope[chanCount[k]*256/sampleRate]+1)>>8;
		return out;
	}
	if(noteFreq[k] == RS){
		chanCount[k]++;
		return 0;
	}
	//waveform + frequency modifier
	switch(noteWaveform[k]){
		case square:
			out = squareWave[(chanCount[k]*freqMap[noteFreq[k]]*2/sampleRate/10)%2]-127;
			break;
		case triangle:
			out = triangleWave[(chanCount[k]*noteRate[k]>>8)%256]-127;
			break;
		case sawtooth:
			out = (chanCount[k]*noteRate[k]>>8)%256-127;
			break;
		case sine:
			out = sineWave[(chanCount[k]*noteRate[k]>>8)%256]-127;
			break;
		case piano:
			out = GeneratePiano(k);
			break;
		case violin:
			out = GenerateViolin(k);
			break;
		default:
			return 0;
	}
	//volume modifier
	out = out*(chanVolume[k]+1)>>8;
	//envelope
	out = out*(expEnvelope[chanCount[k]*256/sampleRate]+1)>>8;
	
	chanCount[k]++;
	return out;
}

unsigned char pianoNote[10] = {89,89,89,89,89,89,89,89,89,89};
const unsigned int pianoOvertone[10] = {0,12,19,24,28,31,34,36,38,40};
const unsigned int pianoCoef[10] = {65,77,44,51,55,55,54,46,28,38};
unsigned int pianoRate[10];

int GeneratePiano(unsigned int k){
	if(noteFreq[k] != pianoNote[0]){
		for(int n=1; n<10; n++){
			pianoNote[n] = pianoOvertone[n] + noteFreq[k];
			if(pianoNote[n]<RS)
				pianoRate[n] = (freqMap[pianoNote[n]]<<8)*256/10/sampleRate;
		}
	}
	unsigned int out=0;
	for(int n=0; n<10; n++){
		if(pianoNote[n]<RS)
			out += (sineWave[(chanCount[k]*pianoRate[n]>>8)%256]*pianoCoef[n]>>8) - pianoCoef[n]/2;
	}
	return out;
}
unsigned char violinNote[14] = {89,89,89,89,89,89,89,89,89,89,89,89,89,89};
const unsigned int violinOvertone[14] = {0,12,19,24,28,31,34,36,38,40,42,43,44,46};
const unsigned int violinCoef[14] = {95,73,62,46,47,29,34,27,18,18,22,16,13,13};
unsigned int violinRate[14];

int GenerateViolin(unsigned int k){
	if(noteFreq[k] != violinNote[0]){
		for(int n=1; n<14; n++){
			violinNote[n] = violinOvertone[n] + noteFreq[k];
			if(violinNote[n]<RS)
				violinRate[n] = (freqMap[violinNote[n]]<<8)*256/10/sampleRate;
		}
	}
	unsigned int out=0;
	for(int n=0; n<14; n++){
		if(violinNote[n]<RS)
			out += (sineWave[(chanCount[k]*violinRate[n]>>8)%256]*violinCoef[n]>>8)-violinCoef[n]/2;
	}
	return out;
}
