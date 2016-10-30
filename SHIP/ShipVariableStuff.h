
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

#define PF1       (*((volatile uint32_t *)0x40025008))	//PIN SPECIFIC ADDRESSING PORT F
#define PF2       (*((volatile uint32_t *)0x40025010))
#define PF3       (*((volatile uint32_t *)0x40025020))
	
#define TRUE  1
#define FALSE 0

//=================================================
//Debug for outputting raw thumbstick input and drawing grid
//  0 = nothing
//  1 = draw grid
//  2 = draw ADC output and grid
//Setting 2 slows EVERYTHING Down a lot
//Period manually speeds up/slows down systick
//-------------------------------------------------
#define SEED   25	//for the random seed
#define Debug  0
#define Period 0x2F0000

#define SHOOTVELOCITY 6
#define ASTEROIDVELOCITY (100+Score/4)

#define POINTMAXVELOCITY     300
#define MAXPOINTSPAWNVELOCITY 50  //+MINPOINTSPAWNVELOCITY
#define MINPOINTSPAWNVELOCITY 50
#define POINTVELOCITYDECAY 20  //smaller is quicker decay
#define POINTLIFEMAX 			50 //+POINTLIFEMIN
#define POINTLIFEMIN			50
#define POINTMAGNETRANGE  2000
#define BOMBGAINSCORE	250

#define DIAMONDMAXVELOCITY 200
#define DIAMONDLIFE    5	

#define MAXSHOOT 			20 //dont forget to update Shoot Entity Array manually
#define ASTEROIDFREQUENCY	 (Score/4+MINIMUMFREQUENCY)
#define MINIMUMFREQUENCY 30
#define DIAMONDFREQUENCY (Score/10-MINIMUMFREQUENCY)

#define MAXASTEROID		200
#define MAXSTAR				150
#define MAXCOLLISION  200
#define MAXFIRE 			10
#define MAXPOINT			200
#define MAXDIAMOND    10

#define STARDISTANCE	4

#define EDGEXMAX			200 //despawn positions in pixels
#define EDGEXMIN			-20
#define EDGEYMAX			148
#define EDGEYMIN			-20

#define ENEMYSPAWN    1
#define DRAWSCORE			1 //Dont draw score and debug thumbsticks at the same time
#define LEGENDARYSCORE 200

#define MOMENTUMDISABLE 1 //disables collision momentum ie everything has constant velocity
#define BOMBFLASH 10 //# of flashes when bomb is used

#define SHIPXPOSITION		(80-SHIPSIDELENGTH/2)
#define SHIPYPOSITION		(64+SHIPSIDELENGTH/2)
#define SHIPXCENTER 81
#define SHIPYCENTER 63
#define SHIPHITBOX	900		//in fixed point 100
#define ASTEROIDHITBOX  500   	//in fixed point 100

#define SHIPSIDELENGTH 9
#define FIRESIDELENGTH 5
#define SHOOTSIDELENGTH 5
#define ASTEROIDSIDELENGTH 5
#define POINTSIDELENGTH 	3
#define DIAMONDSIDELENGTH  13

#define LAYER1ON  1
#define LAYER2ON  1
#define PLAYSOUND		1
#define SONGLENGTH1  379
#define SONGLENGTH2		387

#define PITCHSHIFT 	2  //2^SINELENGTHREDUCER
#define SINELENGTHREDUCER		1	//Artificially raises pitch by decreasing length of sine table
#define BEATSPERMINUTE		1400
#define SOUNDSAMPLERATE		80000000/110250

//----------------------------------------------------

typedef struct VectorGroup{signed int x;signed int y;} Vector;
typedef struct InteractionGroup{signed int i;signed int j;signed int k;} Interaction;
typedef struct EntityGroup{
	
	Vector Position; 
	Vector Velocity; 
	Vector OldPosition; 
	Vector Mail; 
	Vector SpecCode;	//used for various things. ie MetaData
	unsigned short Life;} Entity;

	
	
	