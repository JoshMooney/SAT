#ifndef BOUNCINGOBJECT_H
#define BOUNCINGOBJECT_H

using std::vector;

class BouncingObject
{
private:
	sf::Vector2f m_direction;
	sf::ConvexShape m_shape;
	sf::Transform m_rotationMatrix;
	int vertexCount;
	float m_rot;
	int colourCool;
public:
	BouncingObject();
	void setDirection(sf::Vector2f dir);
	void swapDirectionX();
	void swapDirectionY();
	sf::Vector2f getDirection();
	sf::ConvexShape& getShape();
	void setShape(sf::ConvexShape shape);
	sf::Transform getRotationMatrix();
	void setRotationMatrix();
	float getRotation();
	void setRotation(float r);
	void Update();
	void Draw(sf::RenderWindow& w);
	vector<sf::Vector2f> m_pointArray;
	vector<sf::Vector2f> vertexArray;
	sf::Vector2f m_position;
	int numPoints;
	virtual sf::Vector2f getPosition()	{ return m_position; }
	vector<sf::Vector2f> getVertexArray()	{ return vertexArray; }
	vector<sf::Vector2f> getPointArray()	{ return m_pointArray; }
};

#endif