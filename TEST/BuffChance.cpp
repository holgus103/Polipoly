#include "Chances.h"
#include "messenger.h"

BuffChance::BuffChance(std::fstream& fielddata) :Chance(fielddata){
}

void BuffChance::tryYourLuck(Player& target)
{
	Board::msger->drawMsgBox(message, (std::string) "Szansa", OK);
	target.addImmunity();
}