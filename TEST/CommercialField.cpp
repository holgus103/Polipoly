#include "Fields.h"
#include <Windows.h>

CommercialField::CommercialField(std::fstream& fielddata, int priceIn):Field(fielddata){
	owner = NULL;
	price = priceIn;
}

CommercialField::~CommercialField(){}

bool CommercialField::buyMe(Player& buyer){
	if (!buyer.acquire(price))
		return false;
	else
		owner = &buyer;
	return true;
}

bool CommercialField::payDay(Player& Indepted){
	return owner->transfer(Indepted, 50);
}

void CommercialField::enterTheFieldtrix(Player& Neo){
	if (owner == NULL){
		if (IDOK == MessageBox(NULL, ("Czy chcesz kupic pole " + name).c_str(), "Zakup", MB_OKCANCEL))
			if (buyMe(Neo))
				MessageBox(NULL, ("Kupiles pole " + name).c_str(), "Zakup udany", MB_OK);
			else
				MessageBox(NULL, "Nie masz dosc ECTS", "Zakup nieudany", MB_OK);
		else{
			return;
		}
	}
	else
		if (payDay(Neo))
		{
			MessageBox(NULL, ("Zaplaciles graczowi numer " + std::to_string(owner->getNumber())).c_str(), "Oplata", MB_OK);
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