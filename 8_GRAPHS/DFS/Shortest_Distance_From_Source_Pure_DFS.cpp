#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    ============================================================
    🔥 EXAMPLE (WITH UNREACHABLE NODES)
    ============================================================

    V = 9

    Edges:
    0 -> 1 (2)
    0 -> 2 (4)
    1 -> 3 (7)
    2 -> 3 (1)
    3 -> 4 (3)
    4 -> 5 (1)

    // DISCONNECTED PART
    6 -> 7 (2)
    7 -> 8 (3)

    SOURCE = 0

    EXPECTED:
    [0, 2, 4, 5, 8, 9, -1, -1, -1]
    */

    // 🔷 DFS / BACKTRACK STYLE
    void dfs(vector<vector<pair<int,int>>>& adj,
             int node,
             int cost,
             vector<int>& dist) {

        // 🔶 pruning: if already worse path, stop
        if (cost >= dist[node]) return;

        // 🔶 update shortest distance
        dist[node] = cost;

        // 🔶 explore neighbors
        for (auto it : adj[node]) {
            int nei = it.first;
            int wt  = it.second;

            dfs(adj, nei, cost + wt, dist);
        }
    }

    vector<int> shortestPath(int V, vector<vector<int>>& edges) {

        // 🔶 adjacency list
        vector<vector<pair<int,int>>> adj(V);

        for (auto e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<int> dist(V, INT_MAX);

        // 🔶 source = 0
        dfs(adj, 0, 0, dist);

        // 🔶 convert unreachable to -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};


int main() {

    Solution obj;

    int V = 9;

    vector<vector<int>> edges = {
        {0,1,2},
        {0,2,4},
        {1,3,7},
        {2,3,1},
        {3,4,3},
        {4,5,1},

        // disconnected part
        {6,7,2},
        {7,8,3}
    };

    vector<int> ans = obj.shortestPath(V, edges);

    cout << "Shortest distances from source 0:\n";

    for (int i = 0; i < ans.size(); i++) {
        cout << "Node " << i << " -> " << ans[i] << endl;
    }

    return 0;
}