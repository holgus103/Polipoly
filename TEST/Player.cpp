#include "player.h"

player::player(int numberIn, int x, int y, std::string TexPath){
	number = numberIn;
	PlayerTx.loadFromFile(TexPath);
	Player.setTexture(PlayerTx);
	Player.setPosition(x, y);
}

sf::Sprite& player::getPlayerSprite(){
	return Player;
}