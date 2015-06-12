#include "Chances.h"
#include <Windows.h>

WalletChance::WalletChance(std::fstream& fielddata) :Chance(fielddata){
	fielddata >> money;
}

void WalletChance::tryYourLuck(Player& target)
{
	MessageBox(NULL, (message).c_str(), "Szansa", MB_OK);
	target.giftsAndFines(money);
}