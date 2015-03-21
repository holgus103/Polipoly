#pragma once
#include "board.h"
#include <string>
#include <SFML/Graphics.hpp>

class player{
private:
	int number;
	sf::Sprite Player;
	sf::Texture PlayerTx;
	field* current;
	int ECTS, cash;


public:
	//player* next;
	player(int numberIn, std::string TexPath);
	sf::Sprite& getPlayerSprite(){ return Player; }
	int getNumber(){ return number;}
	field* GetCurrentField(){ return current; }
	void SetCurrentField(field* newField){ current = newField; }
	bool Acquire(int amount);
	void Move(int Roll);
	bool Transfer(player& Indepted, int amount);
};