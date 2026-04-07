#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<pair<int, int>, bool> Dp;

    bool can(int current, int last, int jump, map<int, int>& mpp) {

        // 🔷 Base Case
        if (current == last) {
            return Dp[{current, jump}] = true;   // store + return
        }

        // 🔷 DP Check
        if (Dp.find({current, jump}) != Dp.end()) {
            return Dp[{current, jump}];
        }

        // 🔷 Try all 3 jumps
        for (int i = -1; i <= 1; i++) {
            int canjump = jump + i;

            if (canjump <= 0) continue;

            int nextpos = current + canjump;

            if (mpp.find(nextpos) != mpp.end()) {
                if (can(nextpos, last, canjump, mpp)) {
                    return Dp[{current, jump}] = true;
                }
            }
        }

        // 🔷 If all fail
        return Dp[{current, jump}] = false;
    }

    bool canCross(vector<int>& stones) {

        if (stones[1] != 1) return false;

        map<int, int> mpp;

        for (int i = 0; i < stones.size(); i++) {
            mpp[stones[i]] = i;
        }

        return can(1, stones.back(), 1, mpp);
    }
};

// 🔷 Driver Code (for testing in VS Code)
int main() {
    Solution obj;

    vector<int> stones = {0,1,3,4,5,7,9};

    if (obj.canCross(stones)) {
        cout << "Can Cross ✅" << endl;
    } else {
        cout << "Cannot Cross ❌" << endl;
    }

    return 0;
}