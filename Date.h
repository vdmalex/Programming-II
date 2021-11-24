#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
class Date {
 private:
  int m_year;
  int m_month;
  int m_day;

 public:
  Date(int year, int month, int day);
  Date();

  void SetDate(int year, int month, int day);

  std::string getISODate();

  int getYear() { return m_year; }
  int getMonth() { return m_month; }
  int getDay() { return m_day; }
  void setYear(int year) { m_year = year; }
  void setMonth(int month) { m_month = month; }
  void setDay(int day) { m_day = day; }

  Date operator-(Date d1);  // operator overloading
                            // find days until date argument
  int daysInMonth(Date date);
  int daysInPreviousMonth(Date date);
  friend std::ostream& operator<<(std::ostream& os, const Date& dt);
  // declare ostream a friend class to allow it to access private fields
};

#endif