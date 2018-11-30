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
int tops[100100];
int bottoms[100100];
int iter;
// int visitedOnIteration[100100];

int DFS(int from,  set<int> & visitedOnIteration) {
    tops[from] = iter++;
    visited[from] = true;
    visitedOnIteration.insert(from);
    list<int>::iterator it;
    for (it = adj[from].begin(); it != adj[from].end(); ++it) {
        if (*it != -1) {
            if (!visited[*it]) {
                return DFS(*it, visitedOnIteration);
            } else {
                return fromTo[*it];
            }
        } else {
            return from;
        }
    }
    bottoms[from] = iter++;
    return from;
}

void DFSUtil(int size) {
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            set<int> visitedOnIteration;
            // cout << "----" << endl;
            int res = DFS(i, visitedOnIteration);
            // cout << res << endl;
            set<int>::iterator it;
            for (it = visitedOnIteration.begin(); it != visitedOnIteration.end(); ++it) {
                fromTo[*it] = res;
            }
        }
    }

    // set<int> visitedOnIteration;
    // int res = DFS(1, visitedOnIteration);
    // cout << res << endl;
    // set<int>::iterator it;
    // for (it = visitedOnIteration.begin(); it != visitedOnIteration.end(); ++it) {
    //     fromTo[*it] = res;
    // }

}

int main() {
    ios::sync_with_stdio(false);

    int Q, N;
    cin >> N;
    cin >> Q;

    adj = new list<int>[N];

    memset(minuses, false, sizeof(minuses));

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        adj[i].push_back(num);
        if (num == -1) {
            minuses[i] = true;
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
        if (minuses[x]) {
            if (x == y) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else if (fromTo[x] == fromTo[y]) {
            if (tops[x] < tops[y] && bottoms[x] < bottoms[y]) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}