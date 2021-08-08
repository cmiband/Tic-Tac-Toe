#pragma once
#include <SFML/Graphics.hpp>
#include "Cross.h"
#include "Circle.h"
#include "Place.h"

class Game : public Cross
{
private:
	Cross c;
	Circle ci;

	//colors
	sf::Color bgColor;
	sf::Color placeColor = sf::Color(sf::Color::Red);
	sf::Color barColor = sf::Color(sf::Color::Black);
	
	//positions
	sf::Vector2f textPos = sf::Vector2f(150.0f, 25.0f);
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

	//text
	sf::Font font;
	sf::Text title = sf::Text("Tic Tac Toe", font, 50);

public:
	Game(sf::Color c, sf::RenderWindow& w, sf::Font& f) : window(w), font(f) { bgColor = c; };
	~Game() {};


	sf::Vector2f drawAtPosition(Place& place);
	//text
	void SetTextPosition();
	void RenderText();

	//tic tac board
	void DrawPlaces();
	void ConfigureBars();
	void DrawBars();

	void DrawCross();
	void DrawCircle();

	//checking
	int placeClicked(); // TODO: return index of place clicked
	
	void Play();
};

