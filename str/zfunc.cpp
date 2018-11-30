#include<iostream> 
#include<list> 
#include<stdlib.h>
#include <iostream> 
#include <string.h> 
#include <map>
#include <algorithm> 
#include <math.h>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            cout << "HERE" << endl;
            z[i] = min (r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) {
            cout << "THERE" << endl;
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    string a ="aaabaab";
    vector<int> s = z_function(a);
    vector<int>::iterator it;
    for (it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}