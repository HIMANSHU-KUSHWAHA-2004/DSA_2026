#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int idx,
              vector<int> &price,
              int len,
              vector<vector<int>> &dp)
    {

        if (idx == 0)
        {
            return len * price[0];
        }

        if (dp[idx][len] != -1)
        {
            return dp[idx][len];
        }

        int notTake = solve(idx - 1, price, len, dp);

        int take = -1e9;

        if (idx + 1 <= len)
        {
            take = price[idx] +
                   solve(idx, price,
                         len - (idx + 1),
                         dp);
        }

        return dp[idx][len] =
                   max(take, notTake);
    }

    int cutRod(vector<int> &price)
    {

        int n = price.size();

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1));

        return solve(n - 1, price, n, dp);
    }
};

int main()
{

    vector<int> price = {2, 5, 7, 8};

    Solution obj;

    cout << obj.cutRod(price);

    return 0;
}