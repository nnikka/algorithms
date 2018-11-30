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

string res;

bool getnum(int n) {
    if (n == 0) {
        return true; 
    }
    if (n < 4) {
        return false;
    }

    if (getnum(n - 7)) {
        res += "7";
        return true;
    } else if (getnum(n - 4)) {
        res += "4";
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    if (!getnum(n)) {
        cout << -1 << endl;
    } else {
        string result = "";
        for (int i = 0; i < res.length(); i++) {
            if (res[i] == '4') {
                result += "4";
            }
        }
        int k = res.length() - result.length();
        for (int i = 0; i < k; i++) {
            result += "7";
        }
        cout << result << endl;
    }




    return 0;
}