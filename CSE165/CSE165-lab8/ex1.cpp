#include <iostream>

using namespace std;

class charArr {
public:
    charArr(char c = ' ') { 
        memset(arr, c, size); }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] <<  ' ';
        }
        cout << endl;
    }

private:
    enum {
        size = 15 };
    char arr[size];
};

int main() {
    charArr a('c');
    a.print();
    return 0;
}