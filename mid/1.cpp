#include<iostream> 
#include<list> 
#include<stdlib.h>
#include <iostream> 
#include <string.h> 
#include <map>
#include <algorithm> 
#include <bits/stdc++.h> 

using namespace std; 

class Graph 
{
    int V;
    list<int> * adj;
    void DFSUtil(int ititial, int v, bool visited[], int & result);

  public:
  
    Graph(int v);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int v) {
    this->V = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFSUtil(int ititial, int v, bool visited[], int & result) {
    visited[v] = true;
    if (ititial != v) {
        result++;
    }
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(ititial, *i, visited, result);
        }
    }
}

void Graph::DFS(int v) {
    bool * visited = new bool[V];
    memset(visited, false, sizeof(visited));
    int result = 0;
    DFSUtil(v, v, visited, result);
    cout << result << " ";
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n, m;
        cin >> n;
        cin >> m;  
        Graph g(n);
        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a;
            cin >> b;
            g.addEdge(a - 1, b - 1);
        }
        cout << "Case #" << i + 1 << ":" << endl;
        int arr[n];
        for (int j = 0; j < n; j++) {
            g.DFS(j);
        }
        cout << endl;
    }
    return 0;
}

