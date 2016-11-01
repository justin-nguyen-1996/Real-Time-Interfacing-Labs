
extern "C"{
	#include <stdint.h>
	#include "../inc/tm4c123gh6pm.h"
	#include "ST7735.h"
}
#include "GameRules.h"
#define NULL       0
#define INVALID    -1
#define TOP_LEFT   0
#define BOT_LEFT   1
#define TOP_RIGHT  2
#define BOT_RIGHT  3

//comment everything to test if this compiles

//static Entity entityList[256];

//uint8_t isCollision(Entity* a, Entity* b);
//void resolveCollision(Entity* a, Entity* b);
//void updateLoc(Entity* e);
//void updateVel(Entity* e);
//void updateState(Entity* e);

// ********************************************
// *             Entity Methods               *
// ********************************************

// Updates an entity's location and velocity
void Entity::update (void) 
{
  Bounds.x += Velocity.x; Bounds.y += Velocity.y;
	Velocity += Acceleration;
}

// TODO: push pop isFull

// ********************************************
// *            EntityList Methods            *
// ********************************************

// Removes the dead/null entities from the list of entities
void EntityList::removeZeroes (void)
{
	int i = 0;
	for (int j = 0; j < MAX_OBJECTS; j++) 
  {	
		if (List[j] != NULL) {	List[i++] = List[j]; } // TODO: doesn't copy over elements, just Moves pointers ... could cause issues
	}	
  nextIndex = i;
}		

Entity * EntityList::pop (void) {
	return (List[--nextIndex]);
}

void EntityList::push (Entity * E) {
  List[nextIndex++] = E;
}

bool EntityList::isFull(void) {
	return (nextIndex >= MAX_OBJECTS);
}

bool EntityList::isEmpty(void) {
	return (!nextIndex);
}

// ********************************************
// *             Quadtree Methods             *
// ********************************************

// recursively clears all quadtrees that are descendants of this quadtree
void Quadtree::clear (void)
{
	for (int i = 0; i < MAX_OBJECTS; i++) {delete objects.List[i];}
	for (int i = 0; i < 4; i++) 
	{
		if (nodes[i] != NULL)
		{
			nodes[i]->clear();
			nodes[i] = NULL;
		}
	}
}

// splits a quadtree into four new sub-quadtrees
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

// finds which quadrant the give rectangle exists in and returns that quadrant
int8_t Quadtree::getQuadrant (Rectangle R) 
{
	int8_t index = INVALID;
	uint32_t horizontalMidpoint = bounds.x + (bounds.w >> 1);
	uint32_t verticalMidpoint = bounds.y + (bounds.h >> 1);
	
	bool topHalf = (R.y < verticalMidpoint)  &&  (R.y + R.h < verticalMidpoint);
	bool bottomHalf = (R.y > verticalMidpoint);
	bool leftHalf = (R.x < horizontalMidpoint)  &&  (R.x + R.w < horizontalMidpoint);
	bool rightHalf = (R.x > horizontalMidpoint);
	
	if (topHalf && leftHalf)          { index = TOP_LEFT; }
	else if (bottomHalf && leftHalf)  { index = BOT_LEFT; }
	else if (topHalf && rightHalf)    { index = TOP_RIGHT; }
	else if (bottomHalf && rightHalf) { index = BOT_RIGHT; }

	return index; // doesn't account for when rectangles overlap the quadrants -- yes it does. Returns -1
                // doesn't account for when rectangles are off the screen -- implementation issue, not method issue
}

//so this thing errors silently. If there are bugs look here first.
//we are probably running out of room in the objects array or maybe
//the quadtree is going past the max levels or I'm shit at pointers
// TODO: test this method ... and I guess the rest of them too
// recursively finds the smallest quadrant in which to insert the given entity
void Quadtree::insert (Entity * E)
{
	if (nodes[0] != NULL) // why nodes[0] -- Check if any are initialized. Since all get "new"-ed at the same time during split()
	{
		int8_t quadrant = getQuadrant(E->Bounds);
		if (quadrant != INVALID) 
		{	
			nodes[quadrant]->insert(E);
			return;
		}
	}
	else if (!objects.isFull()) { objects.push(E); }	
	else if (objects.isFull() && level < MAX_LEVELS)
	{
		if (nodes[0] == NULL) { split(); }
		for (int i = 0; i < objects.nextIndex; i++)
		{
			int8_t quadrant = getQuadrant(objects.List[i]->Bounds);
			if (quadrant != INVALID) { nodes[quadrant]->insert(objects.List[i]); }
			objects.List[i] = 0;
			objects.removeZeroes();
		}
	}
}

//retrieves all objects that could potentially collide in a bounding box
EntityList * Quadtree::retrieve (EntityList * returnObjects, Rectangle R)
{
	int8_t index = getQuadrant(R); 
	if (index != INVALID && nodes[0] != NULL)
	{
		nodes[index]->retrieve(returnObjects, R);
	}
	
	for (int i = 0; i < objects.nextIndex; i++)
	{
		returnObjects->push(objects.List[i]);
	}	
	return returnObjects;
}

void DrawEntities(EntityList L)
{
	Entity * E = L.pop();
	if (E->type == SHIP)
	{
    while (!L.isEmpty())
    {	
      Entity * E = L.pop();
      if (E->type == SHIP)
      {
        ST7735_DrawBitmap(E->Bounds.x, E->Bounds.y, Bitmap_Ship, E->Bounds.w, E->Bounds.h);
      }
    }
  }
}
		

void GameRulesTest(void)
{
	Quadtree * WorldSpace = new Quadtree(0, Rectangle(0,0,128,160)); // initializes gamespace the same size as screen
	Entity * Player = new Entity(Rectangle(50,50,8,8), Vector(0,0), Vector(0,0), SHIP, 0, 0);
	WorldSpace->insert(Player);
	
//	ST7735_DrawBitmap(50,50, Bitmap_Ship, 8, 8);
	EntityList entitiesToDraw;
	WorldSpace->retrieve(&entitiesToDraw, Rectangle(50,50,8,8));
	DrawEntities(entitiesToDraw);
}
