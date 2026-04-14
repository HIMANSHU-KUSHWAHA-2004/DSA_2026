
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int DFS(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        // 🔴 out of bound
        if (i >= m || j >= n) return INT_MAX;

        // 🟢 destination
        if (i == m - 1 && j == n - 1) return grid[i][j];

        // 🟡 already computed
        if (dp[i][j] != -1) return dp[i][j];

        int down = DFS(i + 1, j, grid, dp);
        int right = DFS(i, j + 1, grid, dp);

        return dp[i][j] = grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return DFS(0, 0, grid, dp);
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