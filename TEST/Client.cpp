#include "Client.h"
#include "const.h"

bool Client::init(std::string ip){
	sf::Int32 port = 0;
	std::size_t size;
	if (this->serverConnection.connect(ip, PORT) != sf::Socket::Done){
		std::cout << "connection failed to " << ip << " on " << PORT << std::endl;
		return false;
	}
	std::cout << "connected to " << ip << " on " << PORT << std::endl;
	if (this->serverConnection.receive(&port, sizeof(int), size) != sf::Socket::Done){
		std::cout << "failed to receive redirection port" << std::endl;
		return false;
	}
	std::cout << "redirection port received: " << port <<std::endl;
	this->serverConnection.disconnect();
	if (this->serverConnection.connect(ip, port) != sf::Socket::Done){
		std::cout << "redirection failed to " << ip << " on " << port << std::endl;
		return false;
	}
	std::cout << "redirected " << this->serverConnection.getRemoteAddress() << " on " << this->serverConnection.getRemotePort() << std::endl;
	if (this->serverConnection.receive(&(this->players), sizeof(sf::Int8), size) != sf::Socket::Done || this->serverConnection.receive(&(this->id), sizeof(sf::Int8), size)){
		std::cout << "Could not receive players from server" << std::endl;
		return false;
	}
	return true;
}
bool Client::messageLoop(){
	sf::Packet packet;
	std::string var;
	auto j = 0;
	while (true){
		if (this->id == j){
			std::cin >> var;
			packet << var;
			this->serverConnection.send(packet);
		}
		for (auto i = 0; i < this->players-1; i++){
			packet.clear();
			this->serverConnection.receive(packet);
			packet >> var;
			std::cout << var << std::endl;
		}
		j <= this->players ? j++ : j = 0;
	}
}