// Melissa Coblentz
// Project 4

#include "./Person.h"

using namespace std;

Person::Person(string name){
	setName(name);
}

Person::Person(string name,string role){
	setName(name);
	setRole(role);
}

void Person::setName(string name){
	_name = name;
}

string Person::getName(){
	return _name;
}

void Person::setRole(string role){
	_role = role;
}

string Person::getRole(){
	return _role;
}