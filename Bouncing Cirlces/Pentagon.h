#ifndef PENTAGON_H
#define PENTAGON_H

#include "BouncingObject.h"

class Pentagon: public BouncingObject
{
private:
	sf::Vector2f m_p1, m_p2, m_p3, m_p4, m_p5, m_position;
	float size;
	int colourCool;
	
public:
	Pentagon();
	void Bounce();
	void Update();
	void Move();
	void Rotate();
};

#endif