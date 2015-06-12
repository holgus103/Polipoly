#include "Chances.h"
#include <Windows.h>

TravellingChance::TravellingChance(std::fstream& fielddata) :Chance(fielddata){
	fielddata >> steps;
	fielddata >> actions;
}

void TravellingChance::tryYourLuck(Player& target)
{
	MessageBox(NULL, (message).c_str(), "Szansa", MB_OK);
	target.move(steps, actions);
}