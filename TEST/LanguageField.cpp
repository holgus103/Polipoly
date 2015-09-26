#include "fields.h"
#include <Windows.h>
#include "board.h"
#include "messenger.h"
#include "CircularList.h"
#include <math.h>

int LanguageField::getOwnerId()
{
	if (owner == NULL)
		return 0;
	return owner->getNumber();
}

int LanguageField::value()
{
	if (owner == NULL)
		return 25;
	int temp = 0;
	LanguageField* temp2;
	CircularList<Field*>::CircularIterator it(Board::fields);
	for (int i = 0; i < 5; i++)
		it++;
	for (int j = 0; j < 4; j++)
	{
		temp2 = (LanguageField*)(*it);
		if (temp2->getOwnerId() == owner->getNumber())
			temp++;
		for (int i = 0; i < 10; i++)
			it++;
	}
	
	return 25 * pow(2, temp - 1);
}

LanguageField::LanguageField(std::fstream& fielddata) :Field(fielddata){

	owner = NULL;
	fielddata >> price;

}


bool LanguageField::buyMe(Player& buyer){
	if (!buyer.acquire(price))
		return false;
	else
		owner = &buyer;
	return true;
}

bool LanguageField::payDay(Player& Indepted){
	return owner->transfer(Indepted, value());

}

void LanguageField::enterTheFieldtrix(Player& Neo){
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
		if (payDay(Neo))
		{
		Board::msger->drawMsgBox("Zaplaciles graczowi numer " + std::to_string(owner->getNumber()), (std::string) "Oplata", OK);
		}
		else
		{
			Board::msger->drawMsgBox((std::string)"Smuta! Nie masz hajsu, wiec odpadasz z gry!", (std::string)"Smutek", OK);
			Neo.bankrupt();
		}

}

void LanguageField::renderMe(sf::Text& fieldteam, sf::Text& fieldname, sf::ConvexShape& field, sf::Text& fieldContent){
	std::string my_info;
	Field::renderMe(fieldteam, fieldname, field, fieldContent);
	if (owner != NULL){
		my_info = "Wlasciciel: " + std::to_string(owner->getNumber());
	}
	else{
		my_info = "Wolne";
	}
	my_info = my_info + "\nCena: " + std::to_string(price) + " ECTS\nCena za wejscie: " + std::to_string(value());
	fieldContent.setString(my_info);
}

void LanguageField::free()
{
	owner = NULL;
}