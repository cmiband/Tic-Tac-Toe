#pragma once
#include <SFML/Graphics.hpp>

class Cross
{
protected:
	sf::Color color = sf::Color(sf::Color::Black);
	sf::RectangleShape line1 = sf::RectangleShape(sf::Vector2f(70.0f, 10.0f));
	sf::RectangleShape line2 = sf::RectangleShape(sf::Vector2f(70.0f, 10.0f));
public:
	Cross() {};
	~Cross() {};

	void Initialize(const sf::Vector2f& pos);
	sf::RectangleShape getLine1() { return line1; }
	sf::RectangleShape getLine2() { return line2; }
};

