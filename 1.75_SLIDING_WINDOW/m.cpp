#include <bits/stdc++.h>
using namespace std;

void permu(vector<int> &nums, vector<vector<int>> &answer, map<int,bool> &mpp, vector<int> &temp) {
    if (temp.size() == nums.size()) {
        answer.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (!mpp[i]) {
            // skip duplicates: if current number is same as previous AND previous not used
            if (i > 0 && nums[i] == nums[i-1] && !mpp[i-1]) continue;

            mpp[i] = true;
            temp.push_back(nums[i]);

            permu(nums, answer, mpp, temp);

            temp.pop_back();
            mpp[i] = false;
        }
    }
}

int main() {
    vector<int> nums = {1, 2, 2};
    sort(nums.begin(), nums.end()); // important for skipping duplicates

    vector<vector<int>> answer;
    map<int,bool> mpp; // here we track by index, not by value
    vector<int> temp;

    permu(nums, answer, mpp, temp);

    for (auto &i : answer) {
        for (auto k : i) cout << k << " ";
        cout << endl;
    }
}
