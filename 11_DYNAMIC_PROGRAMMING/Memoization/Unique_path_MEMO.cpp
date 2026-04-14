#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔵 DFS + Memoization
    int DFS(int r, int c, int m, int n, vector<vector<int>> &dp) {

        // 🟢 Base case: reached destination
        if (r == m - 1 && c == n - 1) {
            return 1;
        }

        // 🔴 Out of bounds
        if (r >= m || c >= n) {
            return 0;
        }

        // 🟡 Already computed
        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        // ⬇ Move Down
        int down = DFS(r + 1, c, m, n, dp);

        // ➡ Move Right
        int right = DFS(r, c + 1, m, n, dp);

        // 🧠 Store result and return
        return dp[r][c] = down + right;
    }

    int uniquePaths(int m, int n) {
        // 🟢 DP table initialized with -1 (unvisited)
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // 🚀 Start from (0,0)
        return DFS(0, 0, m, n, dp);
    }
};

int main() {
    Solution obj;
    int m = 3, n = 3;

    cout << obj.uniquePaths(m, n) << endl;

    return 0;
}