#include "const.h"
#include "stack.h"

Stack::Stack(std::fstream& chancesdata)
{
	chancesdata >> chancesCount;
	for (int i = 0; i < chancesCount; i++)
	{
		int type;
		indexes += i;
		chancesdata >> type;
		if (type == TRAVEL)
		{
			chances.push_back(new TravellingChance(chancesdata));
		}
		if (type == WALLET)
		{
			chances.push_back(new WalletChance(chancesdata));
		}
		if (type == TELEPORT)
		{
			chances.push_back(new TeleportChance(chancesdata));
		}
		if (type == JAIL)
		{
			chances.push_back(new JailChance(chancesdata));
		}
		if (type == BET)
		{
			chances.push_back(new BetChance(chancesdata));
		}
		if (type == BUFF)
		{
			chances.push_back(new BuffChance(chancesdata));
		}
	}
	indexes.rndm();
	iter = CircularList<int>::CircularIterator::CircularIterator(indexes);
}

void Stack::startNext(Player& currentPlayer)
{
	iter++;
	chances[*iter]->tryYourLuck(currentPlayer);
}