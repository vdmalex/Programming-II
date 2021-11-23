#pragma once

// an abstract class is a class that contians at least one pure virtual functions.
// the purpose of an abstract class is to be used as a base class for new classes
// that share common properties
// abstract classes cannot be instantiated because of their pure virutal functions
class MyAbstractClass {
  virtual ~MyAbstractClass() {}
	virtual void print() = 0;						// pure virutal function example
													// subclasses of the abstract will have to provide
													// definitions for such methods
};
