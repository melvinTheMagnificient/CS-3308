// Melissa Coblentz
// Project 4

#pragma once

#include "./Restaurant.h"

#include <iostream>

using namespace std;

class Person {
public:
	Person(string name);
	Person(string name, string role);

	void setName(string name);

	string getName();

	void setRole(string role);

	string getRole();

	virtual string speak() = 0;

	virtual void pay(int dollars, Restaurant* transactionWith) = 0;

private:
	string _name;
	string _role;
};