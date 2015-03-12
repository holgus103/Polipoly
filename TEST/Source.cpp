//#include <SFML/System.hpp>
#include <iostream>
#include <time.h>
#include <functional>
#include "board.h"
#include "Dice.h"
#include "player.h"
#include <vld.h>





int main()
{
	srand(time(NULL));
	int roll = 0;
	std::fstream fielddata = std::fstream(FIELDDATA_PATH,std::fstream::in);
	sf::RenderWindow window(sf::VideoMode(SCREEN_X, SCREEN_Y), APP_TITLE);
	sf::Sprite dicePic1;
	sf::Sprite dicePic2;
	player player1(1, 700, 700, PLAYER_1_PATH);
	sf::Sprite* Dices[2] = { &dicePic1,&dicePic2};
	dicePic1.setPosition(DICE1_X, DICE1_Y);
	dicePic2.setPosition(DICE2_X,DICE2_Y);
	board::buildGameField(fielddata);
	dice::LoadTextures();
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
					board::renderClickedField(event.mouseButton.x, event.mouseButton.y);
					roll = dice::RollMe(&window, Dices,sizeof(Dices)/sizeof(Dices[0]));			

				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear(sf::Color::Black);
		window.draw(board::getBoardSprite());
		window.draw(board::GetFieldInfo());
		window.draw(board::GetFieldColor());
		window.draw(board::GetTeamName());
		window.draw(board::GetFieldName());
		window.draw(dicePic1);
		window.draw(dicePic2);
		window.draw(player1.getPlayerSprite());
		
		window.display();
	}

	board::dispose();
	fielddata.close();
	return 0;
}