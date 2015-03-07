#include "fields.h"

void field::putSpaces(std::string& input){
	for (int i = 0; i < input.length(); i++)
		if (input[i] == '_')
			input[i] = ' ';
}

	void field::renderMe(sf::Text& fieldteam, sf::Text& fieldname, sf::RectangleShape& field){
		fieldteam.setString(team);
		fieldname.setString(name);
		field.setFillColor(color);
	};
	field::field(std::string newTeam, std::string newName, sf::Color newColor):team(newTeam),name(newName), color(newColor)
	{}
	field::field(std::fstream& fielddata){
		unsigned int RGBA;
		fielddata >> team;
		putSpaces(team);
		fielddata >> name;
		putSpaces(name);
		fielddata >> RGBA;
		color = sf::Color((RGBA >> 24) & 0xFF, (RGBA >> 16) & 0xFF, (RGBA >> 8) & 0xFF, (RGBA)& 0xFF);
	}