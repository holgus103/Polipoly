#include "button.h"

bool Button::belongs(int x, int y)
	{
	if (lx < x && x < rx && uy < y && y < dy)
		return true;
	return false;
	}

void Button::drawButton(sf::RenderWindow& window)
{
	sf::Sprite* tempButton = new sf::Sprite();
	tempButton->setTexture(*pic);
	tempButton->setPosition(lx + 1, uy + 1);
	window.draw(*tempButton);
	delete(tempButton);
}

Button::Button(std::string path, int nlx, int nrx, int nuy, int ndy)
{
	lx = nlx;
	rx = nrx;
	uy = nuy;
	dy = ndy;
	pic = new sf::Texture;
	pic->loadFromFile(path);
}

void Button::chancePic(std::string path){
	delete pic;
	pic = new sf::Texture;
	pic->loadFromFile(path);
}

Button::~Button()
{
	delete (pic);
}