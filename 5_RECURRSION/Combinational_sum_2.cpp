#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combo_sum(int idx, int sum, int tar, vector<int>& can,
                   vector<int>& temp, vector<vector<int>>& answer) {
        // base case: if sum matches target, save result
        if (sum == tar) {
            answer.push_back(temp);
            return;
        }

        // if sum exceeds target OR index goes out of bounds, stop
        if (sum > tar || idx >= can.size())
            return;

        // 1. Its not like the old combinatinal sum here if we want does not want to repead then 
        //      we have to include the index
        temp.push_back(can[idx]);
        combo_sum(idx + 1, sum + can[idx], tar, can, temp, answer);
        temp.pop_back();
        while(idx + 1 < can.size() && can[idx] == can[idx + 1])
            idx++;

        // 2. Exclude current element (move to next idx)
        combo_sum(idx + 1, sum, tar, can, temp, answer);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> temp;
        combo_sum(0, 0, target, candidates, temp, answer);
        return answer;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> result = sol.combinationSum(candidates, target);

    // Print the results
    cout << "Combinations that sum to " << target << " are:\n";
    for (auto &comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
