

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    ============================================================
    🔥 EXAMPLE
    ============================================================

    V = 7, src = 0

    edges:
    0 - 1
    0 - 2
    1 - 3
    1 - 4
    2 - 5
    5 - 6

    GRAPH (undirected):

          0
        /   \
       1     2
     /  \     \
    3    4     5
                \
                 6

    Expected shortest distances from 0:
    [0, 1, 1, 2, 2, 2, 3]
    */

    // 🔷 BFS FUNCTION (unweighted shortest path)
    void BFS(vector<vector<int>> &adj, int src, vector<int> &dist) {

        queue<int> q;
        q.push(src);

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto nei : adj[node]) {

                // 🔶 If we found a shorter path to 'nei'
                if (dist[node] + 1 < dist[nei]) {
                    dist[nei] = dist[node] + 1;
                    q.push(nei);
                }
            }
        }
    }

    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {

        // 🔶 Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 🔶 Distance array
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        BFS(adj, src, dist);

        // 🔶 Convert unreachable to -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};


// 🔷 DRIVER (main)
int main() {

    Solution obj;

    int V = 7;
    int src = 0;

    vector<vector<int>> edges = {
        {0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {5,6}
    };

    vector<int> ans = obj.shortestPath(V, edges, src);

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << "Node " << i << " -> " << ans[i] << "\n";
    }

    return 0;
}