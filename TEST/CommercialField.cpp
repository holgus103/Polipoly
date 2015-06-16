#include "Fields.h"
#include <Windows.h>
#include "board.h"
#include "messenger.h"
#include "FieldSet.h"

CommercialField::CommercialField(std::fstream& fielddata):Field(fielddata){

	owner = NULL;
	fielddata >> price;
	fielddata >> setId;
	*Board::setsInfo[setId] += (this);
	level = 0;
}

//~CommercialField::~CommercialField(){}

int CommercialField::multiplier(int a)
{
	if (a == 0)
		return 1;
	if (a == 1)
		return 4;
	if (a == 2)
		return 12;
	if (a == 3)
		return 28;
	if (a == 4)
		return 34;
	if (a == 5)
		return 40;
}

bool CommercialField::buyMe(Player& buyer){
	if (!buyer.acquire(price))
		return false;
	else
		owner = &buyer;
	return true;
}

bool CommercialField::payDay(Player& Indepted){
	return owner->transfer(Indepted, price*25*multiplier(level));

}

void CommercialField::enterTheFieldtrix(Player& Neo){
	if (owner == NULL){
		if (_YES == Board::msger->drawMsgBox("Czy chcesz kupic pole " + name + " za " + std::to_string(price) + "ECTS?", (std::string)"Potwierdzenie zakupu", OKCANCEL)){
			//if (IDOK == MessageBox(NULL, ("Czy chcesz kupic pole " + name).c_str(), "Zakup", MB_OKCANCEL))
			if (buyMe(Neo))
				Board::msger->drawMsgBox("Kupiles pole " + name + ".", (std::string)"Zakup udany", OK);
			else
				Board::msger->drawMsgBox((std::string)"Nie masz dosc ECTS.", (std::string)"Zakup nieudany", OK);
		}
		else{
			return;
		}
	}
	else
		if (owner != &Neo){
			if (payDay(Neo))
			{
				Board::msger->drawMsgBox("Zaplaciles graczowi numer " + std::to_string(owner->getNumber()), (std::string) "Oplata", OK);
			}
			else{
				Board::msger->drawMsgBox((std::string)"Smuta! Nie masz hajsu, wiec odpadasz z gry!", (std::string)"Smutek", OK);
				Neo.bankrupt();
			}
		}

}

void CommercialField::renderMe(sf::Text& fieldteam, sf::Text& fieldname, sf::ConvexShape& field, sf::Text& fieldContent){
	std::string my_info;
	Field::renderMe(fieldteam, fieldname, field, fieldContent);
	if (owner != NULL){
		my_info = "Wlasciciel: " + std::to_string(owner->getNumber());
	}
	else{
		my_info = "Wolne";
	}
	my_info = my_info + "\nCena: " + std::to_string(price) + " ECTS\nPoziom: " + std::to_string(level) + " \nCena za wejscie: " + std::to_string(25 * price*multiplier(level)) + " \nCena ulepszenia: " + std::to_string(25 * price*(level + 1));
	fieldContent.setString(my_info);
}

int CommercialField::getOwnerId()
{
	if (owner == NULL)
		return 0;
	return owner->getNumber();
}

int CommercialField::getSetId()
{
	return setId;
}

int CommercialField::getLevel()
{
	return level;
}

int CommercialField::getUpgValue()
{
	return 25 * price*(level + 1);
}

void CommercialField::free()
{
	owner = NULL;
	level = 0;
}