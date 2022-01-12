#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#define S(x) #x
#define S_(x) S(x)
#define S__LINE__ S_(__LINE__)

using namespace std;

class MyClass {
public:
    MyClass() { 
    }
    ~MyClass() { 
    }
    void* operator new(size_t sz, string arg) {
        calls.push_back(arg);
        void* m = malloc(sz);
        return m;
    }

    static void print() {
        for(int i = 0; i < calls.size(); i++){
            cout << calls[i] << endl;
        }
    }

private:
    static vector<string> calls;
};

vector<string> MyClass::calls;

int main() {

    MyClass* a = new(__FILE__) MyClass;
    MyClass* b = new(S__LINE__) MyClass;
    MyClass* c = new("test argument") MyClass;

    MyClass::print();

    delete c;
    delete b;
    delete a;

return 0;
}