//#include <SFML/System.hpp>
#include <iostream>
#include <time.h>
#include <functional>
#include "Board.h"
#include "Player.h"
//#include <vld.h>
#include "Fields.h"





int main()
{
	srand(time(NULL));
	int roll = 0;
	std::fstream fielddata(FIELDDATA_PATH,std::fstream::in);
	std::fstream msgdata(MSG_DATA_PATH, std::fstream::in);
	std::fstream chancesdata(CHANCE_DATA_PATH, std::fstream::in);
	sf::RenderWindow window(sf::VideoMode(SCREEN_X, SCREEN_Y), APP_TITLE);
	Board::setWindow(window);
	Board::buildGameField(fielddata, msgdata, chancesdata);
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
	msgdata.close();
	return 0;
}