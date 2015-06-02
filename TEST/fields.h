#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "const.h"
#include <fstream>
#include "Player.h"

class Field{
protected:
	short xl, xr, yu, yd;
	std::string team;
	std::string name;
	sf::Color color;
	void putSpaces(std::string& input);
	//player* occupant;

public:
	virtual void renderMe(sf::Text& fieldteam, sf::Text& fieldname, sf::ConvexShape& field, sf::Text& fieldContent);
	Field(std::fstream& fielddata);
	bool belongs(short x, short y);
	virtual bool payDay(Player& Chaplin);
	void setPosition(Player* occupant);
	virtual ~Field();
	virtual void enterTheFieldtrix(Player& Neo);
};

class CommercialField:public Field{
	Player* owner;
	int price;
public:
	virtual void renderMe(sf::Text& fieldteam, sf::Text& fieldname, sf::ConvexShape& field, sf::Text& fieldContent);
	bool buyMe(Player& buyer);
	virtual bool payDay(Player& Chaplin);
	CommercialField(std::fstream& fielddata,int price);
	virtual ~CommercialField();
	virtual void enterTheFieldtrix(Player& Neo);
};

class MoneyField :public Field{
	short amount;
public:
	MoneyField(std::streambuf& fielddata, int amount);
	virtual ~MoneyField();
	virtual void enterTheFieldtrix(Player& Neo){ Neo.giftsAndFines(amount);}
};