// Melissa Coblentz
// Project 4

#pragma once

#include "./Restaurant.h"

#include <iostream>

using namespace std;

class Manager : public Employee {
public:
	Manager(string name);

	virtual string speak();
};