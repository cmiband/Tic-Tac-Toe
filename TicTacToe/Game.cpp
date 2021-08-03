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
	}
}

void Game::DrawPlaces() {
	for (int i = 0; i < 9; i++) {
		window.draw(places[i]);
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

void Game::Play() {
	window.clear(bgColor);

	ConfigurePlaces();
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
					
			RenderText();
			DrawPlaces();
			DrawBars();

			window.display();
		}
	}
}