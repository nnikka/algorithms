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

string name;
int maxNumber;

int main() {
    int n;
    cin >> n;

    name = "";
    maxNumber = -32767;

    for (int i = 0; i < n; i++) {
        string namehere;
        int n1n, n2n, n3n, n4n, n5n, n6n, n7n;
        cin >> namehere;
        cin >> n1n;
        cin >> n2n;
        cin >> n3n;
        cin >> n4n;
        cin >> n5n;
        cin >> n6n;
        cin >> n7n;

        int result = n1n * 100 + (-1) * n2n * 50 + n3n + n4n + n5n + n6n + n7n;

        if (result > maxNumber) {
            maxNumber = result;
            name = namehere;
        }

    }

    cout << name << endl;
   
    return 0;
}

// #include<iostream> 
// #include<list> 
// #include<stdlib.h>
// #include <iostream> 
// #include <string.h> 
// #include <map>
// #include <algorithm> 
// #include <math.h>
// #include <vector>
// #include <set>
// #include <bits/stdc++.h> 
// #include <cmath>

// using namespace std;

// list<int> *adj;
// bool visited[100100];

// int num;
// int startIndexes[100100];
// int endIndexes[100100];

// void DFS(int from, int to) {
//     startIndexes[from] = num++;
//     visited[from] == true;

//     list<int>::iterator it;
//     for (it = adj[from].begin(); it !=adj[from].end(); ++it) {
//         if (to != *it) {
//             DFS(*it, from);
//         }
//     }

//     endIndexes[from] = num++;
// }

// void DFSUtil(int size) {
//     for (int i = 0; i < size; i++) {
//         if (!visited[i]) {
//             DFS(i, -1);
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);

//     int Q, N;
//     cin >> N;
//     cin >> Q;

//     adj = new list<int>[N];
//     memset(visited, false, sizeof(visited));

//     for (int i = 0; i < N; i++) {
//         int num;
//         cin >> num;
//         if (num == -1) {

//         } else {
//             adj[num].push_back(i);
//             visited[i] = true;
//         }
//     } 
    
//     DFSUtil(N);

//     // for (int i = 0; i < 15; i++) {
//     //     cout << fromTo[i] << endl;
//     // }

//     for (int i = 0; i < Q; i++) {
//         int x, y;
//         cin >> x;
//         cin >> y;
//         if (x == y || (startIndexes[y] < startIndexes[x] && endIndexes[x] < endIndexes[y])) {
//             cout << "Yes" << endl;
//         } else {
//             cout << "No" << endl;
//         }
//     }

//     return 0;
// }