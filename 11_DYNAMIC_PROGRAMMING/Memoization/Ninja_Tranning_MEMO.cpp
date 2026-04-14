#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int solve(int day, int last, vector<vector<int>>& mat) {
        if (day == 0) {
            int maxi = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    maxi = max(maxi, mat[0][task]);
                }
            }
            return maxi;
        }

        if (dp[day][last] != -1)
            return dp[day][last];

        int maxi = 0;

        for (int task = 0; task < 3; task++) {
            if (task != last) {
                int points = mat[day][task] + solve(day - 1, task, mat);
                maxi = max(maxi, points);
            }
        }

        return dp[day][last] = maxi;
    }

    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        dp.resize(n, vector<int>(4, -1));
        return solve(n - 1, 3, mat);
    }
};

int main() {
    Solution obj;
    vector<vector<int>> mat = {
        {10, 50, 40},
        {20, 60, 30},
        {30, 20, 70}
    };
    cout << obj.maximumPoints(mat);
}