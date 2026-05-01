#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        // dp[i][j] = can we make sum j using first (i+1) elements
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // base case: sum 0 always possible
        for(int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // base case: first element
        if(nums[0] <= sum)
            dp[0][nums[0]] = true;

        // fill table
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= sum; j++) {

                bool notake = dp[i - 1][j];
                bool take = false;

                if(nums[i] <= j) {
                    take = dp[i - 1][j - nums[i]];
                }

                dp[i][j] = take || notake;
            }
        }

        // find minimum difference
        int mini = INT_MAX;

        for(int s1 = 0; s1 <= sum; s1++) {
            if(dp[n - 1][s1]) {
                int s2 = sum - s1;
                mini = min(mini, abs(s1 - s2));
            }
        }

        return mini;
    }
};