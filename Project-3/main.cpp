// Melissa Coblentz
// Project 3
//------------------------------------------------------------
//
// CS 3308
// Project 3 - Restaurant I
//
// This project will reinforce pointers and polymorphism in 
// C++. The only changes you should make in main.cpp is
// uncommenting tests in runTests().
//
// You will implement a program for a restaurant.
// There are multiple roles we will model: employees, which
// include managers, cooks and servers; and
// customers. In this project we will only implement customers.
// In the following project we will implement the others.
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
#include "./Customer.h"
#include "./Restaurant.h"

using namespace std;

//------------------------------------------------------------
// Tests
//------------------------------------------------------------
int runTests() {

  int numFails = 0;
  int testNum = 0;

  {
    // Create a Person class. You'll make your changes to Person.h
    // and Person.cpp. The Makefile already has Person in it.

    // Create a Customer class. You'll need to add two files, Customer.h and
    // Customer.cpp and add entries to the Makefile as needed. Customer
    // should inherit from Person.

    // Create a constructor for Person that takes a string with the
    // person's name. You should also add a private data member in Person
    // for the name.

    // Create a constructor for Customer that takes a string with the
    // customer's name. Do not add a data member for the name to Customer.
    // Instead, in the constructor, you'll do this:
    //        Customer::Customer(std::string name) : Person(name) {
    //        }
    // This code will call the Person constructor with the name.

    // Add includes for both Person.h and Customer.h in this file.
    Person* mike = new Customer("Mike");

    // Add a getter as necessary.
    TEST(mike->getName() == "Mike");

    // Add an abstract virtual function to Person called speak() that
    // returns a string. A virtual function is preceded by the keyword
    // virtual and to make it abstract we add "=0" after the closing
    // parenthesis.

    // Override the speak() virtual function in your Customer class.
    TEST(mike->speak() == "I eat burgers!");

    // Add a string data member to Person called _role. Include role
    // in the constructor. Modify your Customer constructor to pass
    // "Customer" as the role to its parent Person constructor.
    // Add a getter in the Person class as necessary.
    TEST(mike->getRole() == "Customer");

    // All of the following tests should pass without any code
    // modification.
    Customer* sally = new Customer("Sally");
    TEST(sally->getName() == "Sally");
    TEST(sally->speak() == "I eat burgers!");
    TEST(sally->getRole() == "Customer");
    Person* sallyp = sally;
    TEST(sallyp->getName() == "Sally");
    TEST(sallyp->speak() == "I eat burgers!");
    TEST(sallyp->getRole() == "Customer");

    // Add a class called Restaurant. You'll need to add the necessary
    // files and modify the Makefile.
    Restaurant* restaurant = new Restaurant();
    
    // // Add functions as necessary
    restaurant->credit(500);
    TEST(restaurant->getCashOnHand() == 500);
    restaurant->debit(13);
    TEST(restaurant->getCashOnHand() == 487);

    // Add functions as necessary. The function should be virtual and
    // overridden in the Customer class.
    mike->pay(45, restaurant);
    TEST(restaurant->getCashOnHand() == 532);
    sally->pay(5, restaurant);
    TEST(restaurant->getCashOnHand() == 537);
    sallyp->pay(8, restaurant);
    TEST(restaurant->getCashOnHand() == 545);
  }

  const int numSuccesses = testNum - numFails;
  cout << numSuccesses << "/" << testNum << " tests succeeded" << endl;

  return numFails;
}

int main(int argc, char** argv) {
  if (argc < 2 || string(argv[1]) != "-i") {
    return runTests();
  } else {
    // runInteraction();
  }
  return 0;
}
