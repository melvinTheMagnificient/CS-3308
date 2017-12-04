// Melissa Coblentz
// Project 4

#include "./Person.h"
#include "./Employee.h"
#include "./Manager.h"

using namespace std;

Manager::Manager(string name):Employee(name){
	setName(name);
	setRole("Manager");
}

string Manager::speak(){
	return "I run the restaurant!";
}