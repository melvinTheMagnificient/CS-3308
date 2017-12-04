// Melissa Coblentz
// Project 4

#include "./Restaurant.h"

using namespace std;

Restaurant::Restaurant(){}

void Restaurant::credit(int dollars){
	_cashOnHand += dollars;
}

void Restaurant::debit(int dollars){
	_cashOnHand -= dollars;
}

int Restaurant::getCashOnHand(){
	return _cashOnHand;
}