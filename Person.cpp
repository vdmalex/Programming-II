#include <iostream>

#include "Person.h"

// .cpp file for class Person
// nontrivial functions (non set/get functions) go here
// a prototype must be provided in the .h file

void Person::walk() { age++; }

std::string Person::drive() { return "normal"; }

// virtual function may be
// overridden by sublasses

void Person::print() { std::cout << "From Person" << std::endl; }
// notice in the implementation you do not have to add the virtual keyword,
// only in the declaration