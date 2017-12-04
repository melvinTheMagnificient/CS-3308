// Melissa Coblentz
// Project 4

#pragma once

using namespace std;

class Restaurant {
	public:
		Restaurant();
		void credit(int dollars);
		void debit(int dollars);
		int getCashOnHand();

	private:
		int _cashOnHand;
};