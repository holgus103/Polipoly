#include "fields.h"


	void field::renderMe(sf::Text& fieldteam, sf::Text& fieldname, sf::RectangleShape& field){
		fieldteam.setString(team);
		fieldname.setString(name);
		field.setFillColor(color);
	};
	field::field(std::string newTeam, std::string newName, sf::Color newColor):team(newTeam),name(newName), color(newColor)
	{}
