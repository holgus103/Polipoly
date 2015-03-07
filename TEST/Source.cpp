#include <SFML/System.hpp>
#include <iostream>
#include "fields.h"


void thread(std::string no){
	for (int i = 0; i < 10; i++){
		std::cout << no + " threat reporting in" << std::endl;
		getchar();
	}
}




int main()
{
	std::fstream fielddata = std::fstream(FIELDDATA_PATH,std::fstream::in);
	sf::RenderWindow window(sf::VideoMode(SCREEN_X,SCREEN_Y), APP_TITLE);
	sf::Texture gamefieldTX;
	sf::Texture fieldInfoTX;
	sf::Sprite gamefield;
	sf::Sprite fieldInfo;
	sf::Font font;
	sf::RectangleShape fieldColor(sf::Vector2f(FIELDCOLOR_SIZEX, FIELDCOLOR_SIZEY));
	sf::Text teamName;
	sf::Text fieldName;
	//std::string help;	
	font.loadFromFile(MY_FONT_PATH);
	gamefieldTX.loadFromFile(GAMEFIELD_PATH);
	fieldInfoTX.loadFromFile(FIELDINFO_TEX_PATH);
	gamefield.setTexture(gamefieldTX);
	fieldInfo.setTexture(fieldInfoTX);
	fieldInfo.setPosition(FIELDINFO_X, FIELDINFO_Y);
	fieldColor.setPosition(FIELDCOLOR_X, FIELDCOLOR_Y);
	teamName.setPosition(TEAMNAME_X, TEAMNAME_Y);
	fieldName.setPosition(FIELDNAME_X, FIELDNAME_Y);
	teamName.setFont(font);
	fieldName.setFont(font);
	teamName.setColor(sf::Color::Black);
	fieldName.setColor(sf::Color::Black);
	teamName.setCharacterSize(15);
	fieldName.setCharacterSize(20);
	field myField(fielddata);
	//position = sf::Text("Welcome", font, 30);
	//position.setPosition(830, 50);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//position.setString("x: " + std::to_string(event.mouseButton.x) + " y: " + std::to_string(event.mouseButton.y));

				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		myField.renderMe(teamName, fieldName, fieldColor);
		window.clear(sf::Color::Black);
		window.draw(gamefield);
		window.draw(fieldInfo);
		window.draw(fieldColor);
		window.draw(teamName);
		window.draw(fieldName);
		window.display();
	}
	fielddata.close();
	return 0;
}