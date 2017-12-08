class Server {

public:
	Server(int port);
	void startServer();
	void acceptConnections();
	void startGame();
	void dropConnections();
	void stopServer();

private:
	int port;
	int serverSocket; // the socket's file descriptor
	int playerOne;
	int playerTwo;

};
