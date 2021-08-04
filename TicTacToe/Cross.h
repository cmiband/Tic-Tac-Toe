#pragma once
#include <SFML/Graphics.hpp>

class Cross
{
protected:
	sf::Color color = sf::Color(sf::Color::Black);
public:
	sf::RectangleShape line1 = sf::RectangleShape(sf::Vector2f(70.0f, 10.0f));
	sf::RectangleShape line2 = sf::RectangleShape(sf::Vector2f(70.0f, 10.0f));
	Cross() {};
	~Cross() {};

	void Initialize(const sf::Vector2f& pos);
};

