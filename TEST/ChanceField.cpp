#include "fields.h"
#include "board.h"
#include "stack.h"

ChanceField::ChanceField(std::fstream& fielddata) :Field(fielddata)
{

}

void ChanceField::enterTheFieldtrix(Player& occupant)
{
	Board::chancesStack->startNext(occupant);
}