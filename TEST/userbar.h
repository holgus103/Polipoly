#pragma once
#include "board.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "const.h"

class userbar{
private:
	int current_player;
	int player_count;
public:
	sf::Texture* avatars[8];
	sf::Texture* led[2];
	userbar(int how_many);
	void start_up(sf::RenderWindow& window);
	void load_textures();
	void next_player();
//	void update(int player, double cash, int ects, sf::RenderWindow& window);
	~userbar();
};
