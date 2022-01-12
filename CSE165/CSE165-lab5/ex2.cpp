/*
copy pasting addingvirtuals.cpp from textbook but making all member functions of "pet" pure virtual 
and provide a definiton for name. must fix dog using base class def of name
*/
#include <iostream>
#include <string>

using namespace std;

class Pet {
  string pname;
public:
  Pet(const string& petName) : pname(petName) {}
  virtual string name() = 0;
  virtual string speak() = 0;
};

string Pet::name() { 
    return pname; 
    }

class Dog : public Pet {
public:
  Dog(const string& petName) : Pet(petName) {}

  virtual string sit() { 
      return Pet::name() + " sits"; }
  string speak() { 
      return Pet::name() + " says 'woof!'"; }
  string name() { 
      return Pet::name(); }
};

int main() {
    Pet* p = new Dog("bill");
    cout << p->speak();
    delete p;
}