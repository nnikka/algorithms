#include<iostream> 
#include<list> 
#include<stdlib.h>
#include <iostream> 
#include <string.h> 
#include <map>
#include <algorithm> 
#include <bits/stdc++.h> 

using namespace std; 

int initArr[100100];
int BITree[100100];
int size = 100100;

int getSum(int index) 
{ 
    if (index < 0) {
        return 0;
    }
    int sum = 0;  
    index = index + 1; 
    while (index>0) 
    { 
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 

void updateBIT(int index, int val) 
{ 
    index = index + 1; 
    while (index <= size) 
    { 
        BITree[index] += val; 
        index += index & (-index); 
    } 
} 
  
int main() 
{ 
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        updateBIT(i, val);
        initArr[i] = val;
    }

    for (int j = 0; j < m; j++) {
        int t, x, y;
        cin >> t;
        cin >> x;
        cin >> y;
        
        if (t == 0) {
            updateBIT(x - 1, y);
        } else {
            int cut = 0;
            if (x == y) {
                cut = initArr[x - 1];
            } else {
                int sumx = getSum(x - 2);
                int sumy = getSum(y - 1);
                cut = sumy - sumx;
            }
            if (cut % 3 == 0) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }

    }
  
    return 0; 
} 