#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxi(int idx, vector<int>& arr, vector<int>& dp) {

        // 🔷 Base Case
        if (idx >= arr.size()) {
            return 0;
        }

        // 🔷 DP Check
        if (dp[idx] != -1) {
            return dp[idx];
        }

        // 🔷 Pick
        int pick = arr[idx] + maxi(idx + 2, arr, dp);

        // 🔷 Not Pick
        int notPick = maxi(idx + 1, arr, dp);

        // 🔷 Store and return
        return dp[idx] = max(pick, notPick);
    }

    int findMaxSum(vector<int>& arr) {
        int n = arr.size();

        vector<int> dp(n, -1);

        return maxi(0, arr, dp);   // start from index 0
    }
};

int main() {
    Solution obj;

    vector<int> arr = {2, 1, 4, 9};

    cout << "Maximum Sum: " << obj.findMaxSum(arr) << endl;

    return 0;
}