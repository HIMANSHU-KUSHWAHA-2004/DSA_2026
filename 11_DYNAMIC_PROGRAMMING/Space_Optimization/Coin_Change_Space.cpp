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
                /*HERE WHAT WE ARE DOING IS THAT AFTER SELECTING THE COIN WEE WILL SEE HOW THIS COIN IS CONTRIBUTING IN 
                EACH AMOUNT LIKE AS WE CAN SEE THE AMOUNT IS IN THE INNER LOOP 
                1. AFTER EVERY INNER LOOP THE DP ARRAY WIL CONTAIN THE BEST ANSWER FOR THE COINS USED FROM THE OUTER LOOP
                    LIKE IF IT RUN ONCE THEN IT CANTAIN FOR THEE COIN[0] IF IT RUN TWICE THEN IT HAS OF COIN[0] AND COIN[1]*/
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