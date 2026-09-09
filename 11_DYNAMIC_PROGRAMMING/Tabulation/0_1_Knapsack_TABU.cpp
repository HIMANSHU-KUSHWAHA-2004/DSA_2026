// 📄 file: Knapsack_TABU.cpp//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int knapsack(int W, vector<int>& val, vector<int>& wt){
        int n = val.size();

        vector<vector<int>> dp(n, vector<int>(W+1, 0));

        // 🔥 base case (row 0)
        for(int w = wt[0]; w <= W; w++){
            dp[0][w] = val[0];
        }

        // 🔥 fill table
        for(int i = 1; i < n; i++){
            for(int w = 0; w <= W; w++){

                int notTake = dp[i-1][w];

                int take = 0;
                if(wt[i] <= w){
                    take = val[i] + dp[i-1][w - wt[i]];
                }

                dp[i][w] = max(take, notTake);
            }
        }

        return dp[n-1][W];
    }
};

int main(){
    vector<int> val = {60, 100, 120};
    vector<int> wt  = {10, 20, 30};
    int W = 50;

    Solution obj;
    cout << "Tabu 2D Answer: " << obj.knapsack(W, val, wt) << endl;

    return 0;
}