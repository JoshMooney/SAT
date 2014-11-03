#include "stdafx.h"
#include "Rectangle.h"

MyRectangle::MyRectangle()
{
	numPoints = RECTANGLE_POINT_COUNT;
	colourCool = 0;
	size = 20;

	m_pointArray.reserve(numPoints);
	getShape().setPointCount(numPoints);

	m_position = sf::Vector2f(400,300);

	m_pointArray.push_back(sf::Vector2f(20 , -20));
	m_pointArray.push_back(sf::Vector2f(-20 , 20));
	m_pointArray.push_back(sf::Vector2f(20, 20));
	m_pointArray.push_back(sf::Vector2f(-20 , -20));

	getShape().setPoint(0, m_pointArray.at(0));
	getShape().setPoint(1, m_pointArray.at(1));
	getShape().setPoint(2, m_pointArray.at(2));
	getShape().setPoint(3, m_pointArray.at(3));

	getShape().setFillColor(sf::Color::Green);
	getShape().setOutlineThickness(2);
	getShape().setOutlineColor(sf::Color::White);
}

void MyRectangle::Bounce()
{
	bool colour = false;

	if(getShape().getPoint(0).x > 800 || getShape().getPoint(0).x < 0 || 
		getShape().getPoint(1).x > 800 || getShape().getPoint(1).x < 0 || 
		getShape().getPoint(2).x > 800 || getShape().getPoint(2).x < 0 || 
		getShape().getPoint(3).x > 800 || getShape().getPoint(3).x < 0) 
	{swapDirectionX();	colour = true;}

	if(getShape().getPoint(0).y > 600 || getShape().getPoint(0).y < 0 || 
		getShape().getPoint(1).y > 600 || getShape().getPoint(1).y < 0 || 
		getShape().getPoint(2).y > 600 || getShape().getPoint(2).y < 0 || 
		getShape().getPoint(3).y > 600 || getShape().getPoint(3).y < 0) 
	{swapDirectionY();	colour = true;}

	if(colour)
	{
		getShape().setFillColor(sf::Color::White);
		colourCool = 0;
	}
}

void MyRectangle::Move()
{
	m_position += getDirection();

	m_pointArray.at(0) = sf::Vector2f(getRotationMatrix() * sf::Vector2f(-20 , 30));
	m_pointArray.at(1) = sf::Vector2f(getRotationMatrix() * sf::Vector2f(20 , 30));
	m_pointArray.at(2) = sf::Vector2f(getRotationMatrix() * sf::Vector2f(20, -30));
	m_pointArray.at(3) = sf::Vector2f(getRotationMatrix() * sf::Vector2f(-20 , -30));

	getShape().setPoint(0, m_position + m_pointArray.at(0));
	getShape().setPoint(1, m_position + m_pointArray.at(1));
	getShape().setPoint(2, m_position + m_pointArray.at(2));
	getShape().setPoint(3, m_position + m_pointArray.at(3));
}

void MyRectangle::Update()
{
	if(getShape().getFillColor() == sf::Color::White)
			colourCool ++;
	if(colourCool == 500)
	{
		colourCool = 0;
		getShape().setFillColor(sf::Color::Green);
	}
	MyRectangle::Bounce();
	MyRectangle::Move();
}