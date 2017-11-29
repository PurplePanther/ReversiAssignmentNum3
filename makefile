
a.out: core.o make
	g++ -std=c++0x @compile.txt

core.o:
	find src -name "*.cpp" > sources.txt
	g++ -std=c++0x -c @sources.txt

make:
	find -name "*.o" > compile.txt
	sed -i '/cmake-build-debug/d' ./compile.txt

clean:
	rm -f *.o
	rm -f sources.txt
	rm -f compile.txt
