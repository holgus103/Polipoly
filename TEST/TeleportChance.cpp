#include "Chances.h"
#include <Windows.h>
#include "messenger.h"

TeleportChance::TeleportChance(std::fstream& fielddata) :Chance(fielddata){
	fielddata >> targetName;
	putSpaces(targetName);
}

void TeleportChance::tryYourLuck(Player& target)
{
	Board::msger->drawMsgBox(message, (std::string) "Szansa", OK);
	target.teleport(targetName);
}