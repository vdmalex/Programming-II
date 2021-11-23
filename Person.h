#pragma once
#include <string>
// creating classes allows us to reuse this code for more applications

// class: 				"category" or "genre"
//						"""
//						A class is an aggregate consisting of variables 						
//						(also called fields or properties) and functions (called methods).
//						Both variables and functions are class components.
//						"""
// Access specifiers:	private - accessible only within the class
//						public 	- accessible to all users of the class
//						A function that is a class component has full access to other class
//						components, including private ones. 						
//						protected - A function that is a class component has full access
//						to other class components, including private ones.
// Class constructors:	function name that is identical to class name
//						used to construct an object
//						no return type, not even void
//						Class object(param);
//						copy constructor: Class(Class const &sourceobject)
// Memory leaks:		unused (but still allocated) memory
//						grows in size, affecting system performance
// Destructors:			~Class()
//						only one destructor allowed
//						no paramaters
//						should not be invoked explicitly


class Person {

 private:
  
  int age = 0;             // default attributes
  std::string name = "0";  // private fields
  std::string dob = "0";
  // accessed by these methods
 public:
static int numberOfPeople;				// static: value will be shared and modified by objects
  Person() {  }
  // this pointer -- this->age = age of class = age from parameters
  Person(int age) { this->age = age; }  // constructor
  const int value = 10;					// const cannot be modified after setting
  void setAge(int age) { this->age = age; }		
  void setName(std::string name) { this->name = name; }
  void setDob(std::string dob) { this->dob = dob; }
  int getAge() { return age; }
  void walk();							// function prototypes				
  std::string drive();					
  virtual void print();					// virtual function may be overridden by subclasses
  ~Person() {}							// destructor
};

// example : class : animal subclasses : mammals,
//                                      reptiles,
//                                      birds
//
// object:			an instance of a class example : an object named myBird
// from class birds
//
// inheritance:		myBird would inherit all qualities of the
// superclass(animals),
//					and any other superclasses such as attributes
//and methods
//
// an object has :	name(myBird) may have properties such as color
//                  behaviors(methods)
//
//      from edube:
//      a noun, you probably define the object’s name
//      adjective, you probably define the object’s property
//		a verb, you probably define the object’s activity
