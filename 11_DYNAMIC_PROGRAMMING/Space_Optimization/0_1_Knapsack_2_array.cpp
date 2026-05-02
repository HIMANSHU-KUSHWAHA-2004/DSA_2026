// 📄 file: Knapsack_SPACE_2ARRAY.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int knapsack(int W, vector<int>& val, vector<int>& wt){
        int n = val.size();

        vector<int> prev(W+1, 0);

        // 🔥 base case
        for(int w = wt[0]; w <= W; w++){
            prev[w] = val[0];
        }

        for(int i = 1; i < n; i++){
            vector<int> curr(W+1, 0);

            for(int w = 0; w <= W; w++){

                int notTake = prev[w];

                int take = 0;
                if(wt[i] <= w){
                    take = val[i] + prev[w - wt[i]];
                }

                curr[w] = max(take, notTake);
            }

            prev = curr;
        }

        return prev[W];
    }
};

int main(){
    vector<int> val = {60, 100, 120};
    vector<int> wt  = {10, 20, 30};
    int W = 50;

    Solution obj;
    cout << "Space 2-array Answer: " << obj.knapsack(W, val, wt) << endl;

    return 0;
}