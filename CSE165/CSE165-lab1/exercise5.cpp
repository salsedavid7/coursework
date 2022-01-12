#include <iostream>
using namespace std;

int main()
{
    string str;
    while(true) { //infinite while loop
        int n; //will be used to keep count for cases
        cin >> str; //user input
        if (str == "break")
            break;
        if (str == "alcohol")
            n = 1;
        else if (str == "steak")
            n = 2;
        else if (str == "italy")
            n = 3;
        else if (str == "table")
            n = 4;
        else if (str== "chair")
            n = 5;
        else if (str== "okay")
            n = 6;
        else
            n = 7;
        switch (n) {
        case 1:
            puts("-->make sure to always operate vehicles on this");
            break;
        case 2:
            puts("-->that sounds really good right now");
            break;
        case 3:
            puts("-->That is a nice place to go");
            break;
        case 4:
            puts("-->this is not an interesting word");
            break;
        case 5:
            puts("-->this is not an interesting word");
            break;
        case 6:
            puts("-->this is not an interesting word");
            break;
        default:
            puts("-->this is an unmapped word");
            break;
        }
    }
    return 0;
}