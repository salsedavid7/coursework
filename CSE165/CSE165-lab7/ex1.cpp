#include <iostream>

using namespace std;
//func will return next value in array until it see -1
int func(const int* intArray = 0) {
    //Creating static variable
    static const int* staticInt;
    //Return next value 
    if(intArray) {
        staticInt = intArray;
        return *staticInt;
    }
    else{
        //If next value is -1, func has reached the end-of-array indicator
        if(*staticInt == -1){
            return 0;
        }
    }
    return *staticInt++;
}
//arr which will contain -1 and arbitrary values
int arr[] = {1, 2, 3, 4, 5, 6, -1, 8, 9};

int main() {
    //Calling function with value
    func(arr);

    int s;
    //Calling func to return next value in array
    while((s = func()) != 0)
        cout << s << endl;
    return 0;
}