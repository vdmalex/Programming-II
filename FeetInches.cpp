#include "FeetInches.h"

#include <iostream>
#include <string>

std::ostream& operator<<(
    std::ostream& os,
    const FeetInches& c1) {  // declaration of << overloading for FeetInches
  os << c1.feet << "'" << c1.inches << '"';
  return os;
}