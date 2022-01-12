#include <iostream>
using namespace std;

int main() {
int number = 12;
int *pnumber = &number;
pnumber = 9;

cout << pnumber <<"\n"; 
}