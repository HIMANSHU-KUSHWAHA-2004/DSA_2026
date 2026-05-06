#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int DFS(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {

        if (idx == 0) {
            return (amount % coins[0] == 0);
        }

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int notake = DFS(idx - 1, amount, coins, dp);

        int take = 0;
        if (coins[idx] <= amount) {
            take = DFS(idx, amount - coins[idx], coins, dp);
        }

        return dp[idx][amount] = take + notake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return DFS(n - 1, amount, coins, dp);
    }
};

int main() {
    Solution obj;

    vector<int> coins = {1,2,3};
    int amount = 4;

    cout << obj.change(amount, coins) << endl;
}