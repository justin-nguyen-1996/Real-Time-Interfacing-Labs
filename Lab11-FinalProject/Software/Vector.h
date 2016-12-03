#include <stdint.h>

public class Vector {
	public:
	uint16_t x;
	uint16_t y;
  
  Vector() {
    
  }

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
