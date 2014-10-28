#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "BouncingObject.h"

class Triangle: public BouncingObject {
private:
	float size;
	int colourCool;
	
public:
	static const int TRIANGLE_POINT_COUNT = 3;
	sf::Vector2f m_p1, m_p2, m_p3, m_position;
	Triangle();
	void Bounce();
	void Update();
	void Move();
	void Rotate();
};

#endif