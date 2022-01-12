#include <iostream>

using namespace std;

class Subject {
public:
    virtual void f() { 
        cout << "Subject::f() called." << endl; }
    virtual void g() { 
        cout << "Subject::g() called." << endl; }
    virtual void h() { 
        cout << "Subject::h() called." << endl; }
};

class Proxy : public Subject {
public:
    Proxy(Subject* s) : Subject(), sPtr(s) {}
    void f() { 
        sPtr->f(); }
    void g() { 
        sPtr->g(); }
    void h() { 
        sPtr->h(); }
    void setImplementation(Subject* s) { 
        sPtr = s; }
private:
    Subject* sPtr;
};

class imp1 : public Subject {
public:
    void f() { 
        cout << "Implementation1::f() called." << endl; }
    void g() { 
        cout << "Implementation1::g() called." << endl; }
    void h() { 
        cout << "Implementation1::h() called." << endl; }
};

class imp2 : public Subject {
public:
    void f() { 
        cout << "Implementation2::f() called." << endl; }
    void g() { 
        cout << "Implementation2::g() called." << endl; }
    void h() { 
        cout << "Implementation2::h() called." << endl; }
};



int main() {

    imp1 i1;
    imp2 i2;

    Proxy p(&i1);

    p.f(); p.g(); p.h();

    p.setImplementation(&i2);
    cout << "Implementation changed." << endl;

    p.f(); p.g(); p.h();

return 0;
}