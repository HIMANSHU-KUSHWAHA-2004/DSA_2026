#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum > 0)
            {
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                res.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                {
                    j++;
                }
                /*WE DID THIS BECAUSE THERE IS NOT DUPLICATES ALLOW IN THE SET AND i IS ALREADY
               DONE IN THE LOOP AS YOU CAN SEE IN THE ABOVE LOOP*/
                while (j < k && nums[k] == nums[k + 1])
                {
                    k--;
                }
            }
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = threeSum(nums);

    for (auto &v : ans)
    {
        for (auto x : v)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
