#include <iostream>
 
using namespace std;

//int for function to change pointer to point to
int test = 50;

//int function with pointer parameter
int intFunc(int *a)
{
    a = &test; //modifies what the pointer is pointing to 
    return *a; //returns the destination of the pointer
}

int main() {
    int  temp  = 10   ;
    int* pTemp = &temp;

    //Displays starting values
    cout << "Starting int value   - " << temp << endl << "Starting int pointer - " << pTemp << endl;

    int newTemp = intFunc(pTemp);

    //displays changed values
    cout << "New int value        - " << newTemp << endl << "New int pointer      - " << &newTemp << endl;

    return 0;
}