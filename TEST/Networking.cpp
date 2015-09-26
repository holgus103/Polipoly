#include "Networking.h"
#include "const.h"

//Networking::Networking(){
//
//}
bool Networking::init(std::string ip){
	return (this->inSocket.listen(PORT) == sf::Socket::Status::Done && this->outSocket.connect(ip, PORT)== sf::Socket::Status::Done);
};
