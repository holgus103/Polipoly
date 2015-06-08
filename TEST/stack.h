#include "CircularList.h"
#include "const.h"

class Stack
{
private:
	CircularList<int> indexes;
	CircularList<int>::CircularIterator iter;
public:
	Stack();
	int giveNext();	
};