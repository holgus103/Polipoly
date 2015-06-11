#include "stack.h"

Stack::Stack()
{
	for (int i = 0; i < CHANCES_COUNT; i++)
		indexes += i;
	indexes.rndm();
}

int Stack::giveNext()
{
	iter++;
	return *iter;
}