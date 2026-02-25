#include <bits\stdc++.h>
using namespace std;
void permu(vector<int> &nums, vector<vector<int>> &answer, int idx)
{
    if (idx == nums.size())
    {
        answer.push_back({nums});
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[i], nums[idx]);
        permu(nums, answer, idx + 1);
        swap(nums[i], nums[idx]);
    }
}
int main()
{
    vector<int> num = {1, 2, 3};
    vector<vector<int>> answer;
    permu(num, answer, 0);
    for (auto &i : answer)
    {
        for (auto &k : i)
        {
            cout << k << " ";
        }
        cout << endl;
    }
}