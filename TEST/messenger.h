#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "const.h"

class Messenger
{
private:
	std::string buy_title;
	std::string buy_message;
	sf::Texture* background;
public:
	void drawMsgBox(sf::RenderWindow& window);
	void drawBuyMessage(sf::RenderWindow& window, std::string fieldName);
	Messenger();
};