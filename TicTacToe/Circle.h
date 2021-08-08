#pragma once
#include <SFML/Graphics.hpp>

class Circle
{
private:
	sf::Color color = sf::Color(sf::Color::Black);
	sf::Vector2f pos;
	sf::CircleShape circle = sf::CircleShape(25);
public:

	Circle() {};
	~Circle() {};

	void ConfigC(const sf::Vector2f& p);
	sf::CircleShape getShape();
	void SetPos(sf::Vector2f p) {
		circle.setPosition(p);
	}
};

