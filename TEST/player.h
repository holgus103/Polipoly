#pragma once
#include "Board.h"
#include "CircularList.h"
#include <string>
#include <SFML/Graphics.hpp>

class Player{
private:
	int number;
	sf::Sprite player;
	sf::Texture playerTx;
	int ECTS, cash;
	int state;
	bool crossedStart;
	int immune;
public:
	CircularList<Field*>::CircularIterator it;
	//player* next;
	Player(int numberIn, std::string TexPath,CircularList<Field*>& list);
	sf::Sprite& getPlayerSprite(){ return player; }
	int getNumber(){ return number;}
	Field* getCurrentField(){ return *it; }
	bool acquire(int amount);
//	bool acquire2(int amount);
	void move(int Roll, bool actions);
	void teleport(std::string);
	bool transfer(Player& Indepted, int amount);
	bool giftsAndFines(int amount){ return (cash += amount) < 0; }
	void drawMe(sf::RenderWindow& window, sf::Font& font, sf::Sprite& bgr);
	int getState();
	void setState(int a);
	bool isPlaying();
	void setCrossedStart(bool);
	bool getCrossedStart();
	int capability(exValue type);
	void addImmunity();
	bool isImmune();
};