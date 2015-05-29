#pragma once
#include "board.h"
#include "CircularList.h"
#include <string>
#include <SFML/Graphics.hpp>

class player{
private:
	int number;
	sf::Sprite Player;
	sf::Texture PlayerTx;
	int ECTS, cash;

public:
	CircularList<field*>::CircularIterator it;
	//player* next;
	player(int numberIn, std::string TexPath,CircularList<field*>& list);
	sf::Sprite& getPlayerSprite(){ return Player; }
	int getNumber(){ return number;}
	field* GetCurrentField(){ return *it; }
	bool Acquire(int amount);
	void Move(int Roll);
	bool Transfer(player& Indepted, int amount);
	void drawMe(sf::RenderWindow& window, sf::Font& font, sf::Sprite& bgr);
};