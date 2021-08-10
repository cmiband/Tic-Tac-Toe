#include "Game.h"
#include <SFML/Graphics.hpp>

void Game::SetTextPosition() {
	title.setPosition(textPos);
}

void Game::RenderText() {
	window.draw(title);
}

void Game::DrawPlaces() {
	for (int i = 0; i < 9; ++i) {
		window.draw(places[i].getShape());
	}
}

void Game::ConfigureBars() {
	verticalBars[0].setPosition(sf::Vector2f(195.0f, 100.0f));
	verticalBars[1].setPosition(sf::Vector2f(295.0f, 100.0f));
	horizontalBars[0].setPosition(sf::Vector2f(100.0f, 195.0f));
	horizontalBars[1].setPosition(sf::Vector2f(100.0f, 295.0f));
	verticalBars[0].setFillColor(barColor); verticalBars[1].setFillColor(barColor);
	horizontalBars[0].setFillColor(barColor); horizontalBars[1].setFillColor(barColor);
}

void Game::DrawBars() {
	window.draw(verticalBars[0]); window.draw(verticalBars[1]);
	window.draw(horizontalBars[0]); window.draw(horizontalBars[1]);
}

void Game::DrawCross(Cross &c) {
	window.draw(c.getLine1());
	window.draw(c.getLine2());
}

void Game::DrawCircle(Circle &c) {
	window.draw(c.getShape());
}

sf::Vector2f Game::drawAtPosition(Place& place) {
	sf::Vector2f p = place.getSignDrawPos();
	return p;
}

int Game::placeClicked() {
	bool clicked = false;
	sf::Vector2i mpos = mouse.getPosition(window);
	sf::Vector2f mposf = sf::Vector2f((float)mpos.x, (float)mpos.y);
	for (int i = 0; i < 9; ++i) {
		sf::RectangleShape rs = places[i].getShape();
		bool c = rs.getGlobalBounds().contains(mposf);
		if (c) {
			clicked = c;
			break;
		}
	}

	return clicked;
}

void Game::Play() {
	window.clear(bgColor);

	SetTextPosition();
	ConfigureBars();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			window.clear(bgColor);
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					int placeIndex = placeClicked();
					sf::Vector2f drawPos = drawAtPosition(places[placeIndex]);
				}
			}
					
			RenderText();
			DrawPlaces();
			DrawBars();

			window.display();
		}
	}
}