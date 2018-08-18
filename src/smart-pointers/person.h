#ifndef PERSON_H
#define PERSON_H

#include <string>
using std::string;

class Person
{
public:
	Person(const string& name, unsigned int age):
	  _name(name),
	  _age(age)
	  {}

	// The copy constructor and assignment operator and destructor are not needed
	//  -- the compiler-generated versions work fine

	string name() const { return _name; }
	void name(const string& newname) { _name = newname; }
	unsigned int age() const { return _age; }
	void age(unsigned int new_age) { _age = new_age; }

private:
	string _name;
	unsigned int _age;
};

#endif
