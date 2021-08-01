#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Game.h"

using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(1200, 1000), "TicTacToe");
	sf::Font f;
	if (!f.loadFromFile("BebasNeue-Regular.ttf"))
		return EXIT_FAILURE;

	sf::Color color(111, 243, 155);
	Game tictac(color, window, f);
	tictac.SetTextPosition();
	tictac.SetPlacesSizesAndFillColors();
	tictac.SetPlacesPositions();
	tictac.Play();

	return 0;
}