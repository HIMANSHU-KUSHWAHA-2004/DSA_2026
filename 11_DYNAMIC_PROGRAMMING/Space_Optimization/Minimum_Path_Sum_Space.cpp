#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);

        // 🟢 first row prefix
        dp[0] = grid[0][0];
        for (int j = 1; j < n; j++) {
            dp[j] = grid[0][j] + dp[j - 1];
        }

        // 🔥 rest rows
        for (int i = 1; i < m; i++) {

            // first column update
            dp[0] = dp[0] + grid[i][0];

            for (int j = 1; j < n; j++) {
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }

        return dp[n - 1];
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