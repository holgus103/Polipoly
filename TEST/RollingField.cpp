#include "fields.h"
#include <Windows.h>
#include "board.h"
#include "messenger.h"

int RollingField::getOwnerId()
{
	if (owner == NULL)
		return 0;
	return owner->getNumber();
}

RollingField::RollingField(std::fstream& fielddata) :Field(fielddata){

	owner = NULL;
	fielddata >> price;
}

bool RollingField::buyMe(Player& buyer){
	if (!buyer.acquire(price))
		return false;
	else
		owner = &buyer;
	return true;
}

bool RollingField::payDay(Player& Indepted, int rolled){
	return owner->transfer(Indepted, price * rolled);

}

void RollingField::enterTheFieldtrix(Player& Neo){
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
		if (payDay(Neo, Board::roll))
		{
		Board::msger->drawMsgBox("Zaplaciles graczowi numer " + std::to_string(owner->getNumber()), (std::string) "Oplata", OK);
		}
		else
		{
			Board::msger->drawMsgBox((std::string)"Smuta! Nie masz hajsu, wiec odpadasz z gry!", (std::string)"Smutek", OK);
			Neo.bankrupt();
		}

}

void RollingField::renderMe(sf::Text& fieldteam, sf::Text& fieldname, sf::ConvexShape& field, sf::Text& fieldContent){
	std::string my_info;
	Field::renderMe(fieldteam, fieldname, field, fieldContent);
	if (owner != NULL){
		my_info = "Wlasciciel: " + std::to_string(owner->getNumber());
	}
	else{
		my_info = "Wolne";
	}
	my_info = my_info + "\nCena: " + std::to_string(price) + " ECTS\nCena za wejscie: pieciokrotnosc\nsumy wyrzuconych oczek";
	fieldContent.setString(my_info);
}

void RollingField::free()
{
	owner = NULL;
}