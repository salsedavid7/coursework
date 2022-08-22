#include<iostream>
using namespace std;
int num = 0;
void printmulSequence(int i, int j, int n, int *bracket)
{
   if (i == j) {
        cout << "A" << num; 
    num++;
    return;
   }

   cout << "(";
   printmulSequence(i, *((bracket+i*n)+j), n, bracket);
   printmulSequence(*((bracket+i*n)+j) + 1, j, n, bracket);
   cout << ")";
}

void matrixChainOrder(int p[], int n) {
   int m[n][n];
   int bracket[n][n];  
   for (int i = 1; i < n; i++)
       m[i][i] = 0;
   for (int len = 2; len < n; len++)
   {
       for (int i = 1; i<  n - len + 1; i++)
       {
           int j = i + len - 1;
           m[i][j] = INT_MAX;
           for (int k = i; k <= j - 1; k++)
           {
               int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
               if (q < m[i][j])
               {
                   m[i][j] = q;
                   bracket[i][j] = k;
               }
           }
       }
   }
//min # of scalar multiplation required
cout << m[1][n-1] << "\n";
//matrix mul sequence
printmulSequence(1, n-1, n, (int *)bracket);

}

int main() {
    int n;
    //# of matrices u want to multiply
    cin >> n;
    int a[n + 1]; 
    //dimension of matrix
    for(int i = 0;i <= n;i++){
        cin >> a[i];
    }
    int N = sizeof(a)/sizeof(a[0]); 
    matrixChainOrder(a, N);
    cout << "\n";
    return 0;
}

