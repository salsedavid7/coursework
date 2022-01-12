#include <iostream>
#include "header.h"
using namespace std;

void func1() {
    cout << "func1 called with void argument/return value\n";
    return;
}

char func2(char c) {
    cout << "func2 called with char argument/return value\n";
    return c;
}

int func3(int i) {
    cout << "func3 called with int argument/return value\n";
    return i;
}

float func4(float f){
    cout << "func4 called with char argument/return value\n";
    return f;
}