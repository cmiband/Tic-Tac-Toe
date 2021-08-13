#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game(sf::Color c, sf::RenderWindow& w, sf::Font& f) : window(w), font(f) 
{ 
	bgColor = c; 

	for (int i = 0; i < 5; ++i) {
		crosses[i].first = NULL;
	}
	for (int i = 0; i < 4; ++i) {
		circles[i].first = NULL;
	}
}

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
	int clicked = NULL;
	sf::Vector2i mpos = mouse.getPosition(window);
	sf::Vector2f mposf = sf::Vector2f((float)mpos.x, (float)mpos.y);
	if (places[0].getShape().getGlobalBounds().contains(mposf))
		return 0;
	if (places[1].getShape().getGlobalBounds().contains(mposf))
		return 1;
	if (places[2].getShape().getGlobalBounds().contains(mposf))
		return 2;
	if (places[3].getShape().getGlobalBounds().contains(mposf))
		return 3;
	if (places[4].getShape().getGlobalBounds().contains(mposf))
		return 4;
	if (places[5].getShape().getGlobalBounds().contains(mposf))
		return 5;
	if (places[6].getShape().getGlobalBounds().contains(mposf))
		return 6;
	if (places[7].getShape().getGlobalBounds().contains(mposf))
		return 7;
	if (places[8].getShape().getGlobalBounds().contains(mposf))
		return 8;

	return clicked;
}

void Game::FinalDraw() {
	if (crosses[0].first != NULL) {
		DrawCross(crosses[0].second);
	}
	if (crosses[1].first != NULL) {
		DrawCross(crosses[1].second);
	}
	if (crosses[2].first != NULL) {
		DrawCross(crosses[1].second);
	}
	if (crosses[3].first != NULL) {
		DrawCross(crosses[1].second);
	}
	if (crosses[4].first != NULL) {
		DrawCross(crosses[1].second);
	}
	if (circles[0].first != NULL) {
		DrawCircle(circles[0].second);
	}
	if (circles[1].first != NULL) {
		DrawCircle(circles[1].second);
	}
	if (circles[2].first != NULL) {
		DrawCircle(circles[2].second);
	}
	if (circles[3].first != NULL) {
		DrawCircle(circles[3].second);
	}
}

void Game::CreateX(int pi) {
	printf("%d move X\n", moveIteratorX);
	Cross x;
	x.Initialize(drawAtPosition(places[pi]));
	crosses[moveIteratorX].first = pi;
	crosses[moveIteratorX].second = x;
	if(moveIteratorX < 5)
		++moveIteratorX;
	drawX = false;
}

void Game::CreateO(int pi) {
	printf("%d move O\n", moveIteratorY);
	Circle o;
	o.ConfigC(drawAtPosition(places[pi]));
	circles[moveIteratorY].first = pi;
	circles[moveIteratorY].second = o;	
	if(moveIteratorY < 4)
		moveIteratorY += 1;
	drawX = true;
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
					printf("%d\n", placeIndex);
					if (placeIndex != NULL) {
						if (drawX) {
							CreateX(placeIndex);
						}
						if (!drawX) {
							CreateO(placeIndex);
						}
					}
				}
			}
			
			FinalDraw();
			RenderText();
			DrawPlaces();
			DrawBars();

			window.display();
		}
	}
}