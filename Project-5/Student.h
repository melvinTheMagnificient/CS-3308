//Melissa Coblentz
//Project 5

#pragma once

#include <string>

using namespace std;

class Student {
public:
	Student();
	Student(string name, double gpa);

	const string& name() const;
	const double& gpa() const;

private:
	string _name;
	double _gpa;
};