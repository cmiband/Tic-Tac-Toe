#include "Circle.h"

void Circle::ConfigC(const sf::Vector2f& p) {
	circle.setFillColor(sf::Color(255, 255, 255, 0));
	circle.setOutlineThickness(10);
	circle.setOutlineColor(color);
	circle.setPosition(p);
}

sf::CircleShape Circle::getShape() {
	return circle;
}