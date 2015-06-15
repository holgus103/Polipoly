#include "Chances.h"
#include <Windows.h>
#include "messenger.h"


BetChance::BetChance(std::fstream& fielddata) :Chance(fielddata){
	fielddata >> money;
}

void BetChance::tryYourLuck(Player& target)
{
	Board::msger->drawMsgBox(message, (std::string) "Szansa", OK);
	for (int i = 0; i < 4; i++)
		target.transfer(*Board::players[i], money);
}