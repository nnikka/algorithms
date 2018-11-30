#include<iostream> 
#include<list> 
#include<stdlib.h>
#include <iostream> 
#include <string.h> 
#include <map>
#include <algorithm> 
#include <bits/stdc++.h> 

using namespace std; 

map<char, int> amap;
map<char, int> bmap;

int main() {
    string a;
    string b;   
    cin >> a;
    cin >> b;

    for(char i='a'; i < 'a' + 26; ++i) {
        amap[i] = 0;
        bmap[i] = 0;
    }
    for (int i = 0; i < a.length(); i++) {
        char c = a.at(i);
        amap[c]++;
    }
    for (int i = 0; i < b.length(); i++) {
        char c = b.at(i);
        bmap[c]++;
    }
    for(char i='a'; i < 'a' + 26; ++i) {
        if (bmap[i] > amap[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    sort(b.begin(), b.end());

    for (int i = 0; i <= (a.length() - b.length()); i++) {
        string asub = "";
        for (int j = 0; j < b.length(); j++) {
            asub += a.at(i + j);
        }
        sort(asub.begin(), asub.end());
        int result = 0;
        for  (int j = 0; j < b.length(); j++) {
            if (b.at(j) != asub.at(j)) {
                j = b.length();
            } else {
                result++;
            }
        }
        if (result == b.length()) {
            cout << "YES" << endl;
            return 0;
        } 
    }

    cout << "NO" << endl;

    return 0;
}