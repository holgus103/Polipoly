#include "messenger.h"
#include "const.h"

void Messenger::drawMsgBox()
{
	sf::Sprite* temp = new sf::Sprite();
	temp->setTexture(*background);
	temp->setPosition(MSG_BG_POSITION, MSG_BG_POSITION);
	window.draw(*temp);
	window.display();
	delete(temp);
}
void Messenger::drawBuyMessage(sf::RenderWindow& window, std::string fieldName)
{
	sf::Text temp;

}

Messenger::Messenger(sf::RenderWindow& w) : window(w)
{
	background = new sf::Texture;
	background->loadFromFile(MSG_BG_PATH);
}