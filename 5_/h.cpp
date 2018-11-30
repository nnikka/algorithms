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
    int n;
    cin >> n;

    int indexes[n];

    for (int i = 0; i < n; i++) {
        cin >> indexes[i];
    }

    sort(indexes, indexes + n);

    int lastResult = indexes[0];
    int result = 0;
    for (int i = 1; i < n; i++) {
        result += indexes[i] - lastResult - 1;
        lastResult = indexes[i];
    }

    cout << result << endl;

    return 0;
}