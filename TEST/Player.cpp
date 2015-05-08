#include "player.h"
#include "fields.h"
#include <Windows.h>

player::player(int numberIn, std::string TexPath){
	cash = INITIAL_CASH;
	ECTS = 10;
	number = numberIn;
	PlayerTx.loadFromFile(TexPath);
	Player.setTexture(PlayerTx);
	current = board::getStart();
	current->SetPosition(this);
}
void player::Move(int Roll){
	for (int i = 0; i < Roll; i++){
		current = current->next;
		current->SetPosition(this);
		board::DrawGamefield();
		Sleep(MOVE_INTERVAL);
	}
	current->EnterTheFieldtrix(*this);
	
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
	sf::Sprite player = Player;
	int x = PLAYERS_X + ((number + 1) % 2) * PLAYER_BGR_X;
	int y = PLAYERS_Y +(floor(number / 3) * PLAYER_BGR_Y);
	bgr.setPosition(x, y);
//	window.draw(bgr);
	player.setPosition(x, y);
	window.draw(player);
	temp.setFont(font);
	temp.setCharacterSize(CONTENT_TEXT_SIZE);
	temp.setColor(sf::Color::Black);
	temp.setPosition(x + 30, y);
	temp.setString("ECTS: " + std::to_string(this->ECTS));
	window.draw(temp);
	temp.setString("Cash: " + std::to_string(this->cash));
	temp.setPosition(x+30, y + 30);
	window.draw(temp);

}
