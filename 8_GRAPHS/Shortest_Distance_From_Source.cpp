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

    ------------------------------------------------------------

    GRAPH:

    Reachable from 0:
    0 → 1 → 3 → 4 → 5
      ↘ 2 ↗

    Unreachable from 0:
    6 → 7 → 8

    ------------------------------------------------------------

    EXPECTED DIST:

    Node 0 → 0
    Node 1 → 2
    Node 2 → 4
    Node 3 → 5   (via 0→2→3)
    Node 4 → 8
    Node 5 → 9
    Node 6 → -1
    Node 7 → -1
    Node 8 → -1

    Final:
    [0, 2, 4, 5, 8, 9, -1, -1, -1]
    */

    // 🔷 DFS for topo sort
    void dfs(vector<vector<pair<int,int>>>& adj,
             vector<int>& vis,
             stack<int>& st,
             int node) {

        vis[node] = 1;

        for (auto it : adj[node]) {
            int nei = it.first;
            if (!vis[nei]) {
                dfs(adj, vis, st, nei);
            }
        }

        st.push(node);
    }

    // 🔷 topo sort
    void topo(vector<vector<pair<int,int>>>& adj,
              int V,
              stack<int>& st) {

        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(adj, vis, st, i);
            }
        }
    }

    // 🔷 shortest path in DAG
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);

        for (auto e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        stack<int> st;
        topo(adj, V, st);

        vector<int> dist(V, INT_MAX);
        dist[0] = 0; // source

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            // only process reachable nodes
            if (dist[node] != INT_MAX) {
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;

                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // convert unreachable to -1
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