#ifndef __keypadh
#define __keypadh

typedef enum Keypad_ID {
  NUMBER_0 = 0,
  NUMBER_1 = 1,
  NUMBER_2 = 2,
  NUMBER_3 = 3,
  NUMBER_4 = 4,
  NUMBER_5 = 5,
  NUMBER_6 = 6,
  NUMBER_7 = 7,
  NUMBER_8 = 8,
  NUMBER_9 = 9,
  DIR_UP = 10,
  DIR_RIGHT = 11,
  DIR_DOWN = 12,
  DIR_LEFT = 13,
  MENU_SELECT = 14
} Keypad_ID;

/* Summary: Initialize ports B and D for a total of 16 pins.
 *          Interrupts will be enabled on rising edges.
 *          Inputs are positive logic.
 * Input:   None
 * Output:  None
 */
void Keypad_Init(void);

#endif
