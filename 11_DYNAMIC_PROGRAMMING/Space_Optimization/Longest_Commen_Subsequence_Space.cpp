#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int longestCommonSubsequence(string s1,
                                 string s2) {

        int m = s1.size();
        int n = s2.size();

        vector<int> prev(n + 1, 0),
                    curr(n + 1, 0);

        for(int i = 1; i <= m; i++) {

            curr[0] = 0;

            for(int j = 1; j <= n; j++) {

                // MATCH
                if(s1[i - 1] == s2[j - 1]) {

                    curr[j] =
                        1 + prev[j - 1];
                }

                // NOT MATCH
                else {

                    curr[j] =
                        max(prev[j],
                            curr[j - 1]);
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};

int main() {

    string s1 = "abcde";
    string s2 = "ace";

    Solution obj;

    cout << obj.longestCommonSubsequence(s1, s2);

    return 0;
}