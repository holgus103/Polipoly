#include "messenger.h"
#include "const.h"

void Messenger::drawMsgBox(sf::RenderWindow& window)
{
	sf::Sprite* temp = new sf::Sprite();

	delete(temp);
}
void drawBuyMessage(sf::RenderWindow& window, std::string fieldName);
Messenger::Messenger()
{
	background->loadFromFile(MSG_BG_PATH);
}