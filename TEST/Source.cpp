//#include <SFML/System.hpp>
#include <iostream>
#include <time.h>
#include <functional>
#include "board.h"
#include "player.h"
//#include <vld.h>
#include "fields.h"





int main()
{
	srand(time(NULL));
	int roll = 0;
	std::fstream fielddata(FIELDDATA_PATH,std::fstream::in);
	sf::RenderWindow window(sf::VideoMode(SCREEN_X, SCREEN_Y), APP_TITLE);
	Board::buildGameField(fielddata);
	Board::setWindow(window);
	sf::Vector2u screen_size;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					screen_size = window.getSize();
					Board::serveClick(event.mouseButton.x * SCREEN_X / screen_size.x, event.mouseButton.y * SCREEN_Y / screen_size.y);
				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear(sf::Color::Black);
		Board::drawGamefield();
	}

	Board::dispose();
	fielddata.close();
	return 0;
}