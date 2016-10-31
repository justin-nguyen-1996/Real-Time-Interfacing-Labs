#ifndef GAMERULES_H
#define GAMERULES_H

#include <stdint.h>

#define ASTEROID_ENTITY    0
#define SHIP_ENTITY        1
#define LASER_ENTITY       2
#define MISSILE_ENTITY     3

typedef enum {
  ASTEROID,
  SHIP,
  LASER,
  MISSILE
} EntityType;

class Vector {
	public:
	uint16_t x;
	uint16_t y;
  
  Vector() : x(0), y(0) {}
  Vector(uint16_t xx, uint16_t yy) : x(xx), y(yy) {}
    // TODO: Vector(Vector v) : x(v.x), y(v.y) {}

	Vector operator+(const Vector & v)
	{
		Vector c;
		c.x = x + v.x;
		c.y = y + v.y;
		return c;
	}

	Vector operator+=(const Vector & v)
	{
		x = x + v.x;
		y = y + v.y;
		return *this;
	} 
};

class Rectangle {
  public:
	uint16_t x;
	uint16_t y;
	uint16_t w;
	uint16_t h;
  
  Rectangle(uint16_t xx, uint16_t yy, uint16_t ww, uint16_t hh) : x(xx), y(yy), w(ww), h(hh) {}
}; 

class Entity {
	public:
	Rectangle Bounds;
	Vector Velocity;
	Vector Acceleration;
	EntityType type;
	uint32_t data1;
	uint32_t data2;
	
	Entity (Rectangle B, Vector V, Vector A, EntityType t, uint32_t d1, uint32_t d2) : 
		Bounds(B), Velocity(V), Acceleration(A), type(t), data1(d1), data2(d2) {};
	void update (void);
};

#define MAX_OBJECTS 10
#define MAX_LEVELS 5

class EntityList {
	public:
  Entity * List[MAX_OBJECTS]; // TODO: supposed to be an array of Entity pointers (which is what it is now) or an array of entities?
	uint8_t nextIndex;
  
  // TODO: need to overload the subscript operator (but to do this, first resolve previous todo 3 lines up)
//  Entity& operator[] (const int index) {
//    return List[index];
//  }
	
	EntityList(void) : nextIndex(0) {}
	~EntityList(void) { for (int i = 0; i < nextIndex; i++) { delete List[i]; }	}
	void removeOs (void);
//TODO:
	void push (Entity * E);
	Entity * pop (void);
	bool isFull(void);
};
	
class Quadtree {
	public:
	uint8_t level;
	EntityList objects;
	Rectangle bounds;
	Quadtree * nodes[4];
	
	Quadtree (uint8_t l, Rectangle b) : level(l), bounds(b) {}
	void clear (void);
	void split (void);
	int8_t getIndex (Rectangle R);
	void insert (Entity * E); 
	EntityList retrieve (EntityList returnObjects, Rectangle R);
	
}; //NOTDONE
	
	
	


//uint8_t isCollision(Entity* a, Entity* b);
//void resolveCollision(Entity* a, Entity* b);
//void updateLoc(Entity* e);
//void updateVel(Entity* e);
//void updateState(Entity* e);



#endif
