#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"
#include "button.h"
#include "messenger.h"
#include "player.h"

class Bank
{
private:
	Button* exitBank;
	Button* plus;
	Button* minus;
	sf::Texture* counter;
	int howMuch;
public:
	Bank();
	~Bank();
	bool visitBank(sf::RenderWindow& window, Player& client);
};