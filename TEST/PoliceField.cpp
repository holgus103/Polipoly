#include "fields.h"
#include "messenger.h"

PoliceField::PoliceField(std::fstream& fielddata) :Field(fielddata)
{
	fielddata >> targetName;
	fielddata >> message;
	fielddata >> message2;
	putSpaces(targetName);
	putSpaces(message);
	putSpaces(message2);
}

void PoliceField::enterTheFieldtrix(Player& occupant)
{
	if (occupant.isImmune())
		Board::msger->drawMsgBox(message2, (std::string) "Integracja", OK);
	else
	{
		Board::msger->drawMsgBox(message, (std::string) "Integracja", OK);
		occupant.setState(4);
		occupant.teleport(targetName);
	}
}