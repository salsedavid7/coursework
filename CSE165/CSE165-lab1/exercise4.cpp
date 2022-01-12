#include <iostream>
using namespace std;

int main (){
    //variable declaration
    int x, y;
    int limit;
    //user input
    cout << "set limit: ";
    cin >> limit;
    for(x = 2; x < limit; x++)
    { 
        for(y = 2; y <= (x / y); y++) 
            if (!(x % y))
                break; //not prime
        if(y > (x / y))
            cout << x << "\n"; //is prime
    }

    return 0; 
}
