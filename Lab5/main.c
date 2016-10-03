#include <stdint.h>
#include "DAC.h"
#include "Switch.h"
#include "Music.h"
#include "../inc/tm4c123gh6pm.h"
#include "PLL.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

static uint16_t sineIndex = 0;
static uint8_t songIndex = 0;
static uint8_t tempoIndex = 0;

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
  TIMER0_CTL_R = 0x00000001;    // 10) enable TIMER0A
  EndCritical(sr);
}

// Timer 0 used for sine wave output
void Timer0A_Handler(void)
{
  TIMER0_ICR_R = TIMER_ICR_TATOCINT;// acknowledge timer0A timeout
	uint16_t value = Sinewave[sineIndex] << 2;
	sineIndex++;
	value = value >> currentVolume;
	DAC_Out( value );
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
  TIMER1_CTL_R = 0x00000001;    // 10) enable TIMER1A
}

// Timer 1 used for tempo value and note changes
void Timer1A_Handler(void)
{
  TIMER1_ICR_R = TIMER_ICR_TATOCINT;// acknowledge TIMER1A timeout
	if (currentLength) { currentLength--; }
	else 
	{
		Note nextNote = Song_Pirates[ songIndex ];
		songIndex ++;
		if ( !nextNote.length )
		{
			TIMER1_TAILR_R = Tempo_Pirates[ tempoIndex ];
			tempoIndex ++;
			nextNote = Song_Pirates[ songIndex ];
			if (nextNote) {	songIndex ++; }
			else { TIMER1_IMR_R = 0; }
		}
		if ( nextNote.frequency ) 
		{
			TIMER0_IMR_R = 1; 
			TIMER0_TAILR_R = nextNote.frequency;
		}
		else { TIMER0_IMR_R = 0; }
		fullLength = nextNote.legnth;
		currentLength = nextNote.length;
		if (nextNote.volume) { currentVolume = nextNote.volume; }
	}
}

int main(void)
{
	DAC_Init();
  for (int i = 0; i < 100; ++i) {
    //DAC_Out(i);
    SSI3_DR_R = i;
  }
}
