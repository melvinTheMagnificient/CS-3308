#Melissa Coblentz

all: restaurant

restaurant: main.o Person.o Customer.o Restaurant.o Employee.o Manager.o Cook.o Server.o interaction.o
	g++ main.o Person.o Customer.o Restaurant.o Employee.o Manager.o Cook.o Server.o interaction.o -o restaurant

# Any files included in main.cpp need to be included in the dependency
# list on the following line. If you don't do this for this and other
# targets, then if you change an include file, the .cpp file that includes
# it may not get recompiled.
main.o: main.cpp Person.h Customer.h Restaurant.h Employee.h Manager.h Cook.h Server.h interaction.h
	g++ -std=c++0x -c main.cpp

Person.o: Person.cpp Person.h
	g++ -std=c++0x -c Person.cpp

Customer.o: Customer.cpp Customer.h
	g++ -std=c++0x -c Customer.cpp

Restaurant.o: Restaurant.cpp Restaurant.h
	g++ -std=c++0x -c Restaurant.cpp

Employee.o: Employee.cpp Employee.h
	g++ -std=c++0x -c Employee.cpp

Manager.o: Manager.cpp Manager.h
	g++ -std=c++0x -c Manager.cpp

Cook.o: Cook.cpp Cook.h
	g++ -std=c++0x -c Cook.cpp

Server.o: Server.cpp Server.h
	g++ -std=c++0x -c Server.cpp

interaction.o: interaction.cpp interaction.h
	g++ -std=c++0x -c interaction.cpp

clean:
	rm *.o restaurant
