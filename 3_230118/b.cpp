#include<iostream> 
#include<list> 
#include<stdlib.h>
#include <iostream> 
#include <string.h> 
#include <map>
#include <algorithm> 
#include <math.h>
#include<bits/stdc++.h> 

using namespace std; 

#define maxn 1000000007

long long power(long long x, long long y) 
{ 
    long long res = 1;  
  
    x = x % maxn;   
  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % maxn; 

        y = y>>1; 
        x = (x*x) % maxn;   
    } 
    return res; 
}

int main() {
    ios::sync_with_stdio(false);
    long long n, m, c;
    cin >> n;
    cin >> m;
    cin >> c;

    long long N = power(c, n * n);

    long long answer = 0;

    for (long long i = 0; i < m; i++) {
        long long powern = __gcd(i, m);
        answer += power(N, powern);
        answer %= maxn;
    }

    answer = answer  * power(m, maxn - 2);

    answer %= maxn;

    cout << answer << endl;

    return 0;
}
