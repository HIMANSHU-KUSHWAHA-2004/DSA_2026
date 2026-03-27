#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;

        int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
        int dy[] = {1, 0, -1, 0, -1, 1, 1, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            for (int i = 0; i < 8; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                    grid[nr][nc] == 0) {
                    
                    if (dist[r][c] + 1 < dist[nr][nc]) {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        if (dist[n - 1][n - 1] == INT_MAX)
            return -1;

        return dist[n - 1][n - 1];
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 0, 0}
    };

    int result = obj.shortestPathBinaryMatrix(grid);

    cout << "Shortest Path Length: " << result << endl;

    return 0;
}
