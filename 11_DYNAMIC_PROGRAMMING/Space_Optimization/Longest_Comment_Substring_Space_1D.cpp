#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
        dp[j]

        = previous row values reused

        We traverse backward because:

        current state needs:
        old dp[j-1]
    */

    int longestCommonSubstring(string &s1,
                               string &s2) {

        int m = s1.size();
        int n = s2.size();

        vector<int> dp(n + 1, 0);

        int ans = 0;

        for(int i = 1; i <= m; i++) {

            // backward traversal
            for(int j = n; j >= 1; j--) {

                // characters match
                if(s1[i - 1] == s2[j - 1]) {

                    dp[j] =
                        1 + dp[j - 1];

                    ans =
                        max(ans, dp[j]);
                }

                // substring breaks
                else {

                    dp[j] = 0;
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

    cout << obj.longestCommonSubstring(s1, s2);

    return 0;
}