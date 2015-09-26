#pragma once
#include <SFML/Graphics.hpp>
#include <windows.h>
class dice{
	static sf::Texture dicePicTX[7];
public:
	static int rollMe(sf::RenderWindow* window, sf::Sprite* diceFields[],int dices);
	static bool loadTextures();
	static void setDicesIdle(sf::Sprite* diceFields[], int dices);
};