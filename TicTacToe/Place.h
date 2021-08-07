#pragma once
#include <SFML/Graphics.hpp>

class Place
{
private:
	sf::RectangleShape pl = sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
	sf::Vector2f placeSignPos = pl.getPosition() + sf::Vector2f(15.0f, 15.0f);
	sf::Color color;
public:
	Place() {};
	Place(sf::Color& c) : color(c) {};
	~Place() {};

	void Config() {
		pl.setFillColor(color);
	}
	void SetPos(sf::Vector2f& p) {
		pl.setPosition(p);
	}
	const sf::Vector2f getSignDrawPos() {
		return placeSignPos;
	}
	sf::RectangleShape getShape() {
		return pl;
	}
};

