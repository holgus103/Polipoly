#include <string>
#include <SFML/Graphics.hpp>
#include "const.h"

class field{
private:
	int number;
	std::string team;
	std::string name;
	sf::Color color;
public:
	void renderMe(sf::Text& fieldteam, sf::Text& fieldname, sf::RectangleShape& field);
	field(std::string newTeam, std::string newName, sf::Color newColor);
};