#include <iostream>

using namespace std;

char* charFunc(char* charArg) {
    int size = 0; 
    //Finding length of char array
    while(charArg[size] != '\0') {
        size = size + 1; //increase the size of the char array by one
    }
    size++; //increase by one at the end to account for the return character
    char* newArr = new char[size]; //dynamically creating new char array 
    //Copies old array to new one
    for(int i = 0;i < size;i++) {
        newArr[i] = charArg[i]; //Assigning values from the old array to the same indeces in the new one
    }
    return newArr; //Returning the new, copied char array pointer
}

int main() {
    char arr[] = "David Salse"; //Static quoted char array
    char* test = charFunc(arr)  ; //Passing char array to function

    cout << test << endl; //Printing out copied version of char

    delete[] test; //This cleans up dynamic storage with delete
}