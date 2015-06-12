#pragma once
#define MY_FONT_PATH  "arial.ttf"
#define GAMEFIELD_PATH "Background_new.png"
#define APP_TITLE "Polipoly"
#define FIELDINFO_TEX_PATH "field.jpg"
#define FIELDDATA_PATH "fielddata.txt"
#define MSG_DATA_PATH "messages.txt"
#define CHANCE_DATA_PATH "chances.txt"
#define DICE_PIC_ONE "Dice_1.png"
#define DICE_PIC_TWO "Dice_2.png"
#define DICE_PIC_THREE "Dice_3.png"
#define DICE_PIC_FOUR "Dice_4.png"
#define DICE_PIC_FIVE "Dice_5.png"
#define DICE_PIC_SIX "Dice_6.png"
#define DICE_PIC_IDLE "Dice_0.png"
#define PLAYER_1_PATH "Pionek1.png"
#define PLAYER_2_PATH "Pionek2.png"
#define PLAYER_3_PATH "Pionek3.png"
#define PLAYER_4_PATH "Pionek4.png"
#define PLAYER_1B_PATH "Pionek1b.png"
#define PLAYER_2B_PATH "Pionek2b.png"
#define PLAYER_3B_PATH "Pionek3b.png"
#define PLAYER_4B_PATH "Pionek4b.png"
#define PLAYER_BGR_PATH "playerbgr.png"
#define USERBAR_LED1_PATH "LED1.png"
#define USERBAR_LED2_PATH "LED2.png"
#define USERBAR_LED3_PATH "LED3.png"
#define BTN_SKIP_PATH "SkipRoundButton.png"
#define MSG_BG_PATH "messenger.jpg"
#define MSG_BG_POSITION 205
#define PLAYERS_X 787
#define PLAYERS_Y 48
#define PLAYER_BGR_X 130
#define PLAYER_BGR_Y 60
#define FIELDINFO_X 768
#define FIELDINFO_Y 103
#define FIELDCOLOR_SIZEX 247
#define FIELDCOLOR_SIZEY 50
#define FIELDCOLOR_X 965
#define FIELDCOLOR_Y 103
#define CONTENT_X 780
#define CONTENT_Y 160
#define SCREEN_X 1024
#define SCREEN_Y 768
#define TEAMNAME_X 802
#define TEAMNAME_Y 103
#define FIELDNAME_X 774
#define FIELDNAME_Y 130
#define GAMEFIELD_SIZE 40
#define DICE1_X 775
#define DICE1_Y 560
#define DICE2_X 835 
#define DICE2_Y 560
#define FIELDNAME_TEXT_SIZE 13
#define TEAMNAME_TEXT_SIZE 12
#define CONTENT_TEXT_SIZE 10
#define PIN_WIDTH 26
#define PIN_HEIGHT 26
#define DICE_SIZE 60
#define PLAYERS 4
#define INITIAL_CASH 1500
#define MOVE_INTERVAL 500
#define CHANCES_COUNT 10

enum FieldType{
	FREE = 1,
	COMMERCIAL = 2,
	CHANCE = 3,
	PENEALTY = 4,
	START = 5,
};

enum ChanceType{
	TRAVEL = 1,
	TELEPORT = 2,
	WALLET = 3,
};