#include <algorithm>
#include "stack.h"

Stack::Stack()
{
	for (int i = 0; i < CHANCES_COUNT; i++)
		indexes += i;
	std::random_shuffle(indexes.begin(), indexes.end());
	iter = indexes.end();
}

int Stack::giveNext()
{
	iter++;
	return indexes[iter];
}