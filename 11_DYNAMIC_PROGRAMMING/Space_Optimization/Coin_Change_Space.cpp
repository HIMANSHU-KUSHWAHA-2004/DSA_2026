#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
🔥 COIN CHANGE - 1D OPTIMIZED DP (MIN COINS)
===========================================================

👉 TYPE:
    Infinite Supply DP

👉 KEY IDEA:
    We only need previous computed values of amount

👉 SPACE:
    O(n * amount) → O(amount)

===========================================================
*/

class Solution {
public:

    int coinChange(vector<int>& coins, int amount){

        /*
        =======================================================
        🔥 DP ARRAY
        dp[a] = minimum coins needed to form amount a
        =======================================================
        */

        vector<int> dp(amount + 1, 1e9);

        // 🔥 base case
        dp[0] = 0;

        /*
        =======================================================
        🔁 MAIN LOGIC
        =======================================================

        👉 OUTER LOOP = coins (choice of items)
        👉 INNER LOOP = amount

        ⚠️ IMPORTANT:
        We go LEFT → RIGHT because:
        → infinite supply allowed
        =======================================================
        */

        for(int coin : coins){

            for(int a = coin; a <= amount; a++){

                /*
                ===================================================
                🔥 TRANSITION
                ===================================================

                dp[a] = min(
                            not take (old value),
                            take (use coin again)
                        )
                ===================================================
                */

                dp[a] = min(dp[a], 1 + dp[a - coin]);
            }
        }

        return (dp[amount] >= 1e9 ? -1 : dp[amount]);
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

    cout << "Optimized 1D Answer: "
         << obj.coinChange(coins, amount) << endl;

    return 0;
}