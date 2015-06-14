#include "Player.h"
#include "Fields.h"
#include <Windows.h>

Player::Player(int numberIn, std::string TexPath,CircularList<Field*>& list){
	it = CircularList<Field*>::CircularIterator::CircularIterator(list);
	cash = INITIAL_CASH;
	ECTS = 10;
	number = numberIn;
	playerTx.loadFromFile(TexPath);
	player.setTexture(playerTx);
	(*it)->setPosition(this);
	state = 2;
}
void Player::move(int Roll, bool actions){
	for (int i = 0; i < Roll; i++){
		it++;
		(*it)->setPosition(this);
		if (actions)// senior Marcin, co to jest actions i po co to komu?
			(*it)->onStepOn(*this);
		Board::drawGamefield();
		Sleep(MOVE_INTERVAL);
	}
	for (int i = 0; i > Roll; i--){
		it--;
		(*it)->setPosition(this);
		if (actions)
			(*it)->onStepOn(*this);
		Board::drawGamefield();
		Sleep(MOVE_INTERVAL);
	}
	(*it)->enterTheFieldtrix(*this);
}

void Player::teleport(std::string target)
{
	do
		it--;
		
	while (target != (*it)->getName());
	(*it)->setPosition(this);
	Board::drawGamefield();
	(*it)->enterTheFieldtrix(*this);
}

bool Player::acquire(int amount){
	if (amount > ECTS)
		return false;
	else
		ECTS -= amount;
	return true;
}

bool Player::transfer(Player& Indepted,int amount){
	if (Indepted.cash < amount)
		return false;
	else{
		Indepted.cash -= amount;
		cash += amount;
		return true;
	}
}


void Player::drawMe(sf::RenderWindow& window,sf::Font& font, sf::Sprite& bgr){
	sf::Text temp;
	int x = PLAYERS_X + (number - 1) * 62;
	temp.setFont(font);
	temp.setCharacterSize(CONTENT_TEXT_SIZE);
	temp.setColor(sf::Color::Black);
	temp.setPosition(x, PLAYERS_Y + 22);
	temp.setString(std::to_string(this->ECTS));
	window.draw(temp);
	temp.setString(std::to_string(this->cash));
	temp.setPosition(x, PLAYERS_Y);
	window.draw(temp);
}

int Player::getState()
{
	if (state > 2)
		return 3;
	return state;
}

void Player::setState(int a)
{
	state = a;
}

bool Player::isPlaying()
{
	if (state == 2)
		return true;
	if (state > 2)
		state--;
	return false;
}