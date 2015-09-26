#include "Chances.h"
#include <Windows.h>
#include "messenger.h"

WalletChance::WalletChance(std::fstream& fielddata) :Chance(fielddata){
	fielddata >> money;
}

void WalletChance::tryYourLuck(Player& target)
{
	Board::msger->drawMsgBox(message, (std::string) "Szansa", OK);
	if (target.giftsAndFines(money) == false)
		target.bankrupt();
}