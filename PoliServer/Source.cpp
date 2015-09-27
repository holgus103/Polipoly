#include "Server.h"

int main(int argc,char** argv){
	auto players = 2;//= atoi(argv[1]) > 1 ? atoi(argv[1]) > 1 : 2;
	Server server(players);
	if (server.connectionLoop())
		std::cout << "sukces" << std::endl;
	while (server.messegeLoop()){}
	return 0;
}