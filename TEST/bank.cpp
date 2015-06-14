#include "board.h"
#include "bank.h"
#include "const.h"

Bank::Bank()
{
	exitBank = new Button(BANK_EXIT_PATH, BANK_ENTER_XL, BANK_ENTER_XR, BANK_ENTER_YU, BANK_ENTER_YD);
	plus = new Button(BANK_PLUS_PATH, BANK_PLUS_XL, BANK_PLUS_XR, BANK_PLUS_YU, BANK_PLUS_YD);
	minus = new Button(BANK_MINUS_PATH, BANK_MINUS_XL, BANK_MINUS_XR, BANK_MINUS_YU, BANK_MINUS_YD);
	buy = new Button(BANK_BUY_PATH, BANK_BUY_XL, BANK_BUY_XR, BANK_BUY_YU, BANK_BUY_YD);
	sell = new Button(BANK_SELL_PATH, BANK_SELL_XL, BANK_SELL_XR, BANK_SELL_YU, BANK_SELL_YD);
	counter = new sf::Texture;
	counter->loadFromFile(BANK_COUNTER_PATH);
	font = new sf::Font;
	font->loadFromFile(MY_FONT_PATH);
}

Bank::~Bank()
{
	delete(exitBank);
	delete(plus);
	delete(minus);
	delete(counter);
	delete(sell);
	delete(buy);

}

bool Bank::visitBank(sf::RenderWindow& window, Player& client)
{
	howMuch = 0;
	window.clear();
	sf::Sprite* temp = new sf::Sprite;
	sf::Text* temp2 = new sf::Text;
	temp->setTexture(*counter);
	temp->setPosition(BANK_COUNTER_X, BANK_COUNTER_Y);
	temp2->setCharacterSize(BANK_TEXT_SIZE);
	temp2->setColor(sf::Color::Black);
	temp2->setFont(*font);
	temp2->setPosition(BANK_COUNTER_CONTENT_X, BANK_COUNTER_CONTENT_Y);


	sf::Event event;
	sf::Vector2u screen_size;
	//bool open = true;
	Board::drawGamefield();
		window.draw(*temp);
		temp2->setString(std::to_string(howMuch) + " ECTS");
		window.draw(*temp2);
		exitBank->drawButton(window);
		plus->drawButton(window);
		minus->drawButton(window);
		buy->drawButton(window);
		sell->drawButton(window);
		window.display();
	while (true){
		window.pollEvent(event);
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			screen_size = window.getSize();//20+205,100+205, 297+205,205+337
			int temp_x = event.mouseButton.x * SCREEN_X / screen_size.x, temp_y = event.mouseButton.y * SCREEN_Y / screen_size.y;
			if (exitBank->belongs(temp_x, temp_y))
			{
				delete(temp);
				delete(temp2);
				return 0;
			}
			if (plus->belongs(temp_x, temp_y))
			{
				howMuch++;
				window.draw(*temp);
				temp2->setString(std::to_string(howMuch) + " ECTS");
				window.draw(*temp2);
				window.display();
			}

			if (minus->belongs(temp_x, temp_y))
				if (howMuch > 1)
				{
					howMuch--;
					window.draw(*temp);
					temp2->setString(std::to_string(howMuch) + " ECTS");
					window.draw(*temp2);
					window.display();
				}

		}
	}

	
	delete(temp);
	delete(temp2);
	return 0;
}