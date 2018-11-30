#include<iostream> 
#include <list> 

using namespace std; 

int solutions[300000];
int opponents[300000];

int max (int a, int b) 
{
    return a > b ? a : b;
}

int main() 
{  
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++) {
        cin >> opponents[i];
    }

    for (int i = m; i < n; i++) {
        solutions[i] = max(opponents[i] + solutions[i - m], solutions[i - 1]);
    }

    cout << solutions[n - 1] << endl;

    return 0;
} 
