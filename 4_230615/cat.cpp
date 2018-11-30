#include<iostream> 
#include<list> 
#include<stdlib.h>
#include <iostream> 
#include <string.h> 
#include <map>
#include <algorithm> 
#include <math.h>
#include <vector>
#include <set>
#include <bits/stdc++.h> 
#include <cmath>

#define modulo 1000000007;

using namespace std;

long long countDivisors(long long n) 
{ 
    long long cnt = 0; 
    for (long long i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            if (n / i == i) 
                cnt++; 
            else
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 

int main() {
    ios::sync_with_stdio(false);
    
    int b, n;
    cin >> b;
    cin >> n;

    //cout << countDivisors(19) << endl;
    long long result = 0;
    for (int i = 0; i < n; i++) {
        long long k;
        cin >> k;
        long long num = countDivisors(k);
        if (num == b) {
            result++;
        }
    }

    result = result % modulo;

    cout << result << endl;

    return 0;
}