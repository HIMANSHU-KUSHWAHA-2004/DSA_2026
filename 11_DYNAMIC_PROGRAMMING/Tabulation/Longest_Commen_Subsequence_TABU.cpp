#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int longestCommonSubsequence(string s1,
                                 string s2) {

        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(
            m + 1,
            vector<int>(n + 1, 0)
        );

        // Base Case already 0

        for(int i = 1; i <= m; i++) {

            for(int j = 1; j <= n; j++) {

                // MATCH
                if(s1[i - 1] == s2[j - 1]) {

                    dp[i][j] =
                        1 + dp[i - 1][j - 1];
                }

                // NOT MATCH
                else {

                    dp[i][j] =
                        max(dp[i - 1][j],
                            dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {

    string s1 = "abcde";
    string s2 = "ace";

    Solution obj;

    cout << obj.longestCommonSubsequence(s1, s2);

    return 0;
}