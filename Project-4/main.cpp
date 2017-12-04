//------------------------------------------------------------
//
// CS 3308
// Project 4 - Restaurant II
//
// This project will reinforce pointers and polymorphism in 
// C++. The only changes you should make in main.cpp is
// uncommenting tests in runTests().
//
// You will implement a program for a restaurant.
// In project 3 you already implemented customers.
// In this project you will add employees, which
// include managers, cooks and servers. Employee should
// derive from Person, and Manager, Cook and Server
// should derive from Employee.
//
// You will start with the code you wrote in project 3, except
// for main.cpp, which is included here.
//
// This project is done in two parts. The first is to
// implement code to run all tests in runTests(). The second
// part is to make an interactive interface for the restaurant.
// If you run ./restaurant -i you will enter interactive
// mode. Implement the runInteraction() function in interaction.cpp.
// When you run your program with -i, your program must behave
// as shown in interaction.txt. You will initialize
// your restaurant to have four people (see the first part of
// interaction.txt) and be able to add people etc as shown
// interaction.txt. This will be largely graded with a script,
// so, even though your output formatting needn't match exactly,
// make sure that all of your command keys are identical to
// those shown.
//
// Test interactive mode interactively (duh), and then you can test
// with canned inputs to make sure your command names match up. You
// can do this by:
//
//    cat input.txt | ./restaurant -i
//
// Hint: use an stl vector to store your people in interactive mode.
//
// You will zip and submit all of your files. Your main.cpp
// file will NOT be used in grading -- a fresh copy will be
// used.
//
//------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <sstream>

#include "./util.h"
#include "./Person.h"
#include "./Employee.h"
#include "./Manager.h"
#include "./Cook.h"
#include "./Server.h"
#include "./Customer.h"
#include "./interaction.h"

using namespace std;

//------------------------------------------------------------
// Tests
//------------------------------------------------------------
int runTests() {

  int numFails = 0;
  int testNum = 0;

  {
    // Create an Employee class. You'll need to add two files, Employee.h and
    // Employee.cpp and add entries to the Makefile as needed. Employee
    // should inherit from Person.

    // Create a Manager class that inherits from Employee.
    Employee* carla = new Manager("Carla");
    TEST(carla->getName() == "Carla");
    TEST(carla->speak() == "I run the restaurant!");
    TEST(carla->getRole() == "Manager");

    Employee* joe = new Cook("Joe");
    TEST(joe->getName() == "Joe");
    TEST(joe->speak() == "I cook burgers!");
    TEST(joe->getRole() == "Cook");

    Employee* louetta = new Server("Louetta");
    TEST(louetta->getName() == "Louetta");
    TEST(louetta->speak() == "Give me tips!");
    TEST(louetta->getRole() == "Server");

    Restaurant* restaurant = new Restaurant();
    restaurant->credit(500);
    TEST(restaurant->getCashOnHand() == 500);
    // pay() should be implemented in the Employee class, since
    // all employees are paid from the restaurant, as opposed to
    // customers, who pay the restaurant.
    carla->pay(45, restaurant);
    TEST(restaurant->getCashOnHand() == 455);
    joe->pay(5, restaurant);
    TEST(restaurant->getCashOnHand() == 450);
    louetta->pay(8, restaurant);
    TEST(restaurant->getCashOnHand() == 442);

    vector<Person*> people;
    people.push_back(carla);
    people.push_back(joe);
    people.push_back(louetta);

    for (int i = 0; i < people.size(); ++i) {
      int before = restaurant->getCashOnHand();
      people[i]->pay(5, restaurant);
      TEST(restaurant->getCashOnHand() == before - 5);
    }
  }

  const int numSuccesses = testNum - numFails;
  cout << numSuccesses << "/" << testNum << " tests succeeded" << endl;

  return numFails;
}

int main(int argc, char** argv) {
  if (argc < 2 || string(argv[1]) != "-i") {
    return runTests();
  } else {
    runInteraction();
  }
  return 0;
}
