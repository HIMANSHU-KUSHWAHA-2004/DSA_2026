#include <bits\stdc++.h>
using namespace std;
void permu(vector<int> &nums, vector<vector<int>> &answer, map<int, bool> &mpp, vector<int> &temp)
{
    if (temp.size() == nums.size())
    {
        answer.push_back({temp});
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if(mpp[i])
            continue;
        if(i > 0 && nums[i] == nums[i - 1] && mpp[i-1] != false)
            continue;

        mpp[i] = true;
        temp.push_back(nums[i]);
        permu(nums, answer, mpp, temp);
        temp.pop_back();
        mpp[i] = false;
    }
}
int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> answer;
    sort(nums.begin(), nums.end());
    map<int, bool> mppp;
    vector<int> temp;
    permu(nums, answer, mppp, temp);
    for (auto i : answer)
    {
        for (auto k : i)
        {
            cout << k << " ";
        }
        cout << endl;
    }
}