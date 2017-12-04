//------------------------------------------------------------
//
// CS 3308
// Project 6 - Linked List
//
// In this project you will create a smart pointer class. You
// will then create a linked list Node class that uses the
// C++ shared_ptr (similar to the smart pointer you will have
// created).
//
// To build:
//   > [navigate to project directory]
//   > mkdir build
//   > cd build
//   > cmake ..
//   > make
//   > ./list
//
// Implement the code as instructed in the comments in
// runTests().
//
// You will zip and submit TWO files: Node.h and SmartPtr.h. Do NOT submit
// any other files and do NOT zip the files.
//
//------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <sstream>

#include "./util.h"
#include "./SmartPtr.h"
#include "./Person.h"
#include "./Node.h"

using namespace std;

//------------------------------------------------------------
// Tests
//------------------------------------------------------------
int runTests() {

  int numFails = 0;
  int testNum = 0;

  {
    // Add a file called SmartPtr.h. The destructor MUST destroy the pointer.
    int* p = new int(3);
    SmartPtr<int> ptr(p);
    TEST(ptr.get() == p);
  }

  {
    // You should implement reference counting like we did in class.
    // Override the copy constructor.
    int* p = new int(3);
    SmartPtr<int> ptr1(p);
    SmartPtr<int> ptr2(ptr1);
    TEST(ptr1.get() == p);
    TEST(ptr2.get() == p);
  }

  {
    // These tests will only pass if you have reference counting implemented.
    int* p = new int(3);
    SmartPtr<int> ptr1(p);
    {
      SmartPtr<int> ptr2(ptr1);
    }
    TEST(ptr1.get() == p);
    TEST(*(ptr1.get()) == 3);
  }

  {
    Person* p = new Person("Bela Fleck");
    SmartPtr<Person> ptr1(p);
    {
      SmartPtr<Person> ptr2(ptr1);
    }
    TEST(ptr1.get() == p);
    TEST(ptr1.get()->getName() == "Bela Fleck");
  }

  {
    // Overload the = operator
    SmartPtr<Person> ptr1(new Person("Chick Corea"));
    {
      SmartPtr<Person> ptr2 = ptr1;
      TEST(ptr2.get()->getName() == "Chick Corea");
    }
    TEST(ptr1.get()->getName() == "Chick Corea");
  }

  {
    SmartPtr<Person> ptr1(new Person("Bobby McFerrin"));
    // Overload the -> operator in SmartPtr. It should look almost identical
    // to the get() function.
    TEST(ptr1->getName() == "Bobby McFerrin");
    // Overload the * operator in SmartPtr. It should look almost identical
    // to the get() function, but should return a reference instead of a
    // pointer.
    TEST((*ptr1).getName() == "Bobby McFerrin");
  }

  {
    // Create a Node for a linked list. You will create a static "factory"
    // function in the Node class. 
    shared_ptr<Node<int>> head = Node<int>::create(3);
    // The "next" pointer in the node should
    // be stored as a C++ std::shared_ptr. You'll need to add
    //     #include <memory>
    // By storing "next" in a shared_ptr you won't need to worry about
    // deleting the dynamically allocated Node objects.
    shared_ptr<Node<int>> next = Node<int>::create(3);
    TEST(head->getNext() == 0);
  }

  {
    shared_ptr<Node<int>> head = Node<int>::create(3);
    head->setNext(Node<int>::create(18));
    head->setNext(Node<int>::create(9));
    TEST(head->getData() == 3);
    TEST(head->getNext()->getData() == 9);
    TEST(head->getNext()->getNext() == nullptr);
  }

  {
    shared_ptr<Node<int>> head = Node<int>::create(3);
    head->setNext(Node<int>::create(18));
    head->setNext(Node<int>::create(9));
    TEST(head->getData() == 3);
    TEST(head->getNext()->getData() == 9);
    TEST(head->getNext()->getNext() == nullptr);
  }

  {
    shared_ptr<Node<int>> head = Node<int>::create(3);
    head->setNext(Node<int>::create(18));
    // The insert function should insert the node, modifying next pointers
    // as necessary.
    head->insert(Node<int>::create(9));
    TEST(head->getData() == 3);
    TEST(head->getNext()->getData() == 9);
    TEST(head->getNext()->getNext()->getData() == 18);
  }

  const int numSuccesses = testNum - numFails;
  cout << numSuccesses << "/" << testNum << " tests succeeded" << endl;

  return numFails;
}

int main(int argc, char** argv) {
  return runTests();
}
