// LeetCode 407 - Trapping Rain Water II
// Min Heap + BFS Solution
// Time Complexity: O(m * n log(m * n))

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, pair<int,int>> P;

    int trapRainWater(vector<vector<int>>& heightMap) {

        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m <= 2 || n <= 2)
            return 0;

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Push left & right boundary
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n - 1], {i, n - 1}});
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }

        // Push top & bottom boundary
        for (int j = 1; j < n - 1; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m - 1][j], {m - 1, j}});
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }

        int water = 0;

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        while (!pq.empty()) {

            P cur = pq.top();
            pq.pop();

            int height = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;

            for (int k = 0; k < 4; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                if (visited[nx][ny])
                    continue;

                visited[nx][ny] = true;

                int neighborHeight = heightMap[nx][ny];

                if (neighborHeight < height)
                    water += (height - neighborHeight);

                pq.push({max(height, neighborHeight), {nx, ny}});
            }
        }

        return water;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> heightMap = {
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}
    };

    int result = obj.trapRainWater(heightMap);

    cout << "Trapped Water = " << result << endl;

    return 0;
}