#pragma once
#include "fields.h"


class board{
private:
	static field* start;
	static sf::Texture gamefieldTX;
	static sf::Texture fieldInfoTX;
	static sf::Sprite gamefield;
	static sf::Sprite fieldInfo;
	static sf::Text teamName;
	static sf::Text fieldName;
	static sf::Font font;
	static sf::RectangleShape fieldColor; 

public:
	static void buildGameField(std::fstream& fielddata);
	static bool renderClickedField(short x, short y);
	static void dispose();
	static sf::Sprite& getBoardSprite();
	static sf::Text& GetTeamName();
	static sf::Text& GetFieldName();
	static sf::RectangleShape& GetFieldColor();
	static  sf::Sprite& GetFieldInfo();

};