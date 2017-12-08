a.out: main.o Server.o Cell.o
	g++ main.o Server.o Cell.o

main.o: main.cpp Server.h
	g++ -c main.cpp

Server.o: Server.cpp
	g++ -c Server.cpp

Cell.o: Cell.cpp
	g++ -c Cell.cpp
