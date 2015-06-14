#include "Chances.h"
#include <Windows.h>

TeleportChance::TeleportChance(std::fstream& fielddata) :Chance(fielddata){
	fielddata >> targetName;
	putSpaces(targetName);
}

void TeleportChance::tryYourLuck(Player& target)
{
	MessageBox(NULL, (message).c_str(), "Szansa", MB_OK);
	target.teleport(targetName);
}