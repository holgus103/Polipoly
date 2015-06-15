#include "Board.h"
#include "Fields.h"
#include "Dice.h"
#include "userbar.h"
#include "messenger.h"
#include "Chances.h"
#include "stack.h"
#include "button.h"
#include "bank.h"

CircularList<Field*> Board::fields;
sf::Texture Board::gamefieldTX;
sf::Texture Board::fieldInfoTX;
sf::Texture Board::bgrTx;
sf::Sprite Board::gamefield;
sf::Sprite Board::fieldInfo;
sf::Sprite* Board::Dices[2];
sf::Sprite Board::dicePic1;
sf::Sprite Board::dicePic2;
sf::Sprite Board::bgr;
sf::Text Board::teamName;
sf::Text Board::fieldName;
sf::Text Board::fieldContent;
sf::Font Board::font;
sf::ConvexShape Board::fieldColor;
Player* Board::players[PLAYERS];
Player* Board::current;
sf::RenderWindow* Board::mainWindow;
userbar* Board::user_bar;
Messenger* Board::msger;
bool Board::rolled = false;
Stack* Board::chancesStack;
Bank* Board::gameBank;
Button* Board::nextButton;
Button* Board::bankEnter;
FieldSet* Board::setsInfo[SETS_COUNT];

void Board::buildGameField(std::fstream& fielddata, std::fstream& msgdata, std::fstream& chancesdata){
	std::string paths[4];
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

//	fieldColor = sf::ConvexShape;
	fieldColor.setPointCount(4);
	fieldColor.setPoint(0, sf::Vector2f(782, 101));
	fieldColor.setPoint(1, sf::Vector2f(1007, 101));
	fieldColor.setPoint(2, sf::Vector2f(987, 121));
	fieldColor.setPoint(3, sf::Vector2f(802, 121));
//	fieldColor.setPosition(FIELDCOLOR_X, FIELDCOLOR_Y);
	
	bgrTx.loadFromFile(PLAYER_BGR_PATH);
	bgr.setTexture(bgrTx);

	fieldContent.setFont(font);
	fieldContent.setCharacterSize(CONTENT_TEXT_SIZE);
	fieldContent.setPosition(CONTENT_X, CONTENT_Y);
	fieldContent.setColor(sf::Color::Black);
	//prepare the dices
	dicePic1.setPosition(DICE1_X, DICE1_Y);
	dicePic2.setPosition(DICE2_X, DICE2_Y);
	dice::loadTextures();
	Dices[0] = &dicePic1;
	Dices[1] = &dicePic2;
	dice::setDicesIdle(Dices, sizeof(Dices) / sizeof(Dices[0]));

	//build the gamefield list 
	int type;
	for (int i = 0; i < SETS_COUNT; i++)
	{
		setsInfo[i] = new FieldSet(i);
	}
	for (int i = 0; i < GAMEFIELD_SIZE; i++){
		fielddata >> type;
		if (type == FREE){
			fields += new Field(fielddata);
		}
		if (type == COMMERCIAL){
			fields += new CommercialField(fielddata);
		}
		if (type == CHANCE){
			fields += new ChanceField(fielddata);
		}
		if (type == PENEALTY){
			fields += new PenealtyField(fielddata);
		}
		if (type == START){
			fields += new StartField(fielddata);
		}
		if (type == POLICE){
			fields += new PoliceField(fielddata);
		}
	}
	

	paths[0] = PLAYER_1_PATH;
	paths[1] = PLAYER_2_PATH;
	paths[2] = PLAYER_3_PATH;
	paths[3] = PLAYER_4_PATH;


	chancesStack = new Stack(chancesdata);
	nextButton = new Button(NEXTP_PATH, NEXTP_XL, NEXTP_XR, NEXTP_YU, NEXTP_YD);
	msger = new Messenger(*mainWindow, msgdata);
	//initialize players
	Response response = msger->drawMsgBox((std::string)"Wybierz liczbe graczy", (std::string)"MENU", MENU);
	for (int i = 0; i < PLAYERS; i++){
		if (i < response)
			players[i] = new Player(i + 1, paths[i], fields);
		else
			players[i] = NULL;
	}
	/*players[0] = new Player(1, PLAYER_1_PATH,fields);
	players[1] = new Player(2, PLAYER_2_PATH,fields);
	players[2] = new Player(3, PLAYER_3_PATH,fields);
	players[3] = new Player(4, PLAYER_4_PATH,fields);*/
	msger->msgMode();
	user_bar = new userbar(response);
	user_bar->load_textures();
	current = players[0];
	current->setState(1);

	gameBank = new Bank();
	nextButton = new Button(NEXTP_PATH, NEXTP_XL, NEXTP_XR, NEXTP_YU, NEXTP_YD);
	bankEnter = new Button(BANK_ENTER_PATH, BANK_ENTER_XL, BANK_ENTER_XR, BANK_ENTER_YU, BANK_ENTER_YD);
}


bool Board::renderClickedField(short x, short y)
{
	CircularList<Field*>::CircularIterator it(fields);
	//field* temp = start;
	do{
		if ((*it)->belongs(x, y)){
			(*it)->renderMe(teamName, fieldName, fieldColor,fieldContent);
			return true;
		}
	} while (!it++);
	return false;
}
// disposes the memory allocated by the main Board class
void Board::dispose(){

//dispose players
	for (int i = 0; i < PLAYERS; i++){
		if (players[i] == NULL)
			break;
		delete (players[i]);
	}
	delete(user_bar);
	delete(msger);
	delete(chancesStack);
	delete(nextButton);
	delete(bankEnter);


}

void Board::drawGamefield(){
	mainWindow->draw(gamefield);
//	mainWindow->draw(fieldInfo);
	mainWindow->draw(fieldColor);
	mainWindow->draw(teamName);
	mainWindow->draw(fieldName);
	mainWindow->draw(fieldContent);
	mainWindow->draw(dicePic1);
	mainWindow->draw(dicePic2);
	nextButton->drawButton(*mainWindow);
	bankEnter->drawButton(*mainWindow);
	for (int i = 0; i < PLAYERS; i++){
		if (players[i] == NULL)
			break;
		mainWindow->draw(players[i]->getPlayerSprite());
		players[i]->drawMe(*mainWindow, font,bgr);
	}
	//if (players[0]!= NULL)
	//mainWindow->draw((players[0]->getPlayerSprite()));
		user_bar->drawUserbar(*mainWindow);
	mainWindow->display();
}

void Board::serveClick(int x, int y){
	int roll;
	if (rolled == false && DICE1_X<x && x<DICE2_X + DICE_SIZE && y>DICE1_Y && y < DICE1_Y + DICE_SIZE){
		roll = dice::rollMe(mainWindow, Dices, sizeof(Dices) / sizeof(Dices[0]));
		
		current->move(roll, true);
		current->getCurrentField()->renderMe(teamName, fieldName, fieldColor,fieldContent);
		
		rolled = true;
	}
	if (rolled == true && nextButton->belongs(x, y))
	{
		if (current->getState() == 1)
			current->setState(2);

		do			
			current = ((players[current->getNumber()] != NULL) && (current->getNumber() != PLAYERS)) ? players[current->getNumber()] : players[0];
		while (current->isPlaying() == false);
		current->setState(1);
		current->setCrossedStart(false);
		rolled = false;
	}
	if (bankEnter->belongs(x, y))
		gameBank->visitBank(*mainWindow, *current);
	renderClickedField(x, y);
}

void Board::drawBgr(){
	sf::Texture* bgrTx;
	sf::Sprite* bgr;
	bgrTx = new sf::Texture();
	bgr = new sf::Sprite();

	bgrTx->loadFromFile(MENU_BGR);
	bgr->setTexture(*bgrTx);
	Board::mainWindow->draw(*bgr);
	delete bgr;
	delete bgrTx;
}