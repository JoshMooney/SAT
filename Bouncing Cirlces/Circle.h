#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
	float m_velocity;
	float m_elasticity;
	int colourCool;
	sf::Vector2f m_previousPositon;
	sf::Vector2f m_direction;
	sf::CircleShape m_shape;

public:
	//Get and sets
	Circle();		//Default Constructor

	float getVelocity() const;
	void setVelocity(const float vel);

	sf::Vector2f getPreviousPosition() const;
	void setPreviousPosition(const sf::Vector2f prev);

	sf::Vector2f getDirection();
	void setDirection(const sf::Vector2f dir);

	float getElasticity();
	void setElasticity(const float elas);

	sf::CircleShape getShape();

	void Bounce();
	void Update();
	void Draw(sf::RenderWindow& w);
	void Move();
};

#endif
