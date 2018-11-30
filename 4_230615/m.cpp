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

using namespace std;

#define max 1000000000000000000

map< long long, int > likesMap;
set< long long, greater<long long> > likes;
set< long long, greater<long long> > hates;



int inLikes = 0;
int inHates = 0;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int indicate;
        cin >> indicate;
        int s;
        cin >> s;

        if (indicate == 1) {
            for (int i = 0; i < s; i++) {
                long long longinteger;
                cin >> longinteger;

                if (inLikes == 0) {
                    if (hates.find(longinteger) == hates.end()) {
                        likes.insert(longinteger);
                        likesMap[longinteger]++;
                    }
                } else {
                    if (hates.find(longinteger) == hates.end()) {
                        if (likes.find(longinteger) != likes.end()) {
                            likes.insert(longinteger);
                            likesMap[longinteger]++;
                        }
                    }
                }
                
            }
            inLikes++;
        } else {
            for (int i = 0; i < s; i++) {
                long long longinteger;
                cin >> longinteger;
                hates.insert(longinteger);
                if (likes.find(longinteger) != likes.end()) {
                    likes.erase(longinteger);
                    likesMap[longinteger] = -1;
                }
            }
            inHates++;
        }
    }

    // cout << "----" << endl;

    // set< long long, greater <long long> >::iterator it;

    // for (it = likes.begin(); it != likes.end(); ++it) {
    //     cout << *it << endl;
    // }

    // cout << "-----" << endl;

    // for (it = hates.begin(); it != hates.end(); ++it) {
    //     cout << *it << endl;
    // }
    if (inHates == 0) {
        if (inLikes == 0) {
            cout << 0 << endl;
        } else {
            int result = 0;
            map< long long, int >::iterator it;
            for (it = likesMap.begin(); it != likesMap.end(); ++it) {
                if (it->second == inLikes) {
                    result ++;
                }
            }
            cout << result << endl;
        }
    } else {
        if (inLikes == 0) {
            cout << max - hates.size() << endl;
        } else {
            int result = 0;
            map< long long, int >::iterator it;
            for (it = likesMap.begin(); it != likesMap.end(); ++it) {
                if (it->second == inLikes) {
                    result ++;
                }
            }
            cout << result << endl;
        }
    }
   
    return 0;
}