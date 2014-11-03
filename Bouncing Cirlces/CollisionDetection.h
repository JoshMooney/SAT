#ifndef COLLISIONDETECTION_H
#define COLLISIONDECTECTION_H

#include "BouncingObject.h"

class CollisionDectection
{
private:

public:
	CollisionDectection()	{}
	static bool CheckForCollisionSAT(BouncingObject &obj1, BouncingObject &obj2);
	static std::vector<sf::Vector2f> getAxis(vector<sf::Vector2f> pointArray, vector<sf::Vector2f> pointArray2);
	static float dotProduct(sf::Vector2f &vector1, sf::Vector2f &vector2);
	static sf::Vector2f normalize(sf::Vector2f input);
};

#endif