#include<iostream> 
#include<list> 
#include<stdlib.h>
#include <iostream> 
#include <string.h> 
#include <map>
#include <algorithm> 
#include <bits/stdc++.h> 

using namespace std;

map< int, list<string> > mp;

bool isSubSequence(char str1[], char str2[], int m, int n) 
{ 
    if (m == 0) return true; 
    if (n == 0) return false; 
    if (str1[m-1] == str2[n-1]) 
        return isSubSequence(str1, str2, m-1, n-1); 
  
    return isSubSequence(str1, str2, m, n-1); 
} 

int calculateChain(int now, string cur, int result) {
    if (now > 26) {
        return result;
    }
    if (mp[now].empty()) {
        return result;
    }
    list<string>::iterator it;

    int maxResult = result;

    for (it = mp[now].begin(); it != mp[now].end(); ++it) {
        string stringhere = *it;
        char curArray[cur.length()+1];
        strcpy(curArray, cur.c_str());
        char stringhereArray[stringhere.length()+1];
        strcpy(stringhereArray, stringhere.c_str());

        int resultHere = result;
        if (isSubSequence(curArray, stringhereArray, cur.length(), stringhere.length())) {
            resultHere = calculateChain(now + 1, stringhere, result+1);
        }

        maxResult = maxResult > resultHere ? maxResult : resultHere;

    }

    return maxResult;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    for (int i = 0; i < 26; i++) {
        list<string> k;
        mp.insert(pair< int, list<string> >(i + 1, k));
    }

    int minLength = 27;

    for (int i = 0; i < T; i++) {
        string st;
        cin >> st;

        minLength = st.length() < minLength ? st.length() : minLength;
        sort(st.begin(), st.end());
        mp[st.length()].push_back(st);

    }

    int maxresult = 0;

    if (minLength < 27) {
        list<string>::iterator it;
        for (it = mp[minLength].begin(); it != mp[minLength].end(); ++it) {
            int result = 1;
            int curres = calculateChain(minLength + 1, *it, result);
            maxresult = maxresult > curres ? maxresult : curres;
        }
    } else {
        cout << 0 << endl;
        return 0;
    }

    cout << maxresult << endl;


    return 0;
}