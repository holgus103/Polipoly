#include "fields.h"

	void field::putSpaces(std::string& input){
	for (int i = 0; i < input.length(); i++)
		if (input[i] == '_')
			input[i] = ' ';
}
	bool field::belongs(short x, short y){
		if (xl < x && x < xr && yu < y && y < yd)
			return true;
		return false;
	}
	void field::renderMe(sf::Text& fieldteam, sf::Text& fieldname, sf::RectangleShape& field){
		fieldteam.setString(team);
		fieldname.setString(name);
		field.setFillColor(color);
	};
	field::field(std::fstream& fielddata,field* newPrev){
		unsigned int RGBA;
		fielddata >> team;
		putSpaces(team);
		fielddata >> name;
		putSpaces(name);
		fielddata >> RGBA;
		color = sf::Color((RGBA >> 24) & 0xFF, (RGBA >> 16) & 0xFF, (RGBA >> 8) & 0xFF, (RGBA)& 0xFF);
		fielddata >> xl;
		fielddata >> xr;
		fielddata >> yu;
		fielddata >> yd;
		prev = newPrev;
	}

	void field::SetPosition(player* occupant){
		int x, y, number;
		number = occupant->getNumber();
		x = xl + (3 - (number % 2) * 2)*(xr - xl) / 4 - PIN_WIDTH/2;
		y = yu + (floor(number / 3) * 2 + 1)*(yd - yu) / 4 -PIN_HEIGHT/2;
		(occupant->getPlayerSprite()).setPosition(x, y);
	}