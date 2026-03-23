#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ================= BFS =================
    bool bfsCheck(int start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto nei : graph[node]) {
                if (color[nei] == -1) {
                    color[nei] = 1 - color[node];
                    q.push(nei);
                }
                else if (color[nei] == color[node]) {
                    return false; // conflict
                }
            }
        }
        return true;
    }

    bool isBipartite_BFS(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!bfsCheck(i, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }

    // ================= DFS =================
    bool dfsCheck(int node, vector<vector<int>>& graph, vector<int>& color, int ch) {
        color[node] = ch;

        for (auto nei : graph[node]) {
            if (color[nei] == -1) {
                if (!dfsCheck(nei, graph, color, 1 - ch)) {
                    return false;
                }
            }
            else if (color[nei] == ch) {
                return false; // conflict
            }
        }
        return true;
    }

    bool isBipartite_DFS(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfsCheck(i, graph, color, 0)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {

    Solution obj;

    // 🔷 Example 1: Bipartite graph (square)
    vector<vector<int>> graph1 = {
        {1, 3},   // 0
        {0, 2},   // 1
        {1, 3},   // 2
        {0, 2}    // 3
    };

    // 🔷 Example 2: NOT bipartite (triangle)
    vector<vector<int>> graph2 = {
        {1, 2},   // 0
        {0, 2},   // 1
        {0, 1}    // 2
    };

    cout << "Graph 1 (Square):\n";
    cout << "BFS: " << (obj.isBipartite_BFS(graph1) ? "Yes" : "No") << endl;
    cout << "DFS: " << (obj.isBipartite_DFS(graph1) ? "Yes" : "No") << endl;

    cout << "\nGraph 2 (Triangle):\n";
    cout << "BFS: " << (obj.isBipartite_BFS(graph2) ? "Yes" : "No") << endl;
    cout << "DFS: " << (obj.isBipartite_DFS(graph2) ? "Yes" : "No") << endl;

    return 0;
}