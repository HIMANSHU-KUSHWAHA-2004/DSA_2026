#include <bits/stdc++.h>
using namespace std;

class SolutionDFS {
public:

    // 🔷 DFS function to detect cycle
    bool dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& visited,
             vector<int>& pathVisited) {

        visited[node] = 1;       // mark as visited
        pathVisited[node] = 1;   // mark as part of current DFS path

        for (auto nei : adj[node]) {

            // 🔹 Case 1: If neighbor is not visited → go deeper
            if (visited[nei] == 0) {
                if (dfs(nei, adj, visited, pathVisited)) {
                    return true;   // cycle found in deeper call
                }
            }

            // 🔹 Case 2: If neighbor is already in current path → cycle
            else if (pathVisited[nei] == 1) {
                return true;
            }
        }

        // 🔹 Backtracking: remove node from current path
        pathVisited[node] = 0;

        return false;  // no cycle from this node
    }

    // 🔷 Function to check cycle in directed graph
    bool isCyclic(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        // 🔹 Build adjacency list
        // edge u → v means u points to v
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);

        // 🔹 Check all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, pathVisited)) {
                    return true;   // cycle exists
                }
            }
        }

        return false;  // no cycle
    }
};

int main() {

    SolutionDFS obj;

    // 🔷 Example 1: Graph WITH cycle
    // 0 → 1 → 2 → 0 (cycle)
    int V1 = 3;
    vector<vector<int>> edges1 = {
        {0, 1},
        {1, 2},
        {2, 0}
    };

    cout << "Graph 1 (Cycle present): ";
    cout << (obj.isCyclic(V1, edges1) ? "Cycle Detected" : "No Cycle") << endl;


    // 🔷 Example 2: Graph WITHOUT cycle
    // 0 → 1 → 2 → 3 (no cycle)
    int V2 = 4;
    vector<vector<int>> edges2 = {
        {0, 1},
        {1, 2},
        {2, 3}
    };

    cout << "Graph 2 (No cycle): ";
    cout << (obj.isCyclic(V2, edges2) ? "Cycle Detected" : "No Cycle") << endl;


    // 🔷 Example 3: Disconnected graph
    // Component 1: 0 → 1 → 2
    // Component 2: 3 → 4 → 3 (cycle)
    int V3 = 5;
    vector<vector<int>> edges3 = {
        {0, 1},
        {1, 2},
        {3, 4},
        {4, 3}
    };

    cout << "Graph 3 (Disconnected with cycle): ";
    cout << (obj.isCyclic(V3, edges3) ? "Cycle Detected" : "No Cycle") << endl;

    return 0;
}