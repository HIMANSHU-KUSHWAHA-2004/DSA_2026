#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> coins = {1,2,3};
    int amount = 4;
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int j = 0; j <= amount; j++) {
        if (j % coins[0] == 0)
            dp[0][j] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= amount; j++) {

            int notake = dp[i - 1][j];

            int take = 0;
            if (coins[i] <= j) {
                take = dp[i][j - coins[i]];
            }

            dp[i][j] = take + notake;
        }
    }

    cout << dp[n - 1][amount] << endl;
}