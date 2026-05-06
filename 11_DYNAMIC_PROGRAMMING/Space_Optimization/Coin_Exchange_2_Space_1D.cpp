#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> coins = {1,2,3};
    int amount = 4;

    vector<int> dp(amount + 1, 0);

    dp[0] = 1;

    for (int coin : coins) {
        for (int j = coin; j <= amount; j++) {
            dp[j] += dp[j - coin];
        }
    }

    cout << dp[amount] << endl;
}