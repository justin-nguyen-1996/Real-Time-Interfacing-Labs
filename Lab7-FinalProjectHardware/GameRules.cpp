
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

void Quadtree::clear (void)
{
	for (int i = 0; i < MAX_OBJECTS; i++) {delete objects[i];}
	for (int i = 0; i < 4; i++) 
	{
		if (nodes[i] != NULL)
		{
			nodes[i]->clear();
			nodes[i] = NULL;
		}
	}
}

void Quadtree::split (void)
{
	uint16_t x = bounds.x;
	uint16_t y = bounds.y;
	uint16_t subWidth = bounds.w >> 1;
	uint16_t subHeight = bounds.h >> 1;
	
	nodes[0] = new Quadtree(level+1, {x, y, subWidth, subHeight});
	nodes[1] = new Quadtree(level+1, {x, y+subHeight, subWidth, subHeight});
	nodes[2] = new Quadtree(level+1, {x+subWidth, y, subWidth, subHeight});
	nodes[3] = new Quadtree(level+1, {x+subWidth, y+subHeight, subWidth, subHeight});
}

	


