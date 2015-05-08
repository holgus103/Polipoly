#include "userbar.h"

userbar::userbar(int how_many)
{
	player_count = how_many;
	current_player = 0;
	for (int i = 0; i < 8; i++)
		avatars[i] = new sf::Texture;
}

void userbar::load_textures()
{
	avatars[0]->loadFromFile(PLAYER_1_PATH);
	avatars[1]->loadFromFile(PLAYER_1B_PATH);
	avatars[2]->loadFromFile(PLAYER_2_PATH);
	avatars[3]->loadFromFile(PLAYER_2B_PATH);
	avatars[4]->loadFromFile(PLAYER_3_PATH);
	avatars[5]->loadFromFile(PLAYER_3B_PATH);
	avatars[6]->loadFromFile(PLAYER_4_PATH);
	avatars[7]->loadFromFile(PLAYER_4B_PATH);
}

void userbar::start_up(sf::RenderWindow& window)
{
//	sf::Text temp_text;
	sf::Sprite* temp_player = new sf::Sprite();
	for (int i = 0; i < player_count; i++)
	{
		temp_player->setTexture(*avatars[2 * i]);
		temp_player->setPosition(780 + i * 62, 11);
		window.draw(*temp_player);
	}
	for (int i = player_count; i < PLAYERS; i++)
	{
		temp_player->setTexture(*avatars[2 * i]);
		temp_player->setPosition(50 * i, 25);
		window.draw(*temp_player);
	}
}