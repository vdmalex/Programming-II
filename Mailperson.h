#pragma once
#include "Person.h"

// class Y:{visibility specifier}X{...};
// class Sub : public Super {
// Private components will remain private, public components will remain public.
// When we omit the visibility specifier,
// the compiler assumes that we’re going to apply a “private inheritance”.This
// means that all public superclass components turn into private access,
// and private superclass components won't be accessible at all.
// It consequently means that you’re not allowed to use the latter inside the
// subclass. The keyword protected means that any component marked with it
// behaves like a public component when used by any of the subclasses and looks
// like a private component to the rest of the world. in general, avoid
// multi-inheritance: 1 class inheriting from 2 different superclasses
class Mailperson : public Person {
 public:
  std::string drive() { return "stops"; }
  using Person::Person;  // use Person default constructor
  void print();
};
