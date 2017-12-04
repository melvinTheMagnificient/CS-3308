all: project

project: main.o Hello.o
	g++ main.o Hello.o -o project

main.o: main.cpp Hello.h
	g++ -std=c++0x -c main.cpp

Hello.o: Hello.cpp Hello.h
	g++ -std=c++0x -c Hello.cpp

clean:
	rm *.o project
