class Solution {
public:
    int boka(int egg, int floor, vector<vector<int>>& dp) {

        if (dp[egg][floor] != -1) return dp[egg][floor];

        if (egg == 1) return dp[egg][floor] = floor;
        if (floor == 0 || floor == 1) return dp[egg][floor] = floor;

        int low = 1, high = floor;
        int ans = 1e9;

        while (low <= high) {
            int mid = (low + high) / 2;

            int left = boka(egg - 1, mid - 1, dp);     // break
            int right = boka(egg, floor - mid, dp);    // survive

            int temp = 1 + max(left, right);

            // minimize answer
            ans = min(ans, temp);

            // move towards balance point
            if (left < right) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return dp[egg][floor] = ans;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return boka(k, n, dp);
    }
};  