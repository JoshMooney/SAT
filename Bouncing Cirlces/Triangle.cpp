#include "stdafx.h"
#include "Triangle.h"

#define _USE_MATH_DEFINES
#include "math.h"

#define DR M_PI/180

Triangle::Triangle()
{
	numPoints = TRIANGLE_POINT_COUNT;
	//numPoints = 3;
	colourCool = 0;
	size = 24;
	//size = 55;

	vertexArray.reserve(numPoints);
	m_pointArray.reserve(numPoints);
	m_position = sf::Vector2f(400,300);
	
	m_pointArray.push_back(sf::Vector2f(cos(DR * 90) * size, sin(DR * 90)* size));
	m_pointArray.push_back(sf::Vector2f(cos(DR * 210)* size, sin(DR * 210)* size));
	m_pointArray.push_back(sf::Vector2f(cos(DR * 330)* size, sin(DR * 330)* size));

	vertexArray.push_back(sf::Vector2f(cos(DR * 90) * size, sin(DR * 90)* size));
	vertexArray.push_back(sf::Vector2f(cos(DR * 210)* size, sin(DR * 210)* size));
	vertexArray.push_back(sf::Vector2f(cos(DR * 330)* size, sin(DR * 330)* size));

	getShape().setPointCount(numPoints);
	getShape().setPoint(0, sf::Vector2f(0, 0));

	getShape().setPoint(0, m_pointArray.at(0));
	getShape().setPoint(1, m_pointArray.at(1));
	getShape().setPoint(2, m_pointArray.at(2));

	getShape().setFillColor(sf::Color::Blue);
	getShape().setOutlineThickness(2);
	getShape().setOutlineColor(sf::Color::White);
}

void Triangle::Bounce()
{
	bool colour = false;
	sf::ConvexShape shape = getShape();
	if(getShape().getPoint(0).x > 800 || getShape().getPoint(0).x < 0 || 
		getShape().getPoint(1).x > 800 || getShape().getPoint(1).x < 0 || 
		getShape().getPoint(2).x > 800 || getShape().getPoint(2).x < 0) 
	{swapDirectionX();	/*colour = true; /*size = 10;*/}

	if(getShape().getPoint(0).y > 600 || getShape().getPoint(0).y < 0 || 
		getShape().getPoint(1).y > 600 || getShape().getPoint(1).y < 0 || 
		getShape().getPoint(2).y > 600 || getShape().getPoint(2).y < 0) 
	{swapDirectionY();	/*colour = true; /*size = 10;*/}

	if(colour)
	{
		getShape().setFillColor(sf::Color::White);
		colourCool = 0;
	}
}

void Triangle::Move()
{
	m_position += getDirection();

	m_pointArray.at(0) = sf::Vector2f(getRotationMatrix() * sf::Vector2f(cos(DR * 90)* size, sin(DR * 90)* size)); // 0 ,20
	m_pointArray.at(1) = sf::Vector2f(getRotationMatrix() * sf::Vector2f(cos(DR * 210)* size, sin(DR * 210)* size));
	m_pointArray.at(2) = sf::Vector2f(getRotationMatrix() * sf::Vector2f(cos(DR * 330)* size, sin(DR * 330)* size));

	getShape().setPoint(0, m_position + m_pointArray.at(0));
	getShape().setPoint(1, m_position + m_pointArray.at(1));
	getShape().setPoint(2, m_position + m_pointArray.at(2));

	vertexArray.at(0) = getShape().getPoint(0);
	vertexArray.at(1) = getShape().getPoint(1);
	vertexArray.at(2) = getShape().getPoint(2);
}

void Triangle::Update()
{
	if(getShape().getFillColor() == sf::Color::White)
			colourCool ++;
	if(colourCool == 500)
	{
		colourCool = 0;
		getShape().setFillColor(sf::Color::Blue);
		size = 24;
	}
	Triangle::Bounce();
	Triangle::Move();
}




