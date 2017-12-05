//Melissa Coblentz
//From Dr. Edwards
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "./Circle.h"

class PrintSpooler {
 public:
  PrintSpooler() {
    // connect to printer
  }

  static PrintSpooler* instance() {
    if (_instance == nullptr) {
      _instance = new PrintSpooler();
    }
    return _instance;
  }

  void addJob(const Circle& job) {
    _jobs.push_back(job);
    // std::cout << "Adding job " << job << "\n";
  }

 private:
  std::vector<Circle> _jobs;
  static PrintSpooler* _instance;
};
