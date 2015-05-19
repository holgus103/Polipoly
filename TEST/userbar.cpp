#include "userbar.h"

userbar::userbar(int how_many)
{
	player_count = how_many;
	current_player = 0;
	for (int i = 0; i < 8; i++)
		avatars[i] = new sf::Texture;
	for (int i = 0; i < 3; i++)
		led[i] = new sf::Texture;
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
	led[0]->loadFromFile(USERBAR_LED1_PATH);
	led[1]->loadFromFile(USERBAR_LED2_PATH);
	led[2]->loadFromFile(USERBAR_LED3_PATH);
}

void userbar::start_up(sf::RenderWindow& window)
{
	//	sf::Text temp_text;
	sf::Sprite* temp_player = new sf::Sprite();
	sf::Sprite* temp_led = new sf::Sprite();
	temp_led->setTexture(*led[0]);
	for (int i = 0; i < player_count; i++)
	{
		temp_player->setTexture(*avatars[2 * i]);
		temp_player->setPosition(780 + i * 62, 11);
		window.draw(*temp_player);
		temp_led->setPosition(818 + i * 62, 9);
		window.draw(*temp_led);
	}
	temp_led->setTexture(*led[1]);
	for (int i = player_count; i < PLAYERS; i++)
	{
		temp_player->setTexture(*avatars[2 * i + 1]);
		temp_player->setPosition(50 * i, 25);
		window.draw(*temp_player);
		temp_led->setPosition(818 + i * 62, 9);
		window.draw(*temp_led);
	}
	temp_led->setTexture(*led[2]);
	temp_led->setPosition(818 + 62 * current_player, 9);
	window.draw(*temp_led);
	delete(temp_led);
	delete(temp_player);
}

void userbar::next_player()
{
	current_player = (current_player + 1) % player_count;
}

userbar::~userbar()
	{
	for (int i = 0; i < 8; i++)
		delete(avatars[i]);
	for (int i = 0; i < 3; i++)
		delete(led[i]);
	}