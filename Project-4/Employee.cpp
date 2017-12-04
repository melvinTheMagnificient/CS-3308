// Melissa Coblentz
// Project 4

#include "./Person.h"
#include "./Employee.h"

using namespace std;

Employee::Employee(string name):Person(name){
	setName(name);
}

void Employee::pay(int dollars, Restaurant* transactionWith){
	transactionWith->debit(dollars);
}