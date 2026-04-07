#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timer = 0;

    void dfs(int node, int parent, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& tin, vector<int>& low,
             vector<vector<int>>& bridges) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto it : adj[node]) {

            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, node, adj, vis, tin, low, bridges);

                low[node] = min(low[node], low[it]);

                if (low[it] > tin[node]) {
                    bridges.push_back({node, it});
                }
            }
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }

    vector<vector<int>> findBridges(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0), tin(n), low(n);
        vector<vector<int>> bridges;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, tin, low, bridges);
            }
        }

        return bridges;
    }
};

int main() {

    int n = 6;

    vector<vector<int>> edges = {
        {0,1}, {1,2}, {2,0},
        {3,4}, {4,5}, {5,3},
        {2,3}
    };

    Solution obj;
    vector<vector<int>> bridges = obj.findBridges(n, edges);

    cout << "Bridges:\n";
    for (auto &b : bridges) {
        cout << b[0] << " - " << b[1] << endl;
    }

    return 0;
}