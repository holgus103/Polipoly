#include "Chances.h"
#include <Windows.h>
#include "messenger.h"

TravellingChance::TravellingChance(std::fstream& fielddata) :Chance(fielddata){
	fielddata >> steps;
	fielddata >> actions;
}

void TravellingChance::tryYourLuck(Player& target)
{
	Board::msger->drawMsgBox(message, (std::string) "Szansa", OK);
	target.move(steps, actions);
}