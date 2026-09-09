#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);  // dp[n] = 0 (base case)

        for (int i = n - 1; i >= 0; i--) {
            int len = 0;
            int maxi = 0;
            int ans = 0;

            for (int j = i; j < min(n, i + k); j++) {
                len++;
                maxi = max(maxi, arr[j]);
                ans = max(ans, len * maxi + dp[j + 1]);
            }

            dp[i] = ans;
        }

        return dp[0];
    }
};