#include <SFML\Network.hpp>

class Networking{
	sf::TcpSocket outSocket;
	sf::TcpListener inSocket;
	sf::Packet output;
	sf::Packet input;
public:
	Networking();
	bool init(std::string);
};