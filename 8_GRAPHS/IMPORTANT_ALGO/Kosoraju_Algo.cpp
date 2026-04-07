#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔹 Step 1: DFS to fill stack (finishing time)
    void dfs1(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs1(it, adj, vis, st);
            }
        }

        st.push(node); // store finishing order
    }

    // 🔹 Step 3: DFS on reversed graph
    void dfs2(int node, vector<vector<int>>& revAdj, vector<int>& vis, vector<int>& comp) {
        vis[node] = 1;
        comp.push_back(node); // store component

        for (auto it : revAdj[node]) {
            if (!vis[it]) {
                dfs2(it, revAdj, vis, comp);
            }
        }
    }

    vector<vector<int>> kosaraju(int V, vector<vector<int>>& adj) {

        stack<int> st;
        vector<int> vis(V, 0);

        // 🔹 Step 1: Fill stack using DFS
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs1(i, adj, vis, st);
            }
        }

        // 🔹 Step 2: Reverse the graph
        vector<vector<int>> revAdj(V);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                revAdj[it].push_back(i);
            }
        }

        // 🔹 Step 3: Process nodes in stack order THIS WILL SET ALL THE vis VECTOR AGAIN TO 0
        fill(vis.begin(), vis.end(), 0);

        vector<vector<int>> allSCC;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!vis[node]) {
                vector<int> comp;
                dfs2(node, revAdj, vis, comp);
                allSCC.push_back(comp);
            }
        }

        return allSCC;
    }
};


// 🔵 MAIN FUNCTION (Example)
int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // Graph:
    // 0 → 1 → 2 → 0
    //      ↓
    //      3 → 4

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);

    Solution obj;
    vector<vector<int>> sccs = obj.kosaraju(V, adj);

    cout << "Strongly Connected Components:\n";

    for (auto comp : sccs) {
        for (auto node : comp) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}