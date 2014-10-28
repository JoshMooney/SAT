#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "BouncingObject.h"

class MyRectangle: public BouncingObject
{
private:
	float size;
	int colourCool;
	
public:
	static const int RECTANGLE_POINT_COUNT = 4;
	sf::Vector2f m_p1, m_p2, m_p3, m_p4, m_position;
	MyRectangle();
	void Bounce();
	void Update();
	void Move();
	void Rotate();
};

#endif