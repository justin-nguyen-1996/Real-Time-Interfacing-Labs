//Switch.h

typedef enum switchState {noPress=0, shortPress, longPress, doublePress} switchState_t;

//typedef enum switchButton {hatLeft, hatUp, hatRight, hatDown} switchButton_t;

#define bPlay   (Switch_State(2))
#define bStop   (Switch_State(3))
#define bSong   (Switch_State(0))
#define bWave   (Switch_State(1))

void Switch_Init(void);

int Switch_State(int k);
