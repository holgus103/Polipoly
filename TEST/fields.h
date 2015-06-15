#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "const.h"
#include <fstream>
#include "Player.h"
#include <typeinfo>

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
	virtual bool payDay(Player& Chaplin){ return true; }
	void setPosition(Player* occupant);
	virtual ~Field(){};
	virtual void enterTheFieldtrix(Player& Neo){}
	virtual void onStepOn(Player& occupant){}
	std::string getName();
};

class CommercialField:public Field{
	Player* owner;
	int price;
	int setId;
	int level;
public:
	int multiplier(int);
	virtual void renderMe(sf::Text& fieldteam, sf::Text& fieldname, sf::ConvexShape& field, sf::Text& fieldContent);
	bool buyMe(Player& buyer);
	virtual bool payDay(Player& Chaplin);
	CommercialField(std::fstream& fielddata);
	virtual ~CommercialField(){};
	virtual void enterTheFieldtrix(Player& Neo);
	int getOwnerId();
	int getSetId();
	int getLevel();
	int getUpgValue();
};

class PenealtyField :public Field{
	short enteringCharge;
public:
	PenealtyField(std::fstream& fielddata);
	virtual ~PenealtyField(){};
	virtual void enterTheFieldtrix(Player& Neo);
};

class StartField : public Field{
	short bonus;
public:
	StartField(std::fstream& fielddata);
	virtual void onStepOn(Player& occupant);
	virtual ~StartField(){};
};

class ChanceField : public Field{
public:
	ChanceField(std::fstream& fielddata);
	virtual void enterTheFieldtrix(Player& occupant);
	virtual ~ChanceField(){};
};

class PoliceField : public Field{
	std::string targetName;
public:
	PoliceField(std::fstream& fielddata);
	virtual void enterTheFieldtrix(Player& occupant);
	virtual ~PoliceField(){};
};