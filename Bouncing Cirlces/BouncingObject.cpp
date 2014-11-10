#include "stdafx.h"
#include "BouncingObject.h"

BouncingObject::BouncingObject()
{
	m_direction = sf::Vector2f((static_cast <float>(rand() % 100 + 1)) / 1000, (static_cast <float>(rand() % 100 + 1)) / 1000);
	//m_direction = sf::Vector2f((static_cast <float>(rand() % 100 + 1)) / 500, (static_cast <float>(rand() % 100 + 1)) / 500);
	int num = rand() % 2;
	if(num >= 1){swapDirectionX();}
	num = rand() % 2;
	if(num >= 1){swapDirectionY();}

	m_rot = static_cast <float>(rand() % 8 + 5)/ 100;
	num = rand() % 2;
	//if(num >= 1){m_rot * -1;}
	m_rotationMatrix.rotate(m_rot);
	colourCool = 0;
	vertexCount = 0;
	radius = 30;
	
}

//void setDirection(sf::Vector2f dir);
void BouncingObject::setDirection(sf::Vector2f dir)
{
	m_direction = dir;
}

//void setDirectionX(float d);
void BouncingObject::swapDirectionX()
{
	m_direction.x *= -1;
}

//void setDirectionY(float d);
void BouncingObject::swapDirectionY()
{
	m_direction.y *= -1;
}

//sf::Vector2f getDirection();
sf::Vector2f BouncingObject::getDirection()
{
	return m_direction;
}

//void Update();
void BouncingObject::Update()
{

}

//void Draw(sf::RenderWindow& w);
void BouncingObject::Draw(sf::RenderWindow& w)
{
	m_rotationMatrix.rotate(m_rot);
	w.draw(m_shape);
}

//void setShape(sf::ConvexShape)
void BouncingObject::setShape(sf::ConvexShape shape)
{
	m_shape = shape;
}

//sf::Transform getRotationMatrix();
sf::Transform BouncingObject::getRotationMatrix()
{
	return m_rotationMatrix;
}

//void setRotationMatrix(sf::Transform rotMatrix);
void BouncingObject::setRotationMatrix()
{
	m_rotationMatrix.rotate(m_rot);
}

//float getRotation();
float BouncingObject::getRotation()
{
	return m_rot;
}

//void setRotation(float r);
void BouncingObject::setRotation(float r)
{
	m_rot = r;
}

sf::ConvexShape& BouncingObject::getShape()	
{ 
	return m_shape; 
}

//vector<sf::Vector2f> getVertexArray();
vector<sf::Vector2f> BouncingObject::getVertexArray()
{
	vertexArray.clear();
	for (int i = 0; i < m_shape.getPointCount(); i++)
		vertexArray.push_back(m_shape.getPoint(i));
	return vertexArray;
}

void BouncingObject::BounceObject(sf::Vector2f otherPos)
{
	sf::Vector2f H = getPosition() - otherPos;
	H /= sqrt(H.x * H.x + H.y * H.y);
	m_direction = m_direction - 2 * (m_direction.x * H.x + m_direction.y * H.y) * H;
}