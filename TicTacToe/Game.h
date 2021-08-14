#pragma once
#include <SFML/Graphics.hpp>
#include "Cross.h"
#include "Circle.h"
#include "Place.h"
#include <stdio.h>
#include <utility>

class Game : public Cross
{
private:
	bool drawX = true;
	int moveIteratorX = 0;
	int moveIteratorY = 0;

	//colors
	sf::Color bgColor;
	sf::Color placeColor = sf::Color(sf::Color::Red);
	sf::Color barColor = sf::Color(sf::Color::Black);
	
	//positions
	sf::Vector2f textPos = sf::Vector2f(150.0f, 25.0f);
	sf::Vector2f endingScreenPos = sf::Vector2f(110.0f, 400.0f);
	sf::Vector2f testCrossPos = sf::Vector2f(15.0f, 15.0f);
	sf::Vector2f testCirclePos = sf::Vector2f(400.0f, 15.0f);
	
	//objects
	sf::RenderWindow& window;
	Place places[9] = {
		Place(placeColor,sf::Vector2f(100.0f,100.0f),sf::Vector2f(130.0f, 130.0f)),
		Place(placeColor,sf::Vector2f(200.0f,100.0f),sf::Vector2f(230.0f, 130.0f)),
		Place(placeColor,sf::Vector2f(300.0f,100.0f),sf::Vector2f(330.0f, 130.0f)),
		Place(placeColor,sf::Vector2f(100.0f,200.0f),sf::Vector2f(130.0f, 230.0f)),
		Place(placeColor,sf::Vector2f(200.0f,200.0f),sf::Vector2f(230.0f, 230.0f)),
		Place(placeColor,sf::Vector2f(300.0f,200.0f),sf::Vector2f(330.0f, 230.0f)),
		Place(placeColor,sf::Vector2f(100.0f,300.0f),sf::Vector2f(130.0f, 330.0f)),
		Place(placeColor,sf::Vector2f(200.0f,300.0f),sf::Vector2f(230.0f, 330.0f)),
		Place(placeColor,sf::Vector2f(300.0f,300.0f),sf::Vector2f(330.0f, 330.0f)),
	};
	sf::RectangleShape verticalBars[2] = {
		sf::RectangleShape(sf::Vector2f(10.0f,300.0f)),
		sf::RectangleShape(sf::Vector2f(10.0f,300.0f))
	};
	sf::RectangleShape horizontalBars[2] = {
		sf::RectangleShape(sf::Vector2f(300.0f, 10.0f)),
		sf::RectangleShape(sf::Vector2f(300.0f, 10.0f))
	};
	sf::Mouse mouse;
	
	std::pair<int, Cross> crosses[5];
	std::pair<int, Circle> circles[4];

	//text
	sf::Font font;
	sf::Text title = sf::Text("Tic Tac Toe", font, 50);
	sf::Text endingScreenX = sf::Text("X player won!", font, 60);
	sf::Text endingScreenO = sf::Text("O player won!", font, 60);

public:
	Game(sf::Color c, sf::RenderWindow& w, sf::Font& f);
	~Game() {};

	sf::Vector2f drawAtPosition(Place& place);
	//text
	void RenderText();

	//tic tac board
	void DrawPlaces();
	void FinalDraw();
	void ConfigureBars();
	void DrawBars();

	void DrawCross(Cross &c);
	void DrawCircle(Circle& c);

	//checking
	int placeClicked();

	void CreateX(int pi);
	void CreateO(int pi);

	// endgame
	bool winConditionsX();
	bool winConditionsO();
	
	void Play();
};

