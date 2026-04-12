#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();

        // 🔷 Map stone value to index
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++){
            mpp[stones[i]] = i;
        }

        // 🔷 dp[i] = set of jumps possible at stone i
        vector<unordered_set<int>> dp(n);

        // 🔷 Start
        dp[0].insert(0);
        
        // 🔷 Fill DP
        for(int i = 0; i < n; i++){
            for(int jump : dp[i]){

                for(int k = jump - 1; k <= jump + 1; k++){

                    if(k <= 0) continue;

                    int nextPos = stones[i] + k;

                    if(mpp.find(nextPos) != mpp.end()){
                        int nextIndex = mpp[nextPos];
                        dp[nextIndex].insert(k);
                    }
                }
            }
        }

        // 🔷 Check last stone
        return !dp[n-1].empty();
    }
};


// 🔷 Driver Code
int main(){
    Solution obj;

    vector<int> stones = {0,1,3,4,5,7,9};

    if(obj.canCross(stones)){
        cout << "Can Cross ✅" << endl;
    } else {
        cout << "Cannot Cross ❌" << endl;
    }

    return 0;
}