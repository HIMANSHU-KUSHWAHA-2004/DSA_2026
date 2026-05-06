// unbounded_1array.cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int unbounded1D(vector<int>& val, vector<int>& wt, int cap) {
        int n = val.size();
        vector<int> dp(cap + 1, 0);

        // base case (only item 0)
        for (int j = 0; j <= cap; j++) {
            if (wt[0] <= j)
                dp[j] = (j / wt[0]) * val[0];
        }

        // fill dp
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= cap; j++) {

                int notake = dp[j];
                int take = 0;

                if (wt[i] <= j) {
                    take = val[i] + dp[j - wt[i]]; // SAME ARRAY
                }

                dp[j] = max(take, notake);
            }
        }

        return dp[cap];
    }
};

int main() {
    Solution obj;

    vector<int> val = {10, 40, 50, 70};
    vector<int> wt = {1, 3, 4, 5};
    int cap = 8;

    cout << "Unbounded Knapsack (1D single array): "
         << obj.unbounded1D(val, wt, cap) << endl;

    return 0;
}