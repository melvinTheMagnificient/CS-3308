// Melissa Coblentz
// Project 4

#pragma once

#include "./Person.h"
#include "./Restaurant.h"

using namespace std;

class Customer: public Person{
	public:
		Customer(string name);

		virtual string speak();

		virtual void pay(int dollars, Restaurant* transactionWith);
};