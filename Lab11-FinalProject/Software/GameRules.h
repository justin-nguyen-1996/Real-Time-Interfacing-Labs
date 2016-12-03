#ifndef GAMERULES_H
#define GAMERULES_H

#define ASTEROID_ENTITY    0
#define SHIP_ENTITY        1
#define LASER_ENTITY       2
#define MISSILE_ENTITY     3

const uint16_t SquareRootTable[301] = {
	50,100,141,173,200,224,245,265,283,300,316,
	332,346,361,374,387,400,412,424,436,447,
	458,469,480,490,500,510,520,529,539,548,
	557,566,574,583,592,600,608,616,624,632,
	640,648,656,663,671,678,686,693,700,707,
	714,721,728,735,742,748,755,762,768,775,
	781,787,794,800,806,812,819,825,831,837,
	843,849,854,860,866,872,877,883,889,894,
	900,906,911,917,922,927,933,938,943,949,
	954,959,964,970,975,980,985,990,995,1000,
	1005,1010,1015,1020,1025,1030,1034,1039,1044,1049,
	1054,1058,1063,1068,1072,1077,1082,1086,1091,1095,
	1100,1105,1109,1114,1118,1122,1127,1131,1136,1140,
	1145,1149,1153,1158,1162,1166,1170,1175,1179,1183,
	1187,1192,1196,1200,1204,1208,1212,1217,1221,1225,
	1229,1233,1237,1241,1245,1249,1253,1257,1261,1265,
	1269,1273,1277,1281,1285,1288,1292,1296,1300,1304,
	1308,1311,1315,1319,1323,1327,1330,1334,1338,1342,
	1345,1349,1353,1356,1360,1364,1367,1371,1375,1378,
	1382,1386,1386,1393,1396,1400,1404,1407,1411,1414,
	1418,1421,1425,1428,1432,1435,1439,1442,1446,1449,
	1453,1456,1459,1463,1466,1470,1473,1476,1480,1483,
	1487,1490,1493,1497,1500,1503,1507,1510,1513,1517,
	1520,1523,1526,1530,1533,1536,1539,1543,1546,1549,
	1552,1556,1559,1562,1565,1568,1572,1575,1578,1581,
	1584,1587,1591,1594,1597,1600,1603,1606,1609,1612,
	1616,1619,1622,1625,1628,1631,1634,1637,1640,1643,
	1646,1649,1652,1655,1658,1661,1664,1667,1670,1673,
	1676,1679,1682,1685,1688,1691,1694,1697,1700,1703,
	1706,1709,1712,1715,1718,1720,1723,1726,1729,1732
};

typedef enum {
  ASTEROID,
  SHIP,
  LASER,
  MISSILE,
	PARTICLE
} EntityType;

class Vector {
	public:
	int16_t x;
	int16_t y;
  
  Vector() : x(0), y(0) {}
  Vector(int16_t xx, int16_t yy) : x(xx), y(yy) {}
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
	
	void normalize(int32_t scale)
	{
		int32_t xs = x*x;
		int32_t ys = y*y;
		uint16_t sqrt = SquareRootTable[ (xs + ys) >>10]; // make sure to stay in range of table
		x = ((x * scale) / sqrt);
		y = ((y * scale) / sqrt);
	}
		
		
};

// objects in our system will be located at the top left corner of that image's border
// e.g. if an image has four vertices {(0,0) (0,4) (4,0) (4,4)} then it will be located at (0,0)
class Rectangle {
  public:
	int16_t x;
	int16_t y;
	uint16_t w;
	uint16_t h;
  
  Rectangle(int16_t xx, int16_t yy, uint16_t ww, uint16_t hh) : x(xx), y(yy), w(ww), h(hh) {}
}; 

class Entity {
	public:
	Rectangle Bounds;
	Vector Velocity;
	Vector Acceleration;
	EntityType type; // type will tell us which entity we are working with (shouldn't use Polymorphism in embedded systems)
	uint32_t data1;  // data will be a generic field used for sending data between objects
	uint32_t data2;
	bool dead;
	
	Entity (Rectangle B, Vector V, Vector A, EntityType t, uint32_t d1, uint32_t d2) : 
		Bounds(B), Velocity(V), Acceleration(A), type(t), data1(d1), data2(d2), dead(false) {};
	void update (void);
	uint8_t direction(void);
	void WallCollision(Rectangle B);
};

#define MAX_OBJECTS   100  // the maximum number of entities per quadtree
#define MAX_LEVELS    5   // the granularity of our quadtrees (i.e. a quadtree can only be divided this many times)

class EntityList {
	public:
  Entity * List[MAX_OBJECTS];
	uint8_t nextIndex;
  
	EntityList(void) : nextIndex(0) {}
	//~EntityList(void) { for (int i = 0; i < nextIndex; i++) { delete List[i]; }	}
	~EntityList(void) {}
	void removeZeroes (void);
	void push (Entity * E);
	Entity * pop (void);
	bool isFull(void);
	bool isEmpty(void);
	void update(uint16_t * tstick, uint16_t * accel, uint32_t gameTick);
	void clear(void);
};
	
class Quadtree {
	public:
	uint8_t level;      // the number of times this quadtree has been divided
	EntityList objects; // list of all the entities in this quadtree
	Rectangle bounds;
	Quadtree * nodes[4];
	
	Quadtree (uint8_t l, Rectangle b) : level(l), bounds(b) {}
	void clear (void);
	void split (void);
	int8_t getQuadrant (Rectangle R);
	void insert (Entity * E); 
	void insert (EntityList * E);
	EntityList * retrieve (EntityList * returnObjects, Rectangle R);
	void drawBounds(void);
	
}; //NOTDONE

void NormalizeAnalogInputs(uint16_t * tstick, uint16_t * accel );
void GameRulesTest(void);
void DrawEntities(EntityList * L);
void EraseEntities(EntityList * L);

//uint8_t isCollision(Entity* a, Entity* b);
//void resolveCollision(Entity* a, Entity* b);
//void updateLoc(Entity* e);
//void updateVel(Entity* e);
//void updateState(Entity* e);



#endif
