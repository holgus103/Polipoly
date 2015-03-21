#include "fields.h"

CommercialField::CommercialField(std::fstream& fielddata, field* prev, int priceIn):field(fielddata,prev){
	owner = NULL;
	price = priceIn;
}

CommercialField::~CommercialField(){}

bool CommercialField::BuyMe(player& buyer){
	if (!buyer.Acquire(price))
		return false;
	else
		owner = &buyer;
	return true;
}

bool CommercialField::PayDay(player& Indepted){
	return owner->Transfer(Indepted, 50);
}

void CommercialField::EnterTheFieldtrix(player& Neo){
	if (owner == NULL)
		BuyMe(Neo);
	else
		PayDay(Neo);
}

void CommercialField::renderMe(sf::Text& fieldteam, sf::Text& fieldname, sf::RectangleShape& field, sf::Text& fieldContent){
	std::string my_info;
	field::renderMe(fieldteam, fieldname, field, fieldContent);
	if (owner != NULL){
		my_info = "Wlasciciel: " +std::to_string(owner->getNumber());
	}
	else{
		my_info = "Wolne";
	}
	fieldContent.setString(my_info);

}