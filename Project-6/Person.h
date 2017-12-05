#pragma once

#include <string>

class Person {
 public:
  Person(const std::string& name) {
    _name = name;
  }

  const std::string& getName() const { return _name; }

 private:
  std::string _name;
};
