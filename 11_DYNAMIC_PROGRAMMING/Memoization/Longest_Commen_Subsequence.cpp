#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Boka(int m, int n, string &st1,
             string &st2,
             vector<vector<int>> &dp)
    {

        // Base Case
        if (m == 0 || n == 0)
        {
            return 0;
        }

        // Already Computed
        if (dp[m][n] != -1)
        {
            return dp[m][n];
        }

        // MATCH
        if (st1[m - 1] == st2[n - 1])
        {

            return dp[m][n] =
                       1 + Boka(m - 1,
                                n - 1,
                                st1,
                                st2,
                                dp);
        }

        // NOT MATCH
        int left =
            Boka(m - 1,
                 n,
                 st1,
                 st2,
                 dp);

        int right =
            Boka(m,
                 n - 1,
                 st1,
                 st2,
                 dp);

        return dp[m][n] =
                   max(left, right);
    }

    int longestCommonSubsequence(string text1,
                                 string text2)
    {

        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(
            m + 1,
            vector<int>(n + 1, -1));

        return Boka(m,
                    n,
                    text1,
                    text2,
                    dp);
    }
};

int main()
{

    string s1 = "abcde";
    string s2 = "ace";

    Solution obj;

    cout << obj.longestCommonSubsequence(s1, s2);

    return 0;
}