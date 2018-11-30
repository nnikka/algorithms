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
    long long n, m;
    cin >> n;
    cin >> m;

    long long x1, y1, x2, y2;

    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;

    long long result = 0;

    long long width = x2 - x1 + 1;
    long long height = y2 - y1 + 1;

    long long withoutFount = (m % 2) * (n - width);

    long long fountLeft = ((y1 - 1) % 2) * width;
    long long fountRight = ((m - y2) % 2) * width;

    result = withoutFount + fountLeft + fountRight;

    if (result % 2 == 1) {
        cout << result / 2 + 1 << endl;
    } else {
        cout << result / 2 << endl;
    }

    cout << result << endl;

    return 0;
}

