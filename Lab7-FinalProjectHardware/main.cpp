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
static uint8_t Flag_GameTick = 0;

void waitForTouch() {
	while (RIGHTSWITCH == 0x01) {}
}

// handles each game tick interrupt
extern "C" {
	void Timer3A_Handler(void){
		TIMER3_ICR_R = TIMER_ICR_TATOCINT;// acknowledge TIMER3A timeout
		Flag_GameTick = 1;
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



//#define NVIC_ST_CTRL_COUNT      0x00010000  // Count flag
//#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
//#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt enable
//#define NVIC_ST_CTRL_ENABLE     0x00000001  // Counter mode
//
//// Initialize SysTick with busy wait running at bus clock.
//void SysTick_Init(void){
//  NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
//  NVIC_ST_RELOAD_R = 444444;  // maximum reload value
//  NVIC_ST_CURRENT_R = 0;                // any write to current clears it
//                                        // enable SysTick with core clock
//  NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_INTEN+NVIC_ST_CTRL_CLK_SRC;
//}
//extern "C"{
//void SysTick_Handler(void)
//{
//	Flag_GameTick = 1;
//}
//}
int main(void) {

	PortA_Init();
	PortB_Init();
	PortC_Init();
	PortD_Init();
	PortE_Init();
	PortF_Init();

	PLL_Init(Bus80MHz);
	//  DAC_Init();
	//  LED_Init();
	//  ESP8266_Init(BAUD_RATE);
	ST7735_InitR(INITR_REDTAB); ST7735_SetRotation(3);
	Buttons_Init();
	Thumbstick_Init();
	Accel_Init();
	ADC_Init();
	GameTick_Init();
	EnableInterrupts();

	//  ST7735_Test();   waitForTouch(); Output_Clear();
	//  DAC_Test(2);     waitForTouch(); Output_Clear();
	//  Buttons_Test();  waitForTouch(); Output_Clear();
  //  ADC_Test();      waitForTouch(); Output_Clear();
	//  ESP_Test();      waitForTouch(); Output_Clear();
	//  GameRulesTest(); waitForTouch(); Output_Clear();

	Rectangle Screen (0,0,160<<7,128<<7);
	Quadtree * WorldSpace = new Quadtree(0, Screen); // initializes gamespace the same size as screen
	
	Entity * Player = new Entity(Rectangle(50<<7,50<<7,8<<7,8<<7), Vector(0,0), Vector(0,0), SHIP, 0, 0);
	Entity * laser = new Entity(Rectangle(60<<7,60<<7,4<<7,4<<7), Vector(0,0), Vector(0,0), LASER, 0, 0); 
	WorldSpace->insert(Player);
	WorldSpace->insert(laser);
	
	uint32_t tick = 0;
	while (1) {
		if (Flag_GameTick) {
			Flag_GameTick = 0;

			//ST7735_SetCursor(0,0);
			//	ST7735_OutUDec(tick++);
			
			ADC_In(tstick, accel);
			NormalizeAnalogInputs(tstick, accel);

			// update entities
			EntityList AllEntities;
			WorldSpace->retrieve(&AllEntities, Screen);
			EraseEntities(&AllEntities);
			AllEntities.update(tstick, accel);
			DrawEntities(&AllEntities);
			WorldSpace->clear();
			WorldSpace->insert(&AllEntities);

			//WorldSpace->drawBounds();

			// check for collisions
		}
	}
}
