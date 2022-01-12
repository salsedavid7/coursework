#include <iostream>
using namespace std;

int main(){
    //variable declaration
    int r;
    float pi = 3.14;
    //user input
    cout << "Enter the radius: ";
    cin >> r;
    //formula
    float area = pi * (r * r);
    //print
    cout << "Area =  " << area << "\n";

}