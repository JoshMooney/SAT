#include "stdafx.h"
#include "Circle.h"

	Circle::Circle()
	{
		//m_shape.setPosition(rand() % 760, rand() % 560);
		m_shape.setPosition(400,300);
		m_shape.setRadius(20);
		m_shape.setFillColor(sf::Color::Red);
		m_shape.setOutlineThickness(2);
		m_shape.setOutlineColor(sf::Color::White);
		//m_velocity = 0.2f;
		
		m_direction = sf::Vector2f((static_cast <float>(rand() % 200 + 1))/ 1000, (static_cast <float>(rand() % 200 + 1))/1000);
		int num = rand() % 2;
		if(num >= 1){m_direction.x *= -1;}
		num = rand() % 2;
		if(num >= 1){m_direction.y *= -1;}
	}

	float Circle::getVelocity() const
	{
		return m_velocity;
	}
	void Circle::setVelocity(const float vel)
	{
		m_velocity = vel;
	}

	sf::Vector2f Circle::getPreviousPosition() const
	{
		return m_previousPositon;
	}
	void Circle::setPreviousPosition(const sf::Vector2f prev)
	{
		m_previousPositon = prev;
	}

	sf::Vector2f Circle::getDirection()
	{
		m_direction.x = m_shape.getPosition().x - m_previousPositon.x;
		m_direction.y = m_shape.getPosition().y - m_previousPositon.y;
		return m_direction;
	}
	void Circle::setDirection(const sf::Vector2f dir)
	{
		m_direction = dir;
	}

	float Circle::getElasticity()
	{
		return m_elasticity;
	}
	void Circle::setElasticity(const float elas)
	{
		m_elasticity = elas;
	}

	sf::CircleShape Circle::getShape()
	{
		return m_shape;
	}

	void Circle::Bounce()
	{
		bool colour = false;
		if(m_shape.getPosition().x > 760 || m_shape.getPosition().x < 0) {m_direction.x *= -1;	colour = true;}
		if(m_shape.getPosition().y > 560 || m_shape.getPosition().y < 0) {m_direction.y *= -1;	colour = true;}

		if(colour)
		{
			m_shape.setFillColor(sf::Color::White);
			colourCool = 0;
		}
	}
	void Circle::Move()
	{
		m_shape.setPosition(m_shape.getPosition().x + m_direction.x,
							m_shape.getPosition().y + m_direction.y);
	}
	void Circle::Update()
	{
		if(m_shape.getFillColor() == sf::Color::White)
			colourCool ++;
		if(colourCool == 120)
		{
			colourCool = 0;
			m_shape.setFillColor(sf::Color::Red);
		}
		Circle::Move();
		Circle::Bounce();	
	}
	void Circle::Draw(sf::RenderWindow& w)
	{
		w.draw(m_shape);
	}