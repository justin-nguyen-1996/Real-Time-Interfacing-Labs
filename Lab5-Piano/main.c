#include <stdint.h>
#include "DAC.h"
#include "Switch.h"
#include "Music.h"
#include "../inc/tm4c123gh6pm.h"
#include "PLL.h"

#define PF0   (*((volatile uint32_t *)0x40025004))
#define PF1   (*((volatile uint32_t *)0x40025008))
#define PF2   (*((volatile uint32_t *)0x40025010))
#define PF3   (*((volatile uint32_t *)0x40025020))
#define PF4   (*((volatile uint32_t *)0x40025040))

// Pins 1 through 3 debugging profile for interrupts and main
void PortF_Init(void){ 
  SYSCTL_RCGCGPIO_R |= 0x20;        // 1) activate clock for Port F
  while((SYSCTL_PRGPIO_R&0x20)==0){}; // allow time for clock to start
                                    // 2) no need to unlock PF2, PF4
  GPIO_PORTF_PCTL_R &= ~0x000FFFF0; // 3) regular GPIO
  GPIO_PORTF_AMSEL_R &= ~0x1E;      // 4) disable analog function on PF1 - PF4
  GPIO_PORTF_PUR_R |= 0x10;         // 5) pullup for PF4
  GPIO_PORTF_DIR_R |= 0x0E;         // 5) set direction to output PF1-3
  GPIO_PORTF_AFSEL_R &= ~0x1E;      // 6) regular port function
  GPIO_PORTF_DEN_R |= 0x1E;         // 7) enable digital port
}

const uint16_t wave[32] = {
  2048,2448,2832,3186,3496,3751,3940,4057,4095,4057,3940,
  3751,3496,3186,2832,2448,2048,1648,1264,910,600,345,
  156,39,0,39,156,345,600,910,1264,1648
};


void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

static uint16_t sineIndex = 0;
static uint8_t songIndex = 0;
static uint8_t tempoIndex = 0;

static uint16_t envIndex = 0;

static uint16_t fullLength = 0;
static uint16_t currentLength = 0;
static uint8_t currentVolume = 0;

// ***************** Timer0A_Init ****************
// Activate TIMER0 interrupts to run user task periodically
// Inputs:  task is a pointer to a user function
//          period in units (1/clockfreq), 32 bits
// Outputs: none
void Timer0A_Init(uint32_t period)
{
	long sr;
  sr = StartCritical(); 
  SYSCTL_RCGCTIMER_R |= 0x01;   // 0) activate TIMER0
  TIMER0_CTL_R = 0x00000000;    // 1) disable TIMER0A during setup
  TIMER0_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
  TIMER0_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
  TIMER0_TAILR_R = period-1;    // 4) reload value
  TIMER0_TAPR_R = 0;            // 5) bus clock resolution
  TIMER0_ICR_R = 0x00000001;    // 6) clear TIMER0A timeout flag
  TIMER0_IMR_R = 0x00000001;    // 7) arm timeout interrupt
  NVIC_PRI4_R = (NVIC_PRI4_R&0x00FFFFFF)|0xA0000000; // 8) priority 5
// interrupts enabled in the main program after all devices initialized
// vector number 35, interrupt number 19
  NVIC_EN0_R = 1<<19;           // 9) enable IRQ 19 in NVIC
	PF1 = 0; //Debugging Profile
  TIMER0_CTL_R = 0x00000001;    // 10) enable TIMER0A
  EndCritical(sr);
}

#define WAVE Sinewave
// Timer 0 used for sine wave output
void Timer0A_Handler(void)
{
	PF1 = 1;
  TIMER0_ICR_R = TIMER_ICR_TATOCINT;// acknowledge timer0A timeout
	uint16_t value = WAVE[sineIndex] << 2 ;
	sineIndex = (sineIndex+1) & 0x1F;
	value = value >> currentVolume;
	DAC_Out( (value * envelope[envIndex]) >> 8 	);
	PF1 = 0;
}

// ***************** TIMER1_Init ****************
// Activate TIMER1 interrupts to run user task periodically
// Inputs:  task is a pointer to a user function
//          period in units (1/clockfreq)
// Outputs: none
void Timer1_Init(uint32_t period)
{
  SYSCTL_RCGCTIMER_R |= 0x02;   // 0) activate TIMER1
  TIMER1_CTL_R = 0x00000000;    // 1) disable TIMER1A during setup
  TIMER1_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
  TIMER1_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
  TIMER1_TAILR_R = period-1;    // 4) reload value
  TIMER1_TAPR_R = 0;            // 5) bus clock resolution
  TIMER1_ICR_R = 0x00000001;    // 6) clear TIMER1A timeout flag
  TIMER1_IMR_R = 0x00000001;    // 7) arm timeout interrupt
  NVIC_PRI5_R = (NVIC_PRI5_R&0xFFFF00FF)|0x00008000; // 8) priority 4
// interrupts enabled in the main program after all devices initialized
// vector number 37, interrupt number 21
  NVIC_EN0_R = 1<<21;           // 9) enable IRQ 21 in NVIC
	PF2 = 0; // Debugging profile
  TIMER1_CTL_R = 0x00000001;    // 10) enable TIMER1A	
}

// Timer 1 used for tempo value and note changes
void Timer1A_Handler(void)
{
	PF2 = 1;
  TIMER1_ICR_R = TIMER_ICR_TATOCINT;// acknowledge TIMER1A timeout
	if (currentLength) // if note duration hasn't ended
	{ 
		currentLength--; 
    envIndex = (envIndex + 1) & 0xFF;
	} 
	else 
	{
		Note nextNote = Song_Pirates[ songIndex ];
		songIndex ++;
    
    // if we need to do a tempo change (used notes of length zero to indicate tempo change)
		if ( !nextNote.length )
		{
			if ( Tempo_Pirates[tempoIndex] ) // if valid tempo
			{	
				TIMER1_TAILR_R = Tempo_Pirates[ tempoIndex ];
				tempoIndex ++;
				nextNote = Song_Pirates[ songIndex ];
				songIndex ++; 
			}
			else { TIMER1_IMR_R = 0; } // else song is done
		}
    
		if ( nextNote.frequency ) // if valid note frequency
		{
			TIMER0_IMR_R = 1; 
			TIMER0_TAILR_R = nextNote.frequency;
			envIndex = 0;
		}
		else { TIMER0_IMR_R = 0; } // else is rest
    
    // update current note length, volume, and envelope multiplier
		fullLength = nextNote.length;
		currentLength = nextNote.length;
		if (nextNote.volume) { currentVolume = nextNote.volume; }
	}
	PF2 = 0;
}

uint8_t playing = 0;
void rewind() {
  playing = 0;
  TIMER0_IMR_R = 0;
  TIMER1_IMR_R = 0;
  tempoIndex = 0;
  songIndex = 0;
  Timer1_Init(Tempo_Pirates[ tempoIndex++ ]);
  TIMER1_IMR_R = 0;
}

void playPause() {
  if ( !Tempo_Pirates[tempoIndex] )
  {
    playing = 1;
    TIMER0_IMR_R = 1;
    tempoIndex = 0;
    songIndex = 0;
    Timer1_Init(Tempo_Pirates[ tempoIndex++ ]);
  }
  else if (playing)
  {
    playing = 0;
    TIMER1_IMR_R = 0;
    TIMER0_IMR_R = 0;
  }
  else 
  {
    playing = 1;
    TIMER1_IMR_R = 1;
    TIMER0_IMR_R = 1;
  }
}

int main(void)
{
	PLL_Init(Bus80MHz);
	DAC_Init();
	Switch_Init();
	PortF_Init();
	Timer0A_Init(0xFFFFFFFF);
	TIMER0_IMR_R = 0;
  Timer1_Init(Tempo_Pirates[ tempoIndex++ ]);
	TIMER1_IMR_R = 0;
	DAC_Test(); // test with sawtooth wave
	PF3 = 0;
	while(1)
	{
		PF3 ^= 1;
		uint8_t switchStatus = Switch_GetStatus();
		switch (switchStatus)
		{
			case 0:
				break;
			case 1:
				playPause();
				break;
			case 2:
				rewind();
				break;
		}
	}
}
