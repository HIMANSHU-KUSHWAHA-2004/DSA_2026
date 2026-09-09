#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
        dp[i][j]

        = length of common substring
          ending at:

          s1[i-1]
          s2[j-1]
    */

    int longestCommonSubstring(string &s1,
                               string &s2) {

        int m = s1.size();
        int n = s2.size();

        // DP table
        vector<vector<int>> dp(
            m + 1,
            vector<int>(n + 1, 0)
        );

        int ans = 0;

        for(int i = 1; i <= m; i++) {

            for(int j = 1; j <= n; j++) {

                // characters match
                if(s1[i - 1] == s2[j - 1]) {

                    dp[i][j] =
                        1 + dp[i - 1][j - 1];

                    ans =
                        max(ans, dp[i][j]);
                }

                // substring breaks
                else {

                    dp[i][j] = 0;
                }
            }
        }

        return ans;
    }
};

int main() {

    string s1 = "abcdgh";
    string s2 = "acdghr";

    Solution obj;
//
    cout << obj.longestCommonSubstring(s1, s2);

    return 0;
}