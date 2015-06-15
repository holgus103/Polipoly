#include "Chances.h"
#include <Windows.h>
#include "messenger.h"

JailChance::JailChance(std::fstream& fielddata) :Chance(fielddata){
	fielddata >> prisonName;
	putSpaces(prisonName);
}

void JailChance::tryYourLuck(Player& target)
{
	Board::msger->drawMsgBox(message, (std::string) "Szansa", OK);
	target.teleport(prisonName);
	target.setState(4);
}