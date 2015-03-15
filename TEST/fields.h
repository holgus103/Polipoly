#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "const.h"
#include <fstream>
#include "player.h"

class field{
private:
	int owner;
	short xl, xr, yu, yd;
	std::string team;
	std::string name;
	sf::Color color;
	void putSpaces(std::string& input);
	player* occupant;

public:
	void renderMe(sf::Text& fieldteam, sf::Text& fieldname, sf::RectangleShape& field);
	int GetOwner(){ return owner; }
	field(std::fstream& fielddata, field* prev);
	bool belongs(short x, short y);
	field* next, *prev;
	void SetPosition(player* occupant);
};