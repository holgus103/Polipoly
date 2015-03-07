#include "board.h"

field* board::start;

void board::buildGameField(std::fstream& fielddata){
	field* temp = NULL;
	start = new field(fielddata, NULL);
	temp = start;
	for (int i = 0; i < GAMEFIELD_SIZE - 1; i++){
		temp->next = new field(fielddata, temp);
		temp = temp->next;
	}
	temp->next = start;
	start->prev = temp;
}

bool board::renderClickedField(short x, short y,sf::Text& fieldteam, sf::Text& fieldname, sf::RectangleShape& fieldh)
{
	field* temp = start;
	do{
		if (temp->belongs(x, y)){
			temp->renderMe(fieldteam, fieldname, fieldh);
			return true;
		}
		temp = temp->next;
	} while (temp != start);
	return false;
}
void board::dispose(){
	start->prev->next = NULL;
	while (start->next!= NULL){
		//start->prev= NULL;
		start = start->next;
		delete start->prev;
	}
	delete start;
}