
extern "C"{
	#include <stdint.h>
	#include "../inc/tm4c123gh6pm.h"
	#include "ST7735.h"
	#include "Graphics.h"
	#include "Thumbstick.h"
	#include "Accel.h"
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

void Entity::WallCollision(Rectangle B)
{
	if (type == SHIP)
	{
		if (Bounds.x < B.x) {Bounds.x = B.x;}
		if (Bounds.x + Bounds.w > B.x + B.w) { Bounds.x = B.x + B.w - Bounds.w; }
		if (Bounds.y < B.y) {Bounds.y = B.y;}
		if (Bounds.y + Bounds.h > B.y + B.h) { Bounds.y = B.y + B.h - Bounds.h; }
	}
}


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

void EntityList::update(uint16_t * tstick, uint16_t * accel) {
	for (int i = 0; i < nextIndex; i++) {
		Entity * E = List[i];
		E->update();

		if (E->type == SHIP) {
			E->Velocity.x = (int16_t) tstick[TSTICK2_H];
			E->Velocity.y = (int16_t) tstick[TSTICK2_V];
		} else if (E->type == MISSILE  ||  E->type == SHIP) {
			ST7735_SetCursor(0,0); ST7735_OutUDec(accel[ACCEL_X]);
			ST7735_SetCursor(0,1); ST7735_OutUDec(accel[ACCEL_Y]);
			E->Velocity.x = (int16_t) accel[ACCEL_X];
			E->Velocity.y = (int16_t) accel[ACCEL_Y];
		}
	}
}

void EntityList::clear(void) {
	for (int i = 0; i < MAX_OBJECTS; i++)
	{
		List[i] = 0;
	}
	nextIndex = 0;
}



// ********************************************
// *             Quadtree Methods             *
// ********************************************

// recursively clears all quadtrees that are descendants of this quadtree
void Quadtree::clear (void)
{
	objects.clear();
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
	int16_t x = bounds.x;
	int16_t y = bounds.y;
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
	int16_t horizontalMidpoint = bounds.x + (bounds.w >> 1);
	int16_t verticalMidpoint = bounds.y + (bounds.h >> 1);

	bool topHalf = (R.y > bounds.y)  &&  (R.y + R.h < verticalMidpoint);
	bool bottomHalf = (R.y > verticalMidpoint) && (R.y + R.h < bounds.y + bounds.h);
	bool leftHalf = (R.x > bounds.x)  &&  (R.x + R.w < horizontalMidpoint);
	bool rightHalf = (R.x > horizontalMidpoint) && (R.x + R.w < bounds.x + bounds.w);

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

//only call this function when inserting to root node of the quadtree
void Quadtree::insert (EntityList * L)
{
	for (int i = 0; i < L->nextIndex; i++)
	{
		if (L->List[i]->type == SHIP && getQuadrant(L->List[i]->Bounds) == -1) { L->List[i]->WallCollision(bounds); }
		insert(L->List[i]);
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

void Quadtree::drawBounds (void)
{
	ST7735_Line(bounds.x>>7, bounds.y>>7, (bounds.x + bounds.w)>>7, bounds.y>>7);
	ST7735_Line((bounds.x + bounds.w)>>7, bounds.y>>7, (bounds.x + bounds.w)>>7, (bounds.y + bounds.h)>>7);
	ST7735_Line(bounds.x>>7, (bounds.y + bounds.h)>>7, (bounds.x + bounds.w)>>7, (bounds.y + bounds.h)>>7);
	ST7735_Line(bounds.x>>7, bounds.y>>7, bounds.x>>7, (bounds.y + bounds.h)>>7);
	if (nodes[0] != NULL)
	{
		nodes[0]->drawBounds();
		nodes[1]->drawBounds();
		nodes[2]->drawBounds();
		nodes[3]->drawBounds();
	}
}


void DrawEntities(EntityList * L)
{
	for (int i = 0; i < L->nextIndex; i++)
	{
		Entity * E = L->List[i];
		const unsigned short* bitmap;
		
		if (E->type == SHIP) { bitmap = Bitmap_Ship; }
		else if (E->type == LASER) { bitmap = Bitmap_GreenLaser; }
		
		ST7735_DrawBitmap(E->Bounds.x >> 7, E->Bounds.y + E->Bounds.h >> 7, bitmap, E->Bounds.w >> 7, E->Bounds.h >> 7);
	}
}

void EraseEntities(EntityList * L)
{
	for (int i = 0; i < L->nextIndex; i++)
	{
		Entity * E = L->List[i];
		ST7735_FillRect((E->Bounds.x>>7), (E->Bounds.y>>7), (E->Bounds.w>>7), (E->Bounds.h>>7), ST7735_BLACK);
	}
}

#define DEADZONE_TSTICK_MIN    1800
#define DEADZONE_TSTICK_MAX    2200
#define DEADZONE_ACCEL_XY_MIN  1900
#define DEADZONE_ACCEL_XY_MAX  2100
#define DEADZONE_ACCEL_Z_MIN   1500
#define DEADZONE_ACCEL_Z_MAX   1700

void NormalizeAnalogInputs( uint16_t * tstick, uint16_t * accel )
{
	// left shift 7 (for precision) and divide by 1000 (>>10)
	// first if clauses check for dead zones
	// second if clauses are checking for negative numbers ... stuff gets typecasted to signed numbers in update ... yeah we know it's bad
	// third if clauses are similar --> simply check and calibrate

	for (int i = 0; i < 4; i++) { // normalize thumbsticks
		if (DEADZONE_TSTICK_MIN <= tstick[i] && DEADZONE_TSTICK_MAX >= tstick[i]) { tstick[i] = 0; }
		else if (DEADZONE_TSTICK_MIN > tstick[i]) { tstick[i] = ((tstick[i] - DEADZONE_TSTICK_MIN) << 7) >> 10; }
		else { tstick[i] = ((tstick[i] - DEADZONE_TSTICK_MAX) << 7) >> 10; }
	}

    for (int i = 0; i < 3; ++i) { // normalize accelerometer
    	if (i < 2) {
			if (DEADZONE_ACCEL_XY_MIN <= accel[i]  &&  accel[i] <= DEADZONE_ACCEL_XY_MAX) { accel[i] = 0; }
			else if (accel[i] < DEADZONE_ACCEL_XY_MIN) { accel[i] = ((accel[i] - DEADZONE_ACCEL_XY_MIN) << 7) >> 10; }
			else { accel[i] = ((accel[i] - DEADZONE_ACCEL_XY_MAX) << 7) >> 10; }
		}
		else {
			if (DEADZONE_ACCEL_Z_MIN <= accel[i]  &&  accel[i]  <= DEADZONE_ACCEL_Z_MAX) { accel[i] = 0; }
			else if (accel[i] < DEADZONE_ACCEL_Z_MIN) { accel[i] = ((accel[i] - DEADZONE_ACCEL_Z_MIN) << 7) >> 10; }
			else { accel[i] = ((accel[i] - DEADZONE_ACCEL_Z_MAX) << 7) >> 10; }
		}
    }
}

void GameRulesTest(void)
{
	Quadtree * WorldSpace = new Quadtree(0, Rectangle(0,0,128,160)); // initializes gamespace the same size as screen
	Entity * Player = new Entity(Rectangle(50,50,8,8), Vector(0,0), Vector(0,0), SHIP, 0, 0);
	WorldSpace->insert(Player);

//	ST7735_DrawBitmap(50,50, Bitmap_Ship, 8, 8);
	EntityList * entitiesToDraw;
	WorldSpace->retrieve(entitiesToDraw, Rectangle(50,50,8,8));
	DrawEntities(entitiesToDraw);
}
