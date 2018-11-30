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

set<long long> sizesAvailabe;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long size;
        cin >> size;
        while (sizesAvailabe.find(size) != sizesAvailabe.end()) {
            sizesAvailabe.erase(size);
            size += size;
        }
        sizesAvailabe.insert(size);
    }

    int size = sizesAvailabe.size();

    set<long long>::iterator it;
    for(it = sizesAvailabe.begin(); it != sizesAvailabe.end(); ++it) {
        cout << *it << endl;
    }

    if (size == 1) {
        cout << -1 << endl;
    } else {
        cout << size << endl;
    }

    return 0;
}