#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int DFS(int row, int col, vector<vector<int>>& tri, map<pair<int,int>, int>& mpp) {
        
        // Base case
        if (row == tri.size() - 1) {
            return tri[row][col];
        }

        // Already computed
        if (mpp.find({row, col}) != mpp.end()) {
            return mpp[{row, col}];
        }

        // Recursive calls
        int down = tri[row][col] + DFS(row + 1, col, tri, mpp);
        int diag = tri[row][col] + DFS(row + 1, col + 1, tri, mpp);

        // Store and return
        return mpp[{row, col}] = min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        map<pair<int,int>, int> mpp;
        return DFS(0, 0, triangle, mpp);
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