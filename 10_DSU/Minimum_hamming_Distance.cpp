#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ============================
    // 🔷 DSU (Union-Find) Approach
    // ============================
    class DSU {
    public:
        vector<int> parent, size;

        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b) return;

            if (size[a] < size[b]) {
                parent[a] = b;
                size[b] += size[a];
            } else {
                parent[b] = a;
                size[a] += size[b];
            }
        }
    };

    int solveUsingDSU(vector<int>& source, vector<int>& target,
                      vector<vector<int>>& allowedSwaps) {

        int n = source.size();
        DSU dsu(n);

        for (auto &e : allowedSwaps)
            dsu.unite(e[0], e[1]);

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++)
            groups[dsu.find(i)].push_back(i);

        int diff = 0;

        for (auto &g : groups) {
            unordered_map<int, int> freq;

            for (int idx : g.second)
                freq[source[idx]]++;

            for (int idx : g.second) {
                if (freq[target[idx]] > 0)
                    freq[target[idx]]--;
                else
                    diff++;
            }
        }

        return diff;
    }

    // ============================
    // 🔷 DFS Approach
    // ============================

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& comp) {
        vis[node] = true;
        comp.push_back(node);

        for (auto nei : adj[node]) {
            if (!vis[nei])
                dfs(nei, adj, vis, comp);
        }
    }

    int solveUsingDFS(vector<int>& source, vector<int>& target,
                      vector<vector<int>>& allowedSwaps) {

        int n = source.size();
        vector<vector<int>> adj(n);

        for (auto &e : allowedSwaps) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int diff = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i, adj, vis, comp);

                unordered_map<int, int> freq;

                for (int idx : comp)
                    freq[source[idx]]++;

                for (int idx : comp) {
                    if (freq[target[idx]] > 0)
                        freq[target[idx]]--;
                    else
                        diff++;
                }
            }
        }

        return diff;
    }

    // ============================
    // 🔷 MAIN LOGIC SWITCH
    // ============================

    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {

        // Choose one:
        return solveUsingDSU(source, target, allowedSwaps);
        // return solveUsingDFS(source, target, allowedSwaps);
    }
};


// ============================
// 🔷 DRIVER CODE (MAIN FUNCTION)
// ============================

int main() {
    Solution sol;

    vector<int> source = {1, 2, 3, 4};
    vector<int> target = {2, 1, 4, 5};
    vector<vector<int>> allowedSwaps = {{0,1}, {2,3}};

    int ans = sol.minimumHammingDistance(source, target, allowedSwaps);

    cout << "Minimum Hamming Distance: " << ans << endl;

    return 0;
}