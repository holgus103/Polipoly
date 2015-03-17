#include "board.h"
#include "fields.h"
#include "Dice.h"

field* board::start;
sf::Texture board::gamefieldTX;
sf::Texture board::fieldInfoTX;
sf::Sprite board::gamefield;
sf::Sprite board::fieldInfo;
sf::Sprite* board::Dices[2];
sf::Sprite board::dicePic1;
sf::Sprite board::dicePic2;
sf::Text board::teamName;
sf::Text board::fieldName;
sf::Font board::font;
sf::RectangleShape board::fieldColor;
player* board::players[PLAYERS];
player* board::current;
sf::RenderWindow* board::mainWindow;


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
	//prepare the dices
	dicePic1.setPosition(DICE1_X, DICE1_Y);
	dicePic2.setPosition(DICE2_X, DICE2_Y);
	dice::LoadTextures();
	Dices[0] = &dicePic1;
	Dices[1] = &dicePic2;
	dice::SetDicesIdle(Dices, sizeof(Dices) / sizeof(Dices[0]));

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

	//initialize players
	players[0] = new player(1, PLAYER_1_PATH);
	players[1] = new player(2, PLAYER_2_PATH);
	players[2] = new player(3,PLAYER_3_PATH);
	players[3] = new player(4, PLAYER_4_PATH);
	current = players[0];
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
		start = start->next;
		delete start->prev;
	}
	delete start;
	for (int i = 0; i < PLAYERS; i++){
		if (players[i] == NULL)
			break;
		delete players[i];
	}
}

void board::DrawGamefield(){
	mainWindow->draw(gamefield);
	mainWindow->draw(fieldInfo);
	mainWindow->draw(fieldColor);
	mainWindow->draw(teamName);
	mainWindow->draw(fieldName);
	mainWindow->draw(dicePic1);
	mainWindow->draw(dicePic2);
	for (int i = 0; i < PLAYERS; i++){
		if (players[i] == NULL)
			break;
		mainWindow->draw(players[i]->getPlayerSprite());
	}
	mainWindow->draw((players[0]->getPlayerSprite()));
	mainWindow->display();
}

void board::serveClick(int x, int y){
	int roll;
	if (DICE1_X<x && x<DICE2_X + DICE_SIZE && y>DICE1_Y && y < DICE1_Y + DICE_SIZE){
		roll = dice::RollMe(mainWindow, Dices, sizeof(Dices) / sizeof(Dices[0]));
		current->Move(roll);
		current->GetCurrentField()->renderMe(teamName, fieldName, fieldColor);
		current = players[current->getNumber()] != NULL ? players[current->getNumber()] : players[0];
	}
	renderClickedField(x, y);
}