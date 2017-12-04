//Melissa Coblentz
//Project 5

#include "./Student.h"

#include<string>

Student::Student(){
	_name = "";
	_gpa = 0;
}

Student::Student(string name, double gpa){
	_name = name;
	_gpa = gpa;
}

const string& Student::name() const{
	return _name;
}

const double& Student::gpa() const{
	return _gpa;
}