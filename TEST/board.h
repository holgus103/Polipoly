#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "const.h"
#include "CircularList.h"

class Field;
class Player;
class userbar;
class Messenger;
class Chance;
class Stack;
class Button;
class Bank;
class FieldSet;

class Board{
private:
	static CircularList<Field*> fields;
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
	static Bank* gameBank;
	static Button* nextButton;
	static Button* bankEnter;
	
	static Player* current;
	
	static userbar* user_bar;
	static bool rolled;
	
	

public:
	static void setWindow(sf::RenderWindow& myWindow){ mainWindow = &myWindow; }
	static void serveClick(int x, int y);
	static void buildGameField(std::fstream& fielddata, std::fstream& msgdata, std::fstream& chancesdata);
	static bool renderClickedField(short x, short y);
	static void dispose();
	static void drawGamefield();
	static sf::RenderWindow* mainWindow;
	static Messenger* msger;
	static Stack* chancesStack;
	static Player* players[PLAYERS];
	static FieldSet* setsInfo[SETS_COUNT];
	static void drawBgr();
};