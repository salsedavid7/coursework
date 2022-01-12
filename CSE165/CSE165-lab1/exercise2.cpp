#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    vector<string> v;
    ifstream in("exercise2.cpp");
    string line;
    while(getline(in, line))
        v.push_back(line); // Add the line to the end
    // Add line numbers:
    string b;
    for(int i = 0; i < v.size(); i++) {
        b += v[i]; //this is all i changed so that the string is concatenated
    }
    cout << b;

    
} 