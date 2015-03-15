#include "player.h"
#include "fields.h"

player::player(int numberIn, std::string TexPath){
	number = numberIn;
	PlayerTx.loadFromFile(TexPath);
	Player.setTexture(PlayerTx);
	current = board::getStart();
	current->SetPosition(this);
}
void player::Move(int Roll){
	for (int i = 0; i < Roll; i++){
		current = current->next;
	}
	current->SetPosition(this);
}
