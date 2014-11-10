#include "stdafx.h"
#include "CollisionDetection.h"

#include <math.h>

bool CollisionDectection::CheckCollision(BouncingObject &obj1, BouncingObject &obj2)
{
	bool collide = false;
	//if (SimpleCollision(obj1.getRadius(), obj1.getPosition(), obj2.getRadius(), obj2.getPosition()))
		collide = CheckForCollisionSAT(obj1.getVertexArray(), obj2.getVertexArray());
	return collide;
}

bool CollisionDectection::SimpleCollision(float obj1Radius, sf::Vector2f obj1Position, float obj2Radius, sf::Vector2f obj2Position)
{
	float distance = sqrt(((obj2Position.x + obj1Position.x) * (obj2Position.x + obj1Position.x)) + ((obj2Position.y + obj1Position.y) * (obj2Position.y + obj1Position.y)));
	return (distance < obj1Radius + obj2Radius);
}

bool CollisionDectection::CheckForCollisionSAT(vector<sf::Vector2f> obj1Vertex, vector<sf::Vector2f> obj2Vertex)
{
	std::vector<sf::Vector2f> axis = getAxis(obj1Vertex, obj2Vertex);	//Get all the seperating Axis of the twoShapes

	for (int i = 0; i < axis.size(); i++)
	{
		float min1 = FLT_MAX;		//Set min
		float max1 = -FLT_MAX;		//Set max

		for (int j = 0; j < obj1Vertex.size(); j++)		//Loop through the object and find the min and max of this axis
		{
			float testNum = dotProduct(axis.at(i), obj1Vertex.at(j));
			if (testNum < min1)
				min1 = testNum;
			if (testNum > max1)
				max1 = testNum;
		}

		float min2 = FLT_MAX;
		float max2 = -FLT_MAX;

		for (int j = 0; j < obj2Vertex.size(); j++)
		{
			float testNum = dotProduct(axis.at(i), obj2Vertex.at(j));
			if (testNum < min2)
				min2 = testNum;
			if (testNum > max2)
				max2 = testNum;
		}

		if (max1 < min2 || max2 < min1)
			return 0;
	}
	return 1;						//Else no gap is found so they must be colliding
}

std::vector<sf::Vector2f> CollisionDectection::getAxis(vector<sf::Vector2f> pointArray, vector<sf::Vector2f> pointArray2)
{
	std::vector<sf::Vector2f> sepAxis;									//create the return variable
	sepAxis.reserve(pointArray.capacity() + pointArray2.capacity());	//Reserve memory 

	sf::Vector2f p1, p2; //Create some temp variable
	for (int i = 0; i < pointArray.size(); i++)
	{
		p1 = pointArray[i];	
		if (i >= pointArray.size() - 1)
			p2 = pointArray.at(0);
		else
			p2 = pointArray.at(i + 1);

		sf::Vector2f normalAxis(-(p1.y - p2.y), p1.x - p2.x);
		normalAxis = normalize(normalAxis);
		sepAxis.push_back(normalAxis);	//Push back onto the vector Array
	}

	for (int i = 0; i < pointArray2.size(); i++)
	{
		p1 = pointArray2[i];	
		if (i >= pointArray2.size() - 1)
			p2 = pointArray2.at(0);
		else
			p2 = pointArray2.at(i + 1);

		sf::Vector2f normalAxis(-(p1.y - p2.y), p1.x - p2.x);
		normalAxis = normalize(normalAxis);
		sepAxis.push_back(normalAxis);	//Push back onto the vector Array
	}

	return sepAxis;
}

sf::Vector2f CollisionDectection::normalize(const sf::Vector2f input)
{
	float length = sqrt(input.x*input.x + input.y*input.y);
	return input / length;
}
float CollisionDectection::dotProduct(sf::Vector2f &vector1, sf::Vector2f &vector2)
{
	return vector1.x*vector2.x + vector1.y*vector2.y;
}