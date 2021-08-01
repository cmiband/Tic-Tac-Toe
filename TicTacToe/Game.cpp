#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::~Game() { }

void Game::SetTextPosition() {
	title.setPosition(sf::Vector2f(500.0f, 20.0f));
}

void Game::RenderText() {
	window.draw(title);
}

void Game::SetPlacesSizesAndFillColors() {
	place1.setSize(size); place1.setFillColor(placeColor);
}

void Game::SetPlacesPositions() {
	place1.setPosition(positions[0]);
}

void Game::RenderPlaces() {
	window.draw(place1);
}

void Game::Play() {
	window.clear(bgColor);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			window.clear(bgColor);
			
			RenderText();
			RenderPlaces();

			window.display();
		}
	}
}