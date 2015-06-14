#include "Chances.h"

TeleportChance::TeleportChance(std::fstream& fielddata) :Chance(fielddata){
	fielddata >> targetName;
	putSpaces(targetName);
}

void TeleportChance::tryYourLuck(Player& target)
{
	target.teleport(targetName);
}