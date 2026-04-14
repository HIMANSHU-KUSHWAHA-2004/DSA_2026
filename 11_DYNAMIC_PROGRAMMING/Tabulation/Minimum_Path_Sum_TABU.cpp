#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 🟢 start
        dp[0][0] = grid[0][0];

        // 🔵 first row
        for (int j = 1; j < n; j++) {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }

        // 🔵 first column
        for (int i = 1; i < m; i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }

        // 🔥 rest
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    cout << obj.minPathSum(grid);

    return 0;
}