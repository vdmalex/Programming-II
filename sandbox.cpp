// sandbox.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
// COP 3003 project: CPA C++ Certification Exam Study preparation resource
// using class excercises and openedg readings
#include <functional>
#include <iostream>
#include <string>

#include "Date.h"
#include "FeetInches.h"
#include "Firefighter.h"
#include "Functions.h"
#include "Mailperson.h"
#include "MyAbstractClass.h"
#include "Person.h"
#include "StaticMember.h"
#include "myException.h"
int StaticMember::amount;  // allow static variable in the main cpp file

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
  void DoIt(Class& c) {  // requires reference of the class object
    c.field = 100;       // allows us to change Class's private member
    c.print();           // and use its private methods
  }
};
class Stack {  // Stack: a last in first out stucture that stores data
               // imagine stacking plates on a table
 private:
  int stackstore[100];
  int SP;

 public:
  void push(int value);
  int pop(void) { return stackstore[--SP]; }
};

void proceduralStackDemo(void);
int stack[100];  // global variable, bad because harder to debug
int SP = 0;

void push(int value) {  // adds a new value to the current position in the stack
  stack[SP++] = value;  // then post increment
}

int pop(void) {        // returns the previous value in the stack
  return stack[--SP];  // pre decrement
}

void proceduralStackDemo(void) {
  std::cout << "push(3) push(2) push(1)\nstd::cout pop() pop() pop()\n";
  push(3);
  push(2);
  push(1);
  std::cout << pop() << std::endl;  // :: scope resolution operator
  std::cout << pop() << std::endl;
  // SP = 34; example of something dangerous, would break the structure
  std::cout << pop() << std::endl;
}
// ** std::vector<int> == template class
template <typename T>  // this is the template parameter declaration
T max_nums(T x, T y)   // this is the function template definition for max<T>
{
  return x + y;
}
// this is the template parameter declaration
template <typename T>  // prototype for template
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
int add(int x, int y);
int invoke(int x, int y, function<int(int, int)> func);
void demoPassFunction();
int multiply(int x, int y);
void staticClassMember();

int main() {
  bool quit = false;
  while (!quit) {
    std::cout
        << "Modes: \n1. Polymorphism \n2. Procedural Stack Demo "
           "\n3. Functions\n4. Class Inheritance\n5. "
           "Default Parameters\n6. Exceptions\n7. Templates\n8. Static and "
           "Auto variables\n9. Friend Classes\n10. Overloading Operators\n11. "
           "Pass Function\n";
    std::cout << "Enter mode or quit with 0: ";
    int mode;
    std::cin >> mode;
    switch (mode) {
      case 0:
        quit = true;
        break;
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
        } catch (const exception& ex) {  // polymorphism
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
        break;
      case 11:
        demoPassFunction();
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
            << std::endl;  // using template classes we can create a function
                           // that takes different
  std::cout << max_nums(db1, db2) << std::endl;  // types of data
  std::cout << max_nums(str1, str2) << std::endl;
  MyClass me;
  return_it(me);  // templates work with new datatypes like classes
}
template <typename T>
T return_it(T x) {
  return x;
}

void demoExceptions() {
  int num2 = 0;
  try {
    if (num2 == 0) {  // if we don't add this the program will fail during
                      // execution the C++ language (unlike some other newer
                      // programming languages), division by zero doesn’t throw
                      // an exception by default
      throw std::invalid_argument("");  // think of throw as a call
    }
    std::cout << 5 / num2;  // try this
                            // end try scope
  } catch (const std::invalid_argument&
               ex) {  // catches a thrown std::invalid_argument -> function call
                      // definition
    std::cout << "Can't divide by 0" << std::endl;  // this line will execute
  } catch (const std::exception& ex) {              // example of polymorphism
    std::cout << "Caught you" << std::endl;
  } catch (...) {  // catch all standard exceptions
    std::cout << "Caught you all" << std::endl;
  }
}
void ClassInheritance() {
  Person person;
  std::cout << "Person age: " << person.getAge() << std::endl;
  person.walk();

  std::cout << "Person age after walk: " << person.getAge() << std::endl;
  // subclasses inherit all base class methods and attributes and can freely
  // access any of them
  Mailperson mail;
  std::cout << mail.Person::drive() << std::endl;  // using parent function
  std::cout << mail.getAge() << std::endl;
  std::cout << mail.drive() << std::endl;  // using derived method
                                           // does not work the other way ex:
  // person.Mailperson::drive() would result in an error

  Firefighter fighter;
  std::cout << fighter.drive() << std::endl;
  std::cout << fighter.getAge() << std::endl;

  // similarly, we cannot access Mailpersons methods by a Firefighter
  // ex: fighter.Mailperson::drive() is illegal
  // cannot use adjacent subclasses, not inheriting
  // from mailperson
}

void demoPolymorphism() {
  Person* jobUnknown = new Mailperson;  // pointer pointing to person object
                                        // with type of mailperson
  Person* regular = new Mailperson();
  std::cout << jobUnknown->drive()
            << std::endl;  // will use superclass method of drive UNLESS it is a
                           // virtual function use -> instead of . with a
                           // pointer to also dereference the pointer
                           // Polymorphism allows us to use Mailperson methods
                           // as a Person pointer object

  std::cout
      << static_cast<Mailperson*>(regular)->drive()
      << std::endl
      // static cast as mailperson to use mailperson's drive method
      << static_cast<Firefighter*>(regular)->drive()
      // will result in Firefighter's method UNLESS superclass drive is virtual
      // (runtime vs compile time polymorphism) from edube.org on static_cast
      /*I am of sound mind,
      I know what I am doing and I want to use the pointer to the superclass in
      relation to the object of the subclass;
      I guarantee that the proper object exists.*/

      << std::endl;
  // create array of Person pointer objects of different types
  std::cout << "array of Person*" << std::endl;
  Person person1;
  Mailperson person2;
  Firefighter person3;
  // Person arrOfSubclasses = {person1, person2, person3};
  // Will not work because person1 - 3 are of different type
  // (Person, Mailperson, Firefighter)
  Person* firefighter = new Firefighter();
  Person* person = new Person();
  // if we use pointers of Person objects and set them to different types
  // we can create an array of different subclasses
  Person* arr[] = {person, firefighter, jobUnknown};
  for (int i = 0; i < 3; ++i) {
    arr[i]->print();  // different output based on type of Person
  }
}

void demoStaticAuto() {
  for (int i = 0; i < 5; ++i) {
    staticFunc();  // will continue to give new values
  }
  for (int i = 0; i < 5; ++i) {
    autoFunc();  // will result in the same value
  }
  staticClassMember();
}

void autoFunc() {
  auto var = 99;  // automatically destroyed when going out of scope

  cout << "auto var = " << ++var << endl;
}

void staticFunc() {
  static int var = 99;  // exist continuously during the whole program execution
  cout << "static var = " << ++var << endl;
}
void staticClassMember() {
  StaticMember member1;
  std::cout << member1.getAmount() << std::endl;
  // set up so every time an object is constructed it will increment
  StaticMember member2;
  StaticMember member3;
  StaticMember member4;
  // will output the same value for all members
  std::cout << member1.getAmount() << std::endl;
  std::cout << member2.getAmount() << std::endl;
  std::cout << member3.getAmount() << std::endl;
  std::cout << member4.getAmount() << std::endl;
}
void demoFriend() {
  // usually, we will use inheritance over friend classes
  // see declaration of classes near top of main
  Class o;  // create Class object

  Friend f;  // create friend class object

  f.DoIt(o);  // invoke method using o's method
}

void demoOverloadOperators() {
  /**
   * note that
   * :: .* . ?:
   * cannot be overloaded
   * any other operator may be
   * x + y
   * is really +(x,y), think of the operator as a function call
   * almost all but some exceptions for what operators can be overloaded
   * (conditional, scope, sizeof, . , *) must be existing operators at
   * least one must be user defined can't change number of operands
   * precedence and associativity remain the same
   **/
  Date halloween(2021, 10, 31);
  Date christmas(2021, 12, 25);

  Date difference;
  difference = christmas - halloween;
  // overloaded function - to calculate days from halloween to christmas
  std::cout << difference << std::endl;
  // overloaded function to display Date data
  Date birthday(1996, 07, 10);
  difference = christmas - birthday;
  std::cout << difference << std::endl;

  int feet1 = 4;
  int feet2 = 3;
  int inches1 = 4;
  int inches2 = 3;
  FeetInches height1(feet1, inches1);
  FeetInches height2(feet2, inches2);

  FeetInches combined_height =
      height1 + height2;            // overloaded + to add FeetInches data
  cout << combined_height << endl;  // overloaded << to display FeetInches data

  FeetInches reduced_height = height1 - height2;
  cout << reduced_height << endl;
}
int add(int x, int y) { return x + y; }
int multiply(int x, int y) { return x * y; }
// 6.6 times faster than std::bind!
// anonymous, inline, 1 time functions
int invoke(int x, int y, function<int(int, int)> func) { return func(x, y); }

void demoPassFunction() {
  std::cout << invoke(1, 50, add) << std::endl;
  std::cout << invoke(32, 53, multiply) << std::endl;

  // lambda function: [](params)->returnType{functionbody})
  int k = invoke(20, 10, [](int x, int y) -> int { return x + y; });
  std::cout << k << std::endl;
}
