#include <bits/stdc++.h>
using namespace std;

bool DFS(vector<vector<int>> &adj, vector<int> &visited, int st, int parent) {
    visited[st] = 1;

    for (auto i : adj[st]) {
        if (!visited[i]) {
            if (DFS(adj, visited, i, st)) {
                return true;
            }
        } 
        else if (i != parent) {
            return true;
        }
    }

    return false;
}

bool iscycle(vector<vector<int>> &adj, int V) {
    vector<int> visited(V, 0);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (DFS(adj, visited, i, -1)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int V = 4;
    vector<vector<int>> graph(V);

    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    graph[3].push_back(1);
    graph[1].push_back(3);

    if (iscycle(graph, V))
        cout << "Cycle Found";
    else
        cout << "No Cycle";

    return 0;
}