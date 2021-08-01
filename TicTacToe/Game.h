#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
private:
	//colors
	sf::Color bgColor;
	sf::Color placeColor = sf::Color(sf::Color::Red);
	
	//positions
	sf::Vector2f positions[9] = {
		sf::Vector2f(100.0f,100.0f),
		sf::Vector2f(200.0f,100.0f),
		sf::Vector2f(300.0f,100.0f),
		sf::Vector2f(100.0f,200.0f),
		sf::Vector2f(200.0f,200.0f),
		sf::Vector2f(300.0f,200.0f),
		sf::Vector2f(100.0f,300.0f),
		sf::Vector2f(200.0f,300.0f),
		sf::Vector2f(300.0f,300.0f)
	};
	sf::Vector2f textPos = sf::Vector2f(500.0f, 50.0f);

	//sizes
	sf::Vector2f size = sf::Vector2f(100.0f, 100.0f);
	
	//objects
	sf::RenderWindow& window;
	sf::RectangleShape place1;

	//text
	sf::Font font;
	sf::Text title = sf::Text("Tic Tac Toe", font, 50);

public:
	Game(sf::Color c, sf::RenderWindow& w, sf::Font& f) : window(w), font(f) { bgColor = c; };
	~Game();

	//text
	void SetTextPosition();
	void RenderText();

	//tic tac board
	void SetPlacesSizesAndFillColors();
	void SetPlacesPositions();
	void RenderPlaces();
	
	void Play();
};

