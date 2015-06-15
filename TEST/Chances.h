#pragma once
#include <string>
#include "const.h"
#include <fstream>
#include "Player.h"

class Chance
{
protected:
	std::string message;
	void putSpaces(std::string& input);
public:
	Chance(std::fstream& fielddata);
	virtual void tryYourLuck(Player& target){};
};

class TravellingChance :public Chance
{
	int steps;
	bool actions;
public:
	TravellingChance(std::fstream& fielddata);
	virtual void tryYourLuck(Player& target);
};

class TeleportChance :public Chance
{
	std::string targetName;
public:
	TeleportChance(std::fstream& fielddata);
	virtual void tryYourLuck(Player& target);
};

class WalletChance :public Chance
{
	int money;
public:
	WalletChance(std::fstream& fielddata);
	virtual void tryYourLuck(Player& target);
};

class JailChance :public Chance
{
	std::string prisonName;
public:
	JailChance(std::fstream& fielddata);
	virtual void tryYourLuck(Player& target);
};

class BetChance :public Chance
{
	int money;
public:
	BetChance(std::fstream& fielddata);
	virtual void tryYourLuck(Player& target);
};

class BuffChance :public Chance
{
public:
	BuffChance(std::fstream& fielddata);
	virtual void tryYourLuck(Player& target);
};