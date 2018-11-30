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

int results[1000000];
int savedResults[27];
int savedResultsPos[27];

int main() {
    ios::sync_with_stdio(false);
    memset(savedResults, 0, sizeof(savedResults));
    memset(savedResultsPos, 0, sizeof(savedResultsPos));

    for (int i = 0; i < 1000000; i++) {
        int a = i / 100000;
        int b = (i - a * 100000) / 10000;
        int c = (i - a * 100000 - b * 10000) / 1000;
        int a1 = (i - a * 100000 - b * 10000 - c * 1000) / 100;
        int b1 = (i - a * 100000 - b * 10000 - c * 1000 - a1 * 100) / 10;
        int c1 = (i - a * 100000 - b * 10000 - c * 1000 - a1 * 100 - b1 * 10) / 1;
        int resultHere = abs((a + b + c) - (a1 + b1 + c1));

        int count = savedResults[resultHere];
        for (int j = savedResultsPos[resultHere]; j < i; j++) {
            int ja = j / 100000;
            int jb = (j - ja * 100000) / 10000;
            int jc = (j - ja * 100000 - jb * 10000) / 1000;
            int ja1 = (j - ja * 100000 - jb * 10000 - jc * 1000) / 100;
            int jb1 = (j - ja * 100000 - jb * 10000 - jc * 1000 - ja1 * 100) / 10;
            int jc1 = (j - ja * 100000 - jb * 10000 - jc * 1000 - ja1 * 100 - jb1 * 10) / 1;
            int jresultHere = abs((ja + jb + jc) - (ja1 + jb1 + jc1));
            if (jresultHere < resultHere) {
                count++;
            }
        }
        results[i] = count;
        savedResults[resultHere] = count;
        savedResultsPos[resultHere] = i; 
    }

    // for (int i = 0; i < 1001; i++) {
    //     cout << results[i] << endl;
    // }
    

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char a, b, c, a1, b1, c1;
        cin >> a;
        cin >> b;
        cin >> c;
        cin >> a1;
        cin >> b1;
        cin >> c1;
        // cout << a << endl;
        // cout << b << endl;
        // cout << c << endl;
        // cout << a1 << endl;
        // cout << b1 << endl;
        // cout << c1 << endl;
        int aint = a - '0';
        int bint = b - '0';
        int cint = c - '0';
        int a1int = a1 - '0';
        int b1int = b1 - '0';
        int c1int = c1 - '0';

        int index = aint * 100000 + bint * 10000 + cint * 1000 + a1int * 100 + b1int * 10 + c1int * 1;
        cout << results[index] << endl;
    }

    return 0;
}

// 000000
// 999000
// 453234
// 654331

// 1
// 0
// 998999
// 121496
// 470362