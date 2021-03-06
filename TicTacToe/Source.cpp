#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(500, 500), "TicTacToe");
	sf::Font f;
	
	if (!f.loadFromFile("BebasNeue-Regular.ttf"))
		return EXIT_FAILURE;

	sf::Color color(111, 243, 155);
	Game tictac(color, window, f);
	Game* tt = &tictac;
	tt->Play();

	return 0;
}