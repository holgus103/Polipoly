#include "messenger.h"
#include "const.h"
#include "fstream"
#include "board.h"

bool Messenger::drawMsgBox(std::string& text, std::string& title, MsgType type)
{
	
	sf::Sprite* temp = new sf::Sprite();
	sf::Text* temp2 = new sf::Text();
	window.clear(); // cleanup needed (otherwise bugs occur)
	Board::drawGamefield();
	temp->setTexture(*background);
	temp->setPosition(MSG_BG_POSITION, MSG_BG_POSITION);
	temp2->setCharacterSize(CONTENT_TEXT_SIZE);
	temp2->setColor(sf::Color::Black);
	temp2->setFont(*font);

	window.draw(*temp);
	temp2->setPosition(MSG_TITLE_X, MSG_TITLE_Y);
	temp2->setString(title);
	window.draw(*temp2);
	temp2->setPosition(MSG_TEXT_X, MSG_TEXT_Y);
	temp2->setString(text);
	window.draw(*temp2);
	

	if (type == OKCANCEL)
	{
		yesButton->drawButton(window);
		noButton->drawButton(window);
	}
	else
		okButton->drawButton(window);
	
	window.display();
	delete(temp);
	return serviceLoop(type);
}
void Messenger::drawBuyMessage(sf::RenderWindow& window, std::string fieldName)
{
	sf::Text temp;
}

Messenger::Messenger(sf::RenderWindow& w, std::fstream& textes) : window(w)
{
	background = new sf::Texture;
	background->loadFromFile(MSG_BG_PATH);
	yesButton = new Button(MSG_YES_PATH, MSG_YES_XL, MSG_YES_XR, MSG_BUTTON_YU, MSG_BUTTON_YD);
	noButton = new Button(MSG_NO_PATH, MSG_NO_XL, MSG_NO_XR, MSG_BUTTON_YU, MSG_BUTTON_YD);
	okButton = new Button(MSG_OK_PATH, MSG_OK_XL, MSG_OK_XR, MSG_BUTTON_YU, MSG_BUTTON_YD);
	font = new sf::Font;
	font->loadFromFile(MY_FONT_PATH);
	textes >> buy_title;
}

bool Messenger::serviceLoop(MsgType type){// ok and cancel button support implementation
	sf::Event event;
	sf::Vector2u screen_size;
	//bool open = true;
	while (true){
		window.pollEvent(event);
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			screen_size = window.getSize();//20+205,100+205, 297+205,205+337
			if (type == OKCANCEL)
			{
				if (yesButton->belongs(event.mouseButton.x * SCREEN_X / screen_size.x, event.mouseButton.y * SCREEN_Y / screen_size.y))
					return true;
				if (noButton->belongs(event.mouseButton.x * SCREEN_X / screen_size.x, event.mouseButton.y * SCREEN_Y / screen_size.y))
					return false;
			}
			else
				if (okButton->belongs(event.mouseButton.x * SCREEN_X / screen_size.x, event.mouseButton.y * SCREEN_Y / screen_size.y))
					return true;			
		}
	}
}

Messenger::~Messenger()
{
	delete(background);
	delete(yesButton);
	delete(noButton);
	delete(okButton);
}