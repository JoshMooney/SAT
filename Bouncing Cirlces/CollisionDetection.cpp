#include "stdafx.h"
#include "CollisionDetection.h"


bool CollisionDectection::CheckForCollisionSAT(BouncingObject &obj1, BouncingObject &obj2)
{
	std::vector<sf::Vector2f> axis = getAxis(obj1.getVertexArray(), obj2.getVertexArray());	//Get all the seperating Axis of the twoShapes
	std::vector<sf::Vector2f> obj1Points = obj1.getVertexArray();
	std::vector<sf::Vector2f> obj2Points = obj2.getVertexArray();

	for (int i = 0; i < axis.size(); i++)
	{
		float min1 = FLT_MAX;		//Set min
		float max1 = -FLT_MAX;		//Set max

		for (int j = 0; j < obj1.getShape().getPointCount(); j++)		//Loop through the object and find the min and max of this axis
		{
			float testNum = dotProduct(axis.at(i), obj1Points.at(j));
			if (testNum < min1)
				min1 = testNum;
			if (testNum > max1)
				max1 = testNum;
		}

		float min2 = FLT_MAX;
		float max2 = -FLT_MAX;

		for (int j = 0; j < obj2.getShape().getPointCount(); j++)
		{
			float testNum = dotProduct(axis.at(i), obj2Points.at(j));
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