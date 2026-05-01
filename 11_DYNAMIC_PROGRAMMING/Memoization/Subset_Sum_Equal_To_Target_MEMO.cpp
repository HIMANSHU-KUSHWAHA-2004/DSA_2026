#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool Ans(int idx, vector<int>& arr, int target, vector<vector<int>>& dp) {
        
        // Example:
        // arr = {1,2,3}, target = 5
        // Calls:
        // Ans(0,5) -> pick 1 -> Ans(1,4)
        //            -> pick 2 -> Ans(2,2)
        //            -> last element = 3 != 2 → false
        //            -> not pick 2 -> Ans(2,4)
        //            -> 3 != 4 → false
        // So backtrack and try different paths

        if (target == 0) return true;

        if (idx == arr.size() - 1) {
            return (target == arr[idx]);
        }

        if (target < 0) return false;

        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }

        bool take = Ans(idx + 1, arr, target - arr[idx], dp);
        bool notake = Ans(idx + 1, arr, target, dp);

        return dp[idx][target] = (take || notake);
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();

        // Example:
        // arr = {1,2,3}, sum = 5
        // Output = true (2 + 3)

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return Ans(0, arr, sum, dp);
    }
};