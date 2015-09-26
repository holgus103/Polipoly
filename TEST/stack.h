#include "CircularList.h"
#include "const.h"
#include "Chances.h"

class Stack
{
private:
	CircularList<int> indexes;
	CircularList<int>::CircularIterator iter;
	std::vector<Chance*> chances;
	int chancesCount;
public:
	Stack(std::fstream& chancesdata);
	~Stack();
	void startNext(Player& currentPlayer);
};