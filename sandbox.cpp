// sandbox.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//
#include <functional>
#include <iostream>
#include <string>

#include "Firefighter.h"
#include "Mailperson.h"
#include "Person.h"
#include "myException.h"
#include "Date.h"


// 6.6 times faster than std::bind!
// anonymous, inline, 1 time functions
int invoke(int x, int y, function<int(int, int)> func) { return func(x, y); }
int k = invoke(20, 10, [](int x, int y) -> int { return x + y; });
// x + y
// really +(x,y)
// almost all but some exceptions for what operators can be overloaded (conditional, scope, sizeof, . , *)
// must be existing operators
// at least one must be user defined
// can't change number of operands
// precedence and associativity remain the same

using namespace std;
class Class {
  friend class Friend;      // gives Friend access to private members

                            // a class may be a friend of many classes 
                            // a class may have many friends
                            // a friend’s friend isn’t my friend 
                            // friendship isn’t inherited – the subclass has to define its own friendships


 private:
  int field;
  void print(void) { cout << "It's a secret, that field = " << field << endl; }
};
class Friend {
 public:
  void DoIt(Class& c) {     // requires reference of the class object
    c.field = 100;          // allows us to change Class's private member
    c.print();              // and use its private methods
  }
};
class Stack {               // Stack: a last in first stucture that stores data
                            // imagine stacking platse on a table
 private:
  int stackstore[100];
  int SP;

 public:
  void push(int value);
  int pop(void) { return stackstore[--SP]; }
};

void procedural_stack_demo(void);
int stack[100];             // global variable, bad because harder to debug
int SP = 0;

void push(int value) {      // adds a new value to the current position in the stack
  stack[SP++] = value;      // then post increment
}

int pop(void) {             // returns the previous value in the stack
  return stack[--SP];       // pre decrement
}

void procedural_stack_demo(void) {
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
template <typename T>       // this is the template parameter declaration
T max_nums(T x, T y)        // this is the function template definition for max<T>
{
  return x + y;
}
                            // this is the template parameter declaration
template <typename T>       // prototype for template
T return_it(T x);
class MyClass {};

// function prototypes
// returntype name(parameters);
// naming function: firstSecondThird
// use verbs
void polymorphism_demo();
void demo_exceptions();
void demonstrate_functions();
void demonstrate_pass_by_value(int, int);
void demonstrate_pass_by_ref(int&, int&);
void demonstrate_pass_by_address(int*, int*);           // name not required, only time
void demonstrate_more_fuction_stuff();
void demonstrate_default_parameters();
void demoOverload();
void demoOverload(int num1);
void demoOverload(int num1, int num2);                  // can give name
inline int inlinemin(int x, int y);
void default_parameters(std::string, int repeats = 1);  // default parameter = 1
void demonstrate_inline_fuctions();
void demonstrate_overloaded_functions();
void demonstrate_default_parameters();
void class_inheritance();
void demo_templates();
void demo_static_auto();
void autoFunc();
void staticFunc();
void demoFriend();
void demoOverloadOperators();
Date calculateDifference(Date d1, Date d2);



int main() {
  while (true) {
    std::cout << "Modes: \n1. Polymorphism Demo \n2. procedural_stack_demo "
                 "\n3. demonstrate_functions\n4. class_inheritance\n5. "
                 "demonstrate_default_parameters\n6. demo_exceptions\n";
    std::cout << "Enter mode : ";
    int mode;
    std::cin >> mode;
    switch (mode) {
      case 1:
        polymorphism_demo();
        break;
      case 2:
        procedural_stack_demo();
        break;
      case 3:
        demonstrate_functions();
        break;
      case 4:
        class_inheritance();
        break;
      case 5:
        demonstrate_default_parameters();
        break;
      case 6:
        try {
          demo_exceptions();
          throw myException();
        } 
        catch (const exception& ex) {  // polymorphism
          std::cout << "Caught. " << ex.what() << std::endl;
         
        } catch (const myException& e) {
          std::cout << "caught myException" << std::endl;
        }
       
        break;
      case 7:
        demo_templates();
        break;
      case 8:
        demo_static_auto();
        break;
      case 9:
        demoFriend();
        break;
    case 10:
        demoOverloadOperators();
      break;
    }
  }
}

void demo_templates() {
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

void demo_exceptions() {
  int num2 = 0;
  try {
    if (num2 ==
        0) {        // if we don't add this the program will fail during execution
                    // the C++ language (unlike some other newer programming languages), 
                    // division by zero doesn’t throw an exception by default
      throw std::invalid_argument("");
    }
    std::cout << 5 / num2;  // try this
    // end try scope
  } catch (const std::invalid_argument& ex) { // catches a thrown std::invalid_argument
    std::cout << "Can't divide by 0" << std::endl; // this line will execute
  } catch (const std::exception& ex) {  // example of polymorphism
    std::cout << "Caught you" << std::endl;
  } catch (...) {  // catch all standard exceptions
    std::cout << "Caught you all" << std::endl;
  }
}
void class_inheritance() {
  Person person;
  std::cout << "Person age: " << person.age << std::endl;

  person.walk();

  std::cout << "Person age after walk: " << person.age << std::endl;
  Mailperson mail;
  std::cout << mail.Person::drive() << std::endl;
  std::cout << "Mailperson after Person::drive() : "
            << mail.Person::drive()  // using parent class function
            << std::endl
            << "this shows we can use parent methods" << std::endl
            << "after mail.drive() : " << mail.drive()
            << std::endl  // using derived method
            << "and derived methods!" << std::endl
            << "However, std::cout << person.Mailperson::drive() is illegal"
            << std::endl;
  Firefighter fighter;
  std::cout << "Firefighter drive(): " << fighter.drive() << std::endl;
  std::cout << "fighter.Mailperson::drive(); // illegal"
            << std::endl;  // cannot use adjacent subclasses, not inheriting
                           // from mailperson
}

void polymorphism_demo() {
  Person* jobUnknown = new Mailperson;  // pointer pointing to person object
                                        // with type of mailperson
  Person* regular = new Mailperson();
  std::cout << jobUnknown->drive()
            << std::endl;  // will use superclass method of drive UNLESS it is a
                           // virtual function use -> instead of . with a
                           // pointer to also dereference the pointer
  // Polymorphism allows us to use Mailperson methods as a Person pointer object

  std::cout
      << static_cast<Mailperson*>(regular)->drive()
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

void demonstrate_functions() {
  int num1 = 4;
  int num2 = 5;
  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;

  demonstrate_pass_by_value(num1, num2);  // call
  // passing a variable by value will not result in changing the value
  // because it is given a copy of that data
  std::cout << "back in calling function" << std::endl;
  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;

  demonstrate_pass_by_ref(num1, num2);  // call
  // passing by reference gives the function the actual location of the variable
  // any changes in the function will be reflected outside of the call
  std::cout << "back in calling function" << std::endl;
  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;

  demonstrate_pass_by_address(&num1, &num2);  // call
  // we pass the address of the data with int* num1 in the parameters and &num1
  // in the arguments to get the value of the variable we have to use the
  // dereferencing operator * passing by address will modify the data outside of
  // the function call
  std::cout << "back in calling function" << std::endl;
  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;
}

void demonstrate_pass_by_value(int num1, int num2) {  // heading
  std::cout << "in demonstrate_pass_by_value" << std::endl;
  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;
  num1 = 6;
  num2 = 7;
  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;
}

void demonstrate_pass_by_ref(int& num1, int& num2) {  // heading
  std::cout << "in demonstrate_pass_by_ref" << std::endl;
  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;
  num1 = 6;
  num2 = 7;
  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;
}

void demonstrate_pass_by_address(int* num1, int* num2) {  // heading
  std::cout << "in demonstrate_pass_by_address" << std::endl;
  std::cout << "the address of num1 is " << num1 << std::endl;
  std::cout << "the address of num2 is " << num2 << std::endl;
  std::cout << "the value of num1 is " << *num1 << std::endl;
  std::cout << "the value of num2 is " << *num2 << std::endl;
  *num1 = 8;  // dereferencing
  *num2 = 9;
  std::cout << "the value of num1 is " << *num1 << std::endl;
  std::cout << "the value of num2 is " << *num2 << std::endl;
}

void demonstrate_more_fuction_stuff() {
  // default parameters, inline functions, overloaded functions

  demonstrate_default_parameters();

  demonstrate_inline_fuctions();
  std::cout << min(5, 6) << '\n';
  std::cout
      << "compiler creates: return 5 > 6 ? 6 : 5\n in place of min(5,6);\n";
  // std::cout << return 5 > 6 ? 6 : 5; << '\n';

  std::cout << inlinemin(5, 6) << '\n';

  demonstrate_overloaded_functions();
  // we can call the same named function with a different number or type of
  // arguments which results in different behaviors
}

inline int inlinemin(int x, int y) { return x > y ? y : x; }

void default_parameters(std::string greet,
                        int repeats) {  // in the prototype, we declared repeats
                                        // = 1, if a value is not given for
                                        // repeats, it is defaulted to 1
  for (int i = 0; i < repeats; i++) std::cout << greet << std::endl;
}

void demonstrate_inline_fuctions() {}

void demonstrate_default_parameters() {
  default_parameters("hello", 2);
  default_parameters("Good morning");  // will use default value (1)
  default_parameters("Hi", 1);         // can use the same as default
}

void demonstrate_overloaded_functions() {
  demoOverload();      // function called with 0 arguments
  demoOverload(2);     // function called with 1 arguments
  demoOverload(2, 1);  // function called with 2 arguments
}

void demoOverload() {
  std::cout << "demoOverload called with 0 arguments" << std::endl;
}

void demoOverload(int num1) {
  std::cout << "demoOverload called with 1 arguments of " << num1 << std::endl;
}

void demoOverload(int num1, int num2) {
  std::cout << "demoOverload called with 2 arguments of " << num1 << " " << num2
            << std::endl;
}

void demo_static_auto() {
  for (int i = 0; i < 5; ++i) {
    staticFunc();  // will continue to give new values
  }
  for (int i = 0; i < 5; ++i) {
    autoFunc();  // will result in the same value
  }
}

void autoFunc() {
  auto var = 99;  // automatically destroyed when going out of scope

  cout << "auto var = " << ++var << endl;
}

void staticFunc() {
  static int var = 99;  // exist continuously during the whole program execution
  cout << "static var = " << ++var << endl;
}

void demoFriend() {
                    // usually, we will use inheritance over friend classes
                    // see declaration of classes near top of main
  Class o;          // create Class object

  Friend f;         // create friend class object

  f.DoIt(o);        // invoke method using o's method
}

void demoOverloadOperators() {
  Date halloween(2021, 10, 31);
  std::cout << halloween.getMonth() << std::endl;
  Date today;

  std::cout << today.getMonth();
//add calculateDifference(m1,m2) 
  std::cout << halloween - today << std::endl;

}

Date calculateDifference(Date d1, Date d2) {

    return d1; }