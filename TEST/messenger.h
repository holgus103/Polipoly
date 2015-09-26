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
	Response serviceLoop(MsgType);
	Button* yesButton;
	Button* noButton;
	Button* okButton;
	sf::Font* font;
public:
	Response drawMsgBox(std::string&, std::string&, MsgType);
	//Rsponse drawMen
	void drawBuyMessage(sf::RenderWindow& window, std::string fieldName);
	void msgMode();
	Messenger(sf::RenderWindow& w, std::fstream& textes);
	~Messenger();
};