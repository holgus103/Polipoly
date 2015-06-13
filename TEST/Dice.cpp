#include "Dice.h"
#include "const.h"
#include <array>
 int dice::rollMe(sf::RenderWindow* window, sf::Sprite* diceFields[],int dices){
	 int* value = new int[dices];
	 int sum=0;
	for (int j = 0; j < 20; j++)
	{
		
		for (int i = 0; i < dices; i++){
			diceFields[i]->setTexture(dicePicTX[value[i] = rand() % 6]);
			window->draw(*diceFields[i]);
		}
		window->display();
		Sleep(j * 15);
	}
	for (int i = 0; i < dices; i++)
		sum += value[i];
	delete[] value;
	return 1;// sum + dices;
}

 void dice::setDicesIdle(sf::Sprite* diceFields[], int dices){
	 for (int i = 0; i < dices; i++){
		 diceFields[i]->setTexture(dicePicTX[6]);
	 }
 }

bool dice::loadTextures(){
		dicePicTX[0].loadFromFile(DICE_PIC_ONE);
		dicePicTX[1].loadFromFile(DICE_PIC_TWO);
		dicePicTX[2].loadFromFile(DICE_PIC_THREE);
		dicePicTX[3].loadFromFile(DICE_PIC_FOUR);
		dicePicTX[4].loadFromFile(DICE_PIC_FIVE);
		dicePicTX[5].loadFromFile(DICE_PIC_SIX);
		dicePicTX[6].loadFromFile(DICE_PIC_IDLE);
		return true;
	}

sf::Texture dice::dicePicTX[7];