
extern "C"{
	#include "../inc/tm4c123gh6pm.h"
}
#include "GameRules.h"

//comment everything to test if this compiles

//static Entity entityList[256];

//uint8_t isCollision(Entity* a, Entity* b);
//void resolveCollision(Entity* a, Entity* b);
//void updateLoc(Entity* e);
//void updateVel(Entity* e);
//void updateState(Entity* e);

void Spatial::update (void) 
{
	Position += Velocity;
	Velocity += Acceleration;
}
