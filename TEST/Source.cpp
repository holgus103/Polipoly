//#include <SFML/System.hpp>
#include <iostream>
#include <time.h>
#include <functional>
#include "board.h"
#include "player.h"
#include <vld.h>
#include "fields.h"





int main()
{
	srand(time(NULL));
	int roll = 0;
	std::fstream fielddata = std::fstream(FIELDDATA_PATH,std::fstream::in);
	sf::RenderWindow window(sf::VideoMode(SCREEN_X, SCREEN_Y), APP_TITLE);
	board::buildGameField(fielddata);
	//player player1(1, 700, 700, PLAYER_1_PATH);
	srand(time(NULL));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					board::serveClick(window,event.mouseButton.x, event.mouseButton.y);
					//board::renderClickedField(event.mouseButton.x, event.mouseButton.y);
					//roll = dice::RollMe(&window, Dices,sizeof(Dices)/sizeof(Dices[0]));		
					//player1.Move(roll);

				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear(sf::Color::Black);
		board::DrawGamefield(window);
		//window.draw(player1.getPlayerSprite());
		
		window.display();
	}

	board::dispose();
	fielddata.close();
	return 0;
}