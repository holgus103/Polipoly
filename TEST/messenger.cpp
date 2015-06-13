#include "messenger.h"
#include "const.h"
#include "fstream"
#include "board.h"

bool Messenger::drawMsgBox(std::string& text, MsgType type)
{
	
	sf::Sprite* temp = new sf::Sprite();
	temp->setTexture(*background);
	temp->setPosition(MSG_BG_POSITION, MSG_BG_POSITION);
	window.clear(); // cleanup needed (otherwise bugs occur)
	Board::drawGamefield();
	window.draw(*temp);
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
			if ((event.mouseButton.y * SCREEN_Y / screen_size.y)<OK_YD && (event.mouseButton.y * SCREEN_Y / screen_size.y)>OK_YU){
				if ((event.mouseButton.x * SCREEN_X / screen_size.x)>OK_XL && (event.mouseButton.x * SCREEN_X / screen_size.x)<OK_XR){
					return true;//ok button pressed
				}// 205+257,337+205,205+297,205+337
				if (type == OKCANCEL &&(event.mouseButton.x * SCREEN_X / screen_size.x)>CANCEL_XL && (event.mouseButton.x * SCREEN_X / screen_size.x)<CANCEL_XR){
					return false;//cancel button pressed
				}
			}
			
		}
	}
}