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
