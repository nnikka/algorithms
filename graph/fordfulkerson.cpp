// C++ program for implementation of Ford Fulkerson algorithm 
#include <iostream> 
#include <limits.h> 
#include <string.h> 
#include <queue> 
using namespace std; 
  
#define V 6 
  

bool bfs(int rGraph[V][V], int s, int t, int parent[]) 
{ 
   bool visited[V];
   memset(visited, 0, sizeof(visited));

   queue<int> q;
   q.push(s);
   visited[s] = true;
   parent[s] = -1;

   while (!q.empty()) {
       int cur = q.front();
       q.pop();
       for (int i = 0; i < V; i++) {
           if (rGraph[cur][i] > 0 && visited[i] == false) {
               q.push(i);
               parent[i] = cur;
               visited[i] = true;
           }
       }
   }

   return (visited[t] == true);
} 
  
int fordFulkerson(int graph[V][V], int s, int t) 
{ 
    int rGraph[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            rGraph[i][j] = graph[i][j];
        }
    }

    int parent[V];
    
    int maxFlow = 0;

    while (bfs(rGraph, s, t, parent)) {

        int pathFlow = INT_MAX;
        for (int i = t; i != s; i = parent[i]) {
            int parentOfi = parent[i];
            pathFlow = min(pathFlow, rGraph[parentOfi][i]);
        }

        for (int i = t; i != s; i = parent[i]) {
            int parentOfi = parent[i];
            rGraph[parentOfi][i] -= pathFlow;
            rGraph[i][parentOfi] += pathFlow;
        }

        maxFlow += pathFlow;

    }

    return maxFlow;
} 
  
int main() 
{ 
    int graph[V][V] = { {0, 16, 13, 0, 0, 0}, 
                        {0, 0, 10, 12, 0, 0}, 
                        {0, 4, 0, 0, 14, 0}, 
                        {0, 0, 9, 0, 0, 20}, 
                        {0, 0, 0, 7, 0, 4}, 
                        {0, 0, 0, 0, 0, 0} 
                      }; 
  
     cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5) << endl; 
  
    return 0; 
} 