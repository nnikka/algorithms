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

string input;

int main () {
    long long N;
    long long x1, x2, y1, y2;
    cin >> N;
    cin >> x1;
    cin >> x2;
    cin >> y1;
    cin >> y2;

    long long result = 0;

    long long lefts = abs(y1 - x1);
    long long rights = abs(y2 - x2);

    // cout << lefts << endl;
    // cout << rights << endl;

    long long min = lefts + rights;

    // cout << min << endl;

    if (min == 0) {
        cout << N / 2 << endl;
    } else if (min > N) {
        cout << 0 << endl;
    } else {
        result = (N - min) / 2 + 1;
        cout << result << endl;
    }

}