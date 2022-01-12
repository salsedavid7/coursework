#include <iostream>
#include <cassert>
//function which will return the next value in a fibonacci sequence every time you call it
int fib(bool reset = false) {
    static int firstNum = 0;
    static int secondNum = 1;
    static int count = 0;
    
    if (reset) {
        //Start over
        firstNum = count = 0;
        secondNum = 1;
    }
    
    int result;
    if (count == 0) {
        assert(firstNum == 0 && secondNum == 1);
        result = 0;
    }
    else if (count == 1) {
        assert(firstNum == 0 && secondNum == 1);
        result = 1;
    }
    else {
        result = firstNum + secondNum;
        firstNum = secondNum;
        secondNum = result;
    }
    ++count;    
    
    return result;
}

int main() {
    using namespace std;
    
    // Print first 10
    for (int i = 0; i < 10; ++i)
        cout << fib() << ' ';
    cout << endl;
        
    // print first 5
    cout << fib(true) << ' ';
    for (int j = 1; j < 5; ++j)
        cout << fib() << ' ';
    cout << endl;
}