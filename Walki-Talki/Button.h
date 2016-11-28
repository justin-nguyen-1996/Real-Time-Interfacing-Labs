//Button.h
//Dung Nguyen
//Wally Guzman

// Stores button state in bit vector as follows:
// PF4 PF0 PE3 PE2 PE1 PE0
// B 	 A   U   R   D   L

#define L	 0x01
#define D	 0x02
#define R  0x04
#define	U	 0x08
#define A  0x10
#define B	 0x20
	
//------------Button_Init------------
// Initialize PE0-3 and PF0, PF4 for switch input
// Input: none
// Output: none	
void Button_Init(void);

//------------Button_Update------------
// Update internal switch state
// Input: none
// Output: none	
void Button_Update(void);

//------------Button_Pressed------------
// Return switches pressed since last update
// Input: none
// Output: Bit vector, 1 is pressed
uint32_t Button_Pressed(void);

//------------Button_Unpressed------------
// Return switches not pressed since last update
// Input: none
// Output: Bit vector, 1 is not pressed
uint32_t Button_Unpressed(void);

//------------Button_NewState------------
// Return flag for new switch state
// Input: none
// Output: 1 if new state
uint32_t Button_NewState(void);

//------------Button_Transmit------------
// Return state of transmit button, A = PF0
// Input: none
// Output: 1 if transmit button pressed
int Button_Transmit(void);

//------------Button_Display------------
// Return state of display button, B = PF4
// Input: none
// Output: 1 if display button pressed
int Button_Display(void);
