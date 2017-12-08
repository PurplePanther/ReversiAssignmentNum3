
#include "Client.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <fstream>

/**
 * the constructor method.
 */
Client::Client() {
    //loading the server ip from the settings file.
    readSettingsFromFile();

}

/**
 * the function connects to the game server.
 */
void Client::connectToServer(){


    // Create a socket point
    this->clientSocket = socket(AF_INET, SOCK_STREAM,0);
    if(clientSocket==-1) {
        throw "Error opening socket";
    }

    // Convert the ip string to a network address
    struct in_addr address;
    if(!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }

    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof(address),  AF_INET);
    if(server == NULL) {
        throw"Host is unreachable";
    }

    // Create a structure for the server address
    struct sockaddr_in serverAddress;

    bzero((char*)&address, sizeof(address));

    serverAddress.sin_family= AF_INET;
    memcpy((char*)&serverAddress.sin_addr.s_addr,
           (char*)server->h_addr, server->h_length);


    //htons converts values between host and network byte orders
    bool connected = false;
    do {
        try {
            serverAddress.sin_port = htons(this->serverPort);
            connected = true;
        }catch (const char* msg){
        }
    } while (!connected);

    // Establish a connection with the TCP server
    if(connect(clientSocket, (struct sockaddr*)&serverAddress,
               sizeof(serverAddress)) ==-1) {
        throw "Error connecting to server";
    }

    //connected to server
    std::cout<<"Connected to server"<<std::endl;

}


/**
 * the function reads an integer from the game server and returns it.
 * @return - an integer.
 */
int Client::readIntFromServer() const{
    int result;
    int n = read(clientSocket, &result,sizeof(result));
    return result;
}

/**
 * the function reads a cell from the game server and returns it.
 * @return - a Cell.
 */
Cell Client::readCellFromServer() const{

    Cell enemyPlay;
    int n = read(this->clientSocket, &enemyPlay,sizeof(enemyPlay));
    return enemyPlay;
}

/**
 * the function writes an integer to the game server.
 * @param num - the integer we are willing to send to the server.
 */
void Client::writeIntToServer(const int num) const{

    int n = write(this->clientSocket, &num,sizeof(num));

}

/**
 * the function writes a cell to the game server.
 * @param Cellx - the cell we are willing to send to the server.
 */
void Client::writeCellToServer(const Cell Cellx) const{

   int n = write(this->clientSocket, &Cellx,sizeof(Cellx));

}

/**
 * The function loads the server IP from a file.
 */
void Client::readSettingsFromFile() {
    std::ifstream settingsFile;
    settingsFile.open("settings.txt");
    std::string placeHolder;
    if (settingsFile.is_open()) {
        char* serverIP;
        std::string StringIp;

        settingsFile >> placeHolder;
        settingsFile >> StringIp;

        char *tempServerIP = new char[StringIp.length() + 1];
        strcpy(tempServerIP, StringIp.c_str());
        this->serverIP = tempServerIP;

        settingsFile >> placeHolder;
        settingsFile >> this->serverPort;

        settingsFile >> placeHolder;
        settingsFile >> clientSocket;

        settingsFile.close();

    }

}

/**
 * The destructor method.
 */
Client::~Client() {
    delete[] this->serverIP;

}
