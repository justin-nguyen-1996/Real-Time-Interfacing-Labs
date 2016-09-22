// Runs on TM4C123

#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "PLL.h"
#include "keypad.h"
#include "timer.h"
#include "draw.h"
#include "out.h"
#include "FIFO.h"

#define ORIGIN_MAIN 0

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

typedef enum actionType {
  SETTING = 0,
  DISPLAY = 1,
  OUT = 2
} actionType;

actionType detectActionType(rxDataType * Action){return (actionType) 0;}
  
void updateSetting(rxDataType * Action){}
void updateDisplay(rxDataType * Action){}
void updateOut(rxDataType * Action){}

void pushInitRoutines(void){};

void initAll (void) 
{
  PLL_Init(Bus80MHz);
  RxFifo_Init();

  // Initialize output modules 
  // These will not push routines on the FIFO
  out_Init();
  draw_Init();

  // Push the initial routines for the program on the FIFO (configure setting values)
  pushInitRoutines();

  // Initialize input modules which use interrupts
  // These may push additional initial routines on FIFO (drawing first screen)
  keypad_Init();
  timer_Init();
}

int main (void) 
{
  initAll();
  while(1)
  {
    rxDataType * nextAction;
    int fifoGetStatus = RxFifo_Get(nextAction);
    if (fifoGetStatus)
    {
      actionType type = detectActionType(nextAction);
      switch (type)
      {
	case SETTING:  updateSetting(nextAction); break;
	case DISPLAY:  updateDisplay(nextAction); break;
	case OUT:      updateOut(nextAction); break;
      }
    }
  }
}

