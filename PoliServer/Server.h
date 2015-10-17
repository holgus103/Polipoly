#include <SFML/Network.hpp>
#include <iostream>
#define PORT 33333
#define MAX_PLAYERS 4

class Server{
	sf::TcpSocket* playerSockets[MAX_PLAYERS];
	int players;
public:
	bool connectionLoop();
	bool messegeLoop();
	~Server();
	Server(int);
};