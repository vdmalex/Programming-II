#pragma once
#include <string>
class Person {
 //private:
 public:

	int age=0;
	std::string name="0";
	std::string dob="0";

       //public:
		/*void setAge(int age) { this->age = age;}
        void setName(std::string name) { this->name = name; }
        void setDob(std::string dob) { this->dob = dob; }
        int getAge()*/


	void walk() { age++; }
       virtual std::string drive() { return "normal"; }









};
