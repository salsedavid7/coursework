#include <iostream>

using namespace std;

//Base class X
class X {
    int num;
    public:
    X(int num){
        this->num=num;
    };
    
    void f(){
        cout << "test: f() called. num value: " << num << endl;
    }
};

//Inherit X into Y
class Y: X {
    public:
    Y(int num):X(num){}

    void f() {
        X::f();
    }
};

//Inherit X into Z
class Z: X {
    public:
    Z(int num):X(num){

    }
    
    void f() {
        X::f();
    }
};

//Multiple inherit Y and Z into A
class A: Y, Z{
    public:
    A(int num):Y(num),Z(num){
        
    }
    
    void f(){
        Y::f();
    }
};

int main(){
    A a = A(10);
    a.f();

    return 0;
}