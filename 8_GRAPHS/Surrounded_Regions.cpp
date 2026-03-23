#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 130. Surrounded Regions

Problem Statement:
Given an m × n board containing 'X' and 'O',
capture all regions that are surrounded by 'X'.

A region is captured by flipping all 'O' into 'X'
if that region is completely surrounded by 'X'.

Important Rule:
'O' connected to the boundary cannot be flipped,
because they are not fully surrounded.

Approach:
1. Traverse the boundary (first row, last row, first column, last column).
2. Start DFS from every boundary 'O'.
3. Mark those 'O' and their connected 'O' as visited (safe).
4. Convert remaining 'O' (not visited) into 'X'.
*/

class Solution {
public:

    // DFS to mark boundary-connected 'O' as safe
    void dfs(vector<vector<int>> &visited, vector<vector<char>> &grid, int r, int c)
    {
        visited[r][c] = 1;

        // Directions: right, down, left, up
        int dirx[] = {0,1,0,-1};
        int diry[] = {1,0,-1,0};

        for(int i = 0; i < 4; i++)
        {
            int row = r + dirx[i];
            int col = c + diry[i];

            // Check if inside grid and valid 'O'
            if(row >= 0 && row < grid.size() &&
               col >= 0 && col < grid[0].size() &&
               grid[row][col] == 'O' &&
               !visited[row][col])
            {
                dfs(visited, grid, row, col);
            }
        }
    }

    void solve(vector<vector<char>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> visited(r, vector<int>(c,0));

        // Check first and last column
        for(int i = 0; i < r; i++)
        {
            if(grid[i][0] == 'O' && !visited[i][0])
                dfs(visited, grid, i, 0);

            if(grid[i][c-1] == 'O' && !visited[i][c-1])
                dfs(visited, grid, i, c-1);
        }

        // Check first and last row
        for(int i = 0; i < c; i++)
        {
            if(grid[0][i] == 'O' && !visited[0][i])
                dfs(visited, grid, 0, i);

            if(grid[r-1][i] == 'O' && !visited[r-1][i])
                dfs(visited, grid, r-1, i);
        }

        // Flip surrounded 'O'
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(!visited[i][j] && grid[i][j] == 'O')
                    grid[i][j] = 'X';
            }
        }
    }
};

int main()
{
    Solution obj;

    /*
    Example Input Board

    X O X X
    O X O X
    X O X O
    O X O X
    */

    vector<vector<char>> board = {
        {'X','O','X','X'},
        {'O','X','O','X'},
        {'X','O','X','O'},
        {'O','X','O','X'}
    };

    cout << "Original Board:\n";
    for(auto &row : board)
    {
        for(auto &c : row)
            cout << c << " ";
        cout << endl;
    }

    obj.solve(board);

    cout << "\nFinal Board:\n";
    for(auto &row : board)
    {
        for(auto &c : row)
            cout << c << " ";
        cout << endl;
    }

    return 0;
}