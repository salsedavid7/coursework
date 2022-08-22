#include <iostream>
#include<vector>
#define LEN 10
using namespace std;

int main(){
    int n = 0;
    vector< vector<int> > toSort(n, vector<int>(LEN));
    vector<int> tempVec;

    cin >> n;

    int i = 0, j = 0;
    for(i = 0; i < n; i++) {
        int temp = 0;
        tempVec.clear();
        for(j = 0; j < LEN; j++) {
            cin >> temp;
            tempVec.push_back(temp);
        }
        toSort.push_back(tempVec);
    }

    tempVec.clear();
    int min = 0;
    for(i = LEN - 1 ; i >= 0; i--) {
        for(j = 0; j < n; j++) {
        min = j;
        for(int k = j; k < n; k++) {
            if(toSort[k][i] < toSort[min][i])
            min = k;
    }

        if(min != j){
            tempVec = toSort[j];
            toSort[j] = toSort[min];
            toSort[min] = tempVec;
        }
        }
    } 

    cout << endl;
    for(i = 0; i < n; i++) {
        for(j = 0; j < LEN; j++) {
        cout << toSort[i][j] << ';';
    }
    cout << endl;
    }
    return 0;
}