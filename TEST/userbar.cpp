#include "userbar.h"
#include "board.h"
#include "player.h"

userbar::userbar(int how_many)
{
	player_count = how_many;
	for (int i = 0; i < 8; i++)
		avatars[i] = new sf::Texture;
	for (int i = 0; i < 4; i++)
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
	led[0]->loadFromFile(USERBAR_LED2_PATH);
	led[1]->loadFromFile(USERBAR_LED3_PATH);
	led[2]->loadFromFile(USERBAR_LED0_PATH);
	led[3]->loadFromFile(USERBAR_LED1_PATH);
}

void userbar::drawUserbar(sf::RenderWindow& window)
{
	//	sf::Text temp_text;
	sf::Sprite* temp_player = new sf::Sprite();
	sf::Sprite* temp_led = new sf::Sprite();
	for (int i = 0; i < player_count; i++)
	{
		int temp_state = Board::players[i]->getState();
		temp_led->setTexture(*led[temp_state]);
		if (temp_state == 0)
			temp_player->setTexture(*avatars[2 * i + 1]);
		else
			temp_player->setTexture(*avatars[2 * i]);
		temp_player->setPosition(780 + i * 62, 11);
		window.draw(*temp_player);
		temp_led->setPosition(818 + i * 62, 9);
		window.draw(*temp_led);
	}
	temp_led->setTexture(*led[0]);
	for (int i = player_count; i < PLAYERS; i++)
	{
		temp_player->setTexture(*avatars[2 * i + 1]);
		temp_player->setPosition(780 + i * 62, 11);
		window.draw(*temp_player);
		temp_led->setPosition(818 + i * 62, 9);
		window.draw(*temp_led);
	}


	delete(temp_led);
	delete(temp_player);
}

userbar::~userbar()
	{
	for (int i = 0; i < 8; i++)
		delete(avatars[i]);
	for (int i = 0; i < 3; i++)
		delete(led[i]);
	}