// Melissa Coblentz
// Project 4

#pragma once

#include <iostream>
#include <vector>

#include "./Person.h"

using namespace std;

void runInteraction();

vector<Person*> PrintPeople(vector<Person*> v);

vector<Person*> AddPerson(vector<Person*> v);

vector<Person*> Pay(vector<Person*> v, Restaurant* transactionWith);

vector<Person*> Speak(vector<Person*> v);

void Quit();