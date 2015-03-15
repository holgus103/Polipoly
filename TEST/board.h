#pragma once
//#include "fields.h"
#include <string>
#include <SFML/Graphics.hpp>
class field;
class player;



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
	static sf::Sprite& getBoardSprite(){ return gamefield; }
	static sf::Text& GetTeamName(){ return teamName; }
	static sf::Text& GetFieldName(){ return fieldName; }
	static sf::RectangleShape& GetFieldColor(){ return fieldColor; }
	static  sf::Sprite& GetFieldInfo(){ return fieldInfo; }
	static field* getStart(){ return start; }
	static void move(int roll);

};