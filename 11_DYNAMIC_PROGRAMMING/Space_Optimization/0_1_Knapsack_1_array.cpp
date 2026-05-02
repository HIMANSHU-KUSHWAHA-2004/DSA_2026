// 📄 file: Knapsack_SPACE_1ARRAY.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int knapsack(int W, vector<int>& val, vector<int>& wt){
        int n = val.size();

        vector<int> dp(W+1, 0);

        // 🔥 base case
        for(int w = wt[0]; w <= W; w++){
            dp[w] = val[0];
        }

        for(int i = 1; i < n; i++){
            for(int w = W; w >= 0; w--){   // 🔥 reverse loop

                int notTake = dp[w];

                int take = 0;
                if(wt[i] <= w){
                    take = val[i] + dp[w - wt[i]];
                }

                dp[w] = max(take, notTake);
            }
        }

        return dp[W];
    }
};

int main(){
    vector<int> val = {60, 100, 120};
    vector<int> wt  = {10, 20, 30};
    int W = 50;

    Solution obj;
    cout << "Space 1-array Answer: " << obj.knapsack(W, val, wt) << endl;

    return 0;
}