#include <string>
#include <SFML/Graphics.hpp>
#include "const.h"
#include <fstream>

class field{
private:
	int number;
	std::string team;
	std::string name;
	sf::Color color;
	void putSpaces(std::string& input);
public:
	void renderMe(sf::Text& fieldteam, sf::Text& fieldname, sf::RectangleShape& field);
	field(std::string newTeam, std::string newName, sf::Color newColor);
	field(std::fstream& fielddata);
};