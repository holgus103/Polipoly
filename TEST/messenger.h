#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "const.h"
#include "button.h"

class Messenger
{
private:
	std::string buy_title;
	std::string buy_message;
	sf::Texture* background;
	sf::RenderWindow& window;
	bool serviceLoop(MsgType);
	Button* yesButton;
	Button* noButton;
	Button* okButton;
public:
	bool drawMsgBox(std::string&, std::string&, MsgType);
	void drawBuyMessage(sf::RenderWindow& window, std::string fieldName);
	Messenger(sf::RenderWindow& w, std::fstream& textes);
	~Messenger();
};