a.out: Cell.o main.o ReversiBoard.o Game.o Player.o OfflinePlayer.o Menu.o ComputerAi.o RemotePlayer.o Client.o
	g++ main.o Cell.o ReversiBoard.o Game.o Player.o OfflinePlayer.o Menu.o ComputerAi.o RemotePlayer.o Client.o

Cell.o: Cell.cpp Cell.h
	g++ -c Cell.cpp

main.o: main.cpp Game.h Menu.h
	g++ -c main.cpp

ReversiBoard.o: ReversiBoard.cpp Cell.h
	g++ -c ReversiBoard.cpp

Game.o: Game.cpp ReversiBoard.h Player.h Player.h Client.h
	g++ -c Game.cpp

Player.o: Player.cpp ReversiBoard.h
	g++ -c Player.cpp

OfflinePlayer.o: OfflinePlayer.cpp Player.h
	g++ -c OfflinePlayer.cpp	

Menu.o: Menu.cpp
	g++ -c Menu.cpp

ComputerAi.o: ComputerAi.cpp Player.h
	g++ -c ComputerAi.cpp

RemotePlayer.o: RemotePlayer.cpp Player.h Client.h
	g++ -c RemotePlayer.cpp

Client.o: Client.cpp Cell.h
	g++ -c Client.cpp

run: a.out
	./a.out
