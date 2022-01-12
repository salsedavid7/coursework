#include <iostream>
#include <stack>
using namespace std;

int main() {
    int num;
    cout << "Enter num of fibonacci elements: ";
    cin >> num;
    int size = num;
    int x = 0, y = 1;
//stack declaration to build fib sequence
    stack<int> s;
    s.push(0);
    s.push(1);

    while(num > 0){
        int z = x + y;
        s.push(z);
        x = y;
        y = z;
        num--;
    }

    cout<<"Fibonacci Sequence : \n";
    int arr[50];
    int i = 0;
//storing elements in stack in array until stack is empty
    while(!s.empty()){
        arr[i] = s.top();
        s.pop();
        i++;
        num--;
    }
//prints array in reverse order so we get correct fib sequence
    for(int i = size + 1; i >= 0; i--){
        cout << arr[i] << " "; 
    }

    return 0;
}