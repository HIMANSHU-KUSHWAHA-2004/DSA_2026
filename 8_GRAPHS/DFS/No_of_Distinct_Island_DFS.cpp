#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Directions: Left, Right, Up, Down
    vector<tuple<int, int, char>> directions = {
        {0, -1, 'L'},
        {0, 1, 'R'},
        {-1, 0, 'U'},
        {1, 0, 'D'}};

    // DFS to generate shape string
    void dfs(vector<vector<int>> &grid,
             vector<vector<int>> &visited,
             int row,
             int col,
             string &path)
    {

        int r = grid.size();
        int c = grid[0].size();

        visited[row][col] = 1;

        for (auto dir : directions)
        {
            int dx = get<0>(dir);
            int dy = get<1>(dir);
            char ch = get<2>(dir);

            int newr = row + dx;
            int newc = col + dy;

            if (newr >= 0 && newr < r &&
                newc >= 0 && newc < c &&
                grid[newr][newc] == 1 &&
                !visited[newr][newc])
            {

                path.push_back(ch); // move
                dfs(grid, visited, newr, newc, path);
                path.push_back('B'); // backtrack
            }
        }
    }

    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> visited(r, vector<int>(c, 0));
        unordered_set<string> shapes;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {

                if (grid[i][j] == 1 && !visited[i][j])
                {

                    string path = "S"; // starting marker

                    dfs(grid, visited, i, j, path);

                    shapes.insert(path);
                }
            }
        }

        return shapes.size();
    }
};

int main()
{
    Solution obj;

    // 🔷 BIG EXAMPLE
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 0, 1, 0}};

    int result = obj.countDistinctIslands(grid);

    cout << "Number of distinct islands: " << result << endl;

    return 0;
}