#pragma once

// an interface is a class that only contians pure virtual functions.
// the purpose of an interface is to be used as a base class for new classes
// that share common properties
// interfaces cannot be instantiated because of their pure virutal functions
class MyInterface {
	virtual ~MyInterface() {}
	virtual void print() = 0;		// pure virutal function example
									// subclasses of the interface will have definitions for such methods
};
