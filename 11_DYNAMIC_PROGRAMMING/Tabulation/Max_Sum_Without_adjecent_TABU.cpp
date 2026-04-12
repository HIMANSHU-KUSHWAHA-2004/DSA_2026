#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) return arr[0];

        vector<int> dp(n);

        // 🔷 Base cases
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        // 🔷 Fill DP table
        for (int i = 2; i < n; i++) {
            int pick = arr[i] + dp[i - 2];
            int notPick = dp[i - 1];

            dp[i] = max(pick, notPick);
        }

        return dp[n - 1];
    }
};

int main() {
    Solution obj;

    vector<int> arr = {2, 1, 4, 9};

    cout << "Maximum Sum: " << obj.findMaxSum(arr) << endl;

    return 0;
}