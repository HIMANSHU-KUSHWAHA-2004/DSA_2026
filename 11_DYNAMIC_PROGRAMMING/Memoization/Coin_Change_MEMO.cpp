#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
🔥 COIN CHANGE - MEMOIZATION (MIN COINS)
===========================================================

👉 TYPE:
    Infinite Supply DP (same coin can be reused)

👉 STATE:
    dp[idx][amount]

👉 MEANING:
    "Minimum coins needed using coins 0 → idx to form amount"

===========================================================
*/

class Solution {
public:

    int solve(int idx, int amount, vector<int>& coin,
              vector<vector<int>>& dp){

        /*
        =======================================================
        🔥 BASE CASES
        =======================================================

        👉 amount == 0 → 0 coins needed
        👉 idx == 0 → only one coin available
        =======================================================
        */

        if(amount == 0) return 0;

        if(idx == 0){
            if(amount % coin[0] == 0)
                return amount / coin[0];
            else
                return 1e9; // impossible
        }

        if(dp[idx][amount] != -1)
            return dp[idx][amount];

        // ❌ NOT TAKE
        int notTake = solve(idx - 1, amount, coin, dp);

        // ✅ TAKE (INFINITE SUPPLY → SAME INDEX)
        int take = 1e9;
        if(coin[idx] <= amount){
            take = 1 + solve(idx, amount - coin[idx], coin, dp);
        }

        return dp[idx][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount){
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        int ans = solve(n-1, amount, coins, dp);

        return (ans >= 1e9 ? -1 : ans);
    }
};


/*
===========================================================
🔥 MAIN (EXAMPLE)
===========================================================
*/

int main(){

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution obj;

    cout << "Memo Answer: " << obj.coinChange(coins, amount) << endl;

    return 0;
}