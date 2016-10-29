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

typedef struct Loc {
  uint8_t x;
  uint8_t y;
} Loc;

typedef struct Vel {
  uint8_t speed;
  uint8_t dir;
} Vel;

typedef struct Entity {
  Vel vel;
  Loc loc;
  EntityType id;
} Entity;

typedef struct Asteroid {
  Vel vel;
  Loc loc;
  Entity id;
} Asteroid;

typedef struct Ship {
  Vel vel;
  Loc loc;
  Entity id;
} Ship;

// TODO: do we want a separate type of entity called "projectile"?
typedef struct Laser {
  Vel vel;
  Loc loc;
  Entity id;
} Laser;

typedef struct Missile {
  Vel vel;
  Loc loc;
  Entity id;
} Missile;

uint8_t isCollision(Entity* a, Entity* b);
void resolveCollision(Entity* a, Entity* b);
void updateLoc(Entity* e);
void updateVel(Entity* e);
void updateState(Entity* e);

#endif
