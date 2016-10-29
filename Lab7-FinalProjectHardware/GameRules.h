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

//typedef struct Loc {
//  uint8_t x;
//  uint8_t y;
//} Loc;
//
//typedef struct Vel {
//  uint8_t speed;
//  uint8_t dir;
//} Vel;

typedef struct Vector {
	public:
	uint16_t x;
	uint16_t y;

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
} Vector;

class Spatial {
	public:
	Vector Position;
	Vector Velocity;
	Vector Acceleration;
	
	Spatial (Vector P, Vector V, Vector A) : Position(P), Velocity(V), Acceleration(A) {};
	void update (void);
};
	
//typedef struct Entity {
//  Vel vel;
//  Loc loc;
//  EntityType id;
//} Entity;

class Asteroid : public Spatial {
	public:
	uint8_t radius;
	Asteroid (Vector P, Vector V, Vector A, uint8_t r) : Spatial(P, V, A), radius(r) {}
};

class Ship : public Spatial {
	uint8_t playerID;
	uint16_t health;
	uint16_t bullets;
// other things like reload time remaining, rate of fire, special weapons, special abilities, etc.
	Ship (uint8_t pID, uint16_t h, uint16_t b, Vector P, Vector V, Vector A) : 
		Spatial(P, V, A), playerID(pID), health(h), bullets(b) {}
	
};

// Base class for things that do damage
// timer is for things that will dissapear or blow up after some delay
class Shoot : public Spatial {
	uint8_t damage;
	uint16_t timer;
	Shoot (Vector P, Vector V, Vector A, uint8_t d, uint16_t t) : Spatial(P, V, A), damage(d), timer(t) {}
};

//typedef struct Laser {
//  Vel vel;
//  Loc loc;
//  Entity id;
//} Laser;
//
//typedef struct Missile {
//  Vel vel;
//  Loc loc;
//  Entity id;
//} Missile;

//still reading about collisions in a quadtree

//uint8_t isCollision(Entity* a, Entity* b);
//void resolveCollision(Entity* a, Entity* b);
//void updateLoc(Entity* e);
//void updateVel(Entity* e);
//void updateState(Entity* e);

#endif
