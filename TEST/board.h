#include "fields.h"


class board{
private:
	static field* start;
public:
	static void buildGameField(std::fstream& fielddata);
	static bool renderClickedField(short x, short y, sf::Text& fieldteam, sf::Text& fieldname, sf::RectangleShape& fieldh);
	static void dispose();
};