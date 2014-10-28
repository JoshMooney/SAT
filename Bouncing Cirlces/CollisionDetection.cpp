#include "stdafx.h"
#include "CollisionDetection.h"


//static bool CheckForCollisionSAT(BouncingObject *obj1, BouncingObject *obj2);
bool CollisionDectection::CheckForCollisionSAT(BouncingObject *obj1, BouncingObject *obj2)
{
	std::vector<sf::Vector2f> axis1 = getAxis(obj1->m_pointArray);	//get all the axis in the two point arrays
	std::vector<sf::Vector2f> axis2 = getAxis(obj2->m_pointArray);

	//for(std::iterator<std::vector> itr = axis1.begin(); itr != axis1.end(); )

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