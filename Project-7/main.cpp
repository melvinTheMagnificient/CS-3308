//------------------------------------------------------------
//
// CS 3308
// Project 7 - Binary search and sorting
//
// In this project you will implement binary search, bubble
// sort and selection sort.
//
// Implement the code as instructed in the comments in
// runTests().
//
// You will submit TWO files: search.h and sort.h. Do NOT submit
// any other files and do NOT zip the files.
//
//------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "./util.h"
#include "./search.h"
#include "./sort.h"
#include "./Person.h"

using namespace std;

//------------------------------------------------------------
// Tests
//------------------------------------------------------------
int runTests() {

  int numFails = 0;
  int testNum = 0;

  //------------------------------------------------------------
  // Binary search
  //------------------------------------------------------------
  {
    // Put your implementation of binarySearch in search.h
    int numArray[] = { 1, 4, 5, 7, 9, 12 };
    vector<int> numbers(numArray, numArray+6);
    TEST(binarySearch(numbers, 0) == -1);
    TEST(binarySearch(numbers, 1) == 0);
    TEST(binarySearch(numbers, 2) == -1);
    TEST(binarySearch(numbers, 5) == 2);
    TEST(binarySearch(numbers, 12) == 5);
    TEST(binarySearch(numbers, 13) == -1);
  }

  {
    string array[] = { "1", "12", "4", "5", "7", "8" };
    vector<string> vec(array, array+6);
    TEST(binarySearch<string>(vec, "0") == -1);
    TEST(binarySearch<string>(vec, "1") == 0);
    TEST(binarySearch<string>(vec, "2") == -1);
    TEST(binarySearch<string>(vec, "5") == 3);
    TEST(binarySearch<string>(vec, "12") == 1);
    TEST(binarySearch<string>(vec, "13") == -1);
    TEST(binarySearch<string>(vec, "9") == -1);
  }

  {
    Person array[] = { Person("Jack"), Person("Jill"), Person("Mary"), Person("Tom") };
    vector<Person> vec(array, array+4);
    TEST(binarySearch<Person>(vec, Person("Andrew")) == -1);
    TEST(binarySearch<Person>(vec, Person("Jack")) == 0);
    TEST(binarySearch<Person>(vec, Person("Mary")) == 2);
    TEST(binarySearch<Person>(vec, Person("Zachary")) == -1);
  }

  //------------------------------------------------------------
  // Bubble sort
  //------------------------------------------------------------
  {
    // Put your implementation of bubbleSort in sort.h
    int numArray[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    vector<int> numbers(numArray, numArray+10);
    // The second parameter indicates how many values to bubble up.
    // See the target array below.
    bubbleSort(numbers, 3);
    // printVector(numbers);
    int target[] = { 6, 5, 4, 3, 2, 1, 0, 7, 8, 9, };
    TEST(vectorEquals(numbers, target));
  }

  {
    int numArray[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    vector<int> numbers(numArray, numArray+10);
    // The second parameter indicates how many values to bubble up.
    // See the target array below.
    bubbleSort(numbers, 8);
    // printVector(numbers);
    int target[] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9, };
    TEST(vectorEquals(numbers, target));
  }

  {
    int numArray[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    vector<int> numbers(numArray, numArray+10);
    // The second parameter indicates how many values to bubble up.
    // See the target array below.
    bubbleSort(numbers, numbers.size());
    // printVector(numbers);
    int target[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
    TEST(vectorEquals(numbers, target));
  }

  {
    int numArray[] = { 5, 1, 7, 2, 3, 9 };
    vector<int> numbers(numArray, numArray+6);
    bubbleSort(numbers, 3);
    // printVector(numbers);
    int target[] = { 1, 2, 3, 5, 7, 9, };
    TEST(vectorEquals(numbers, target));
  }

  {
    int numArray[] = { 5, 1, 7, 2, 3, 9 };
    vector<int> numbers(numArray, numArray+6);
    bubbleSort(numbers, numbers.size());
    int target[] = { 1, 2, 3, 5, 7, 9, };
    TEST(vectorEquals(numbers, target));
  }

  {
    Person array[] = { Person("Jill"), Person("Tom"),
                       Person("Mary"), Person("Jack") };
    Person target[] = { Person("Jack"), Person("Jill"),
                        Person("Mary"), Person("Tom") };
    vector<Person> vec(array, array+4);
    bubbleSort(vec, vec.size());
    TEST(vectorEquals(vec, target));
  }

  //------------------------------------------------------------
  // Selection sort
  //------------------------------------------------------------
  {
    // Put your implementation of selectionSort in sort.h
    int numArray[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    vector<int> numbers(numArray, numArray+10);
    // The second parameter indicates how many values to have sorted.
    // In other words, if 3 is the second parameter, then the array
    // will have the smallest three values in sorted order at the
    // beginning of the array.
    // 
    // Your implementation of selection sort should find the minimum
    // value and swap it with the first value, then find the second
    // minimum value and swap it with the second value and so on.
    selectionSort(numbers, 3);
    // printVector(numbers);
    int target[] = { 0, 1, 2, 6, 5, 4, 3, 7, 8, 9, };
    TEST(vectorEquals(numbers, target));
  }

  {
    int numArray[] = { 6, 7, 8, 9, 5, 4, 3, 2, 1, 0 };
    vector<int> numbers(numArray, numArray+10);
    selectionSort(numbers, 7);
    // printVector(numbers);
    int target[] = { 0, 1, 2, 3, 4, 5, 6, 8, 7, 9, };
    TEST(vectorEquals(numbers, target));
  }

  {
    int numArray[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    vector<int> numbers(numArray, numArray+10);
    selectionSort(numbers, numbers.size());
    // printVector(numbers);
    int target[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
    TEST(vectorEquals(numbers, target));
  }

  {
    int numArray[] = { 5, 1, 7, 2, 3, 9 };
    vector<int> numbers(numArray, numArray+6);
    selectionSort(numbers, 3);
    // printVector(numbers);
    int target[] = { 1, 2, 3, 5, 7, 9, };
    TEST(vectorEquals(numbers, target));
  }

  {
    int numArray[] = { 5, 1, 7, 2, 3, 9 };
    vector<int> numbers(numArray, numArray+6);
    selectionSort(numbers, numbers.size());
    int target[] = { 1, 2, 3, 5, 7, 9, };
    TEST(vectorEquals(numbers, target));
  }

  {
    Person array[] = { Person("Jill"), Person("Tom"),
                       Person("Mary"), Person("Jack") };
    Person target[] = { Person("Jack"), Person("Jill"),
                        Person("Mary"), Person("Tom") };
    vector<Person> vec(array, array+4);
    selectionSort(vec, vec.size());
    TEST(vectorEquals(vec, target));
  }

  const int numSuccesses = testNum - numFails;
  cout << numSuccesses << "/" << testNum << " tests succeeded" << endl;

  return numFails;
}

int main(int argc, char** argv) {
  return runTests();
}
