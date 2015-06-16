#include "Player.h"
#include "Fields.h"
#include <Windows.h>
#include "messenger.h"

Player::Player(int numberIn, std::string TexPath,CircularList<Field*>& list){
	it = CircularList<Field*>::CircularIterator::CircularIterator(list);
	cash = INITIAL_CASH;
	ECTS = 10;
	number = numberIn;
	playerTx.loadFromFile(TexPath);
	player.setTexture(playerTx);
	(*it)->setPosition(this);
	state = 2;
	immune = 0;
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
	(*it)->onStepOn(*this);
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
	if (Indepted.getNumber() == number)
		return true;
	if (Indepted.cash < amount)
	{
		int tempECTS = Indepted.ECTS;
		int tempCash = Indepted.cash;
		for (int i = 0; i < tempECTS; i++)
		{
			Indepted.ECTS--;
			Indepted.cash += ECTS_SELL_PRICE;
			if (Indepted.cash < amount)
			{
				Indepted.cash -= amount;
				cash += amount;
				return true;
			}
		}
		cash += Indepted.cash;
		ECTS = tempECTS;
		cash = tempCash;
		return false;
	}
	else{
		Indepted.cash -= amount;
		cash += amount;
		return true;
	}
}

bool Player::giftsAndFines(int amount)
{
	if (cash < -amount)
	{
		int tempECTS = ECTS;
		int tempCash = cash;
		for (int i = 0; i < tempECTS; i++)
		{
			ECTS--;
			cash += ECTS_SELL_PRICE;
			if (cash < amount)
			{
				cash += amount;
				return true;
			}
		}
		ECTS = tempECTS;
		cash = tempCash;
		return false;
	}
	else{
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

void Player::setCrossedStart(bool a)
{
	crossedStart = a;
}

bool Player::getCrossedStart()
{
	return crossedStart;
}

int Player::capability(exValue type)
{
	if (type == ECTS)
		return ECTS * ECTS_SELL_PRICE;
	if (crossedStart)
		return cash / ECTS_BUY_PRICE2;
	return cash / ECTS_BUY_PRICE;
}

void Player::addImmunity()
{
	immune++;
}

bool Player::isImmune()
{
	if (immune == 0)
		return false;
	immune--;
	return true;
}

void Player::bankrupt()
{
	CommercialField* temp1;
	LanguageField* temp2;
	RollingField* temp3;
	CircularList<Field*>::CircularIterator it(Board::fields);
	do{
		if ((std::string)typeid(**it).name() == (std::string)"class CommercialField")
		{
			temp1 = (CommercialField*)(*it);
			if (temp1->getOwnerId() == number)
				temp1->free();
		}
		if ((std::string)typeid(**it).name() == (std::string)"class LanguageField")
		{
			temp2 = (LanguageField*)(*it);
			if (temp2->getOwnerId() == number)
				temp2->free();
		}
		if ((std::string)typeid(**it).name() == (std::string)"class RollingField")
		{
			temp3 = (RollingField*)(*it);
			if (temp3->getOwnerId() == number)
				temp3->free();
		}
	} while (!it++);
	state = 0;
	cash = 0;
	ECTS = 0;
	Board::msger->drawMsgBox((std::string)"Gracz " + std::to_string(number) + (std::string)" zostal wyeliminowany.", (std::string)"Zycie", OK);
}