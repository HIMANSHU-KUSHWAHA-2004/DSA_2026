#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int DFS(int r, int c, vector<vector<int>>& ob, vector<vector<int>>& dp) {
        int m = ob.size();
        int n = ob[0].size();

        if (r >= m || c >= n) return 0;
        if (ob[r][c] == 1) return 0;
        if (r == m - 1 && c == n - 1) return 1;

        if (dp[r][c] != -1) return dp[r][c];

        int down = DFS(r + 1, c, ob, dp);
        int right = DFS(r, c + 1, ob, dp);

        return dp[r][c] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m = ob.size();
        int n = ob[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return DFS(0, 0, ob, dp);
    }
};

int main() {
    Solution obj;

    vector<vector<int>> ob = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    cout << obj.uniquePathsWithObstacles(ob);

    return 0;
}