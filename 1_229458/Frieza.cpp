#include<iostream> 
#include <list> 

using namespace std; 

struct Path {
    int to;
    int from;
};
  
class Graph 
{ 
    int size;   
    Path *pathes;
    list<int> *adj; 
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int n, int m);   
    void addEdge(int v, int w, int number); 
    void deleteEdge(int number);
    void connectedComponents(); 
    void printGraph();
}; 

void Graph::printGraph() {
    for (int j = 0; j < size; j++) {
        list<int>::iterator i; 
        for(i = adj[j].begin(); i != adj[j].end(); ++i) {
            cout << j + 1 << " " << *i + 1 << endl;
        }
    }
}

void Graph::deleteEdge(int number)
{
    Path path = pathes[number];
    adj[path.from].remove(path.to);
    adj[path.to].remove(path.from);
}
  
void Graph::connectedComponents() 
{   
    int result = 0;
    bool *visited = new bool[size]; 
    for(int v = 0; v < size; v++) 
        visited[v] = false; 
  
    for (int v=0; v<size; v++) 
    { 
        if (visited[v] == false) 
        { 
            DFSUtil(v, visited); 
            result ++;
        } 
    } 
    cout << result << endl;
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    visited[v] = true; 
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
Graph::Graph(int n, int m) 
{ 
    this->size = n; 
    adj = new list<int>[n];
    pathes = new Path[m];
} 
  
void Graph::addEdge(int v, int w, int number) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v);
    Path path;
    path.from = v;
    path.to = w; 
    pathes[number] = path;
} 



int main() 
{  
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    cin >> m;

    Graph g(n, m);

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from;
        cin >> to;
        g.addEdge(from - 1, to - 1, i);
    }

   // g.connectedComponents();

    for (int i = 0; i < m; i++) {
        int number;
        cin >> number;
        g.deleteEdge(number - 1);
        // g.printGraph();
        g.connectedComponents();
    }

    return 0; 
} 
