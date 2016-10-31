
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

// ---------- Entity Methods ---------------

void Entity::update (void) 
{
	(Vector) {Bounds.x, Bounds.y} += Velocity;
	Velocity += Acceleration;
}

// TODO: push pop isFull
// ---------- EntityList Methods ------------

void EntityList::removeOs (void)
{
	int i = 0;
	for (int j = 0; j < MAX_OBJECTS; j++)
	{	
		if (List[j] != 0) {	List[i++] = List[j]; }
	}	
}		

// ----------- Quadtree Methods -------------

void Quadtree::clear (void)
{
	for (int i = 0; i < MAX_OBJECTS; i++) {delete objects[i];}
	for (int i = 0; i < 4; i++) 
	{
		if (nodes[i] != 0)
		{
			nodes[i]->clear();
			nodes[i] = 0;
		}
	}
}

void Quadtree::split (void)
{
	uint16_t x = bounds.x;
	uint16_t y = bounds.y;
	uint16_t subWidth = bounds.w >> 1;
	uint16_t subHeight = bounds.h >> 1;
	
	nodes[0] = new Quadtree(level+1, Rectangle(x, y, subWidth, subHeight));
	nodes[1] = new Quadtree(level+1, Rectangle(x, y+subHeight, subWidth, subHeight));
	nodes[2] = new Quadtree(level+1, Rectangle(x+subWidth, y, subWidth, subHeight));
	nodes[3] = new Quadtree(level+1, Rectangle(x+subWidth, y+subHeight, subWidth, subHeight));
}

int8_t Quadtree::getIndex (Rectangle R) 
{
	int8_t index = -1;
	uint32_t horizontalMidpoint = bounds.x + (bounds.w >> 1);
	uint32_t verticalMidpoint = bounds.y + (bounds.h >> 1);
	
	bool topHalf = (R.y < verticalMidpoint && R.y + R.h < verticalMidpoint);
	bool bottomHalf = (R.y > verticalMidpoint);
	bool leftHalf = (R.x < horizontalMidpoint && R.x + R.w < horizontalMidpoint);
	bool rightHalf = (R.x > horizontalMidpoint);
	
	if (topHalf && leftHalf)     { index = 0; }
	else if (bottomHalf && leftHalf)  { index = 1; }
	else if (topHalf && rightHalf)    { index = 2; }
	else if (bottomHalf && rightHalf) { index = 3; }

	return index;
}

//so this thing errors silently. If there's bugs look here first.
//we are probably running out of room in the objects array or maybe
//the quadtree is going past the max levels or I'm shit at pointers
void Quadtree::insert (Entity * E)
{
	if (nodes[0] != 0)
	{
		int8_t index = getIndex(E->Bounds);
		if (index != -1) 
		{	
			nodes[index]->insert(*E);
			return;
		}
	}
	else if (!objects.isFull()) { objects.push(*E); }	
	else if (objects.isFull() && level < MAX_LEVELS)
	{
		if (nodes[0] == 0) { split(); }
		for (int i = 0; i < objectsNextIndex; i++)
		{
			int8_t index = getIndex(objects.List[i]->Bounds);
			if (index != -1) { nodes[index]->insert(objects.List[i]); }
			objects.List[i] = 0;
			objects.removeOs;
		}
	}
}

//retrieves all objecs that could potentially collide in a bounding box
EntityList Quadtree::retrieve (EntityList returnObjects, Rectangle R)
{
	int8_t index = getIndex(R); 
	if (index != -1 && nodes[0] != 0)
	{
		nodes[index]->retrieve(returnObjects, R);
	}
	
	for (int i = 0; i < objects.nextIndex; i++)
	{
		returnObjects.push(objects.List[i]);
	}	
	return returnObjects;
}


