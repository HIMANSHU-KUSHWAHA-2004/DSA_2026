#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // dp[r][c][cost] = max score to reach (r,c) using 'cost'/
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, -1))
        );

        // 🔰 start point
        dp[0][0][0] = 0;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                for (int cost = 0; cost <= k; cost++) {

                    // ❌ unreachable state → skip
                    if (dp[r][c][cost] == -1) continue;

                    // 👉 move DOWN
                    if (r + 1 < n) {
                        int cell = grid[r+1][c];   // next cell
                        int nc = cost + (cell == 0 ? 0 : 1); // new cost

                        if (nc <= k) {
                            dp[r+1][c][nc] = max(
                                dp[r+1][c][nc],
                                dp[r][c][cost] + cell // add score
                            );
                        }
                    }

                    // 👉 move RIGHT
                    if (c + 1 < m) {
                        int cell = grid[r][c+1];
                        int nc = cost + (cell == 0 ? 0 : 1);

                        if (nc <= k) {
                            dp[r][c+1][nc] = max(
                                dp[r][c+1][nc],
                                dp[r][c][cost] + cell
                            );
                        }
                    }
                }
            }
        }

        // 🎯 find best score at destination with any valid cost
        int ans = -1;
        for (int cost = 0; cost <= k; cost++) {
            ans = max(ans, dp[n-1][m-1][cost]);
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 1},
        {2, 0}
    };
    int k = 1;

    Solution obj;
    cout << "Tabu Answer: " << obj.maxPathScore(grid, k) << endl;
}