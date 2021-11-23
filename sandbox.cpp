// sandbox.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
// COP 3003 project: CPA C++ Certification Exam Study preparation resource
// using class excercises and openedg readings
#include <functional>
#include <iostream>
#include <string>
#include "Person.h"
#include "Date.h"
#include "FeetInches.h"
#include "Firefighter.h"
#include "Mailperson.h"
#include "Functions.h"
#include "myException.h"

// 6.6 times faster than std::bind!
// anonymous, inline, 1 time functions
int invoke(int x, int y, function<int(int, int)> func) { return func(x, y); }
int k = invoke(20, 10, [](int x, int y) -> int { return x + y; });


using namespace std;
class Class {
  friend class Friend;  
  // gives Friend access to private members

  // a class may be a friend of many classes
  // a class may have many friends
  // a friend’s friend isn’t my friend
  // friendship isn’t inherited – the subclass has to define its own friendships
  // ~openedg

 private:
  int field;
  void print(void) { cout << "It's a secret, that field = " << field << endl; }
};
class Friend {
 public:
  void DoIt(Class& c) {                             // requires reference of the class object
    c.field = 100;                                  // allows us to change Class's private member
    c.print();                                      // and use its private methods
  }
};
class Stack {                                       // Stack: a last in first stucture that stores data
                                                    // imagine stacking plates on a table
 private:
  int stackstore[100];
  int SP;

 public:
  void push(int value);
  int pop(void) { return stackstore[--SP]; }
};

void proceduralStackDemo(void);
int stack[100];                                     // global variable, bad because harder to debug
int SP = 0;

void push(int value) {                              // adds a new value to the current position in the stack
  stack[SP++] = value;                              // then post increment
}

int pop(void) {                                     // returns the previous value in the stack
  return stack[--SP];                               // pre decrement
}

void proceduralStackDemo(void) {
  std::cout << "push(3) push(2) push(1)\nstd::cout pop() pop() pop()\n";
  push(3);
  push(2);
  push(1);
  std::cout << pop() << std::endl;                  // :: scope resolution operator
  std::cout << pop() << std::endl;
  // SP = 34; example of something dangerous, would break the structure
  std::cout << pop() << std::endl;
}
// ** std::vector<int> == template class
template <typename T>                               // this is the template parameter declaration
T max_nums(T x, T y)                                // this is the function template definition for max<T>
{
  return x + y;
}
// this is the template parameter declaration
template <typename T>                               // prototype for template
T return_it(T x);
class MyClass {};

// function prototypes
// returntype name(parameters);
// naming function: firstSecondThird
// use verbs
void demoPolymorphism();
void demoExceptions();
void ClassInheritance();
void demoTemplates();
void autoFunc();
void staticFunc();
void demoFriend();
void demoOverloadOperators();
Date calculateDifference(Date d1, Date d2);

int main() {
  while (true) {
    std::cout << "Modes: \n1. Polymorphism \n2. Procedural Stack Demo "
                 "\n3. Functions\n4. Class Inheritance\n5. "
                 "Default Parameters\n6. Exceptions\n7. Templates\n8. Static and Auto variables\n9. Friend Classes\n10. Overloading Operators\n";
    std::cout << "Enter mode : ";
    int mode;
    std::cin >> mode;
    switch (mode) {
      case 1:
        demoPolymorphism();
        break;
      case 2:
        proceduralStackDemo();
        break;
      case 3:
        Functions::demonstrate_functions();
        break;
      case 4:
        ClassInheritance();
        break;
      case 5:
        Functions::demonstrate_default_parameters();
        break;
      case 6:
        try {
          demoExceptions();
          throw myException();
        } catch (const exception& ex) {             // polymorphism
          std::cout << "Caught. " << ex.what() << std::endl;

        } catch (const myException& e) {
          std::cout << "caught myException" << std::endl;
        }

        break;
      case 7:
        demoTemplates();
        break;
      case 8:
        demoStaticAuto();
        break;
      case 9:
        demoFriend();
        break;
      case 10:
        demoOverloadOperators();
        // note that 
        // :: .* . ?:
        // cannot be overloaded
        // any other operator may be
        // x + y
        // is really +(x,y), think of the operator as a function call
        // almost all but some exceptions for what operators can be overloaded
        // (conditional, scope, sizeof, . , *) must be existing operators at
        // least one must be user defined can't change number of operands
        // precedence and associativity remain the same
        break;
      case 11:
        demoOverloadOperators();
        break;

    }
  }
}

void demoTemplates() {
  int int1 = 23;
  int int2 = 35;
  double db1 = 23;
  double db2 = 25;
  string str1 = "Help";
  string str2 = "Me";
  std::cout << max_nums(int1, int2)
            << std::endl;                           // using template classes we can create a function
                                                    // that takes different
  std::cout << max_nums(db1, db2) << std::endl;     // types of data
  std::cout << max_nums(str1, str2) << std::endl;
  MyClass me;
  return_it(me);                                    // templates work with new datatypes like classes
}
template <typename T>
T return_it(T x) {
  return x;
}

void demoExceptions() {
  int num2 = 0;
  try {
    if (num2 == 0) {                                // if we don't add this the program will fail during
                                                    // execution the C++ language (unlike some other newer
                                                    // programming languages), division by zero doesn’t throw
                                                    // an exception by default
      throw std::invalid_argument("");
    }
    std::cout << 5 / num2;                          // try this
                                                    // end try scope
  } catch (const std::invalid_argument&
               ex) {                                // catches a thrown std::invalid_argument
    std::cout << "Can't divide by 0" << std::endl;  // this line will execute
  } catch (const std::exception& ex) {              // example of polymorphism
    std::cout << "Caught you" << std::endl;
  } catch (...) {                                   // catch all standard exceptions
    std::cout << "Caught you all" << std::endl;
  }
}
void ClassInheritance() {
  Person person;
  std::cout << "Person age: " << person.getAge() << std::endl;
  person.walk();

  std::cout << "Person age after walk: " << person.getAge() << std::endl;
  Mailperson mail;
  std::cout << mail.Person::drive() << std::endl;
  std::cout << "Mailperson after Person::drive() : "
            << mail.Person::drive()                 // using parent class function
            << std::endl
            << "this shows we can use parent methods" << std::endl
            << "after mail.drive() : " << mail.drive()
            << std::endl                            // using derived method
            << "and derived methods!" << std::endl
            << "However, std::cout << person.Mailperson::drive() is illegal"
            << std::endl;
  Firefighter fighter;
  std::cout << "Firefighter drive(): " << fighter.drive() << std::endl;
  std::cout << "fighter.Mailperson::drive(); // illegal"
            << std::endl;                           // cannot use adjacent subclasses, not inheriting
                                                    // from mailperson
}

void demoPolymorphism() {
  Person* jobUnknown = new Mailperson;              // pointer pointing to person object
                                                    // with type of mailperson
  Person* regular = new Mailperson();
  std::cout << jobUnknown->drive()
            << std::endl;                           // will use superclass method of drive UNLESS it is a
                                                    // virtual function use -> instead of . with a
                                                    // pointer to also dereference the pointer
                                                    // Polymorphism allows us to use Mailperson methods as a Person pointer object

  std::cout<< static_cast<Mailperson*>(regular)->drive()
                                                    // static cast as mailperson to use mailperson's drive method
      << "\nWe can also use Mailperson functions through static_cast \n"
      << static_cast<Firefighter*>(regular)->drive()
                                                    // will result in Firefighter's method UNLESS superclass drive is virtual
                                                    // from edube.org on static_cast
                                                    /*I am of sound mind,
                                                    I know what I am doing and I want to use the pointer to the superclass in
                                                    relation to the object of the subclass;
                                                    I guarantee that the proper object exists.*/

      << std::endl;
}

void demoStaticAuto() {
  for (int i = 0; i < 5; ++i) {
    staticFunc();                                   // will continue to give new values
  }
  for (int i = 0; i < 5; ++i) {
    autoFunc();                                     // will result in the same value
  }
}

void autoFunc() {
  auto var = 99;                                    // automatically destroyed when going out of scope

  cout << "auto var = " << ++var << endl;
}

void staticFunc() {
  static int var = 99;                              // exist continuously during the whole program execution
  cout << "static var = " << ++var << endl;
}

void demoFriend() {
  // usually, we will use inheritance over friend classes
  // see declaration of classes near top of main
  Class o;                                          // create Class object

  Friend f;                                         // create friend class object

  f.DoIt(o);                                        // invoke method using o's method
}

void demoOverloadOperators() {
  Date halloween(2021, 10, 31);
  std::cout << halloween.getMonth() << std::endl;
  Date today;

  Date difference;
  difference = today - halloween;
  // std::cout << difference << endl;
  // add calculateDifference(m1,m2)
  // std::cout << halloween - today << std::endl;
  int feet1 = 4;
  int feet2 = 3;
  int inches1 = 4;
  int inches2 = 3;
  FeetInches height1(feet1, inches1);
  FeetInches height2(feet2, inches2);

  FeetInches combined_height =
      height1 + height2;                            // overloaded + to add FeetInches data
  cout << combined_height << endl;                  // overloaded << to display FeetInches data

  FeetInches reduced_height = height1 - height2;
  cout << reduced_height << endl;
}

Date calculateDifference(Date d1, Date d2) { return d1; }