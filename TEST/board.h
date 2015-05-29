#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "const.h"
#include "CircularList.h"
class field;
class player;
class userbar;



class board{
private:
	static CircularList<field*> fields;
	static sf::Texture gamefieldTX;
	static sf::Texture fieldInfoTX;
	static sf::Texture bgrTx;
	static sf::Sprite gamefield;
	static sf::Sprite fieldInfo;
	static sf::Sprite dicePic1;
	static sf::Sprite dicePic2;
	static sf::Sprite bgr;
	static sf::Text teamName;
	static sf::Text fieldName;
	static sf::Text fieldContent;
	static sf::Font font;
	static sf::ConvexShape fieldColor; 
	static sf::Sprite* Dices[2];
	static player* players[PLAYERS];
	static player* current;
	static sf::RenderWindow* mainWindow;
	static userbar* user_bar;
	static bool rolled;


public:
	static void setWindow(sf::RenderWindow& myWindow){ mainWindow = &myWindow; }
	static void serveClick(int x, int y);
	static void buildGameField(std::fstream& fielddata);
	static bool renderClickedField(short x, short y);
	static void dispose();
	static void DrawGamefield();
};