#include <iostream>

using namespace std;

//class which will hold the array of ints
class array {
public:
    array() : value (1) {}
    static void printNum();
    inline void printArr();
private:
//size of array using static const int variable
    static const int arrSize = 10;
    static int num;
    const int value;
    int arr[arrSize] = {1,2,3,4,5,6,7,8,9,10};
};

int array::num = 2;

//here we will declare the static member func which will print the static member data
void array::printNum() {
    cout << "static int: " << num<< endl;
}

///inline member func which will call the static member func
void array::printArr() {
    cout << "array: ";

    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    printNum();
}

int main() {
    array a;
    a.printArr();
    return 0;
}