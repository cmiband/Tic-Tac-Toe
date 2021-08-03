#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::~Game() { }

void Game::SetTextPosition() {
	title.setPosition(textPos);
}

void Game::RenderText() {
	window.draw(title);
}

void Game::ConfigurePlaces() {
	for (int i = 0; i < 9; i++) {
		places[i].setPosition(positions[i]);
		places[i].setFillColor(placeColor);
		window.draw(places[i]);
	}
}

void Game::ConfigureBars() {
	
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
			
			SetTextPosition();
			RenderText();
			ConfigurePlaces();

			window.display();
		}
	}
}