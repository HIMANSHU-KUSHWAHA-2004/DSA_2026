#include <bits/stdc++.h>
using namespace std;

/*
=====================================================================
🔥 GRID DP MASTER TEMPLATE
=====================================================================

👉 PATTERN:
    We are at cell (r, c)

👉 GOAL:
    Move from start → end OR end → start

👉 MOVES (MOST COMMON):
    ✔ Right  → (r, c+1)
    ✔ Down   → (r+1, c)

=====================================================================
🔥 CORE IDEA
=====================================================================

👉 dp[r][c] = answer from cell (r, c)

👉 You ALWAYS come from:
    ✔ Top    (r-1, c)
    ✔ Left   (r, c-1)

=====================================================================
*/


class Solution {
public:

/*====================================================================
🔥 MEMOIZATION (TOP-DOWN)
====================================================================*/

int memo(int r, int c, vector<vector<int>>& grid,
         vector<vector<int>>& dp){

    int n = grid.size();
    int m = grid[0].size();

    /*
    ================================================================
    🔥 BASE CASE THINKING
    ================================================================

    👉 Destination reached → return value
    👉 Out of bounds → invalid path

    ---------------------------------------------------------------
    */

    if(r >= n || c >= m) return 1e9;  // invalid path (for MIN problems)

    if(r == n-1 && c == m-1){
        return grid[r][c];  // reached destination
    }

    if(dp[r][c] != -1) return dp[r][c];

    // 🔥 MOVE RIGHT
    int right = memo(r, c+1, grid, dp);

    // 🔥 MOVE DOWN
    int down = memo(r+1, c, grid, dp);

    return dp[r][c] = grid[r][c] + min(right, down);
}


/*====================================================================
🔥 TABULATION (BOTTOM-UP)
====================================================================*/

int tabu(vector<vector<int>>& grid){

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    /*
    ================================================================
    🔥 BASE CASE (IMPORTANT)
    ================================================================

    👉 Start filling from DESTINATION (bottom-right)
    ================================================================
    */

    dp[n-1][m-1] = grid[n-1][m-1];

    /*
    ================================================================
    🔁 FILL LAST ROW (only right movement possible)
    ================================================================
    */

    for(int j = m-2; j >= 0; j--){
        dp[n-1][j] = grid[n-1][j] + dp[n-1][j+1];
    }

    /*
    ================================================================
    🔁 FILL LAST COLUMN (only down movement possible)
    ================================================================
    */

    for(int i = n-2; i >= 0; i--){
        dp[i][m-1] = grid[i][m-1] + dp[i+1][m-1];
    }

    /*
    ================================================================
    🔁 FILL REMAINING GRID
    ================================================================
    */

    for(int i = n-2; i >= 0; i--){
        for(int j = m-2; j >= 0; j--){

            int right = dp[i][j+1];
            int down  = dp[i+1][j];

            dp[i][j] = grid[i][j] + min(right, down);
        }
    }

    return dp[0][0];
}

};


/*====================================================================
🔥 MAIN EXAMPLE
====================================================================*/

int main(){

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    Solution obj;

    int n = grid.size();
    int m = grid[0].size();

    // 🔥 MEMO
    vector<vector<int>> dp1(n, vector<int>(m, -1));
    cout << "Memo Answer: " << obj.memo(0, 0, grid, dp1) << endl;

    // 🔥 TABU
    cout << "Tabu Answer: " << obj.tabu(grid) << endl;

    return 0;
}