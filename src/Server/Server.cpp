#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include "Cell.h"

using namespace std;

#define MAX_CONNECTED_CLIENTS 2
#define BOTH_PLAYERS_ARE_CONNECTED 10
#define GAME_HAS_ENDED -5


/**
 * the constructor method
 * @param port - the port we want the server to listen to.
 */
Server::Server(int port):port(port),serverSocket(0) {
	cout<<"Server"<<endl;
}

/**
 * The function starts the server, and looks for 2 connections to start.
 */
void Server::startServer() {
// Create a socket point
	this->serverSocket = socket(AF_INET, SOCK_STREAM,0);
	if(this->serverSocket==-1) {
	throw "Error opening socket";
	}


	// Assign a local address to the socket
	struct sockaddr_in serverAddress;
	bzero((void *)&serverAddress, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	bool connectedToServer = false;

	do {
		try {
			serverAddress.sin_port = htons(port);
			connectedToServer = true;
			if (bind(this->serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) ==-1){
			throw "Error on binding";
			}
		} catch (const char* msg) {
		}

	} while (!connectedToServer);


	// Start listening to incoming connections
	listen(this->serverSocket, MAX_CONNECTED_CLIENTS);

}


void Server::acceptConnections() {

	// Define the client socket's structures
	//first Player
	struct sockaddr_in clientAddress;
	socklen_t clientAddressLen = sizeof((struct sockaddr*) &clientAddress);

	// Define the client socket's structures
	//second Player
	struct sockaddr_in clientAddress2;
	socklen_t clientAddressLen2 = sizeof((struct sockaddr*) &clientAddress2);

	cout<<"Waiting for client connections..."<<endl;
	// Accept a new client connection
	this->playerOne = accept(this->serverSocket, (struct
			sockaddr*)&clientAddress, &clientAddressLen);

	//notifying the first player he is first.
	cout<<"Client connected"<<endl;
	int arg1 = 1;
	write(this->playerOne, &arg1, sizeof(arg1));
	cout<<"Clients # is: " << arg1 <<endl;


	// Accept a new client connection
	this->playerTwo = accept(serverSocket, (struct
				sockaddr*)&clientAddress2, &clientAddressLen2);

	//notifying the second player he is second.
	cout<<"Client 2 connected"<<endl;
	int arg2 = 2;
	write(this->playerTwo, &arg2, sizeof(arg2));
	cout<<"Clients # is: " << arg2 <<endl;


	//notifying the first play that the second player has connected.
	arg2 = BOTH_PLAYERS_ARE_CONNECTED;
	write(this->playerOne, &arg2, sizeof(arg2));
			cout<<"both clients are connected " <<endl;

	if(this->playerOne==-1 || this->playerTwo ==-1)
		throw "Error on accept";


}

/**
 * the server game loop.
 * the game loop transfers the plays between the clients.
 * @param PlayerOne - the connection with the first player.
 * @param PlayerTwo - the connection with the second player.
 */
void Server::startGame() {

	//the played cell that we are transferring between the clients.
	Cell lastPlayed;

	while(true){
			// Reading the first play
			int n = read(this->playerOne, &lastPlayed, sizeof(lastPlayed));
			if(n ==-1) {
				cout<<"Error reading lastPlayed"<<endl;
				return;
			}
			if(n ==0) {
				cout<<"Client disconnected"<<endl;
				return;
			}
			if(lastPlayed.getX() == GAME_HAS_ENDED){
				cout<<"game has ended"<<endl;
				return;
			}

			// sending the last cell played to the second player.
			write(this->playerTwo, &lastPlayed,sizeof(lastPlayed));
		    cout <<"first player played cell :"<<lastPlayed.getX() << ","
		    		<<lastPlayed.getY() << endl;



			// Reading the second play
			n = read(this->playerTwo, &lastPlayed, sizeof(lastPlayed));
			if(n ==-1) {
				cout<<"Error reading lastPlayed"<<endl;
				return;
			}
			if(n ==0) {
				cout<<"Client disconnected"<<endl;
				return;
			}
			if(lastPlayed.getX() == GAME_HAS_ENDED){
				cout<<"game has ended"<<endl;
				return;
			}

			// sending the last cell played cell to the first player.
			write(this->playerOne, &lastPlayed,sizeof(lastPlayed));

		    cout <<"second player played cell :" <<lastPlayed.getX() << ","
		    		<<lastPlayed.getY() << endl;

	}
}


/**
 * the function drops the connection with both current 2 clients\players.
 */
void Server::dropConnections(){
	close(this->playerOne);
	close(this->playerTwo);
}


/**
 * the function stops the server.
 */
void Server::stopServer() {
	close(serverSocket);
}

