#include "fields.h"

PoliceField::PoliceField(std::fstream& fielddata) :Field(fielddata)
{
	fielddata >> targetName;
	putSpaces(targetName);
}

void PoliceField::enterTheFieldtrix(Player& occupant)
{
	occupant.setState(4);
	occupant.teleport(targetName);
}