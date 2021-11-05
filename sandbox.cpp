// sandbox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Person.h"
#include "Mailperson.h"
#include "Firefighter.h"
#include <string>
using namespace std;

class Stack {
 private:
  int stackstore[100];
  int SP;

 public:
  void push(int value);
  int pop(void) { return stackstore[--SP]; }
};

void procedural_stack_demo(void);
int stack[100];  // global variable, bad because harder to debug
int SP = 0;

void push(int value) {
  stack[SP++] = value;  // post increment
}

int pop(void) {
  return stack[--SP];  // pre decrement
}

void procedural_stack_demo(void) {
  std::cout << "push(3) push(2) push(1)\nstd::cout pop() pop() pop()\n";
  push(3);
  push(2);
  push(1);
  std::cout << pop() << std::endl;
  std::cout << pop() << std::endl;  // :: scope resolution
  // SP = 34; ex of something dangerous
  std::cout << pop() << std::endl;
}

// funciton prototypes
void polymorphism_demo();

void demonstrate_functions();
void demonstrate_pass_by_value(int, int);
void demonstrate_pass_by_ref(int&, int&);
void demonstrate_pass_by_address(int*, int*);
void demonstrate_more_fuction_stuff();
void demonstrate_default_parameters();
void demoOverload();
void demoOverload(int num1);
void demoOverload(int num1, int num2);

inline int min(int x, int y);

void default_parameters(std::string, int repeats = 1);  // default parameter = 1

void demonstrate_inline_fuctions();
void demonstrate_overloaded_functions();
void demonstrate_default_parameters();

void class_inheritance();


int main() {

 
  while (true) {

    std::cout << "Modes: \n1. Polymorphism Demo \n2. procedural_stack_demo \n3. demonstrate_functions\n4. class_inheritance\n5. demonstrate_default_parameters\n";
    std::cout << "Enter mode : ";
    int mode;
    std::cin >> mode;
    switch (mode) {
      case 1:
        polymorphism_demo();  // prints "1"
        break;                // and exits the switch
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
    }
  }
}
void class_inheritance() {
  Person person;
  std::cout << "Person age: " << person.age << std::endl;

  person.walk();

  std::cout << "Person age after walk: " << person.age << std::endl;
  Mailperson mail;
  std::cout << mail.Person::drive() << std::endl;
  std::cout << "Mailperson after Person::drive() : " << mail.Person::drive()
            << std::endl
            << "this shows we can use parent methods" << std::endl
            << "after mail.drive() : " << mail.drive() << std::endl
            << "and derived methods!" << std::endl
            << "However, std::cout << person.Mailperson::drive() is illegal"
            << std::endl;
  Firefighter fighter;
  std::cout << "Firefighter drive(): " << fighter.drive() << std::endl;
  std::cout << "fighter.Mailperson::drive(); // illegal" << std::endl;

}
void polymorphism_demo() {
 
  Person* jobUnknown = new Mailperson;
  Person* regular = new Mailperson;
  std::cout << "Person* jobUnkown = new Mailperson, jobUnkown->drive() : "
            << jobUnknown->drive() << "Polymorphism allows us to use Mailperson methods as a Person pointer object"
            << std::endl;  // will use person unless drive is a virtual function
  std::cout << "static_cast<Mailperson*>(regular)->drive(): "
            << static_cast<Mailperson*>(regular)->drive() << "We can also use Mailperson functions through static_cast"
            << std::endl;  // uses mailperson
}
void demonstrate_functions() {
  int num1 = 4;
  int num2 = 5;
  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;

  demonstrate_pass_by_value(num1, num2);  // call

  std::cout << "back in calling function" << std::endl;
  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;

  demonstrate_pass_by_ref(num1, num2);  // call

  std::cout << "back in calling function" << std::endl;
  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;

  demonstrate_pass_by_address(&num1, &num2);  // call

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
  *num1 = 8;
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

  std::cout << min(5, 6) << '\n';

  demonstrate_overloaded_functions();
  demoOverload();
  demoOverload(2);
  demoOverload(2, 1);
}

void demoOverload() {}

void demoOverload(int num1) {}

void demoOverload(int num1, int num2) {}
inline int min(int x, int y) { return x > y ? y : x; }

void demonstrate_default_parameters() {
  default_parameters("hello", 2);
  default_parameters("Good morning");  // will use default value (1)
  default_parameters("Hi", 1);         // can use the same as default
}

void default_parameters(std::string greet, int repeats) {
  for (int i = 0; i < repeats; i++) std::cout << greet << std::endl;
}

void demonstrate_inline_fuctions() {}

void demonstrate_overloaded_functions() {}

