#pragma once
//#include "fields.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "const.h"
class field;
class player;



class board{
private:
	static field* start;
	static sf::Texture gamefieldTX;
	static sf::Texture fieldInfoTX;
	static sf::Sprite gamefield;
	static sf::Sprite fieldInfo;
	static sf::Sprite dicePic1;
	static sf::Sprite dicePic2;
	static sf::Text teamName;
	static sf::Text fieldName;
	static sf::Font font;
	static sf::RectangleShape fieldColor; 
	static sf::Sprite* Dices[2];
	static player* players[PLAYERS];
	static player* current;


public:
	static void serveClick(sf::RenderWindow& window,int x, int y);
	static void buildGameField(std::fstream& fielddata);
	static bool renderClickedField(short x, short y);
	static void dispose();
	static field* getStart(){ return start; }
	//static void move(int roll);
	static void DrawGamefield(sf::RenderWindow& window);
};