#pragma once
#include <SFML/Graphics.hpp>

class Cross
{
private:
	sf::Color color = sf::Color(sf::Color::Black);
	sf::RectangleShape line1 = sf::RectangleShape(sf::Vector2f(70.0f, 10.0f));
	sf::RectangleShape line2 = sf::RectangleShape(sf::Vector2f(70.0f, 10.0f));
	sf::Vector2f pos;
public:
	Cross();
	Cross(sf::Vector2f& p) : pos(p) {};
	~Cross() {};

	void SetPosition();
	void Initialize();
};

