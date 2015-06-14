#include "Fields.h"
#include <Windows.h>
#include "board.h"
#include "messenger.h"

CommercialField::CommercialField(std::fstream& fielddata):Field(fielddata){

	owner = NULL;
	fielddata >> price;
}

//~CommercialField::~CommercialField(){}

bool CommercialField::buyMe(Player& buyer){
	if (!buyer.acquire(price))
		return false;
	else
		owner = &buyer;
	return true;
}

bool CommercialField::payDay(Player& Indepted){
	return owner->transfer(Indepted, price*10);

}

void CommercialField::enterTheFieldtrix(Player& Neo){
	if (owner == NULL){
		if (_YES==Board::msger->drawMsgBox("Czy chcesz kupic pole " + name + "?", (std::string)"Potwierdzenie zakupu", OKCANCEL)){
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
		if (payDay(Neo))
		{
		Board::msger->drawMsgBox("Zaplaciles graczowi numer " + std::to_string(owner->getNumber()), (std::string) "Oplata", OK);
		}

}

void CommercialField::renderMe(sf::Text& fieldteam, sf::Text& fieldname, sf::ConvexShape& field, sf::Text& fieldContent){
	std::string my_info;
	Field::renderMe(fieldteam, fieldname, field, fieldContent);
	if (owner != NULL){
		my_info = "Wlasciciel: " +std::to_string(owner->getNumber());
	}
	else{
		my_info = "Wolne";
	}
	fieldContent.setString(my_info);

}