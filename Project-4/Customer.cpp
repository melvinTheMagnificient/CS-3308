// Melissa Coblentz
// Project 4

#include "./Person.h"
#include "./Customer.h"

using namespace std;

Customer::Customer(string name) : Person(name){
	Person::setRole("Customer");
}

string Customer::speak() {
	return "I eat burgers!";
}

void Customer::pay(int dollars, Restaurant* transactionWith){
	transactionWith->credit(dollars);
}