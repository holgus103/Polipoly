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
	}
	indexes.rndm();
	iter = CircularList<int>::CircularIterator::CircularIterator(indexes);
}

void Stack::startNext(Player& currentPlayer)
{
	iter++;
	chances[*iter]->tryYourLuck(currentPlayer);
}