// Melissa Coblentz
// Project 4

#pragma once

#include "./Restaurant.h"

#include <iostream>

using namespace std;

class Cook : public Employee {
public:
	Cook(string name);

	virtual string speak();
};