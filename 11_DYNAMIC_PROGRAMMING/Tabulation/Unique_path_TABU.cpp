#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔴 YOUR STYLE (fixed version)
    int yourTabu(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // base case
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    int down = 0;
                    int right = 0;

                    // boundary check (important fix)
                    if (i > 0) down = dp[i - 1][j];
                    if (j > 0) right = dp[i][j - 1];

                    dp[i][j] = down + right; // (you missed this)
                }
            }
        }

        return dp[m - 1][n - 1];
    }

    // 🟢 MY STANDARD TABULATION
    int myTabu(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // first row = 1
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        // first column = 1
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        // fill rest
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution obj;

    int m = 3, n = 3;

    cout << "Your Tabu: " << obj.yourTabu(m, n) << endl;
    cout << "My Tabu  : " << obj.myTabu(m, n) << endl;

    return 0;
}