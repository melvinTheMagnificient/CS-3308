//Melissa Coblentz
//CS 3308
//Project 2
//Due Aug 31

#include "./Hello.h"

void printHello(std::ostream& out) {
  out << "Hello world!" << std::endl;
}

void printYo(std::ostream& out){
	out<<"Yo!" <<std::endl;
}

std::string getHelloString() {
  return "Hello world!";
}

std::string getCourageString(){
	return "Courage is the price that life exacts for granting peace.";
}

float miles2km(const float miles) {
  return miles * 1.609;
}

float km2miles(const float km){
	return km / 1.609;
}

int add(int a, int b) {
  return a+b;
}

std::string add(std::string a, std::string b){
	return a+b;
}
