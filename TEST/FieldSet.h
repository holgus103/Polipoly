#pragma once
#include <vector>
#include "fields.h"

class FieldSet
{
private:
	int id;
	std::vector<CommercialField*> wektor;
public:
	void operator+=(CommercialField* data);
	bool compareOwners(int wantedId);
	bool canUpgrade(int level);
	FieldSet(int);
};