#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔷 Kahn’s Algorithm (BFS) to detect cycle
    bool topo(int V, vector<vector<int>> &edges) {

        // 🔹 Step 1: Build adjacency list
        vector<vector<int>> adj(V);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int vtx = edges[i][1];   // renamed to avoid shadowing V
            adj[u].push_back(vtx);
        }

        // 🔹 Step 2: Compute indegree
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (auto nei : adj[i]) {
                indegree[nei]++;
            }
        }

        // 🔹 Step 3: Push all nodes with indegree 0
        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // 🔹 Step 4: Process nodes
        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            count++;

            for (auto nei : adj[node]) {
                indegree[nei]--;

                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // 🔹 Step 5: Cycle check
        if (count != V) {
            return true;   // cycle exists
        }

        return false;      // no cycle
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        return topo(V, edges);
    }
};