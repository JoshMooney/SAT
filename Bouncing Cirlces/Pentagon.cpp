#include "stdafx.h"
#include "Pentagon.h"

#define _USE_MATH_DEFINES
#include "math.h"

#define DR M_PI/180

Pentagon::Pentagon()
{
	colourCool = 0;
	size = 20;
	vertexArray.reserve(5);
	getShape().setPointCount(5);

	//m_position = sf::Vector2f(400,300);
	m_position = sf::Vector2f((static_cast <float>(rand() % 800)), (static_cast <float>(rand() % 600)));

	m_p1 = sf::Vector2f(20 , -20);
	m_p2 = sf::Vector2f(-20 , 20);
	m_p3 = sf::Vector2f(20, 20);
	m_p4 = sf::Vector2f(-20 , -20);
	m_p5 = sf::Vector2f(-20 , -20);

	getShape().setPoint(0, m_p1);
	getShape().setPoint(1, m_p2);
	getShape().setPoint(2, m_p3);
	getShape().setPoint(3, m_p4);
	getShape().setPoint(4, m_p5);

	getShape().setFillColor(sf::Color::Magenta);
	getShape().setOutlineThickness(2);
	getShape().setOutlineColor(sf::Color::White);
}

void Pentagon::Bounce()
{
	bool colour = false;

	if(getShape().getPoint(0).x > 800 || getShape().getPoint(0).x < 0 || 
		getShape().getPoint(1).x > 800 || getShape().getPoint(1).x < 0 || 
		getShape().getPoint(2).x > 800 || getShape().getPoint(2).x < 0 || 
		getShape().getPoint(3).x > 800 || getShape().getPoint(3).x < 0|| 
		getShape().getPoint(4).x > 800 || getShape().getPoint(4).x < 0) 
	{swapDirectionX();	colour = true;}

	if(getShape().getPoint(0).y > 600 || getShape().getPoint(0).y < 0 || 
		getShape().getPoint(1).y > 600 || getShape().getPoint(1).y < 0 || 
		getShape().getPoint(2).y > 600 || getShape().getPoint(2).y < 0 || 
		getShape().getPoint(3).y > 600 || getShape().getPoint(3).y < 0 || 
		getShape().getPoint(4).y > 600 || getShape().getPoint(4).y < 0) 
	{swapDirectionY();	colour = true;}

	if(colour)
	{
		getShape().setFillColor(sf::Color::White);
		colourCool = 0;
	}
}

void Pentagon::Move()
{
	m_position += getDirection();

	m_p1 = getRotationMatrix() * sf::Vector2f(cos(DR * 90)* size, sin(DR * 90)* size);
	m_p2 = getRotationMatrix() * sf::Vector2f(cos(DR * 150)* size, sin(DR * 150)* size);
	m_p3 = getRotationMatrix() * sf::Vector2f(cos(DR * 225)* size, sin(DR * 225)* size);
	m_p4 = getRotationMatrix() * sf::Vector2f(cos(DR * 315)* size, sin(DR * 315)* size);
	m_p5 = getRotationMatrix() * sf::Vector2f(cos(DR * 30)* size, sin(DR * 30)* size);

	getShape().setPoint(0, m_position + m_p1);
	getShape().setPoint(1, m_position + m_p2);
	getShape().setPoint(2, m_position + m_p3);
	getShape().setPoint(3, m_position + m_p4);
	getShape().setPoint(4, m_position + m_p5);
}

void Pentagon::Update()
{
	if(getShape().getFillColor() == sf::Color::White)
			colourCool ++;
	if(colourCool == 500)
	{
		colourCool = 0;
		getShape().setFillColor(sf::Color::Magenta);
	}
	Pentagon::Bounce();
	Pentagon::Move();
}