#include <string>
#include <SFML/Graphics.hpp>

class Button
{
private:
	int lx;
	int rx;
	int uy;
	int dy;
	sf::Texture* pic;
public:
	Button(std::string path, int nlx, int nrx, int nuy, int ndy);
	bool belongs(int x, int y);
	void drawButton(sf::RenderWindow& window);
	~Button();
};