#include <SFML\Network.hpp>
#include <iostream>

class Client{
	sf::TcpSocket serverConnection;
	sf::Int8 players;
	sf::Int8 id;
	int current;
public:
	Client();
	bool init(std::string);
	bool messageLoop();
};