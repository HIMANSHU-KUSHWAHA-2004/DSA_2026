#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cutRod(vector<int> &price)
    {

        int n = price.size();

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, 0));

        // Base Row
        for (int j = 0; j <= n; j++)
        {
            dp[0][j] = j * price[0];
        }

        for (int i = 1; i < n; i++)
        {

            for (int j = 0; j <= n; j++)
            {

                int notTake = dp[i - 1][j];

                int take = -1e9;

                // current rod length = i + 1
                int rodLength = i + 1;
                if (rodLength <= j)
                {
                    take = price[i] +
                           dp[i][j - rodLength];
                }

                dp[i][j] =
                    max(take, notTake);
            }
        }

        return dp[n - 1][n];
    }
};

int main()
{

    vector<int> price = {2, 5, 7, 8};

    Solution obj;

    cout << obj.cutRod(price);

    return 0;
}