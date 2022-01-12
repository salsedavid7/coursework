#include <iostream>
//importing c time for clock func
#include <ctime>

using namespace std;

class Base {
public:
    //declaring one virtual and one non virtual func
    virtual void virt() const { 
        char c[100]; }
    void non() const { 
        char c[100]; }
    virtual ~Base(){}
};

class Derived : public Base {};

int main() {
    //arbitrary val
    int x = 1000000;
    Base*  ptr = new Derived;
    //clock func
    clock_t t0 = clock();
    //printing virtual calls
    cout << "Virtual calls: ";

    for (size_t i = 0; i < x; i++)
        ptr->virt();

    clock_t t1 = clock();
    cout << (double)(t1 - t0) / CLOCKS_PER_SEC  << endl;

    t0 = clock();
    //printing non-virtual calls
    cout << "Non-virtual calls: ";

    for (size_t i = 0; i < x; i++)
        ptr->non();

    t1 = clock();
    cout << (double)(t1 - t0) / CLOCKS_PER_SEC  << endl;

return 0;
}