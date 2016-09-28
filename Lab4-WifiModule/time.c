
#include <stdint.h>
#include "time.h"

static uint32_t startTime = 0;
static uint32_t endTime = 0;

#include "../inc/tm4c123gh6pm.h"
#define NVIC_ST_CTRL_COUNT      0x00010000  // Count flag
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Counter mode
#define NVIC_ST_RELOAD_M        0x00FFFFFF  // Counter load value

/* Summary: initialize SysTick
 * Input:   none
 * Output:  none
 */
void time_Init(void)
{
  NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
  NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;  // maximum reload value
  NVIC_ST_CURRENT_R = 0;                // any write to current clears it
                                        // enable SysTick with core clock
  NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC;
}

/* Summary: enable the clock and capture the data register value
 * Input:   none
 * Output:  none
 */
void time_Start(void)
{
//	time_Init();
  NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC;
	startTime = NVIC_ST_CURRENT_R ; //& 0x00FFFFFF;
}

/* Summary: capture the data register value and disable the clock
 * Input:   none
 * Output:  none
 */
void time_End(void)
{
	endTime = NVIC_ST_CURRENT_R ; //& 0x00FFFFFF;
  NVIC_ST_CTRL_R = 0; 
//	NVIC_ST_CURRENT_R = 0;
}

/* Summary: return the difference in time measurements between start and end
 * Input:   none
 * Output:  the time difference
 */
uint32_t time_Get(void)
{
	return (startTime - endTime) & 0x00FFFFFF; // data register is only bottom 24 bits
}

/* Summary: update the time struct
 * Input:   none
 * Output:  none
 */
void time_Update(Time * x)
{
	uint32_t diff = time_Get();
	if ( diff < x->min ){ x->min = diff; }
	if ( diff > x->max ){ x->max = diff; }
	x->sum += diff;
	x->iter ++;
	x->av = x->sum / x->iter;
	x->last = diff;
}
