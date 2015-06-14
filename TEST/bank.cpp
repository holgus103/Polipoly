#include "board.h"
#include "bank.h"
#include "const.h"

Bank::Bank()
{
	exitBank = new Button(BANK_EXIT_PATH, BANK_ENTER_XL, BANK_ENTER_XR, BANK_ENTER_YU, BANK_ENTER_YD);
	plus = new Button(BANK_PLUS_PATH, BANK_PLUS_XL, BANK_PLUS_XR, BANK_PLUS_YU, BANK_PLUS_YD);
	minus = new Button(BANK_MINUS_PATH, BANK_MINUS_XL, BANK_MINUS_XR, BANK_MINUS_YU, BANK_MINUS_YD);
	counter = new sf::Texture;
	counter->loadFromFile(BANK_COUNTER_PATH);
}

Bank::~Bank()
{
	delete(exitBank);
	delete(plus);
	delete(minus);
	delete(counter);
}

bool Bank::visitBank(sf::RenderWindow& window, Player& client)
{
	howMuch = 0;
	window.clear();
	sf::Sprite* temp = new sf::Sprite;
	temp->setTexture(*counter);
	temp->setPosition(BANK_COUNTER_X, BANK_COUNTER_Y);
	
	Board::drawGamefield();
	window.draw(*temp);
	exitBank->drawButton(window);
	plus->drawButton(window);
	minus->drawButton(window);

	window.display();
	delete(temp);
	return 0;
}