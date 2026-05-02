// 📄 file: Knapsack_MEMO.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp){
        
        // 🔥 base case
        if(idx == 0){
            if(wt[0] <= W) return val[0];
            return 0;
        }

        if(dp[idx][W] != -1) return dp[idx][W];

        int notTake = solve(idx-1, W, val, wt, dp);

        int take = 0;
        if(wt[idx] <= W){
            take = val[idx] + solve(idx-1, W - wt[idx], val, wt, dp);
        }

        return dp[idx][W] = max(take, notTake);
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt){
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return solve(n-1, W, val, wt, dp);
    }
};

int main(){
    vector<int> val = {60, 100, 120};
    vector<int> wt  = {10, 20, 30};
    int W = 50;

    Solution obj;
    cout << "Memo Answer: " << obj.knapsack(W, val, wt) << endl;

    return 0;
}