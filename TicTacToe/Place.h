#pragma once
#include <SFML/Graphics.hpp>

class Place
{
private:
	sf::RectangleShape pl = sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
	sf::Vector2f position;
	sf::Vector2f placeSignPos;
	sf::Color color;
	bool isCovered;
public:
	Place(sf::Color c, sf::Vector2f pos, sf::Vector2f drawPos) {
		color = c;
		position = pos;
		placeSignPos = drawPos;
		isCovered = false;
		pl.setFillColor(color);
		pl.setPosition(position);
	};
	~Place() {};

	const sf::Vector2f getSignDrawPos() {
		return placeSignPos;
	}
	sf::RectangleShape getShape() {
		return pl;
	}
	bool getCover() {
		return isCovered;
	}
	void setCover(bool val) {
		isCovered = val;
	}
};

