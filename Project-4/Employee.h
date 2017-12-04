// Melissa Coblentz
// Project 4

#pragma once

#include "./Restaurant.h"

#include <iostream>

using namespace std;

class Employee : public Person {
public:
	Employee(string name);

	void pay(int dollars, Restaurant* transactionWith);
};