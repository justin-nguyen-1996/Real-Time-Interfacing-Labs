#include "../inc/tm4c123gh6pm.h"
#include "GameRules.h"

static Entity entityList[256];

uint8_t isCollision(Entity* a, Entity* b);
void resolveCollision(Entity* a, Entity* b);
void updateLoc(Entity* e);
void updateVel(Entity* e);
void updateState(Entity* e);
