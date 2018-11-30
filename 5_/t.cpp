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

using namespace std;

int main() {
    long long a, b, x, y;
    cin >> a;
    cin >> b;
    cin >> x;
    cin >> y;

    long long result = 0;
    long long gcd = __gcd (x, y);
    result = min(b / (y / gcd), a / (x / gcd));
    cout << result << endl;

    return 0;
}

