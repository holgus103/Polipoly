#include "Fields.h"

	void Field::putSpaces(std::string& input){
	for (int i = 0; i < input.length(); i++)
		if (input[i] == '_')
			input[i] = ' ';
}
	bool Field::belongs(short x, short y){
		if (xl < x && x < xr && yu < y && y < yd)
			return true;
		return false;
	}
	void Field::renderMe(sf::Text& Fieldteam, sf::Text& Fieldname, sf::ConvexShape& Field, sf::Text& FieldContent){
		Fieldteam.setString(team);
		Fieldname.setString(name);
		Field.setFillColor(color);
		FieldContent.setString("");
	};
	Field::Field(std::fstream& Fielddata){
		unsigned int RGBA;
		Fielddata >> team;
		putSpaces(team);
		Fielddata >> name;
		putSpaces(name);
		Fielddata >> RGBA;
		color = sf::Color((RGBA >> 24) & 0xFF, (RGBA >> 16) & 0xFF, (RGBA >> 8) & 0xFF, (RGBA)& 0xFF);
		Fielddata >> xl;
		Fielddata >> xr;
		Fielddata >> yu;
		Fielddata >> yd;
	}

	void Field::setPosition(Player* occupant){
		int x, y, number;
		number = occupant->getNumber();
		x = xl + (3 - (number % 2) * 2)*(xr - xl) / 4 - PIN_WIDTH/2;
		y = yu + (floor(number / 3) * 2 + 1)*(yd - yu) / 4 -PIN_HEIGHT/2;
		(occupant->getPlayerSprite()).setPosition(x, y);
	}
	Field::~Field(){}
	void Field::enterTheFieldtrix(Player& Neo){}
	bool Field::payDay(Player& Chaplin){ return true; }
