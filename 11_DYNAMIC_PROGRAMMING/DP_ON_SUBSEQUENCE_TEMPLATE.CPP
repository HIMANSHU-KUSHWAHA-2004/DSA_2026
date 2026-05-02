#include <bits/stdc++.h>
using namespace std;

/*
=====================================================================
🔥 GENERAL SUBSEQUENCE DP TEMPLATE
=====================================================================

👉 PATTERN:
    At every index → 2 choices:
        1. NOT TAKE
        2. TAKE

👉 STATE:
    dp[idx][target]

👉 MEANING:
    "Using elements from 0 → idx, we try to build target"

=====================================================================
🔥 IMPORTANT THINKING RULES
=====================================================================

👉 0/1 TYPE:
    TAKE → idx - 1

👉 UNBOUNDED TYPE:
    ITS WHEN YOU CAN TAKE AN ELEMENT MULTIPLE TIMES AND THERE ARE IFINITE SUPPLY OF THAT ELEMENT.
    QUESTION INCLUDE WORDS LIKE "INFINITE", "UNLIMITED", "ANY NUMBER OF TIMES" ETC.
    TAKE → idx (same index)

👉 COMBINATION RULE:
    COUNT   → +
    BOOLEAN → ||
    MAX     → max()
    MIN     → min()

=====================================================================
*/


class Solution {
public:

/*====================================================================
🔥 MEMOIZATION (TOP-DOWN)
====================================================================*/

int memo(int idx, int target, vector<int>& arr, vector<vector<int>>& dp){

    /*
    --------------------------------------------------------------
    🔥 BASE CASE THINKING
    --------------------------------------------------------------

    👉 target == 0:
        means "we achieved the goal"
        return:
            count → 1
            bool  → true
            min   → 0

    👉 idx == 0:
        only one element available
    --------------------------------------------------------------
    */

    if(target == 0) return 1;

    if(idx == 0){
        return (arr[0] == target);
    }

    if(dp[idx][target] != -1) return dp[idx][target];

    // ❌ NOT TAKE
    int notTake = memo(idx - 1, target, arr, dp);

    // ✅ TAKE
    int take = 0;
    if(arr[idx] <= target){
        take = memo(idx - 1, target - arr[idx], arr, dp);
    }

    return dp[idx][target] = take + notTake;
}


/*====================================================================
🔥 TABULATION (BOTTOM-UP)
====================================================================*/

int tabu(vector<int>& arr, int target){

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    /*
    ================================================================
    🔥 BASE CASE FILLING (FIRST ROW)
    ================================================================

    👉 IMPORTANT IDEA:

    Sometimes:
        ✔ only one cell depends on first element → NO LOOP

    Sometimes:
        ✔ multiple targets possible → LOOP NEEDED

    ---------------------------------------------------------------
    */

    // target = 0 always possible
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }

    // first element base case
    dp[0][arr[0]] = 1;

    /*
    ⚠️ NOTE:
    If multiple ways exist using arr[0] (like coin change),
    then we would use a LOOP here instead.
    */

    /*
    ================================================================
    🔁 FILL DP TABLE
    ================================================================
    */

    for(int i = 1; i < n; i++){
        for(int t = 0; t <= target; t++){

            // ❌ NOT TAKE
            int notTake = dp[i - 1][t];

            // ✅ TAKE
            int take = 0;

            if(arr[i] <= t){

                /*
                🔥 CHANGE BASED ON TYPE:

                0/1 DP:
                    dp[i-1][t - arr[i]]

                UNBOUNDED DP:
                    dp[i][t - arr[i]]
                */

                take = dp[i - 1][t - arr[i]];
            }

            // 🔥 COMBINE ANSWERS
            dp[i][t] = take + notTake;
        }
    }

    return dp[n - 1][target];
}

};


/*====================================================================
🔥 MAIN (EXAMPLE)
====================================================================*/

int main(){

    vector<int> arr = {1,2,3,3};
    int target = 6;

    Solution obj;

    int n = arr.size();

    // 🔥 MEMO
    vector<vector<int>> dp1(n, vector<int>(target + 1, -1));
    cout << "Memo Answer: " << obj.memo(n - 1, target, arr, dp1) << endl;

    // 🔥 TABU
    cout << "Tabu Answer: " << obj.tabu(arr, target) << endl;

    return 0;
}