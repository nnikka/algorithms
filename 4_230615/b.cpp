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

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    int n;
    cin >> n;
    cin >> input;

    input = input + input;

    vector<int> v = z_function(input);

    // vector<int>::iterator it;
    // for (it = v.begin(); it != v.end(); ++it) {
    //     cout << * it;
    // }
    // cout << endl;
    
    for (int i = 1; i <= n - 1; i++) {
        if (v[i] == 0) {
            if (input[0] > input[i]) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if (v[i] + i < 2 * n) {
                if (input[v[i]] > input[i + v[i]]) {
                    // cout << v[i] << endl;
                    // cout << i << endl;
                    // cout << input[v[i]] << endl;
                    // cout << input[i + v[i]] << endl;
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }   
    cout << "Yes" << endl;
    return 0;
}