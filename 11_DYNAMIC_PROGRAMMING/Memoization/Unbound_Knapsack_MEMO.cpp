// memo.cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans(int idx, int capacity, vector<int> &val, vector<int> &wt,
            vector<vector<int>> &dp) {

        if (idx == 0) {
            if (wt[0] > capacity)
                return 0;
            else
                return (capacity / wt[0]) * val[0];
        }

        if (dp[idx][capacity] != -1)
            return dp[idx][capacity];

        int notake = ans(idx - 1, capacity, val, wt, dp);

        int take = 0;
        if (wt[idx] <= capacity) {
            take = val[idx] + ans(idx, capacity - wt[idx], val, wt, dp);
        }

        return dp[idx][capacity] = max(take, notake);
    }

    int solve(vector<int>& val, vector<int>& wt, int cap) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(cap + 1, -1));
        return ans(n - 1, cap, val, wt, dp);
    }
};

int main() {
    Solution obj;

    vector<int> val = {10, 40, 50, 70};
    vector<int> wt = {1, 3, 4, 5};
    int cap = 8;

    cout << "Memo Answer: " << obj.solve(val, wt, cap) << endl;

    return 0;
}