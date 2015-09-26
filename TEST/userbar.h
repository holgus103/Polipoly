#pragma once
#include "Board.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "const.h"

class userbar{
private:
	int current_player;
	int player_count;
public:
	sf::Texture* avatars[8];
	sf::Texture* led[4];
	userbar(int how_many);
	void drawUserbar(sf::RenderWindow& window);
	void load_textures();
//	void update(int player, double cash, int ects, sf::RenderWindow& window);
	~userbar();
};
