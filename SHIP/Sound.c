#include "tm4c123gh6pm.h"
#include "ShipVariableStuff.h"
#include "Notes.h"

signed int CollisionSound;
short PlaySoundStatus = 0;
int Layer1;
int Layer2;
int ResetPosFlag = 0;

const unsigned short SineTable[256] = {255	,
256	,
251	,
242	,
231	,
217	,
201	,
183	,
165	,
146	,
128	,
111	,
95	,
81	,
69	,
61	,
55	,
52	,
51	,
54	,
59	,
66	,
75	,
85	,
96	,
107	,
118	,
128	,
137	,
145	,
151	,
156	,
158	,
158	,
157	,
154	,
150	,
144	,
138	,
131	,
125	,
118	,
113	,
108	,
104	,
101	,
100	,
100	,
102	,
105	,
108	,
113	,
118	,
123	,
128	,
133	,
138	,
141	,
144	,
146	,
147	,
146	,
145	,
143	,
140	,
136	,
132	,
127	,
123	,
119	,
116	,
113	,
111	,
110	,
109	,
110	,
112	,
114	,
117	,
121	,
124	,
128	,
132	,
135	,
138	,
140	,
142	,
143	,
142	,
142	,
140	,
137	,
135	,
131	,
128	,
124	,
121	,
118	,
116	,
114	,
113	,
113	,
113	,
114	,
116	,
119	,
122	,
125	,
128	,
131	,
134	,
137	,
139	,
140	,
141	,
141	,
140	,
139	,
137	,
134	,
131	,
128	,
125	,
122	,
119	,
117	,
115	,
114	,
114	,
114	,
115	,
117	,
119	,
122	,
125	,
128	,
131	,
134	,
137	,
139	,
140	,
141	,
141	,
140	,
139	,
137	,
134	,
131	,
128	,
125	,
122	,
119	,
116	,
114	,
113	,
113	,
113	,
114	,
116	,
118	,
121	,
124	,
128	,
131	,
135	,
137	,
140	,
142	,
142	,
143	,
142	,
140	,
138	,
135	,
132	,
128	,
124	,
121	,
117	,
114	,
112	,
110	,
109	,
110	,
111	,
113	,
116	,
119	,
123	,
127	,
132	,
136	,
140	,
143	,
145	,
146	,
147	,
146	,
144	,
141	,
138	,
133	,
128	,
123	,
118	,
113	,
108	,
105	,
102	,
100	,
100	,
101	,
104	,
108	,
113	,
118	,
125	,
131	,
138	,
144	,
150	,
154	,
157	,
158	,
158	,
156	,
151	,
145	,
137	,
128	,
118	,
107	,
96	,
85	,
75	,
66	,
59	,
54	,
51	,
52	,
55	,
61	,
69	,
81	,
95	,
111	,
128	,
146	,
165	,
183	,
201	,
217	,
231	,
242	,
251	,
256};


const Vector SongLayer1[SONGLENGTH1] = {{B3,EN},{E4,EN},{F4S,EN},{B4,EN},{E5,EN},{F5S,EN},{B5,EN},{F5S,EN},{E5,EN},{B4,EN},{F4S,EN},{E4,EN},

{B3,EN},{E4,EN},{F4S,EN},{B4,EN},{E5,EN},{F5S,EN},{B5,EN},{F5S,EN},{E5,EN},{B4,EN},{F4S,EN},{E4,EN},

{B3,EN},{E4,EN},{A4,EN},{B4,EN},{E5,EN},{A5,EN},{B5,EN},{A5,EN},{E5,EN},{B4,EN},{A4,EN},{E4,EN},

{B3,EN},{E4,EN},{A4,EN},{B4,EN},{E5,EN},{A5,EN},{B5,EN},{A5,EN},{E5,EN},{B4,EN},{A4,EN},{E4,EN},

{B3,EN},{E4,EN},{F4S,EN},{B4,EN},{E5,EN},{F5S,EN},{B5,EN},{F5S,EN},{E5,EN},{B4,EN},{F4S,EN},{E4,EN},

{B3,EN},{E4,EN},{F4S,EN},{B4,EN},{E5,EN},{F5S,EN},{B5,EN},{F5S,EN},{E5,EN},{B4,EN},{F4S,EN},{E4,EN},

{B3,EN},{E4,EN},{A4,EN},{B4,EN},{E5,EN},{A5,EN},{B5,EN},{A5,EN},{E5,EN},{B4,EN},{A4,EN},{E4,EN},

{B3,EN},{E4,EN},{A4,EN},{B4,EN},{E5,EN},{A5,EN},{B5,EN},{A5,EN},{E5,EN},{A5,EN},{E5,EN},{B4,EN},

{E5,EN},{A4,EN},{E4,EN},{E5,EN},{A4,EN},{E4,EN},{D5S,EN},{A4,EN},{E4,EN},{D5S,EN},{A4,EN},{E4,EN},

{D5,EN},{A4,EN},{E4,EN},{D5,EN},{A4,EN},{E4,EN},{C5S,EN},{A4,EN},{E4,EN},{C5S,EN},{A4,EN},{E4,EN},

{E5,EN},{A4,EN},{E4,EN},{E5,EN},{A4,EN},{E4,EN},{D5S,EN},{A4,EN},{E4,EN},{D5S,EN},{A4,EN},{E4,EN},

{D5,EN},{A4,EN},{E4,EN},{D5,EN},{A4,EN},{E4,EN},{C5,EN},{A4,EN},{E4,EN},{C5,EN},{A4,EN},{E4,EN},

{E4,HN},{A3,HN},{G4,HN},{F4S,QN},{G4,QN},{F4S,QN},{E4,HN},{A3,HN},{E4,EN},{E4,EN},{E4,EN},{F4S,EN},{F4S,EN},{F4S,EN},{G4,EN},{G4,EN},{G4,EN},{A4,QN},

{E4,HN},{C4,HN},{G4,HN},{F4S,QN},{G4,QN},{A4,QN},{B4,HN},{E4,HN},{B4,EN},{B4,EN},{B4,EN},{A4,EN},{A4,EN},{A4,EN},{B4,EN},{B4,EN},{B4,EN},{G4,QN},{E5,HN},{B4,HN},{G5,HN},{F5S,QN},{G5,QN},{F5,QN},{E5,HN},{A4,HN},{E5,EN},{A4,EN},{E4,EN},{E5,EN},{A4,EN},{E4,EN},{D5,EN},{A4,EN},{E4,EN},{C5,EN},{A4,EN},{E4,EN},{E5,HN},{A4,HN},{G5,HN},{F5,QN},{G5,QN},{A5,QN},{B5,HN},{B5,EN},{A5,EN},{B5,EN},{A5,HN},{G5S,QN},{B5,QN},{D6,QN},{C6S,HN},{A5,HN},{A5,HN},{E5,QN},{A5,QN},{B5,QN},{C6,HN},{A5,HN},{A5,HN},{E5,QN},{A5,QN},{E6,QN},{D6,HN},{B5,HN},{B5,HN},{D5,QN},{G5,QN},{D6,QN},{C6S,HN},{A5,HN},{A5,HN},{E4,QN},{A4,QN},{E5,QN},{F5S,HN},{A4,HN},{A4,HN},{G4S,QN},{B4,QN},{G5S,QN},{A5,HN},{E5,HN},{E5,HN},{E5,QN},{D5,QN},{C5S,QN},

{D5,HN},{B4,HN},{B4,HN},{D5,QN},{C5S,QN},{D5,QN},{B4,QN},{B4,EN},{A4,EN},{B4,EN},{B4,QN},{B4,EN},{A4,EN},{B4,EN},{D5,HN},{E5,HN},{A4,QN},{A4,EN},{G4,EN},{A4,EN},{D5,HN},{A4,QN},{A4,EN},{G4,EN},{A4,EN},{E5,HN},{A4,QN},{A4,EN},{G4,EN},{A4,EN},{G5,QN},{F5S,QN},{E5,QN},{C5,QN},{D5,QN},{E5,QN},{A4,HN},{A4,QN},{A4,EN},{G4,EN},{A4,EN},{D5,HN},{A4,QN},{A4,EN},{G4,EN},{A4,EN},{E5,HN},{A4,QN},{A4,EN},{G4,EN},{A4,EN},{G5,QN},{A5,QN},{G5,QN},{F5S,QN},{E5,QN},{F5S,QN},{C5,HN},{E5,QN},{E5,EN},{D5,EN},{E5,EN},{G5,HN},{E5,QN},{E5,EN},{D5,EN},{E5,EN},{A5,HN},{E5,QN},{E5,EN},{D5,EN},{E5,EN},{B5,QN},{A5,QN},{G5,QN},{D6,QN},{C6,QN},{B5,QN},{B5,QN},{A5,QN},{G5,QN},

{E5,EN},{A4,EN},{E4,EN},{E5,EN},{A4,EN},{E4,EN},{D5S,EN},{A4,EN},{E4,EN},{D5S,EN},{A4,EN},{E4,EN},{D5,EN},{A4,EN},{E4,EN},{D5,EN},{A4,EN},{E4,EN},{C5S,EN},{A4,EN},{E4,EN},{C5S,EN},{A4,EN},{E4,EN},{E5,EN},{A4,EN},{E4,EN},{E5,EN},{A4,EN},{E4,EN},{D5S,EN},{A4,EN},{E4,EN},{D5S,EN},{A4,EN},{E4,EN},{D5,EN},{A4,EN},{E4,EN},{D5,EN},{A4,EN},{E4,EN},{C5,EN},{A4,EN},{E4,EN},{C5,EN},{A4,EN},{E4,EN}
};
const Vector SongLayer2[SONGLENGTH2] = {{E2,HN},{E2,HN},{E2,HN},{E2,HN},{F2,HN},{F2,HN},{F2,HN},{F2,QN},{F2,QN},{E2,QN},{E2,QN},{E2,QN},{E2,QN},{E2,QN},{E2,QN},{E2,QN},{E2,QN},{E2,EN},{F2,QN},{F2,QN},{F2,QN},{F2,QN},{G2,QN},{G2,QN},{G2,QN},{G2,QN},{A2,HN},{A2,HN},{A2,HN},{E2,QN},{A2,HN},{A2,HN},{A2,QN},{A2,QN},{A2,QN},{A2,QN},{A2,QN},{A2,EN},{A2,EN},{A2,EN},{A2,QN},{A2,QN},{A2,QN},{A2,EN},{A2,EN},{A2,EN},{A2,QN},{A2,QN},{A2,QN},{A2,EN},{A2,EN},{A2,EN},{A2,QN},{A2,QN},{A2,QN},{A2,QN},{A2,QN},{B2,QN},{C2,QN},{C2,EN},{C2,EN},{C2,EN},{C2,QN},{C2,QN},{C2,QN},{C2,EN},{C2,EN},{C2,EN},{C2,QN},{C2,QN},{E2,QN},{E2,EN},{E2,EN},{E2,EN},{E2,QN},{E2,QN},{E2,QN},{E2,QN},{E2,QN},{E2,EN},{E2,EN},{E2,EN},{E2,QN},{E2,EN},{E2,EN},{E2,EN},{E2,QN},{E2,QN},{E2,QN},{E2,EN},{E2,EN},{E2,EN},{E2,QN},{E2,QN},{F2,QN},{F2,EN},{F2,EN},{F2,EN},{F2,QN},{C2,QN},{A2S,QN},{F2,QN},{F2,QN},{E2,QN},{D2,QN},{D2,EN},{D2,EN},{D2,EN},{D2,QN},{C2,QN},{A2S,QN},{A2,EN},{A2,EN},{A2,EN},{A2,QN},{A2,QN},{B2,QN},{B2,EN},{B2,EN},{B2,EN},{B2,QN},{B2,QN},{E2,QN},{E2,EN},{E2,EN},{E2,EN},{E3,QN},{E3,EN},{A3,EN},{E3,EN},{A2,EN},{E3,EN},{A3,EN},{C4S,EN},{A3,EN},{C4,EN},{E4,EN},{C4,EN},{E4,EN},{A4,EN},{E4,EN},{C4,EN},{A2,EN},{E3,EN},{A3,EN},{C4S,EN},{A3,EN},{C4,EN},{E4,EN},{C4,EN},{E4,EN},{A4,EN},{E4,EN},{C4,EN},{F2,EN},{C3,EN},{F3,EN},{A3,EN},{F3,EN},{A3,EN},{C4,EN},{A3,EN},{C4,EN},{F4,EN},{C4,EN},{A3,EN},{F2,EN},{C3,EN},{F3,EN},{A3,EN},{F3,EN},{A3,EN},{C4,EN},{A3,EN},{C4,EN},{F4,EN},{C4,EN},{A3,EN},{G2,EN},{D3,EN},{G3,EN},{B3,EN},{G3,EN},{B3,EN},{D4,EN},{B3,EN},{D4,EN},{G4,EN},{D4,EN},{B3,EN},{G2,EN},{D3,EN},{G3,EN},{B3,EN},{G3,EN},{B3,EN},{D4,EN},{B3,EN},{D4,EN},{G4,EN},{D4,EN},{B3,EN},{A2,EN},{E3,EN},{A3,EN},{C4S,EN},{A3,EN},{C4,EN},{E4,EN},{C4,EN},{E4,EN},{A4,EN},{E4,EN},{C4,EN},{A2,QN},{A2,EN},{A2,EN},{A2,EN},{A2,QN},{A2,QN},{D2,EN},{D2,EN},{D2,EN},{D2,QN},{D2,EN},{D2,EN},{D2,EN},{D2,QN},{E2,EN},{E2,EN},{E2,EN},{E2,QN},{E2,EN},{E2,EN},{E2,EN},{E2,QN},{C2,EN},{C2S,EN},{C2,EN},{C2,QN},{C2,EN},{C2,EN},{C2,EN},{C2,QN},{F2,EN},{F2S,EN},{F2,EN},{F2,QN},{F2,EN},{F2,EN},{F2,EN},{F2,QN},

{G2,EN},{G2,EN},{G2,EN},{G2,QN},{G2,EN},{G2,EN},{G2,EN},{G2,QN},{D2,EN},{G2,EN},{G2,EN},{G2,EN},{G2,QN},{G2,EN},{G2,EN},{G2,EN},{G2,QN},{E2,QN},{E2,EN},{E2,EN},{E2,EN},{E2,QN},{B2,QN},{E2,EN},{B2,EN},{E2,EN},{E2,EN},{B2,EN},{E2,EN},{E2,EN},{B2,EN},{E2,EN},{E2,EN},{B2,EN},{E2,EN},{D2,QN},{D2,QN},{D2,EN},{A2,EN},{D3,EN},{A3,EN},{D3,EN},{A2,EN},{D2,QN},{D2,QN},{D2,EN},{A2,EN},{D3,EN},{A3,EN},{D3,EN},{A2,EN},{D2,QN},{D2,QN},{D2,EN},{A2,EN},{D3,EN},{A3,EN},{D3,EN},{A2,EN},{D4,EN},{D3,EN},{A2,EN},{A3,EN},{D3,EN},{A2,EN},{C4,EN},{D3,EN},{A2,EN},{A3,EN},{D3,EN},{A2,EN},{D2,QN},{D2,QN},{D2,EN},{A2,EN},{D3,EN},{A3,EN},{D3,EN},{A2,EN},{D2,QN},{D2,QN},{D2,EN},{A2,EN},{D3,EN},{A3,EN},{D3,EN},{A2,EN},{D2,QN},{D2,QN},{D2,EN},{A2,EN},{D3,EN},{A3,EN},{D3,EN},{A2,EN},{D4,EN},{D3,EN},{A2,EN},{A3,EN},{D3,EN},{A2,EN},{C4,EN},{D3,EN},{A2,EN},{A3,EN},{D3,EN},{A2,EN},{E2,QN},{E2,QN},{E2,QN},{E2,QN},{E2,QN},{E2,QN},{E2,QN},{E2,QN},{F2,QN},{F2,QN},{F2,QN},{F2,QN},{F2,QN},{F2,QN},{G2,QN},{G2,QN},{G2,QN},{G2,QN},{A2,HN},{A2,HN},{A2,HN},{E2,QN},{A2,HN},{A2,HN},{A2,QN},{A2,QN},{A2,QN},{A2,QN}
};


void DAC_Init(void){

	GPIO_PORTB_DIR_R |= 0xFF;
	GPIO_PORTB_AMSEL_R = 0;
	GPIO_PORTB_AFSEL_R = 0;
	GPIO_PORTB_PUR_R = 0;
	GPIO_PORTB_PDR_R = 0;
	GPIO_PORTB_DEN_R |= 0xFF;
	
	SYSCTL_RCGCTIMER_R |= 0xE;													// Start timer clock
	while((SYSCTL_RCGCTIMER_R&0xE) == 0){}
		
	TIMER3_CTL_R = 0x00000000;
	TIMER3_CFG_R = 0x00000000;   
  TIMER3_TAMR_R = 0x00000002;  
  TIMER3_TAILR_R = SOUNDSAMPLERATE;   
  TIMER3_TAPR_R = 0;           
  TIMER3_ICR_R = 0x00000001;   
	TIMER3_IMR_R = 0x00000001;  
	NVIC_PRI8_R = (NVIC_PRI8_R&0x1FFFFFFF)|0x60000000; //Priority 3
	NVIC_EN1_R |= 1<<(35-32);	
	
	TIMER2_CTL_R = 0x00000000;
	TIMER2_CFG_R = 0x00000000;   
  TIMER2_TAMR_R = 0x00000002;  
  TIMER2_TAILR_R = SOUNDSAMPLERATE;   
  TIMER2_TAPR_R = 0;           
  TIMER2_ICR_R = 0x00000001;   
	TIMER2_IMR_R = 0x00000001;  
	NVIC_PRI5_R = (NVIC_PRI5_R&0x1FFFFFFF)|0x40000000; //Priority 2
	NVIC_EN0_R |= 1<<(23);
		
		
	TIMER1_CTL_R = 0x00000000;
	TIMER1_CFG_R = 0x00000000;   
  TIMER1_TAMR_R = 0x00000002;  
  TIMER1_TAILR_R = SOUNDSAMPLERATE;   
  TIMER1_TAPR_R = 0;           
  TIMER1_ICR_R = 0x00000001;   
	TIMER1_IMR_R = 0x00000001;  
	NVIC_PRI5_R = (NVIC_PRI5_R&0xFFFF1FFF)|0x00002000; //Priority 1
	NVIC_EN0_R |= 1<<(21);
		
		if(PLAYSOUND == TRUE){
			TIMER3_CTL_R = 0x00000001;
			TIMER2_CTL_R = 0x00000001;
			TIMER1_CTL_R = 0x00000001;
		}
	
		
}

void Timer3A_Handler(void){
	static Vector LoopCount;
	static Vector SongLocation;
	static int Note = A0;
	static signed int Articulation;
	TIMER3_ICR_R = 0x1;
	if(Articulation>0){
		Articulation -= LoopCount.x*Note;
		LoopCount.x ++;
	}
	else{
		if(ResetPosFlag == TRUE){
			SongLocation.x =0;
			ResetPosFlag = FALSE;
		}
		if(Note != 0){
			SongLocation.x = (SongLocation.x+SINELENGTHREDUCER)%256;
			Layer1 = SineTable[SongLocation.x];
			PlaySoundStatus = TRUE;
		}
		if(SongLayer1[SongLocation.y].y - (Note*LoopCount.y) <= 0){
			SongLocation.y = (SongLocation.y+1)%(SONGLENGTH1);
			if(SongLayer1[SongLocation.y].x != 0 ){
				Note = SongLayer1[SongLocation.y].x;
				TIMER3_TAILR_R = Note; 
			}
			LoopCount.y = 0;
			LoopCount.x = 0;
			SongLocation.x = 0;
			ResetPosFlag = TRUE;
			Articulation = EN;
		}
		else{LoopCount.y ++;}
	}
}
void Timer2A_Handler(void){
	static Vector LoopCount;
	static Vector SongLocation;
	static int Note = A0;
	static signed int Articulation;
	TIMER2_ICR_R = 0x1;
	if(ResetPosFlag == TRUE){
			SongLocation.x =0;
			ResetPosFlag = FALSE;
		}
	if(Articulation>0){
		Articulation -= LoopCount.x*Note;
		LoopCount.x ++;
	}
	else{
		if(Note != 0){
			SongLocation.x = (SongLocation.x+SINELENGTHREDUCER)%256;
			Layer2 = SineTable[SongLocation.x];
			PlaySoundStatus = TRUE;
		}
		if(SongLayer2[SongLocation.y].y - (Note*LoopCount.y) <= 0){
			SongLocation.y = (SongLocation.y+1)%(SONGLENGTH2);
			if(SongLayer2[SongLocation.y].x != 0 ){
				Note = SongLayer2[SongLocation.y].x;
				TIMER2_TAILR_R = Note; 
			}
			LoopCount.y = 0;
			LoopCount.x = 0;
			//Articulation = EN;
			SongLocation.x = 0;
			ResetPosFlag = TRUE;
		}
		else{LoopCount.y ++;}
	}}
void Timer1A_Handler(void){
		TIMER1_ICR_R = 0x1;
		if(PlaySoundStatus == TRUE){
			PlaySoundStatus = FALSE;
			GPIO_PORTB_DATA_R = (Layer1*LAYER1ON+Layer2*LAYER2ON)/2;
		}
	}
