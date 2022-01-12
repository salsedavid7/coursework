#include<iostream>
using namespace std;

int main() {
    string str = "stuff\nmore\rstuffs";
    int x = str.size();
    for(int i = 0; i < x; i++) {
        if(str[i] == 0x0d) {
            str.erase(str.begin() + i);
            x--;
        }
    }
    cout << "after removing 0x0d: "<< str <<"\n";
    return 0;
}