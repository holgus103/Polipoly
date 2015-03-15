#pragma once
#include "board.h"
#include <string>
#include <SFML/Graphics.hpp>

class player{
	int number;
	sf::Sprite Player;
	sf::Texture PlayerTx;
	field* current;

public:
	//player* next;
	player(int numberIn, int x, int y, std::string TexPath);
	sf::Sprite& getPlayerSprite(){ return Player; }
	int getNumber(){ return number;}
	field* GetCurrentField(){ return current; }
	void SetCurrentField(field* newField){ current = newField; }
	void Move(int Roll);
};