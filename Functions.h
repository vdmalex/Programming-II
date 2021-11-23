#pragma once
#include <iostream>
#include <string>

void demoStaticAuto();                                  // function definition in main

// functions and variables can be accessed by the scope resolution operator
// ::
// example: MyNamespace::function();



namespace Functions {
void demonstrate_functions();							// function prototypes go within the namespace (if needed)
void demonstrate_pass_by_value(int, int);               // returnType functionName(parameters)
void demonstrate_pass_by_ref(int&, int&);
void demonstrate_pass_by_address(int*, int*);			// name not required, only time
void demonstrate_more_fuction_stuff();
void demonstrate_default_parameters();
void demoOverload();
void demoOverload(int num1);
void demoOverload(int num1, int num2);					// can give name
inline int inlinemin(int x, int y);
void default_parameters(std::string,
                                   int repeats = 1);	// default parameter = 1
void demonstrate_inline_fuctions();	
void demonstrate_overloaded_functions();
void demonstrate_default_parameters();
	void demonstrate_functions() {
  int num1 = 4;
  int num2 = 5;
  std::cout << "num1 is " << num1 << std::endl;
  std::cout << "num2 is " << num2 << std::endl;

  demonstrate_pass_by_value(num1, num2);                // call -> function(arguments)
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
  std::cout << inlinemin(5, 6) << '\n';
  std::cout
      << "compiler creates: return 5 > 6 ? 6 : 5\n in place of min(5,6);\n";
  // std::cout << return 5 > 6 ? 6 : 5; << '\n';

  std::cout << inlinemin(5, 6) << '\n';

  demonstrate_overloaded_functions();
  // we can call the same named function with a different number or type of
  // arguments which results in different behaviors
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

inline int inlinemin(int x, int y) { return x > y ? y : x; }

void default_parameters(std::string greet,
                        int repeats) {  // in the prototype, we declared repeats
                                        // = 1, if a value is not given for
                                        // repeats, it is defaulted to 1
  for (int i = 0; i < repeats; i++) std::cout << greet << std::endl;
}
}