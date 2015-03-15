#include "player.h"
#include "fields.h"

player::player(int numberIn, int x, int y, std::string TexPath){
	number = numberIn;
	PlayerTx.loadFromFile(TexPath);
	Player.setTexture(PlayerTx);
	Player.setPosition(x, y);
	current = board::getStart();
	current->SetPosition(this);
}
void player::Move(int Roll){
	for (int i = 0; i < Roll; i++){
		current = current->next;
	}
	current->SetPosition(this);
}
