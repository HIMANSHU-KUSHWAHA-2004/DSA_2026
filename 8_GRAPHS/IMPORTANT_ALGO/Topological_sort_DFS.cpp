#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🔷 DFS function
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& st) {
        visited[node] = 1;   // mark node as visited

        // visit all neighbors first
        for (auto nei : adj[node]) {
            if (!visited[nei]) {
                dfs(nei, adj, visited, st);
            }
        }

        // push after visiting all neighbors
        st.push(node);
    }

    // 🔷 Topological Sort using DFS
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        // Step 2: Visited array
        vector<int> visited(V, 0);

        // Step 3: Stack to store topo order
        stack<int> st;

        // Step 4: Run DFS for all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }

        // Step 5: Pop stack into answer
        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }

        return topo;
    }
};

int main() {
    Solution obj;

    // 🔷 Example DAG
    int V = 6;
    vector<vector<int>> edges = {
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    vector<int> result = obj.topoSort(V, edges);

    cout << "Topological Sort using DFS: ";
    for (auto x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}