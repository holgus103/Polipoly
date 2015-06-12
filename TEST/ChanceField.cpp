#include "fields.h"
#include "board.h"
#include "stack.h"

ChanceField::ChanceField(std::fstream& fielddata) :Field(fielddata)
{

}

void ChanceField::onStepOn(Player& occupant)
{
	Board::chancesStack->startNext(occupant);
}