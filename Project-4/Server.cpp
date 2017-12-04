// Melissa Coblentz
// Project 4

#include "./Person.h"
#include "./Employee.h"
#include "./Server.h"

using namespace std;

Server::Server(string name):Employee(name) {
	setName(name);
	setRole("Server");
}

string Server::speak(){
	return "Give me tips!";
}