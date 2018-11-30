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

list<int> *adj;
int fromTo[100100];
bool visited[100100];
bool minuses[100100];
bool pluses[100100];
int num;
int startIndexes[100100];
int endIndexes[100100];

void DFS(int from, int to, set<int> & iterationResults) {
    visited[from] == true;
    iterationResults.insert(from);
    num += 1;
    startIndexes[from] = num;
    list<int>::iterator it;
    for (it = adj[from].begin(); it !=adj[from].end(); ++it) {
        if (to != *it) {
            DFS(*it, from, iterationResults);
        }
    }
    num += 1;
    // fromTo[from] = to;
    endIndexes[from] = num;
}

void DFSUtil(int size) {
    set<int> iterationResults;
    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            DFS(i, -1, iterationResults);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    int Q, N;
    cin >> N;
    cin >> Q;

    adj = new list<int>[N];
    memset(visited, false, sizeof(visited));
    memset(minuses, false, sizeof(minuses));
    memset(pluses, false, sizeof(pluses));

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num == -1) {
            minuses[i] = true;
        } else {
            pluses[i] = true;
            adj[num].push_back(i);
            visited[i] = true;
        }
    } 
    
    DFSUtil(N);

    // for (int i = 0; i < 15; i++) {
    //     cout << fromTo[i] << endl;
    // }

    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x;
        cin >> y;
        // cout << "----" << endl;
        if (x == y) {
            cout << "Yes" << endl;
        } else if (startIndexes[y] >= startIndexes[x] ) {
            cout << "No" << endl;
        } else if (endIndexes[x] >= endIndexes[y]) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }

    return 0;
}