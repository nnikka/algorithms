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

set< pair<int, int> > result;
pair<int, int> prs[10000100];

bool printDivisors(int n, int j) 
{ 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) {
                pair<int,int> pr;
                pr = make_pair(i, i);
                if (result.find(pr) == result.end()) {
                    result.insert(pr);
                    prs[j] = pr;
                    return true;
                }
            } else {

                pair<int,int> pr;
                pr = make_pair(i, n/i);
                if (result.find(pr) == result.end()) {
                    result.insert(pr);
                    prs[j] = pr;
                    return true;
                }

                pair<int,int> pr2;
                pr2 = make_pair(n/i, i);
                if (result.find(pr2) == result.end()) {
                    result.insert(pr2);
                    prs[j] = pr2;
                    return true;
                }
            } 
        } 
    } 
    return false;
} 
  

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (!printDivisors(k, i)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    // set< pair<int, int> >::iterator it;
    // for (it = result.begin(); it != result.end(); it++) {
    //     cout << it->first << " " << it->second << endl;
    // }
    for (int i = 0; i < n; i++) {
        cout << prs[i].first << " " << prs[i].second << endl;
    }

    return 0;
}

