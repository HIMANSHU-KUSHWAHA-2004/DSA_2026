#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Start from last row
        vector<int> dp = triangle[n - 1];

        // Bottom-up calculation
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }

        return dp[0];
    }
};

// Driver code (for testing)
int main() {
    Solution obj;

    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    cout << obj.minimumTotal(triangle) << endl; // Output: 11

    return 0;
}