#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "const.h"
#include <fstream>
#include "player.h"

class field{
protected:
	short xl, xr, yu, yd;
	std::string team;
	std::string name;
	sf::Color color;
	void putSpaces(std::string& input);
	//player* occupant;

public:
	virtual void renderMe(sf::Text& fieldteam, sf::Text& fieldname, sf::ConvexShape& field, sf::Text& fieldContent);
	field(std::fstream& fielddata, field* prev);
	bool belongs(short x, short y);
	field* next, *prev;
	virtual bool PayDay(player& Chaplin);
	void SetPosition(player* occupant);
	virtual ~field();
	virtual void EnterTheFieldtrix(player& Neo);
};

class CommercialField:public field{
	player* owner;
	int price;
public:
	virtual void renderMe(sf::Text& fieldteam, sf::Text& fieldname, sf::ConvexShape& field, sf::Text& fieldContent);
	bool BuyMe(player& buyer);
	virtual bool PayDay(player& Chaplin);
	CommercialField(std::fstream& fielddata, field* prev, int price);
	virtual ~CommercialField();
	virtual void EnterTheFieldtrix(player& Neo);
};

class TakeAChangeOnMe:public field{

};