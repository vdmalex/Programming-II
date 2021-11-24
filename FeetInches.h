#pragma once
#include <iostream>
#include <string>

class FeetInches {
 public:
  int feet = 0;
  int inches = 0;
  FeetInches() {
    feet = 0;
    inches = 0;
  }
  FeetInches(int feet1, int inch1) {
    feet = feet1;
    inches = inch1;
  }
  FeetInches operator+(FeetInches y) {
    FeetInches result;
    result.feet = feet + y.feet;
    if (y.inches + inches > 11) {
      result.feet++;
      result.inches = inches + y.inches - 12;
    } else {
      result.inches = inches + y.inches;
    }

    return result;
  }

  FeetInches operator-(FeetInches y) {
    FeetInches result;
    result.feet = feet - y.feet;
    if (inches - y.inches < 0) {
      result.feet--;
      result.inches = inches - y.inches + 12;
    } else {
      result.inches = inches - y.inches;
    }
    return result;
  }
  friend std::ostream& operator<<(std::ostream& os, const FeetInches& dt);
  // declare ostream a friend class to allow it to access private fields
};
