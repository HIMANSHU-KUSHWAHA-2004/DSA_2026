#include <bits\stdc++.h>
using namespace std;
int answer(int idx, vector<int> &arr, int sum,vector<vector<int>>& dp)
{
    if (idx == 0)
    {
        if (sum == 0 && arr[0] == 0)
            return 2;
        if (sum == 0 || sum == arr[0])
            return 1;
        return 0;
    }
    if(dp[idx][sum] != -1) return dp[idx][sum];
    int notake = answer(idx - 1, arr, sum,dp);
    int take = 0;
    if (arr[idx] <= sum)
    {
        take = answer(idx - 1, arr, sum - arr[idx],dp);
    }
    return dp[idx][sum] = take + notake;
}

int main()
{
    vector<int> arr = {0, 0, 1};
    int sum = 1;
    vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
    int n = arr.size();
    cout << "Memo Answer: " << answer(n - 1, arr, sum,dp) << endl;
    return 0;
}