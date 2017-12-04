//Melissa Coblentz
//Project 5

//------------------------------------------------------------
//
// CS 3308
// Project 5 - Dynamic array
//
// This project introduces you to cmake, a utility that is
// simpler to use than just plain make. You will also
// implement a templatized dynamic array class.
//
// The first thing to notice is that there is no Makefile.
// It has been replaced with CMakeLists.txt. You will modify
// this file as you add files.
//
// To build:
//   > [navigate to project directory]
//   > mkdir build
//   > cd build
//   > cmake ..
//   > make
//   > ./dynarray
//
// You only need to call the cmake utility the first time
// and when you have modified CMakeLists.txt. Any other time
// you simply call make.
//
// Notice also that all of your intermediate (*.o) and binary
// files are nicely contained in the build directory. Your
// project directory has only source files.
//
// Implement the code as instructed in the comments in
// runTests().
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
#include "./DynArray.h"
#include "./Student.h"
#include "./Button.h"
#include "./RadioButton.h"

using namespace std;

//------------------------------------------------------------
// Tests
//------------------------------------------------------------
int runTests() {

  int numFails = 0;
  int testNum = 0;

  {
    // Add a file called DynArray.h and create a templatized container
    // class called DynArray. You do not need to add DynArray.h to
    // CMakeLists.txt. As is usual, all functions for the templatized
    // class will go in the header file DynArray.h.
    DynArray<int> arr;

    // Add three data members to DynArray: size, capacity and the array
    // itself, which will be of type pointer to T. Initialize these
    // values in the constructor.
    TEST(arr.size() == 0);
    TEST(arr.capacity() == 4);

    // // Add member functions as necessary. You don't yet need to make the array
    // // dynamic.
    arr.add(12);
    TEST(arr.get(0) == 12);
    TEST(arr.size() == 1);
    TEST(arr.capacity() == 4);

    arr.add(157);
    TEST(arr.get(0) == 12);
    TEST(arr.get(1) == 157);
    TEST(arr.size() == 2);
    TEST(arr.capacity() == 4);

    arr.add(3);
    TEST(arr.get(0) == 12);
    TEST(arr.get(1) == 157);
    TEST(arr.get(2) == 3);
    TEST(arr.size() == 3);
    TEST(arr.capacity() == 4);

    arr.add(14);
    TEST(arr.get(3) == 14);
    TEST(arr.size() == 4);
    TEST(arr.capacity() == 4);

    // Now you need to implement dynamic array functionality.
    // If the new size is going to exceed the capacity, then
    // double the size of the array as we discussed in class.
    // You MUST delete the old array: if your data member is
    // named _array, then be sure to call
    //    delete [] _array;
    arr.add(28);
    TEST(arr.get(0) == 12);
    TEST(arr.get(1) == 157);
    TEST(arr.get(2) == 3);
    TEST(arr.get(3) == 14);
    TEST(arr.get(4) == 28);
    TEST(arr.size() == 5);
    TEST(arr.capacity() == 8);
  }

  {
    DynArray<int> arr;
    for (int i = 0; i < 1000; ++i) {
      arr.add(i);
    }
    TEST(arr.size() == 1000);
    TEST(arr.capacity() == 1024);
  }

  {
    // Create a class called Student. Uncomment the Student.cpp
    // line inCMakeLists.txt. All functions must be declared in
    // Student.h and defined in Student.cpp. Student must
    // have a default constructor (constructor with no
    // parameters).
    const Student kelly("Kelly", 3.8);

    // Your accessor functions should be const. That is:
    //     const std::string& name() const;
    // The first const refers to the return value. The const
    // at the end of the line means that the function is const
    // and can't change any of the data members.
    // This way, you can call name() on kelly which, as you
    // see above, is const, meaning it can't be changed.
    // Accessors are almost always const.
    TEST(kelly.name() == "Kelly");
    TEST(kelly.gpa() == 3.8);
  }

  {
    DynArray<Student> students;
    students.add(Student("Frank", 2.9));
    students.add(Student("Coraline", 3.1));
    students.add(Student("Callie", 4.0));
    students.add(Student("Ephraim", 3.9));

    TEST(students.get(0).name() == "Frank");
    TEST(students.get(0).gpa() == 2.9);
    TEST(students.get(3).name() == "Ephraim");
    TEST(students.get(3).gpa() == 3.9);
  }

  {
    // Create a class called Button. Add Button.cpp to CMakeLists.txt.
    const Button ok("OK");
    const Button cancel("Cancel");

    // Remember to make accessors const.
    TEST(ok.text() == "OK");
    TEST(cancel.text() == "Cancel");
  }

  {
    DynArray<Button> buttons;
    buttons.add(Button("Yes"));
    buttons.add(Button("No"));
    buttons.add(Button("Cancel"));

    TEST(buttons.get(0).text() == "Yes");
    TEST(buttons.get(2).text() == "Cancel");
  }

  {
    // Add code as needed. You'll add RadioButton.cpp to
    // CMakeLists.txt.
    const Button* choice1 = new RadioButton("One");
    const Button* choice2 = new RadioButton("Two");
    const Button* choice3 = new Button("Three");

    TEST(choice1->text() == "Choice One");
    TEST(choice2->text() == "Choice Two");
    TEST(choice3->text() == "Three");

    delete choice1;
    delete choice2;
    delete choice3;
  }

  {
    DynArray<Button*> buttons;
    buttons.add(new Button("Yes"));
    buttons.add(new RadioButton("No"));
    buttons.add(new RadioButton("Cancel"));
    buttons.add(new Button("Push me"));

    stringstream ss;
    for (int i = 0; i < buttons.size(); ++i) {
      ss << buttons.get(i)->text() << endl;
    }
    TEST(ss.str() == "Yes\nChoice No\nChoice Cancel\nPush me\n");
  }

  const int numSuccesses = testNum - numFails;
  cout << numSuccesses << "/" << testNum << " tests succeeded" << endl;

  return numFails;
}

int main(int argc, char** argv) {
  return runTests();
}
