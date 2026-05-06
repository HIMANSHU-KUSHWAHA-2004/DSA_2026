// tabu_2d.cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tabu(vector<int> &val, vector<int> &wt, int cap) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(cap + 1, 0));

        for (int j = 0; j <= cap; j++) {
            if (wt[0] > j) {
                dp[0][j] = 0;
            } else {
                dp[0][j] = (j / wt[0]) * val[0];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= cap; j++) {

                int notake = dp[i - 1][j];
                int take = 0;

                if (wt[i] <= j) {
                    take = val[i] + dp[i][j - wt[i]];
                }

                dp[i][j] = max(take, notake);
            }
        }

        return dp[n - 1][cap];
    }
};

int main() {
    Solution obj;

    vector<int> val = {10, 40, 50, 70};
    vector<int> wt = {1, 3, 4, 5};
    int cap = 8;

    cout << "Tabulation 2D Answer: " << obj.tabu(val, wt, cap) << endl;

    return 0;
}