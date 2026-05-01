#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ============================
    // 🔷 Recursive + Memoization
    // ============================

    int solve(int row, int c1, int c2,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {

        int n = grid.size();
        int m = grid[0].size();

        // ❌ out of bounds
        if (c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
            return -1e8;

        // ✅ last row
        if (row == n - 1) {
            if (c1 == c2)
                return grid[row][c1];
            return grid[row][c1] + grid[row][c2];
        }

        // ✅ memo check
        if (dp[row][c1][c2] != -1)
            return dp[row][c1][c2];

        int ans = -1e8;

        // 🔁 try all 9 moves
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {

                int curr;

                if (c1 == c2)
                    curr = grid[row][c1];
                else
                    curr = grid[row][c1] + grid[row][c2];

                curr += solve(row + 1, c1 + d1, c2 + d2, grid, dp);

                ans = max(ans, curr);
            }
        }

        return dp[row][c1][c2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // 🔷 3D DP initialized with -1
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1))
        );

        return solve(0, 0, m - 1, grid, dp);
    }
};

// ============================
// 🔷 DRIVER CODE
// ============================

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1}
    };

    int result = sol.cherryPickup(grid);

    cout << "Maximum cherries collected (Memo): " << result << endl;

    return 0;
}