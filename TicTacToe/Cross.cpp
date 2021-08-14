#include <SFML/Graphics.hpp>
#include "Cross.h"

void Cross::Initialize(const sf::Vector2f& pos) {
	line1.setFillColor(color); line2.setFillColor(color);
	line1.setPosition(pos);
	line2.setPosition(pos + sf::Vector2f(0.0f, 48.0f));
	line1.setRotation(45.0f); line2.setRotation(315.0f);
}
