#include "Date.h"
#include <string>
#include <iostream>
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
// operator overloading
    
  Date Date::operator-(Date d1) { 
  // date1 - date2;
  // *this - d1
  // this should be bigger than d1

  Date result;
  int rDay;
  int rMonth;
  int rYear;
  
  if (d1.getDay() > m_day) {
    rDay = m_day-d1.getDay() + daysInPreviousMonth(*this);
    this->setMonth(m_month-1);
  }
  else rDay = m_day-d1.getDay(); 

  rYear = m_year - d1.getYear();
    if (m_month < d1.getMonth()) {
      rMonth = m_month - d1.getMonth() + 12;
      rYear--;
    } else
      rMonth = m_month - d1.getMonth();
    

    result.SetDate(rYear, rMonth, rDay);


    return result;
  }  

  int Date::daysInMonth(Date date) {
   int month = date.getMonth();
    switch (month) {
      case 1 || 3 || 5 || 7 || 8 || 10 || 12:
        return 31;
     case 2:
        if (date.getYear() % 4 == 0)
          return 29;
        else
          return 28;
     default:
       return 30;
    }
    
  }

    int Date::daysInPreviousMonth(Date date) {
    int month = date.getMonth()-1;
    switch (month) {
      case 1 || 3 || 5 || 7 || 8 || 10 || 12:
        return 31;
      case 2:
        if (date.getYear() % 4 == 0)
          return 29;
        else
          return 28;
      default:
        return 30;
    }
  }

    std::ostream& operator<<(
      std::ostream& os,
      const Date& d1) {  // declaration of << overloading for Date
    os << d1.m_year << '-' << d1.m_month << '-' << d1.m_day;

    return os;
  }

  
  
