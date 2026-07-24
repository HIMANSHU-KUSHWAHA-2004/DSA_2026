
/*******************************************************
    🔥 UNIVERSAL PARTITION DP TEMPLATE (C++)

    Covers:
    - Matrix Chain Multiplication (MCM)
    - Minimum Cost to Cut Stick
    - Burst Balloons
    - Palindrome Partition

    👉 Only change: extra_cost(...)
********************************************************/

#include <bits/stdc++.h>
using namespace std;

class PartitionDP {
public:

    /******************** 🔹 MEMOIZATION ********************/
    int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp){

        // 👉 BASE CASE
        if(i > j) return 0;

        // 👉 MEMO CHECK
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1e9; // use INT_MIN for max problems

        // 👉 TRY ALL PARTITIONS
        for(int k = i; k <= j; k++){

            int left  = solve(i, k-1, arr, dp);
            int right = solve(k+1, j, arr, dp);

            int cost = left + right + extra_cost(i, j, k, arr);

            ans = min(ans, cost); // change to max if needed
        }

        return dp[i][j] = ans;
    }


    /******************** 🔹 TABULATION ********************/
    int tabulation(int n, vector<int>& arr){

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // len = size of segment
        for(int len = 1; len <= n; len++){

            for(int i = 1; i + len - 1 <= n-2; i++){

                int j = i + len - 1;

                dp[i][j] = 1e9;

                for(int k = i; k <= j; k++){

                    int left  = (k-1 >= i) ? dp[i][k-1] : 0;
                    int right = (k+1 <= j) ? dp[k+1][j] : 0;

                    int cost = left + right + extra_cost(i, j, k, arr);

                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[1][n-2]; // typical return for boundary problems
    }


    /******************** 🔹 EXTRA COST ********************/
    int extra_cost(int i, int j, int k, vector<int>& arr){

        // 🔥 CHANGE THIS PER PROBLEM

        // 👉 MCM
        // return arr[i-1] * arr[k] * arr[j];

        // 👉 CUT STICK (after adding 0 and n)
        // return arr[j+1] - arr[i-1];

        // 👉 BURST BALLOONS
        // return arr[i-1] * arr[k] * arr[j+1];

        // 👉 PALINDROME PARTITION
        // return 1;

        return 0;
    }


    /******************** 🔹 DRIVER ********************/
    int runMemo(vector<int>& arr){

        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(1, n-2, arr, dp);
    }

};


/******************** 🔹 USAGE EXAMPLE ********************/
int main(){

    PartitionDP obj;

    // Example: Cut Stick
    int n = 7;
    vector<int> cuts = {1,3,4,5};

    // Add boundaries
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    cout << obj.runMemo(cuts) << endl;

    return 0;
}
