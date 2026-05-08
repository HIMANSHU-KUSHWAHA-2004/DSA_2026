// tabu_1d.cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tabu2(vector<int> &val, vector<int> &wt, int cap) {
        int n = val.size();
        vector<int> dp(cap + 1, 0);

        for (int j = 0; j <= cap; j++) {
            if (wt[0] > j) {
                dp[j] = 0;
            } else {
                dp[j] = (j / wt[0]) * val[0];
            }
        }

        for (int i = 1; i < n; i++) {
            vector<int> curr(cap + 1, 0);

            for (int j = 0; j <= cap; j++) {

                int notake = dp[j];
                int take = 0;

                if (wt[i] <= j) {
                    take = val[i] + curr[j - wt[i]];
                    //here we know we have to use the different array because we are in the same iteration 
                    //and we have to take the value from the current array we have infinite number of times we can take the same item.
                }

                curr[j] = max(take, notake);
            }

            dp = curr;
        }

        return dp[cap];
    }
};

int main() {
    Solution obj;

    vector<int> val = {10, 40, 50, 70};
    vector<int> wt = {1, 3, 4, 5};
    int cap = 8;

    cout << "Tabulation 1D Answer: " << obj.tabu2(val, wt, cap) << endl;

    return 0;
}