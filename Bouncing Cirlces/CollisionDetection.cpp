#include "stdafx.h"
#include "CollisionDetection.h"


//static boolean CheckForCollisionSAT(BouncingObject *obj1, BouncingObject *obj2);
bool CollisionDectection::CheckForCollisionSAT(BouncingObject &obj1, BouncingObject &obj2)
{
	sf::Vector2f vectorOffset(obj1.getPosition().x - obj2.getPosition().x, obj1.getPosition().y - obj2.getPosition().y);	//Get the distance between the two shapes

	std::vector<sf::Vector2f> axis1 = getAxis(obj1.getPointArray());	//Get all the seperating Axis of the twoShapes
	std::vector<sf::Vector2f> axis2 = getAxis(obj2.getPointArray());

	for (int i = 0; i < obj1.getShape().getPointCount(); i++)
	{
		float min1 = dotProduct(axis1.at(i), obj1.getPointArray().at(i));
		float max1 = min1;

		for (int j = 1; j < obj1.getShape().getPointCount(); j++)
		{
			float testNum = dotProduct(axis1.at(j), obj1.getPointArray().at(j));
			if (testNum < min1)
				min1 = testNum;
			if (testNum > max1)
				max1 = testNum;
		}

		float min2 = dotProduct(axis1.at(i), obj2.getPointArray().at(i));
		float max2 = min2;

		for (int j = 1; j < obj2.getShape().getPointCount(); j++)
		{
			float testNum = dotProduct(axis2.at(j), obj2.getPointArray().at(j));
			if (testNum < min2)
				min2 = testNum;
			if (testNum > max2)
				max2 = testNum;
		}

		float offset = dotProduct(axis1.at(i), vectorOffset);
		min1 += offset;
		max1 += offset;

		float test1 = min1 - max2;
		float test2 = min2 - max1;

		if (test1 > 0 || test2 > 0)
			return 0;				//if gap is found return false
	}
	return 1;						//Else no gap is found so they must be colliding
}

std::vector<sf::Vector2f> CollisionDectection::getAxis(vector<sf::Vector2f> pointArray)
{
	std::vector<sf::Vector2f> sepAxis;	//create the return variable
	sepAxis.reserve(pointArray.capacity());	//Reserve memory 

	sf::Vector2f p1, p2; //Create some temp variable
	for (int i = 0; i < pointArray.size(); i++)
	{
		p1 = pointArray[i];		//Take one edge
		if (i <= pointArray.size() - 1)
			p2 = pointArray.at(0);
		else
			p2 = pointArray.at(i + 1);

		sf::Vector2f normalAxis(-(p1.y - p2.y), p1.x - p2.x);
		normalAxis = normalize(normalAxis);
		sepAxis.push_back(normalAxis);	//Push back onto the vector Array
	}

	return sepAxis;
}

sf::Vector2f CollisionDectection::getNormalAxis(sf::VertexArray shape, int index)
{
	sf::Vector2f vector1 = shape[index].position;
	sf::Vector2f vector2;
	if (index >= shape.getVertexCount() - 1)
		vector2 = shape[0].position;
	else
		vector2 = shape[index + 1].position;

	sf::Vector2f normalAxis(-(vector2.y - vector1.y), vector2.x - vector1.x);
	normalAxis = normalize(normalAxis);
	return normalAxis;
}

bool CollisionDectection::sat(BouncingObject shape1, BouncingObject shape2)
{
	/*
	std::vector<sf::Vector2f> axis1 = getAxis(obj1->m_pointArray);	//get all the axis in the two point arrays
	std::vector<sf::Vector2f> axis2 = getAxis(obj2->m_pointArray);

	itr = axis1.begin();

	for ( ; itr != axis1.end(); itr++)
	{

	}
	*//*
	sf::Vector2f vectorOffset(obj1.getPosition().x - obj2.getPosition().x, obj1.getPosition().y - obj2.getPosition().y);

	for (int i = 0; i < obj1.getShape().getPointCount(); i++)
	{
		sf::Vector2f axis = getNormalAxis(obj1.getVertexArray(), i);


		float min1 = dotProduct(axis, obj1.getVertexArray()[0].position);
		//float min1 = dotProduct(axis, shape1.getShape()[0].position);
		float max1 = min1;

		for (int j = 1; j < obj1.getShape().getPointCount(); j++)
		{
			//float testNum = dotProduct(axis, shape1.getShape()[j].position);
			float testNum = dotProduct(axis, obj1.getVertexArray()[j].position);
			if (testNum < min1)
				min1 = testNum;
			if (testNum > max1)
				max1 = testNum;
		}

		float min2 = dotProduct(axis, obj2.getVertexArray()[0].position);
		float max2 = min2;

		for (int j = 1; j < obj2.getShape().getPointCount(); j++)
		{
			//float testNum = dotProduct(axis, shape2.getShape()[j].position);
			float testNum = dotProduct(axis, obj2.getVertexArray()[j].position);
			if (testNum < min2)
				min2 = testNum;
			if (testNum > max2)
				max2 = testNum;
		}

		float offset = dotProduct(axis, vectorOffset);
		min1 += offset;
		max1 += offset;

		float test1 = min1 - max2;
		float test2 = min2 - max1;

		if (test1 > 0 || test2 > 0)
			return 0;
	}
	return 1;*/
	return true;
}

sf::Vector2f CollisionDectection::normalize(sf::Vector2f input)
{
	if (sqrt(input.x*input.x + input.y*input.y) == 0)
	{
		input.x = 1;
		return input;
	}
	float length = sqrt(input.x*input.x + input.y*input.y);

	input.x /= length;
	input.y /= length;
	return input;
}

float CollisionDectection::dotProduct(sf::Vector2f &vector1, sf::Vector2f &vector2)
{
	return vector1.x*vector2.x + vector1.y*vector2.y;
}