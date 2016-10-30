#include "ShipVariableStuff.h"
#include <stdint.h>

extern Vector	PositionStick[2];
extern Vector ADCAveraging[6];
extern Vector PositionReal[2];
extern Vector NormalShootingVelocity;

extern Entity Grid;														//Floating Point (100)
extern Entity Alien;				//Position is of the bottom left pixel of bitmap
extern Entity Shoot[MAXSHOOT];
extern Entity Asteroid[MAXASTEROID];
extern Entity Star[MAXSTAR];
extern Entity Fire[MAXFIRE];
extern Entity Point[MAXPOINT];
extern Entity Diamond[MAXDIAMOND];

extern Interaction Collision[MAXCOLLISION];

extern int Direction;						//Used to control ship Bitmap
extern int CompareDirection;				//Used to determine if erasing exhaust pixels is neccissary
extern int Exhaust;							//Used for Making the fire look cool
extern int ExhaustToggle;				//Used for turning the fire off
extern int Flying;								//Used to determine if direction is being asserted for ship
extern int Shooting;							//Used to determine if direction is being asserted for shooting
extern int ShootingDelay;				//Used to half the number of bullets/tick
extern int PositionUpdateStatus;
extern int NormalSquare;
extern uint8_t Rotation;
extern int Exhaust;
extern signed int CollisionSound;
extern short BeenHit;
extern short BombsLeft;
extern int MaxScore;

extern int LastScore;
extern int Score;

extern const unsigned short SquareRootTable[301];


