
#include <bits/stdc++.h>
using namespace std;
int countWays(string &s)
{
    int n = s.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

    // Base case
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'T')
            dp[i][i][1] = 1;
        else
            dp[i][i][0] = 1;
    }

    // length of substring
    for (int len = 3; len <= n; len += 2)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;

            for (int k = i + 1; k <= j - 1; k += 2)
            {

                int LT = dp[i][k - 1][1];
                int LF = dp[i][k - 1][0];
                int RT = dp[k + 1][j][1];
                int RF = dp[k + 1][j][0];

                if (s[k] == '|')
                {
                    dp[i][j][1] += LT * RT + LT * RF + LF * RT;
                    dp[i][j][0] += LF * RF;
                }
                else if (s[k] == '&')
                {
                    dp[i][j][1] += LT * RT;
                    dp[i][j][0] += LT * RF + LF * RT + LF * RF;
                }
                else if (s[k] == '^')
                {
                    dp[i][j][1] += LT * RF + LF * RT;
                    dp[i][j][0] += LT * RT + LF * RF;
                }
            }
        }
    }

    return dp[0][n - 1][1];
}
