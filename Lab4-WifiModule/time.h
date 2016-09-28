#ifndef __timeh
#define __timeh

typedef struct{
	uint32_t min;
	uint32_t max;
	double sum;
	uint32_t iter;
	uint32_t av;
	uint32_t last;
} Time;

/* Summary: initialize SysTick
 * Input:   none
 * Output:  none
 */
void time_Init(void);

/* Summary: enable the clock and capture the data register value
 * Input:   none
 * Output:  none
 */
void time_Start(void);

/* Summary: capture the data register value and disable the clock
 * Input:   none
 * Output:  none
 */
void time_End(void);

/* Summary: return the difference in time measurements between start and end
 * Input:   none
 * Output:  the time difference
 */
uint32_t time_Get(void);

/* Summary: update the time struct
 * Input:   none
 * Output:  none
 */
void time_Update(Time * x);


#endif
