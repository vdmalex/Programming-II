#pragma once
#include "Person.h"
class Firefighter : public Person {
 public:
  std::string licenseExpiration = "";
  int stationCode = 0;

  std::string drive() { return "really fast";
  }

};
