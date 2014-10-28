#ifndef COLLISIONDETECTION_H
#define COLLISIONDECTECTION_H

#include "BouncingObject.h"

class CollisionDectection
{
private:

public:
	CollisionDectection();
	static bool CheckForCollisionSAT(BouncingObject *obj1, BouncingObject *obj2);
	static std::vector<sf::Vector2f> getAxis(vector<sf::Vector2f> pointArray);
};

#endif