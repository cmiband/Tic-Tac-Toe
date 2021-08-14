#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game(sf::Color c, sf::RenderWindow& w, sf::Font& f) : window(w), font(f) 
{ 
	bgColor = c; 

	for (int i = 0; i < 5; ++i) {
		crosses[i].first = -1;
	}
	for (int i = 0; i < 4; ++i) {
		circles[i].first = -1;
	}

	title.setPosition(textPos);
	endingScreenX.setPosition(endingScreenPos);
	endingScreenO.setPosition(endingScreenPos);
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
	int clicked = -1;
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
	if (crosses[0].first != -1) {
		crosses[0].second.Initialize(drawAtPosition(places[crosses[0].first]));
		DrawCross(crosses[0].second);
	}
	if (crosses[1].first != -1) {
		crosses[1].second.Initialize(drawAtPosition(places[crosses[1].first]));
		DrawCross(crosses[1].second);
	}
	if (crosses[2].first != -1) {
		crosses[2].second.Initialize(drawAtPosition(places[crosses[2].first]));
		DrawCross(crosses[2].second);
	}
	if (crosses[3].first != -1) {
		crosses[3].second.Initialize(drawAtPosition(places[crosses[3].first]));
		DrawCross(crosses[3].second);
	}
	if (crosses[4].first != -1) {
		crosses[4].second.Initialize(drawAtPosition(places[crosses[4].first]));
		DrawCross(crosses[4].second);
	}
	if (circles[0].first != -1) {
		circles[0].second.ConfigC(drawAtPosition(places[circles[0].first]));
		DrawCircle(circles[0].second);
	}
	if (circles[1].first != -1) {
		circles[1].second.ConfigC(drawAtPosition(places[circles[1].first]));
		DrawCircle(circles[1].second);
	}
	if (circles[2].first != -1) {
		circles[2].second.ConfigC(drawAtPosition(places[circles[2].first]));
		DrawCircle(circles[2].second);
	}
	if (circles[3].first != -1) {
		circles[3].second.ConfigC(drawAtPosition(places[circles[3].first]));
		DrawCircle(circles[3].second);
	}
}

void Game::CreateX(int pi) {
	Cross x;
	places[pi].setCover(true);
	places[pi].setCoverX(true);
	crosses[moveIteratorX].first = pi;
	crosses[moveIteratorX].second = x;
	if(moveIteratorX < 5)
		++moveIteratorX;
	drawX = false;
	printf("%d move X\n", moveIteratorX);
	printf("%d place %d cover X\n", pi, places[pi].getCoverX());
}

void Game::CreateO(int pi) {
	Circle o;
	o.ConfigC(drawAtPosition(places[pi]));
	places[pi].setCover(true);
	places[pi].setCoverO(true);
	circles[moveIteratorY].first = pi;
	circles[moveIteratorY].second = o;	
	if(moveIteratorY < 4)
		++moveIteratorY;
	drawX = true;
	printf("%d move O\n", moveIteratorY);
	printf("%d place %d cover O\n", pi, places[pi].getCoverO());
}

bool Game::winConditionsX() {
	if (places[0].getCoverX() && places[1].getCoverX() && places[2].getCoverX())
		return true;
	if (places[0].getCoverX() && places[3].getCoverX() && places[6].getCoverX())
		return true;
	if (places[0].getCoverX() && places[4].getCoverX() && places[8].getCoverX())
		return true;
	if (places[6].getCoverX() && places[4].getCoverX() && places[2].getCoverX())
		return true;
	if (places[6].getCoverX() && places[7].getCoverX() && places[8].getCoverX())
		return true;
	if (places[2].getCoverX() && places[5].getCoverX() && places[8].getCoverX())
		return true;
	if (places[1].getCoverX() && places[4].getCoverX() && places[7].getCoverX())
		return true;
	if (places[3].getCoverX() && places[4].getCoverX() && places[5].getCoverX())
		return true;
	return false;
}

bool Game::winConditionsO() {
	if (places[0].getCoverO() && places[1].getCoverO() && places[2].getCoverO())
		return true;
	if (places[0].getCoverO() && places[3].getCoverO() && places[6].getCoverO())
		return true;
	if (places[0].getCoverO() && places[4].getCoverO() && places[8].getCoverO())
		return true;
	if (places[6].getCoverO() && places[4].getCoverO() && places[2].getCoverO())
		return true;
	if (places[6].getCoverO() && places[7].getCoverO() && places[8].getCoverO())
		return true;
	if (places[2].getCoverO() && places[5].getCoverO() && places[8].getCoverO())
		return true;
	if (places[1].getCoverO() && places[4].getCoverO() && places[7].getCoverO())
		return true;
	if (places[3].getCoverO() && places[4].getCoverO() && places[5].getCoverO())
		return true;
	return false;
}

void Game::Play() {
	window.clear(bgColor);

	ConfigureBars();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			bool xwon = winConditionsX();
			bool owon = winConditionsO();
			bool won = xwon || owon;

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			window.clear(bgColor);
			if (!won) {
				if (drawX) {
					if (event.type == sf::Event::MouseButtonPressed) {
						if (event.mouseButton.button == sf::Mouse::Left) {
							int placeIndex = placeClicked();
							if (placeIndex != -1 && !places[placeIndex].getCover())
								CreateX(placeIndex);
						}
					}
				}
				if (!drawX) {
					if (event.type == sf::Event::MouseButtonPressed) {
						if (event.mouseButton.button == sf::Mouse::Left) {
							int plIn = placeClicked();
							if (plIn != -1 && !places[plIn].getCover()) {
								CreateO(plIn);
							}
						}
					}
				}
			}

			RenderText();
			DrawPlaces();
			DrawBars();
			FinalDraw();
			if (xwon)
				window.draw(endingScreenX);
			if (owon)
				window.draw(endingScreenO);

			window.display();
		}
	}
}
