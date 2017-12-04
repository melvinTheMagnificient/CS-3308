// Melissa Coblentz
// Project 4

#pragma once

#include "./Restaurant.h"

#include <iostream>

using namespace std;

class Server : public Employee {
public:
	Server(string name);

	virtual string speak();
};