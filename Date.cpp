#include "Date.h"

#include <string>
// Date constructor
Date::Date(int year, int month, int day) { SetDate(year, month, day); }
Date::Date() : m_month(10), m_year(2021), m_day(18) 
// initializer list
{
// no need for assignment
}  // Date member function

//    S() : n(7) {} // constructor definition
                  // ": n(7)" is the initializer list
                  // ": n(7) {}" is the function body
void Date::SetDate(int year, int month, int day) {
  m_month = month;
  m_day = day;
  m_year = year;
}

std::string Date::getISODate() {
  std::string str = std::to_string(m_year) + "-" +
                    std::to_string(m_month) + "-" +
                    std::to_string(m_day);
  return str;
}

  int Date::operator-(Date d1) { return m_day-d1.getDay(); }  
  
  
  // operator overloading