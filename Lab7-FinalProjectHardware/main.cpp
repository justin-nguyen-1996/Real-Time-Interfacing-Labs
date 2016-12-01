extern "C" {
#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "PLL.h"
#include "DAC.h"
#include "LED.h"
#include "esp8266.h"
#include "ST7735.h"
#include "Buttons.h"
	//#include "UART.h"
#include "Thumbstick.h"
#include "Accel.h"
#include "Graphics.h"
#include "ADC.h"
#include "PortInit.h"
	void DisableInterrupts(void); // Disable interrupts
	void EnableInterrupts(void);  // Enable interrupts
	long StartCritical (void);    // previous I bit, disable interrupts
	void EndCritical(long sr);    // restore I bit to previous value
	void WaitForInterrupt(void);  // low power mode
}
#include "GameRules.h"

//static const int BAUD_RATE = 115200;
static uint16_t tstick[4] = {0,0,0,0}; 
static uint16_t accel[3] = {0,0,0};
static uint32_t Flag_GameTick = 0;

void waitForTouch() {
	while (RIGHTSWITCH == 0x01) {}
}

// handles each game tick interrupt
extern "C" {
	void Timer3A_Handler(void){
		TIMER3_ICR_R = TIMER_ICR_TATOCINT;// acknowledge TIMER3A timeout
		Flag_GameTick += 1;
	}
}

// each game tick will occur at 180HZ
void GameTick_Init(void) {
	SYSCTL_RCGCTIMER_R |= 0x08;   // activate TIMER3
	TIMER3_CTL_R = 0x00000000;    // disable TIMER3A during setup
	TIMER3_CFG_R = 0x00000000;    // configure for 32-bit mode
	TIMER3_TAMR_R = 0x00000002;   // configure for periodic mode, default down-count settings
	TIMER3_TAILR_R = 444444;      // reload value
	TIMER3_TAPR_R = 0;            // bus clock resolution
	TIMER3_ICR_R = 0x00000001;    // clear TIMER3A timeout flag
	TIMER3_IMR_R = 0x00000001;    // arm timeout interrupt
	NVIC_PRI8_R = (NVIC_PRI8_R&0x00FFFFFF)|0x80000000; // 8) priority 4
	NVIC_EN1_R = 1<<(35-32);      // enable IRQ 35 in NVIC
	TIMER3_CTL_R = 0x00000001;    // enable TIMER3A
}

Quadtree* WorldSpace_Init() {
  Rectangle Screen (0,0,160<<7,128<<7);
	Quadtree * WorldSpace = new Quadtree(0, Screen); // initializes gamespace to the same size as screen
	Entity * Player = new Entity(Rectangle(50<<7,50<<7,8<<7,8<<7), Vector(0,0), Vector(0,0), SHIP, 0, 0);
	WorldSpace->insert(Player);
  return WorldSpace;
}

//EntityList AllEntities;
int main(void) {

	PortA_Init();
	PortB_Init();
	PortC_Init();
	PortD_Init();
	PortE_Init();
	PortF_Init();

	PLL_Init(Bus80MHz);
	DAC_Init();
	ST7735_InitR(INITR_REDTAB); ST7735_SetRotation(3);
	Buttons_Init();
	Thumbstick_Init();
	Accel_Init();
	ADC_Init();
	GameTick_Init();
  Timer0A_Init(8000); disableSound();
	EnableInterrupts();

//	ST7735_Test();   waitForTouch(); Output_Clear();
//	DAC_Test(2);     waitForTouch(); Output_Clear();
//	Buttons_Test();  waitForTouch(); Output_Clear();
//  ADC_Test();      waitForTouch(); Output_Clear();
//	ESP_Test();      waitForTouch(); Output_Clear();
//	GameRulesTest(); waitForTouch(); Output_Clear();
  
  Rectangle Screen (0,0,160<<7,128<<7);
  Quadtree* WorldSpace = WorldSpace_Init();
	uint32_t oldGameTick = 0;
	while (1) {
		if (oldGameTick != Flag_GameTick) {
			oldGameTick = Flag_GameTick; 
			
      // read and normalize ADC inputs
			ADC_In(tstick, accel); 
			NormalizeAnalogInputs(tstick, accel);

			// update entities
			EntityList AllEntities; // TODO: can we make this a global?
			WorldSpace->retrieve(&AllEntities, Screen);
			EraseEntities(&AllEntities);
			AllEntities.update(tstick, accel, oldGameTick);
			DrawEntities(&AllEntities);
			WorldSpace->clear();
			WorldSpace->insert(&AllEntities);

			//WorldSpace->drawBounds();

			// check for collisions
		}
	}

}
