#include "Server.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

/**
 * The function reads from the setting file the server's port.
 */
int readFromSettingsFile(){
	std::ifstream settingsFile;
	settingsFile.open("ServerSettings.txt");
	int port;
	string placeHolder;
    settingsFile >> placeHolder;
	settingsFile >> port;
	settingsFile.close();
	std::cout << port << std::endl;
	return port;
}

/**
 * the main function opens a server on the provided port
 * and transfers moves between the clients.
 */
int main() {

	int port = readFromSettingsFile();

	Server server(port);

		try{
			//starting the game server.
			server.startServer();
		}catch(const char *msg) {
			cout<<"Cannot start server. Reason: "<<msg<<endl;
			exit(-1);
		}

	do {
		try {
			server.acceptConnections();
			server.startGame();
			server.dropConnections();
		} catch (const char *msg) {
		}
	} while (true);

	server.stopServer();

}
