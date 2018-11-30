#include<iostream> 
#include <list> 
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>

using namespace std; 

map<string, int> stateToInt;

struct Path {
    int from;
    int to;
};

class Graph 
{   
    int size;   
    list<int> * adj;
    bool DFSUtil(int from, int to, bool visited[]);
public: 
    Graph(int size);   
    void addEdge(int from, int to);
    bool DFS(int from, int to, int nodes);
}; 

Graph::Graph(int size) {
    this->size = size;
    adj = new list<int>[size];
}

void Graph::addEdge(int from, int to) {
    adj[from].push_back(to);
}

bool Graph::DFSUtil(int from, int to, bool visited[]) {

    stack<int> st;

    st.push(from);

    while(!st.empty()) {
        int pop = st.top();
        st.pop();
        if (!visited[pop]) {
            // cout << "from " << from << endl;
            // cout << "to " << to << endl;
            if (pop == to) {
                return true;
            }
            list<int>::iterator it;
            for (it = adj[pop].begin(); it != adj[pop].end(); ++it) {
                if (!visited[*it]) {
                    st.push(*it);
                }
            }
        } else {
            continue;
        }
    }

    return false;
}

bool Graph::DFS(int from, int to, int nodes) {

    bool visited[nodes];

    for (int i = 0; i < nodes; i++) {
        visited[i] = false;
    }

    return DFSUtil(from, to, visited);

}


int main() 
{ 
    int n, m;
    cin >> n;
    cin >> m;

    Graph g(n * 2);

    int stateInt = 0;

    for (int i = 0; i < n; i++) {
        string from;
        string are;
        string worse;
        string then;
        string to;

        cin >> from;
        cin >> are;
        cin >> worse;
        cin >> then;
        cin >> to;

        int fromInt;
        int toInt;

        if (stateToInt.find(from) == stateToInt.end()) {
            stateToInt[from] = stateInt;
            fromInt = stateInt;
            stateInt++;
        } else {
            fromInt = stateToInt[from];
        }

        if (stateToInt.find(to) == stateToInt.end()) {
            stateToInt[to] = stateInt;
            toInt = stateInt;
            stateInt++;
        } else {
            toInt = stateToInt[to];
        }

        g.addEdge(fromInt, toInt);
    }

    //cout << " - - - - " << endl;

    for (int i = 0; i < m; i++) {
        string from;
        string are;
        string worse;
        string then;
        string to;

        cin >> from;
        cin >> are;
        cin >> worse;
        cin >> then;
        cin >> to;

        if (stateToInt.find(from) == stateToInt.end() || stateToInt.find(to) == stateToInt.end()) {
            cout << "Pants on Fire" << endl;
        } else {
            if (g.DFS(stateToInt[from], stateToInt[to], stateInt)) {
                cout << "Fact" << endl;
            } else if (g.DFS(stateToInt[to], stateToInt[from], stateInt)) {
                cout << "Alternative Fact" << endl;
            } else {
                cout << "Pants on Fire" << endl;
            }
        }

    }

    return 0;
}