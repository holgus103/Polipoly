#include "Fields.h"

PenealtyField::PenealtyField(std::fstream& fielddata) : Field(fielddata)
{
	fielddata >> enteringCharge;
}

void PenealtyField::enterTheFieldtrix(Player& Neo)
{
	Neo.giftsAndFines(enteringCharge); 
}
