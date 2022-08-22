#include<iostream>
#include<limits.h>
using namespace std;

int main()
{
   int n;
   cin >> n;
   int revenue[n];
   int x, y;
   for(x = 0;x < n;x++)
   {
       cin >> revenue[x];
   }
   int dp[n + 1];
   dp[0] = 0;
   int ind[n + 1];

   for(x = 1;x <= n;x++)
   {
       int mx = INT_MIN;
       for (y = 1; y <= x; y++)
       {
        if(mx < revenue[y - 1] + dp[x - y])
        {
            mx = revenue[y - 1] + dp[x - y];
            ind[x] = y;
        }
       }
       dp[x] = mx;
   }
   cout << dp[n] << "\n";

   while(n > 0)
   {
       cout << ind[n] << " ";
       n = n - ind[n];
   }
   cout<<"-1\n";
}