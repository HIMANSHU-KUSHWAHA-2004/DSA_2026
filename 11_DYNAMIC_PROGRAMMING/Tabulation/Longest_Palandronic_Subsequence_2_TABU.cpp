#include <bits/stdc++.h>
using namespace std;

/*
=========================================================
LONGEST PALINDROMIC SUBSEQUENCE
(DIRECT INTERVAL DP)
=========================================================

EXAMPLE:

Input:
bbbab

Output:
4

Possible palindrome subsequence:
bbbb

=========================================================
*/

class Solution {
public:

    int longestPalindromeSubseq(string s) {

        int n = s.size();

        vector<vector<int>> dp(
            n,
            vector<int>(n, 0)
        );

        // Single character palindrome
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Length of substring
        for(int len = 2; len <= n; len++) {

            for(int i = 0; i < n; i++) {

                int j = i + len - 1;

                // Out of bound
                if(j >= n)
                    break;

                // MATCH
                if(s[i] == s[j]) {

                    if(len == 2)
                        dp[i][j] = 2;

                    else
                        dp[i][j] =
                            2 + dp[i+1][j-1];
                }

                // NOT MATCH
                else {

                    dp[i][j] = max(
                        dp[i+1][j],
                        dp[i][j-1]
                    );
                }
            }
        }

        return dp[0][n-1];
    }
};

int main() {

    Solution obj;

    string s = "bbbab";

    cout << "String : " << s << endl;

    cout << "Longest Palindromic Subsequence Length : ";

    cout << obj.longestPalindromeSubseq(s);

    return 0;
}