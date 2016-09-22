#ifndef __keypadh
#define __keypadh

typedef enum keypad_id {
  NUMBER_0  = 1024,
  NUMBER_1  = 4,
  NUMBER_2  = 1,
  NUMBER_3  = 2,
  NUMBER_4  = 8,
  NUMBER_5  = 32,
  NUMBER_6  = 16,
  NUMBER_7	= 64,
  NUMBER_8	= 128,
  NUMBER_9	= 32768,
  DIR_UP		= 2048,
  DIR_RIGHT = 512,
  DIR_DOWN  = 256,
  DIR_LEFT  = 16384,
  MENU_SELECT = 65536 
} keypad_id;

void Keypad_Init(void);
void Timer2Arm(void);
void GPIOArm_PortB(void);
void GPIOArm_PortD(void);
void keypad_main(void);
#endif

