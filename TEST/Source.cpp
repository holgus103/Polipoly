//#include <SFML/System.hpp>
#include <iostream>
#include <time.h>
#include "board.h"
#include <windows.h>

//#include <vld.h>
void thread(std::string no){
	for (int i = 0; i < 10; i++){
		std::cout << no + " threat reporting in" << std::endl;
		getchar();
	}
}




int main()
{
	srand(time(NULL));

	std::fstream fielddata = std::fstream(FIELDDATA_PATH,std::fstream::in);
	
	sf::RenderWindow window(sf::VideoMode(SCREEN_X, SCREEN_Y), APP_TITLE);
	sf::Texture gamefieldTX;
	sf::Texture fieldInfoTX;
	sf::Texture dicePicTX[6];
	sf::Sprite gamefield;
	sf::Sprite dicePic1;
	sf::Sprite dicePic2;
	sf::Sprite fieldInfo;
	sf::Font font;
	sf::RectangleShape fieldColor(sf::Vector2f(FIELDCOLOR_SIZEX, FIELDCOLOR_SIZEY));
	sf::Text teamName;
	sf::Text fieldName;
	font.loadFromFile(MY_FONT_PATH);
	gamefieldTX.loadFromFile(GAMEFIELD_PATH);
	dicePicTX[0].loadFromFile(DICE_PIC_ONE);
	dicePicTX[1].loadFromFile(DICE_PIC_TWO);
	dicePicTX[2].loadFromFile(DICE_PIC_THREE);
	dicePicTX[3].loadFromFile(DICE_PIC_FOUR);
	dicePicTX[4].loadFromFile(DICE_PIC_FIVE);
	dicePicTX[5].loadFromFile(DICE_PIC_SIX);
	fieldInfoTX.loadFromFile(FIELDINFO_TEX_PATH);
	gamefield.setTexture(gamefieldTX);
	fieldInfo.setTexture(fieldInfoTX);
	dicePic1.setTexture(dicePicTX[0]);
	dicePic2.setTexture(dicePicTX[0]);
	fieldInfo.setPosition(FIELDINFO_X, FIELDINFO_Y);
	dicePic1.setPosition(800, 500);
	dicePic2.setPosition(860, 500);
	fieldColor.setPosition(FIELDCOLOR_X, FIELDCOLOR_Y);
	teamName.setPosition(TEAMNAME_X, TEAMNAME_Y);
	fieldName.setPosition(FIELDNAME_X, FIELDNAME_Y);
	teamName.setFont(font);
	fieldName.setFont(font);
	teamName.setColor(sf::Color::Black);
	fieldName.setColor(sf::Color::Black);
	teamName.setCharacterSize(12);
	fieldName.setCharacterSize(13);
	board::buildGameField(fielddata);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					board::renderClickedField(event.mouseButton.x, event.mouseButton.y,teamName, fieldName,fieldColor);
					int random1, random2;
					for (int j = 0; j < 50; j++)
					{
						random1 = rand() % 6;
						dicePic1.setTexture(dicePicTX[random1]);
						random2 = rand() % 6;
						dicePic2.setTexture(dicePicTX[random2]);
						Sleep(j * 15);
						window.display();
					}

				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear(sf::Color::Black);
		window.draw(gamefield);
		window.draw(fieldInfo);
		window.draw(fieldColor);
		window.draw(teamName);
		window.draw(fieldName);
		window.draw(dicePic1);
		window.draw(dicePic2);
		
		window.display();
	}
	
	/*gamefieldTX.~Texture();
	fieldInfoTX.~Texture();
	teamName.~Text();
	fieldName.~Text();
	gamefield.~Sprite();
	fieldInfo.~Sprite();
	//font.~Font();
	fieldColor.~RectangleShape();
	window.~RenderWindow();*/
	board::dispose();
	fielddata.close();
	window.~RenderWindow();
	return 0;
}