#include "fields.h"

StartField::StartField(std::fstream& fielddata) :Field(fielddata)
{
	fielddata >> bonus; 
}

void StartField::onStepOn(Player& occupant)
{ 
	occupant.giftsAndFines(bonus);
	occupant.setCrossedStart(true);
}