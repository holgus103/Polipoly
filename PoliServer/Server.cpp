#include "Server.h"

bool Server::connectionLoop(){
	sf::TcpListener listener, helper;
	sf::TcpSocket socket;
	int currentPort;
	if (listener.listen(PORT) != sf::Socket::Done)
		return false;
	std::cout << "listener setup on: " << PORT << std::endl;
	for (int i = 0; i < this->players; i++){
		// set up base listener for redirection
		if (listener.accept(socket) != sf::Socket::Done){
			std::cout << "new client could not connect: " << i + 1 << std::endl;
			return false;
		}
		std::cout << "client connected: " << socket.getRemoteAddress() << std::endl;
		// set up port base port number
		currentPort = PORT + 1 + i;
		// find closest free port and set up a new listener for a player
		while (helper.listen(currentPort) != sf::Socket::Done){
			currentPort++;
			std::cout << "trying setup on: " << currentPort<< std::endl;
		}
		std::cout << "helper setup on: " << currentPort << std::endl;
		// send port number to client
		if (socket.send(&currentPort, sizeof(sf::Int32)) != sf::Socket::Done){
			std::cout << "failed to send to: " << socket.getRemoteAddress() << std::endl;
			return false;
		}
		std::cout << "sent " << currentPort << " to " << socket.getRemoteAddress()<< std::endl;
		this->playerSockets[i] = new sf::TcpSocket();
		if (helper.accept(*(this->playerSockets[i])) != sf::Socket::Done){
			std::cout << "failed to accept on " << currentPort << std::endl;
			return false;
		}
		std::cout << "client redirected: " << (*this->playerSockets[i]).getRemoteAddress() << currentPort<< std::endl;
		helper.close();
		if ((*this->playerSockets[i]).send(&this->players, sizeof(sf::Int8)) != sf::Socket::Done || 
			(*this->playerSockets[i]).send(&i, sizeof(sf::Int8)) != sf::Socket::Done){
			std::cout << "player data could not be send to" << socket.getRemoteAddress() << std::endl;
			return false;
		}
		std::cout << "player data send to " << socket.getRemoteAddress() << std::endl;
	}
	return true;

}
Server::~Server(){

}
Server::Server(int players){
	this->players = players;
	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		this->playerSockets[i] = NULL;
	}
}

bool Server::messegeLoop(){
	auto i = 0;
	bool result = true;
	sf::Packet packet;
	while (true){
		std::cout << "waiting for player " << i << std::endl;
		if ((*this->playerSockets[i]).receive(packet) != sf::Socket::Done){
			return false;
		}
		else{
			for (auto j = 0; j < this->players; j++){
				if (i == j)
					continue;
				else{
					if ((*this->playerSockets[j]).send(packet) != sf::Socket::Done){
						return false;
					}
				}
			}
		}
		packet.clear();
		i < this->players-1 ? i++ : i = 0;
	}
}