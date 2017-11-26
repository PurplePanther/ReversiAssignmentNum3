###########################################
#Student name: Tal Pogorelis
#Student ID: 318225349
#Exercise #: 2
###########################################

a.out: Cell.o main.o ReversiBoard.o Game.o Player.o OfflinePlayer.o Menu.o ComputerAi.o
	g++ main.o Cell.o ReversiBoard.o Game.o Player.o OfflinePlayer.o Menu.o ComputerAi.o

Cell.o: Cell.cpp Cell.h
	g++ -c Cell.cpp

main.o: main.cpp Game.h Menu.h
	g++ -c main.cpp

ReversiBoard.o: ReversiBoard.cpp Cell.h
	g++ -c ReversiBoard.cpp

Game.o: Game.cpp ReversiBoard.h Cell.h Player.h OfflinePlayer.h
	g++ -c Game.cpp

Player.o: Player.cpp Cell.h ReversiBoard.h
	g++ -c Player.cpp

OfflinePlayer.o: OfflinePlayer.cpp Player.h
	g++ -c OfflinePlayer.cpp	

Menu.o: Menu.cpp
	g++ -c Menu.cpp

ComputerAi.o: ComputerAi.cpp Player.h
	g++ -c ComputerAi.cpp

run: a.out
	./a.out
