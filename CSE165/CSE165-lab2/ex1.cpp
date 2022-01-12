#include <iostream>
#include <string>
using namespace std;

//Creating structure
typedef struct
{
    int sid;
    string name;
    string major;
} Student;

int main() {
    //Creating instance of struct Student
    Student me;
    me.sid   = 100311749         ;
    me.name  = "David Salse"   ;
    me.major = "Computer Science";

    cout << "Original Values: \n----------------"<< "\nStudent ID: " << me.sid << "\nName : " << me.name << "\nMajor: " << me.major << "\n" << endl;

    //Assigning address 
    Student* ptr = &me; 

    //Changing values of struct using pointer 
    (*ptr).sid   = 999999999 ;
    (*ptr).name  = "New Name";
    (*ptr).major = "English" ;

    //Printing out new values of struct
    cout << "New Values: \n----------------" << " \nStudent ID: " << me.sid << "\nName : " << me.name << "\nMajor: " << me.major << endl;
}