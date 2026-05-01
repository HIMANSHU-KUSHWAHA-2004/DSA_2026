#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int r, int c, int k,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {

        int n = grid.size();
        int m = grid[0].size();

        if (r >= n || c >= m) return -1e9;

        int cost = (grid[r][c] == 0 ? 0 : 1);
        k -= cost;

        if (k < 0) return -1e9;

        if (r == n - 1 && c == m - 1) {
            return grid[r][c];
        }

        if (dp[r][c][k] != -1) return dp[r][c][k];

        int right = solve(r, c + 1, k, grid, dp);
        int down  = solve(r + 1, c, k, grid, dp);

        return dp[r][c][k] = grid[r][c] + max(right, down);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, -1))
        );

        int ans = solve(0, 0, k, grid, dp);

        return (ans < 0 ? -1 : ans);
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 1},
        {2, 0}
    };
    int k = 1;

    Solution obj;
    cout << "Memo Answer: " << obj.maxPathScore(grid, k) << endl;

    return 0;
}