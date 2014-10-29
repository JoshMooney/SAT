#include "stdafx.h"
#include "CollisionDetection.h"


//static bool CheckForCollisionSAT(BouncingObject *obj1, BouncingObject *obj2);
bool CollisionDectection::CheckForCollisionSAT(BouncingObject *obj1, BouncingObject *obj2)
{
	std::vector<sf::Vector2f> axis1 = getAxis(obj1->m_pointArray);	//get all the axis in the two point arrays
	std::vector<sf::Vector2f> axis2 = getAxis(obj2->m_pointArray);
	
	itr = axis1.begin();

	for ( ; itr != axis1.end(); itr++)
	{

	}

	return true;
}

std::vector<sf::Vector2f> CollisionDectection::getAxis(vector<sf::Vector2f> pointArray)
{
	std::vector<sf::Vector2f> sepAxis;	//create the return varible
	sepAxis.reserve(pointArray.capacity());	//Reserve memory 

	sf::Vector2f p1, p2; //Create some temperary Varibles
	for (int i = 0; i < pointArray.size(); i++)
	{
		p1 = pointArray[i];		//Take two edges
		p2 = pointArray[i + 1];

		sf::Vector2f edge = p1 - p2;	//Create a vector from the set of co ordinates

		edge = sf::Vector2f(-edge.y, edge.x);	//Normalise the vector
		sepAxis.push_back(edge);	//Push back onto the vector Array
	}
	return sepAxis;
}
/*
bool sat(Object& shape1, Object& shape2)
{
	sf::Vector2f vectorOffset(shape1.getPosition().x - shape2.getPosition().x, shape1.getPosition().y - shape2.getPosition().y);

	for (int i = 0; i < shape1.getShape().getVertexCount(); i++)
	{
		sf::Vector2f axis = getNormalAxis(shape1.getShape(), i);

		float min1 = dotProduct(axis, shape1.getShape()[0].position);
		float max1 = min1;

		for (int j = 1; j < shape1.getShape().getVertexCount(); j++)
		{
			float testNum = dotProduct(axis, shape1.getShape()[j].position);
			if (testNum < min1)
				min1 = testNum;
			if (testNum > max1)
				max1 = testNum;
		}

		float min2 = dotProduct(axis, shape2.getShape()[0].position);
		float max2 = min2;

		for (int j = 1; j < shape2.getShape().getVertexCount(); j++)
		{
			float testNum = dotProduct(axis, shape2.getShape()[j].position);
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
	return 1;
}
*/
sf::Vector2f normalize(sf::Vector2f& input)
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

sf::Vector2f getNormalAxis(sf::VertexArray& shape, int index)
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

float dotProduct(sf::Vector2f& vector1, sf::Vector2f& vector2)
{
	return vector1.x*vector2.x + vector1.y*vector2.y;
}