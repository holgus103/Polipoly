#include "FieldSet.h"

void FieldSet::operator+=(CommercialField* data)
{
	wektor.push_back(data);
}

bool FieldSet::compareOwners(int wantedId)
{
	for (std::vector<CommercialField*>::iterator it = wektor.begin(); it != wektor.end(); ++it)
	{
		if ((*it)->getOwnerId() != wantedId)
			return false;
	}
	return true;
}

bool FieldSet::canUpgrade(int level)
{
	for (std::vector<CommercialField*>::iterator it = wektor.begin(); it != wektor.end(); ++it)
	{
		if ((*it)->getLevel() < level)
			return false;
	}
	return true;
}

FieldSet::FieldSet(int a)
{
	id = a;
}