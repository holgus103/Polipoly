#include "board.h"
#include "fields.h"

field* board::start;
sf::Texture board::gamefieldTX;
sf::Texture board::fieldInfoTX;
sf::Sprite board::gamefield;
sf::Sprite board::fieldInfo;
sf::Text board::teamName;
sf::Text board::fieldName;
sf::Font board::font;
sf::RectangleShape board::fieldColor;



void board::buildGameField(std::fstream& fielddata){
	//create gamefield sprite
	gamefieldTX.loadFromFile(GAMEFIELD_PATH);
	gamefield.setTexture(gamefieldTX);
	//create font
	font.loadFromFile(MY_FONT_PATH);
	//create text fields and images
	teamName.setFont(font);
	teamName.setCharacterSize(TEAMNAME_TEXT_SIZE);
	teamName.setPosition(TEAMNAME_X, TEAMNAME_Y);
	teamName.setColor(sf::Color::Black);

	fieldName.setFont(font);
	fieldName.setCharacterSize(FIELDNAME_TEXT_SIZE);
	fieldName.setPosition(FIELDNAME_X, FIELDNAME_Y);
	fieldName.setColor(sf::Color::Black);

	fieldInfoTX.loadFromFile(FIELDINFO_TEX_PATH);
	fieldInfo.setTexture(fieldInfoTX);
	fieldInfo.setPosition(FIELDINFO_X, FIELDINFO_Y);

	fieldColor = sf::RectangleShape(sf::Vector2f(FIELDCOLOR_SIZEX, FIELDCOLOR_SIZEY));
	fieldColor.setPosition(FIELDCOLOR_X, FIELDCOLOR_Y);
	//build the gamefield list 
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

bool board::renderClickedField(short x, short y)
{
	field* temp = start;
	do{
		if (temp->belongs(x, y)){
			temp->renderMe(teamName, fieldName, fieldColor);
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
void board::move(int roll){

}