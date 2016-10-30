//Notes.h
//This file defines the Hz for different musical notes in terms of clock cycles  (assumes 80MHz Clock)
/* Assuming 4 bit-dac
#define R 0     //Rest



#define C2	19112
#define C2S	18039        //C3 SHARP
#define D2	17027 
#define D2S	16071 
#define E2	15169 
#define F2	14318
#define F2S	13514
#define G2	12756 
#define G2S	12040 
#define A2	11364 
#define A2S	10726 
#define B2	10124 
#define C3	9556
#define C3S	9020
#define D3	8514 
#define D3S	8036 
#define E3	7585 
#define F3	7159 
#define F3S	6757 
#define G3	6378 
#define G3S	6020
#define A3	5682  
#define A3S	5363  
#define B3	5062  
#define C4	4778  
#define C4S	4510  
#define D4	4257  
#define D4S	4018  
#define E4	3793  
#define F4	3580  
#define F4S	3379  
#define G4	3189  
#define G4S	3010  
#define A4	2841  
#define A4S	2682  
#define B4	2531  
#define C5	 
#define C5S	  
#define D5	  
#define D5S	  
#define E5	  
#define F5	  
#define F5S	  
#define G5	  
#define G5S	  
#define A5	  
#define A5S	  
#define B5	
*/

#define  C0 		(80000000/(	16	*256/PITCHSHIFT))
#define  C0S 		(80000000/(	17	*256/PITCHSHIFT))
#define  D0 		(80000000/(	18	*256/PITCHSHIFT))
#define  D0S 		(80000000/(	19	*256/PITCHSHIFT))
#define  E0   		(80000000/(	21	*256/PITCHSHIFT))
#define  F0		(80000000/(	22	*256/PITCHSHIFT))
#define  F0S 		(80000000/(	23	*256/PITCHSHIFT))
#define  G0		(80000000/(	25	*256/PITCHSHIFT))
#define  G0S		(80000000/(	26	*256/PITCHSHIFT))
#define  A0		(80000000/(	28	*256/PITCHSHIFT))
#define  A0S		(80000000/(	29	*256/PITCHSHIFT))
#define  B0		(80000000/(	31	*256/PITCHSHIFT))
#define  C1  		(80000000/(	33	*256/PITCHSHIFT))
#define  C1S		(80000000/(	35	*256/PITCHSHIFT))
#define  D1		(80000000/(	37	*256/PITCHSHIFT))
#define  D1S		(80000000/(	39	*256/PITCHSHIFT))
#define  E1		(80000000/(	41	*256/PITCHSHIFT))
#define  F1  		(80000000/(	44	*256/PITCHSHIFT))
#define  F1S		(80000000/(	46	*256/PITCHSHIFT))
#define  G1		(80000000/(	49	*256/PITCHSHIFT))
#define  G1S		(80000000/(	52	*256/PITCHSHIFT))
#define  A1		(80000000/(	55	*256/PITCHSHIFT))
#define  A1S		(80000000/(	58	*256/PITCHSHIFT))
#define  B1  		(80000000/(	62	*256/PITCHSHIFT))
#define  C2		(80000000/(	65	*256/PITCHSHIFT))
#define  C2S		(80000000/(	69	*256/PITCHSHIFT))
#define  D2  		(80000000/(	73	*256/PITCHSHIFT))
#define  D2S		(80000000/(	78	*256/PITCHSHIFT))
#define  E2		(80000000/(	82	*256/PITCHSHIFT))
#define  F2		(80000000/(	87	*256/PITCHSHIFT))
#define  F2S		(80000000/(	93	*256/PITCHSHIFT))
#define  G2		(80000000/(	98	*256/PITCHSHIFT))
#define  G2S		(80000000/(	104	*256/PITCHSHIFT))
#define  A2 		(80000000/(	110	*256/PITCHSHIFT))
#define  A2S		(80000000/(	117	*256/PITCHSHIFT))
#define  B2		(80000000/(	123	*256/PITCHSHIFT))
#define  C3		(80000000/(	131	*256/PITCHSHIFT))
#define  C3S		(80000000/(	139	*256/PITCHSHIFT))
#define  D3		(80000000/(	147	*256/PITCHSHIFT))
#define  D3S		(80000000/(	156	*256/PITCHSHIFT))
#define  E3  		(80000000/(	165	*256/PITCHSHIFT))
#define  F3  		(80000000/(	175	*256/PITCHSHIFT))
#define  F3S		(80000000/(	185	*256/PITCHSHIFT))
#define  G3		(80000000/(	196	*256/PITCHSHIFT))
#define  G3S		(80000000/(	208	*256/PITCHSHIFT))
#define  A3 		(80000000/(	220	*256/PITCHSHIFT))
#define  A3S		(80000000/(	233	*256/PITCHSHIFT))
#define  B3		(80000000/(	247	*256/PITCHSHIFT))
#define  C4		(80000000/(	262	*256/PITCHSHIFT))
#define  C4S 		(80000000/(	277	*256/PITCHSHIFT))
#define  D4		(80000000/(	294	*256/PITCHSHIFT))
#define  D4S 		(80000000/(	311	*256/PITCHSHIFT))
#define  E4		(80000000/(	330	*256/PITCHSHIFT))
#define  F4		(80000000/(	349	*256/PITCHSHIFT))
#define  F4S  		(80000000/(	370	*256/PITCHSHIFT))
#define  G4		(80000000/(	392	*256/PITCHSHIFT))
#define  G4S 		(80000000/(	415	*256/PITCHSHIFT))
#define  A4		(80000000/(	440	*256/PITCHSHIFT))
#define  A4S		(80000000/(	466	*256/PITCHSHIFT))
#define  B4		(80000000/(	494	*256/PITCHSHIFT))
#define  C5		(80000000/(	523	*256/PITCHSHIFT))
#define  C5S		(80000000/(	554	*256/PITCHSHIFT))
#define  D5		(80000000/(	587	*256/PITCHSHIFT))
#define  D5S		(80000000/(	622	*256/PITCHSHIFT))
#define  E5		(80000000/(	659	*256/PITCHSHIFT))
#define  F5		(80000000/(	698	*256/PITCHSHIFT))
#define  F5S		(80000000/(	740	*256/PITCHSHIFT))
#define  G5		(80000000/(	784	*256/PITCHSHIFT))
#define  G5S		(80000000/(	831	*256/PITCHSHIFT))
#define  A5		(80000000/(	880	*256/PITCHSHIFT))
#define  A5S		(80000000/(	932	*256/PITCHSHIFT))
#define  B5		(80000000/(	988	*256/PITCHSHIFT))
#define  C6		(80000000/(	1047	*256/PITCHSHIFT))
#define  C6S		(80000000/(	1109	*256/PITCHSHIFT))
#define  D6		(80000000/(	1175	*256/PITCHSHIFT))
#define  D6S		(80000000/(	1245	*256/PITCHSHIFT))
#define  E6		(80000000/(	1319	*256/PITCHSHIFT))
#define  F6		(80000000/(	1397	*256/PITCHSHIFT))
#define  F6S		(80000000/(	1480	*256/PITCHSHIFT))
#define  G6		(80000000/(	1568	*256/PITCHSHIFT))
#define  G6S		(80000000/(	1661	*256/PITCHSHIFT))
#define  A6		(80000000/(	1760	*256/PITCHSHIFT))
#define  A6S		(80000000/(	1865	*256/PITCHSHIFT))
#define  B6		(80000000/(	1976	*256/PITCHSHIFT))
#define  C7		(80000000/(	2093	*256/PITCHSHIFT))
#define  C7S		(80000000/(	2217	*256/PITCHSHIFT))
#define  D7		(80000000/(	2349	*256/PITCHSHIFT))
#define  D7S		(80000000/(	2489	*256/PITCHSHIFT))
#define  E7		(80000000/(	2637	*256/PITCHSHIFT))
#define  F7		(80000000/(	2794	*256/PITCHSHIFT))
#define  F7S		(80000000/(	2960	*256/PITCHSHIFT))
#define  G7		(80000000/(	3136	*256/PITCHSHIFT))
#define  G7S		(80000000/(	3322	*256/PITCHSHIFT))
#define  A7		(80000000/(	3520	*256/PITCHSHIFT))
#define  A7S		(80000000/(	3729	*256/PITCHSHIFT))
#define  B7		(80000000/(	3951	*256/PITCHSHIFT))
#define  C8		(80000000/(	4186	*256/PITCHSHIFT))
#define  C8S		(80000000/(	4435	*256/PITCHSHIFT))
#define  D8		(80000000/(	4699	*256/PITCHSHIFT))
#define  D8S		(80000000/(	4978	*256/PITCHSHIFT))
#define  E8		(80000000/(	5274	*256/PITCHSHIFT))
#define  F8		(80000000/(	5588	*256/PITCHSHIFT))
#define  F8S		(80000000/(	5920	*256/PITCHSHIFT))
#define  G8		(80000000/(	6272	*256/PITCHSHIFT))
#define  G8S		(80000000/(	6645	*256/PITCHSHIFT))
#define  A8		(80000000/(	7040	*256/PITCHSHIFT))
#define  A8S		(80000000/(	7459	*256/PITCHSHIFT))
#define  B8		(80000000/(	7902	*256/PITCHSHIFT))



//Defines lengths of notes in terms of clock cycles (assumes 80MHz clock and 120BPM)
/*
#define WN 0x9896800
#define HN 0x4C4B400
#define DQN 0x3938700 //DOTTED QUATER NOTE
#define QN 0x2625A00
#define EN 0x1312D00
#define SN 0x989680

#define QNT 0x196E6AA  //QUARTER NOTE TRIPLET
*/
//Defines lengths of notes in terms of clock cycles (assumes 80MHz clock and 240BPM)

#define QN 0x2625A00/2

#define WN (QN*4)
#define HN (QN*2)
#define EN (QN/2)
#define SN (QN/4) 

#define DHN HN+QN //Dotted Half Note
#define DQN QN+EN	//DOTTED QUATER NOTE 
#define DEN EN+SN

#define QNT HN/3  //QUARTER NOTE TRIPLET
#define ENT QN/3

