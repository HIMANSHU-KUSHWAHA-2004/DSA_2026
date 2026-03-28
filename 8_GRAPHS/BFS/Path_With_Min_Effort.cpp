/*🔷 LeetCode Problem

👉 Number: 1631
👉 Name: Path With Minimum Effort

🔷 Problem Statement (short)

👉 You are given a grid heights[][]
👉 You can move in 4 directions

👉 Effort of a path =

maximum absolute difference between adjacent cells

👉 Return minimum effort from (0,0) → (n-1,m-1)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));

        // min heap {effort, {row, col}}
        priority_queue<pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>> pq;

        effort[0][0] = 0;
        pq.push({0, {0,0}});

        int dx[] = {0,1,-1,0};
        int dy[] = {1,0,0,-1};

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // 🔥 reached destination
            if(r == n-1 && c == m-1) return diff;

            for(int i = 0; i < 4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m){

                    int newEffort = max(diff, abs(heights[nr][nc] - heights[r][c]));

                    if(newEffort < effort[nr][nc]){
                        effort[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> heights = {
        {1,2,2},
        {3,8,2},
        {5,3,5}
    };

    int ans = obj.minimumEffortPath(heights);

    cout << "Minimum Effort Path: " << ans << endl;

    return 0;
}