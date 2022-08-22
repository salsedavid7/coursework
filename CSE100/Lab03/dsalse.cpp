#include <iostream>
using namespace std;

int max(int a, int b) {
   return (a > b)? a : b;
}

int max(int a, int b, int c) {
   return max(max(a, b), c);
}

int maxCrossingSum(int arr[], int l, int m, int h) {
   int sum = 0;
   int left = INT_MIN;

   for (int i = m; i >= l; i--) {
      sum = sum + arr[i];
      if (sum > left)
         left = sum;
   }

   sum = 0;
   int right = INT_MIN;

   for (int i = m + 1; i <= h; i++) {
      sum = sum + arr[i];
      if (sum > right)
      right = sum;
   }
   return left + right;
}

int maxSubArraySum(int arr[], int low, int high) {
   if (low == high)
   return arr[low];
   int mid = (low + high) / 2;
   return max(maxSubArraySum(arr, low, mid), maxSubArraySum(arr, mid+1, high), maxCrossingSum(arr, low, mid, high));
}

int main() {
   int x, y;
   cin >> x;
   int arr[x];
   for(y = 0; y < x; y++) {
    cin >> arr[y];
  }
   int n = sizeof(arr) / sizeof(arr[0]);
   int max_sum = maxSubArraySum(arr, 0, n - 1);
   cout << max_sum;
   cout << endl;
}