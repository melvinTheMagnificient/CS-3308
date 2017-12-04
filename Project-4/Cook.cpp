// Melissa Coblentz
// Project 4

#include "./Person.h"
#include "./Employee.h"
#include "./Cook.h"

using namespace std;

Cook::Cook(string name):Employee(name) {
	setName(name);
	setRole("Cook");
}

string Cook::speak(){
	return "I cook burgers!";
}