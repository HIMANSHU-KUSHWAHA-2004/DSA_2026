#include <bits/stdc++.h>
using namespace std;

/*
================= PROBLEM STATEMENT =================

You are given a 2D grid of characters.

A cycle exists if:
1. You move in 4 directions (up, down, left, right)
2. You only move to adjacent cells having SAME character
3. You revisit a cell that is NOT your immediate parent
4. The cycle length >= 4

Return true if cycle exists, otherwise false.

====================================================
*/

class Solution {
public:

    // ================= DFS =================
    bool DFS(int r, int c, int pr, int pc,
             vector<vector<char>>& grid,
             vector<vector<int>>& visited) {

        int n = grid.size();
        int m = grid[0].size();

        visited[r][c] = 1;

        int dx[] = {0, 1, -1, 0};
        int dy[] = {1, 0, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                continue;

            if (grid[nr][nc] != grid[r][c])
                continue;

            if (!visited[nr][nc]) {
                if (DFS(nr, nc, r, c, grid, visited))
                    return true;
            }
            else if (nr != pr || nc != pc) {
                return true; // cycle found
            }
        }

        return false;
    }

    bool containsCycleDFS(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    if (DFS(i, j, -1, -1, grid, visited))
                        return true;
                }
            }
        }

        return false;
    }

    // ================= BFS =================
    bool BFS(int sr, int sc,
             vector<vector<char>>& grid,
             vector<vector<int>>& visited) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, pair<int,int>>> q;

        q.push({{sr, sc}, {-1, -1}});
        visited[sr][sc] = 1;

        int dx[] = {0, 1, -1, 0};
        int dy[] = {1, 0, 0, -1};

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            int r = node.first.first;
            int c = node.first.second;
            int pr = node.second.first;
            int pc = node.second.second;

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;

                if (grid[nr][nc] != grid[r][c])
                    continue;

                if (!visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    q.push({{nr, nc}, {r, c}});
                }
                else if (nr != pr || nc != pc) {
                    return true; // cycle found
                }
            }
        }

        return false;
    }

    bool containsCycleBFS(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    if (BFS(i, j, grid, visited))
                        return true;
                }
            }
        }

        return false;
    }
};

// ================= MAIN FUNCTION =================
int main() {

    /*
    Example Grid:

    A A A
    A B A
    A A A

    This forms a cycle of 'A'
    */

    vector<vector<char>> grid = {
        {'A','A','A'},
        {'A','B','A'},
        {'A','A','A'}
    };

    Solution obj;

    // DFS result
    bool dfsResult = obj.containsCycleDFS(grid);

    // BFS result
    bool bfsResult = obj.containsCycleBFS(grid);

    cout << "DFS Cycle Detection: " << (dfsResult ? "Cycle Found" : "No Cycle") << endl;
    cout << "BFS Cycle Detection: " << (bfsResult ? "Cycle Found" : "No Cycle") << endl;

    return 0;
}