#include <iostream>
using namespace std;

int main() {
  int x, y;
  cout << "Enter amount of elements in array: ";
  cin >> x;
  int arr[x];

  for(y = 0; y < x; y++) {
    cout << "Enter value for element #" << y + 1 << ": ";
    cin >> arr[y];
  }
  int i, j;
  int list[x];
  list[0] = arr[0];

  for(int k = 2; k < x; k++) {
    j = arr[k];
    i = k - 1;

    while(list[i] > j && i > 0) {
      list[i + 1] = list[i];
      i = i - 1;
    }
    list[i + 1] = j;

    for(int a = 0; a <= k; a++) {
        cout << list[a] << ";";
    }
    cout << endl;
  }


}
