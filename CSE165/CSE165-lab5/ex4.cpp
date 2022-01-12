#include <iostream>
#include <algorithm>

using namespace std;

class test {
public:
    test() : i(0), d(0), c('-') {}
    test(int ii, double dd, char cc) : i(ii), d(dd), c(cc) {}
    virtual void f() { cout << "test::f()" << endl; }

    int getInt() const { 
        return i; 
        }
    double getDouble() const { 
        return d; 
        }
    char getChar() const { 
        return c; 
        }
private:
    int i;
    double d;
    char c;
};
//looks at memory in test and prints out pieces of it.
void print(test& t) {
    int offset_int = 0, offset_dub = 0, offset_char = 0;

    size_t size = sizeof(t);
    unsigned char* data = new unsigned char[size];
    const char* const cPtr = reinterpret_cast<char*>(&t);

    fill(data, data + size, 0);
    copy(cPtr, cPtr + size, data);

    for (size_t i = 0; i < size; i++) {

        if ( *(int*)(data + i) == t.getInt() ) {
            offset_int = i;
            cout << "Int found, Offset: " << offset_int <<  ", value: " << *(int*)(data + offset_int) << endl;
        }

        if ( *(double*)(data + i) == t.getDouble() ) {
            offset_dub = i;
            cout << "Double found, Offset: " << offset_dub <<  ", value: " << *(double*)(data + offset_dub) << endl;
        }

        if ( *(char*)(data + i) == t.getChar() ) {
            offset_char = i;
            cout << "Char found, Offset: " << offset_char <<  ", value: " << *(char*)(data + offset_char) << endl;
        }

    }
}

int main() {
    test t(999, 3.14, 'a');
    print(t);
return 0;
}