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
	board::buildGameField(fielddata);
	board::setWindow(window);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					board::serveClick(event.mouseButton.x, event.mouseButton.y);
				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear(sf::Color::Black);
		board::DrawGamefield();
	}

	board::dispose();
	fielddata.close();
	return 0;
}