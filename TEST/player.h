#pragma once
#include "board.h"
#include "CircularList.h"
#include <string>
#include <SFML/Graphics.hpp>

class Player{
private:
	int number;
	sf::Sprite player;
	sf::Texture playerTx;
	int ECTS, cash;

public:
	CircularList<Field*>::CircularIterator it;
	//player* next;
	Player(int numberIn, std::string TexPath,CircularList<Field*>& list);
	sf::Sprite& getPlayerSprite(){ return player; }
	int getNumber(){ return number;}
	Field* GetCurrentField(){ return *it; }
	bool Acquire(int amount);
	void Move(int Roll);
	bool Transfer(Player& Indepted, int amount);
	void drawMe(sf::RenderWindow& window, sf::Font& font, sf::Sprite& bgr);
};