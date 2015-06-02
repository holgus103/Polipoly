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
	//current->SetPosition(this);
	(*it)->setPosition(this);
}
void Player::move(int Roll){
	for (int i = 0; i < Roll; i++){
		it++;
		//current = current->next;
		(*it)->setPosition(this);
		//current->SetPosition(this);
		Board::drawGamefield();
		Sleep(MOVE_INTERVAL);
	}
	(*it)->enterTheFieldtrix(*this);
	//current->EnterTheFieldtrix(*this);
	
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
	temp.setPosition(x, PLAYERS_Y);
	temp.setString(std::to_string(this->ECTS));
	window.draw(temp);
	temp.setString(std::to_string(this->cash));
	temp.setPosition(x, PLAYERS_Y + 22);
	window.draw(temp);

}
