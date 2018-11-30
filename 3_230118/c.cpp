#include<iostream> 
#include<list> 
#include<stdlib.h>

using namespace std; 

int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
  
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
}


int main() {
    int x;
    cin >> x;
    int n, m, t;
    cin >> n;
    cin >> m;
    cin >> t;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a;
        cin >> b;
    }

    for (int i = 0; i < n; i++) {
        int t, p;
        cin >> t;
        cin >> p;

    }

    for (int i = 0; i < n; i++) {

    }

    return 0;
}
  
