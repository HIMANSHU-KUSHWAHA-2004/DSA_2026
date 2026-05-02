#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
🔥 COIN CHANGE - TABULATION (MIN COINS)
===========================================================

👉 TYPE:
    Infinite Supply DP

👉 KEY RULE:
    TAKE → SAME ROW (i)
    NOT TAKE → PREVIOUS ROW (i-1)

===========================================================
*/

class Solution {
public:

    int tabu(vector<int>& coin, int amount){

        int n = coin.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));

        /*
        =======================================================
        🔥 BASE CASE (FIRST ROW ONLY)
        =======================================================
        */

        for(int a = 0; a <= amount; a++){
            if(a % coin[0] == 0)
                dp[0][a] = a / coin[0];
        }

        /*
        =======================================================
        🔁 FILL DP TABLE
        =======================================================
        */

        for(int i = 1; i < n; i++){
            for(int a = 0; a <= amount; a++){

                // ❌ NOT TAKE
                int notTake = dp[i-1][a];

                // ✅ TAKE (INFINITE → SAME ROW)
                int take = 1e9;
                if(coin[i] <= a){
                    take = 1 + dp[i][a - coin[i]];
                }

                dp[i][a] = min(take, notTake);
            }
        }

        int ans = dp[n-1][amount];
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

    cout << "Tabu Answer: " << obj.tabu(coins, amount) << endl;

    return 0;
}