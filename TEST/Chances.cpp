#include "Chances.h"

void Chance::putSpaces(std::string& input)
{
	for (int i = 0; i < input.length(); i++)
		if (input[i] == '_')
			input[i] = ' ';
}

Chance::Chance(std::fstream& Fielddata)
{
	Fielddata >> message;
	putSpaces(message);
}