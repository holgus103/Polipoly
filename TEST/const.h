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
#define USERBAR_LED0_PATH "LED0.png"
#define USERBAR_LED1_PATH "LED1.png"
#define USERBAR_LED2_PATH "LED2.png"
#define USERBAR_LED3_PATH "LED3.png"
#define BTN_SKIP_PATH "SkipRoundButton.png"
#define MSG_BG_PATH "messenger.jpg"
#define MENU_BGR "MenuBg.jpg"
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
#define FIELDNAME_X 780
#define FIELDNAME_Y 130
#define GAMEFIELD_SIZE 40
// dice coordinates
#define DICE1_X 775
#define DICE1_Y 560
#define DICE2_X 835 
#define DICE2_Y 560

#define FIELDNAME_TEXT_SIZE 13
#define TEAMNAME_TEXT_SIZE 12
#define CONTENT_TEXT_SIZE 10
#define BANK_TEXT_SIZE 24
#define PIN_WIDTH 26
#define PIN_HEIGHT 26
#define DICE_SIZE 60
#define PLAYERS 4
#define INITIAL_CASH 1500
#define MOVE_INTERVAL 100
#define CHANCES_COUNT 10


//msgbox button coordinates
//ok button //20+205,100+205, 297+205,205+337
#define OK_XL 225
#define OK_XR 305
#define OK_YU 502
#define OK_YD 542
//cancel button // 205+257,337+205,205+297,205+337
#define CANCEL_XL 462
#define CANCEL_XR 542
#define CANCEL_YU 502
#define CANCEL_YD 542


#define NEXTP_PATH "SkipRoundButton.png"
#define NEXTP_XL 900
#define NEXTP_XR 1013
#define NEXTP_YU 559
#define NEXTP_YD 620
//button img paths
#define MSG_YES_PATH "YesButton.png"
#define MSG_NO_PATH "NoButton.png"
#define MSG_OK_PATH "OKButton.png"
#define MSG_2P_PATH "2PButton.png"
#define MSG_3P_PATH "3PButton.png"
#define MSG_4P_PATH "4PButton.png"

#define MSG_BUTTON_YU 502
#define MSG_BUTTON_YD 542

#define MSG_YES_XL 225
#define MSG_YES_XR 305

#define MSG_NO_XL 462
#define MSG_NO_XR 542

#define MSG_OK_XL 344
#define MSG_OK_XR 424

#define MSG_TITLE_X 253
#define MSG_TITLE_Y 270

#define MSG_TEXT_X 212
#define MSG_TEXT_Y 305

#define BANK_ENTER_PATH "Bank.png"
#define BANK_EXIT_PATH "BankExit.png"
#define BANK_ENTER_XL 774
#define BANK_ENTER_XR 835
#define BANK_ENTER_YU 427
#define BANK_ENTER_YD 478

#define BANK_MINUS_PATH "Minus.png"
#define BANK_MINUS_XL 774
#define BANK_MINUS_XR 835
#define BANK_MINUS_YU 493
#define BANK_MINUS_YD 544

#define BANK_PLUS_PATH "Plus.png"
#define BANK_PLUS_XL 834
#define BANK_PLUS_XR 895
#define BANK_PLUS_YU 493
#define BANK_PLUS_YD 544

#define BANK_SELL_PATH "Sell.png"
#define BANK_SELL_XL 840
#define BANK_SELL_XR 901
#define BANK_SELL_YU 427
#define BANK_SELL_YD 478

#define BANK_BUY_PATH "Buy.png"
#define BANK_BUY_XL 933
#define BANK_BUY_XR 986
#define BANK_BUY_YU 427
#define BANK_BUY_YD 478

#define BANK_COUNTER_PATH "Counter.png"
#define BANK_COUNTER_X 901
#define BANK_COUNTER_Y 494

#define BANK_COUNTER_CONTENT_X 912
#define BANK_COUNTER_CONTENT_Y 507

#define ECTS_BUY_PRICE2 50
#define ECTS_BUY_PRICE 65
#define ECTS_SELL_PRICE 35

#define SETS_COUNT 8

#define UPG_PATH "Upgrade.png"
#define UPG_XL 900
#define UPG_XR 1013
#define UPG_YU 261
#define UPG_YD 322

#define RSGN_PATH "GiveUp.png"
#define RSGN_XL 774
#define RSGN_XR 895
#define RSGN_YU 261
#define RSGN_YD 322

#define PORT 33333

enum FieldType{
	FREE = 1,
	COMMERCIAL = 2,
	CHANCE = 3,
	PENEALTY = 4,
	START = 5,
	POLICE = 6,
	ROLLING = 7,
	LANGUAGE = 8,
};

enum ChanceType{
	TRAVEL = 1,
	TELEPORT = 2,
	WALLET = 3,
	JAIL = 4,
	BET = 5,
	BUFF = 6,
};

enum MsgType{
	OK = 1,
	OKCANCEL = 2,
	MENU = 3,
};

enum Response{
	_YES = 2,
	_NO = 4,
	_OK = 3,
};

enum exValue{
	ECTS = 1,
	DOLLARS = 2,
};