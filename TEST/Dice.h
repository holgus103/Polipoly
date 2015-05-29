#pragma once
#include <SFML/Graphics.hpp>
#include <windows.h>
class dice{
	static sf::Texture dicePicTX[7];
public:
	static int RollMe(sf::RenderWindow* window, sf::Sprite* diceFields[],int dices);
	static bool LoadTextures();
	static void SetDicesIdle(sf::Sprite* diceFields[], int dices);
};