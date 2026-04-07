/*
🟢 Problem: Number of Islands II (Dynamic)

You are given a grid of size n x m initially filled with water (0).
Operators array contains positions where land (1) is added.

After each operation, return the number of islands.

👉 An island is formed by connecting adjacent lands (up, down, left, right).

Example:
Input:
n = 4, m = 5
operators = {{1,1}, {0,1}, {3,3}, {3,4}}

Output:
1 1 2 2

Explanation:
Step 1: Add (1,1) → 1 island
Step 2: Add (0,1) → connected → still 1 island
Step 3: Add (3,3) → new island → 2
Step 4: Add (3,4) → connected → still 2
*/

#include <bits/stdc++.h>
using namespace std;

// 🔵 DSU (Disjoint Set Union)
class DSU {
private:
    vector<int> Parent, Size;

public:
    DSU(int n) {
        Parent.resize(n);
        Size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            Parent[i] = i;
        }
    }

    // Find with Path Compression
    int Find(int node) {
        if (node == Parent[node])
            return node;
        return Parent[node] = Find(Parent[node]);
    }

    // Union by Size
    void Union(int u, int v) {
        int par_u = Find(u);
        int par_v = Find(v);

        if (par_u == par_v)
            return;

        if (Size[par_u] > Size[par_v]) {
            Parent[par_v] = par_u;
            Size[par_u] += Size[par_v];
        } else {
            Parent[par_u] = par_v;
            Size[par_v] += Size[par_u];
        }
    }
};

class Solution {
public:
    // Check valid cell
    bool isvalid(int n, int m, int nr, int nc, vector<vector<int>>& vis) {
        return nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 1;
    }

    vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
        vector<vector<int>> visited(n, vector<int>(m, 0));
        DSU ds(n * m);

        vector<int> ans;
        int count = 0;

        for (auto g : operators) {
            int r = g[0];
            int c = g[1];

            // If already land → no change
            if (visited[r][c] == 1) {
                ans.push_back(count);
                continue;
            }

            visited[r][c] = 1;
            count++;

            int node = r * m + c;

            // 4 directions
            int dx[] = {1, 0, -1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (isvalid(n, m, nr, nc, visited)) {
                    int adjNode = nr * m + nc;

                    // If not in same component → merge
                    if (ds.Find(node) != ds.Find(adjNode)) {
                        count--;
                        ds.Union(node, adjNode);
                    }
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};

// 🟡 MAIN FUNCTION (TEST CASES)
int main() {
    Solution obj;

    int n = 4, m = 5;

    vector<vector<int>> operators = {
        {1, 1},
        {0, 1},
        {3, 3},
        {3, 4}
    };

    vector<int> result = obj.numOfIslands(n, m, operators);

    cout << "Number of islands after each operation:\n";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    /*
    Expected Output:
    1 1 2 2
    */

    return 0;
}