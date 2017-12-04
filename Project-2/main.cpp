//------------------------------------------------------------
//
// CS 3385
// Project project2
//
// This project will familiarize you with C++ and the make
// utility. You will make changes to Hello.h and Hello.cpp.
// You will uncomment lines in this file in the runTests()
// function until all tests are run. You know you're
// finished when you run the program and see
//      8/8 tests succeeded
// at the end of the output.
//
// You will submit two files only (listed below) on Moodle.
// You will NOT submit main.cpp or Makefile.
//
// Files to submit:
//   * Hello.h
//   * Hello.cpp
// 
//------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <sstream>

#include "./util.h"
#include "./Hello.h"

using namespace std;

//------------------------------------------------------------
// Tests
//------------------------------------------------------------
int runTests() {

  int numFails = 0;
  int testNum = 0;

  {
    cout << "The following code should print \"Hello world!\" to the screen."
         << endl;
    printHello(cout);

    stringstream sout1;
    printHello(sout1);
    TEST(sout1.str() == "Hello world!\n");

    // You will need to add both a function declaration in
    // Hello.h and the function definition in Hello.cpp.
    stringstream sout2;
    printYo(sout2);
    TEST(sout2.str() == "Yo!\n");

    string str1 = getHelloString();
    TEST(str1 == "Hello world!");

    string str2 = getCourageString();
    TEST(str2 == "Courage is the price that life exacts for granting peace.");

    float km = miles2km(3.11);
    cout << "miles2km() returned " << km << endl;
    TEST(km < 5.1 && km > 4.9);

    float miles = km2miles(5);
    TEST(miles < 3.2 && miles > 3);

    int test1 = add(3, 4);
    TEST(test1 == 7);

    // To add two strings just use the plus operator:
    //   string a("a");
    //   string b("b");
    //   string c = a+b;
    //
    // This add function is an overload.
    string test2 = add("3", "4");
    TEST(test2 == "34");
  }

  const int numSuccesses = testNum - numFails;
  cout << numSuccesses << "/" << testNum << " tests succeeded" << endl;

  return numFails;
}

int main(int argc, char** argv) {
  return runTests();
}

