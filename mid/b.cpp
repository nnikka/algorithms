#include<iostream> 
#include<list> 
#include<stdlib.h>
#include <iostream> 
#include <string.h> 
#include <map>
#include <algorithm> 
#include <bits/stdc++.h> 

using namespace std; 

int Asubar[26];
int Bar[26];

int main() {
    ios::sync_with_stdio(false);
    string a;
    string b;   
    cin >> a;
    cin >> b;

    if (b.length() > a.length()) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < b.length(); i++) {
        char ch = b.at(i);
        int index = ch - 'a';
        Bar[index]++;
        char ach = a.at(i);
        index = ach - 'a';
        Asubar[index]++;
    }

    int match = 0;

    for (int i = 0; i < (a.length() - b.length() + 1); i++) {
        match = 0;
        if (i != 0) {
            char aprevch = a.at(i - 1);
            int index = aprevch - 'a';
            Asubar[index]--;

            char curChar =a.at(i + b.length()-1);
            index = curChar - 'a';
            Asubar[index]++;
        }
        for (int j = 0; j < 26; j++) {
            if (Asubar[j] == Bar[j]) {
                match++;
            }
        }
        if (match == 26) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}