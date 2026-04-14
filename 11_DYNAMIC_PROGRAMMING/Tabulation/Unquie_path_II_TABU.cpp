#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& ob) {

        int m = ob.size();
        int n = ob[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (ob[0][0] == 1) return 0;
        dp[0][0] = 1;

        // first column
        for (int i = 1; i < m; i++) {
            if (ob[i][0] == 0)
                dp[i][0] = dp[i - 1][0];
        }

        // first row
        for (int j = 1; j < n; j++) {
            if (ob[0][j] == 0)
                dp[0][j] = dp[0][j - 1];
        }

        // fill rest
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                if (ob[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
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