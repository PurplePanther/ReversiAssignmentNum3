
#ifndef ASS3_CLIENT_H
#define ASS3_CLIENT_H


#include "Cell.h"

class Client {

private:
    //the server
    const char *serverIP;
    int serverPort;
    int clientSocket;

public:
    //the constructor method.
    Client();

    //the function loads the server ip from a file.
    void readSettingsFromFile();

    //the function connects to the game server.
    void connectToServer();

    //the function reads an integer from the server.
    int readIntFromServer() const;

    //the destructor method.
    virtual ~Client();

    //the function reads a cell from the server.
    Cell readCellFromServer() const;

    //the function sends a cell to the game server.
    void writeCellToServer(const Cell CellX) const;
};


#endif //ASS3_CLIENT_H
