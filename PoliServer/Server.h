#include <SFML/Network.hpp>
#include <iostream>
#define PORT 33333

class Server{
	sf::TcpSocket* playerSockets[4];
	int players;
public:
	bool connectionLoop();
	bool messegeLoop();
	~Server();
	Server(int);
};