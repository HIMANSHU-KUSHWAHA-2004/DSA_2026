#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // store all LCS strings
    vector<vector<set<string>>> store;

    // check if state already computed
    vector<vector<bool>> visited;

    set<string> maker(int i, int j,
                      string &s1,
                      string &s2,
                      vector<vector<int>> &Dp) {

        set<string> ans;

        // base case
        if(i == 0 || j == 0) {
            return {""};
        }

        // already computed
        if(visited[i][j]) {
            return store[i][j];
        }

        visited[i][j] = true;

        // characters match
        if(s1[i - 1] == s2[j - 1]) {

            set<string> temp =
                maker(i - 1, j - 1, s1, s2, Dp);

            for(auto x : temp) {
                ans.insert(x + s1[i - 1]);
            }

            return store[i][j] = ans;
        }

        // move up
        if(Dp[i - 1][j] > Dp[i][j - 1]) {

            set<string> temp =
                maker(i - 1, j, s1, s2, Dp);

            for(auto x : temp) {
                ans.insert(x);
            }

            return store[i][j] = ans;
        }

        // move left
        else if(Dp[i - 1][j] < Dp[i][j - 1]) {

            set<string> temp =
                maker(i, j - 1, s1, s2, Dp);

            for(auto x : temp) {
                ans.insert(x);
            }

            return store[i][j] = ans;
        }

        // both equal -> explore both paths
        else {

            set<string> up =
                maker(i - 1, j, s1, s2, Dp);

            set<string> left =
                maker(i, j - 1, s1, s2, Dp);

            for(auto x : up) {
                ans.insert(x);
            }

            for(auto x : left) {
                ans.insert(x);
            }

            return store[i][j] = ans;
        }
    }

    vector<string> allLCS(string &s1, string &s2) {

        int m = s1.size();
        int n = s2.size();

        // normal LCS DP
        vector<vector<int>> Dp(
            m + 1,
            vector<int>(n + 1, 0)
        );

        for(int i = 1; i <= m; i++) {

            for(int j = 1; j <= n; j++) {

                if(s1[i - 1] == s2[j - 1]) {
                    Dp[i][j] =
                        1 + Dp[i - 1][j - 1];
                }

                else {
                    Dp[i][j] =
                        max(Dp[i - 1][j],
                            Dp[i][j - 1]);
                }
            }
        }

        // initialize memoization arrays
        store.resize(
            m + 1,
            vector<set<string>>(n + 1)
        );

        visited.resize(
            m + 1,
            vector<bool>(n + 1, false)
        );

        // get all LCS strings
        set<string> temp =
            maker(m, n, s1, s2, Dp);

        // convert set -> vector
        vector<string> ans(
            temp.begin(),
            temp.end()
        );

        return ans;
    }
};

int main() {

    string s1 = "abc";
    string s2 = "bac";

    Solution obj;

    vector<string> ans =
        obj.allLCS(s1, s2);

    for(auto x : ans) {
        cout << x << endl;
    }

    return 0;
}