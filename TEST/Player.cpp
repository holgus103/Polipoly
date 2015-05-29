#include "player.h"
#include "fields.h"
#include "CircularIterator.cpp"
#include <Windows.h>

player::player(int numberIn, std::string TexPath,CircularList<field*>& list){
	it = CircularList<field*>::CircularIterator::CircularIterator(list);
	cash = INITIAL_CASH;
	ECTS = 10;
	number = numberIn;
	PlayerTx.loadFromFile(TexPath);
	Player.setTexture(PlayerTx);
	//current->SetPosition(this);
	(*it)->SetPosition(this);
}
void player::Move(int Roll){
	for (int i = 0; i < Roll; i++){
		it++;
		//current = current->next;
		(*it)->SetPosition(this);
		//current->SetPosition(this);
		board::DrawGamefield();
		Sleep(MOVE_INTERVAL);
	}
	(*it)->EnterTheFieldtrix(*this);
	//current->EnterTheFieldtrix(*this);
	
}
bool player::Acquire(int amount){
	if (amount > ECTS)
		return false;
	else
		ECTS -= amount;
	return true;
}

bool player::Transfer(player& Indepted,int amount){
	if (Indepted.cash < amount)
		return false;
	else{
		Indepted.cash -= amount;
		cash += amount;
		return true;
	}
}

void player::drawMe(sf::RenderWindow& window,sf::Font& font, sf::Sprite& bgr){
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
