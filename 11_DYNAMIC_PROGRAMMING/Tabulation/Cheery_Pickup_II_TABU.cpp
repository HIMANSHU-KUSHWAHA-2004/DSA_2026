#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // 3D DP: dp[row][col1][col2]
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, 0))
        );

        // ============================
        // 🔷 Base Case (last row)
        // ============================
        for (int c1 = 0; c1 < m; c1++) {
            for (int c2 = 0; c2 < m; c2++) {
                if (c1 == c2)
                    dp[n - 1][c1][c2] = grid[n - 1][c1];
                else
                    dp[n - 1][c1][c2] = grid[n - 1][c1] + grid[n - 1][c2];
            }
        }

        // ============================
        // 🔷 Fill DP (Bottom-Up)
        // ============================
        for (int row = n - 2; row >= 0; row--) {
            for (int c1 = 0; c1 < m; c1++) {
                for (int c2 = 0; c2 < m; c2++) {

                    int ans = -1e8;

                    // try all 9 moves
                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {

                            int nc1 = c1 + d1;
                            int nc2 = c2 + d2;

                            int curr = 0;

                            // collect cherries
                            if (c1 == c2)
                                curr = grid[row][c1];
                            else
                                curr = grid[row][c1] + grid[row][c2];

                            // check bounds
                            if (nc1 >= 0 && nc1 < m && nc2 >= 0 && nc2 < m)
                                curr += dp[row + 1][nc1][nc2];
                            else
                                curr += -1e8;

                            ans = max(ans, curr);
                        }
                    }

                    dp[row][c1][c2] = ans;
                }
            }
        }

        return dp[0][0][m - 1];
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

    cout << "Maximum cherries collected: " << result << endl;

    return 0;
}