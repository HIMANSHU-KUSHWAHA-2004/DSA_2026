#include <bits/stdc++.h>
using namespace std;

int countSubsets(vector<int>& arr, int k) {
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // 🔥 Base case
    if (arr[0] == 0) {
        dp[0][0] = 2;  // take / not take
    } else {
        dp[0][0] = 1;  // not take
    }
    if (arr[0] != 0 && arr[0] <= k) {
        dp[0][arr[0]] = 1;  // take
    }

    // 🔁 Fill DP
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {

            int notake = dp[i - 1][j];

            int take = 0;
            if (arr[i] <= j) {
                take = dp[i - 1][j - arr[i]];
            }

            dp[i][j] = take + notake;
        }
    }

    return dp[n - 1][k];
}

int main() {

    // 🔥 Example
    vector<int> arr = {0, 1, 2, 3};
    int k = 3;

    int ans = countSubsets(arr, k);

    cout << "Number of subsets with sum " << k << " = " << ans << endl;

    return 0;
}