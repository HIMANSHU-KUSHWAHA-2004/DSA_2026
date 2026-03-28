#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    🔥 EXAMPLE DRY RUN

    graph = {
        {1, 2},   // 0 → 1, 2
        {3},      // 1 → 3
        {3},      // 2 → 3
        {}        // 3
    }

    target = 3

    ALL PATHS:
    0 → 1 → 3
    0 → 2 → 3

    ----------------------------------

    🔶 STEP BY STEP:

    Call Back(0)
    path = [0]

        → go to 1
        path = [0,1]

            → go to 3
            path = [0,1,3]
            ✔ reached target → store
            backtrack → path = [0,1]

        backtrack → path = [0]

        → go to 2
        path = [0,2]

            → go to 3
            path = [0,2,3]
            ✔ reached target → store
            backtrack → path = [0,2]

        backtrack → path = [0]

    final backtrack → path = []

    ----------------------------------

    ans = {
        {0,1,3},
        {0,2,3}
    }
    */

    // 🔷 BACKTRACK FUNCTION
    void Back(vector<vector<int>>& graph,
              vector<vector<int>>& ans,
              int nd,
              int target,
              vector<int>& path) {

        // 🔶 STEP 1: CHOOSE
        path.push_back(nd);

        // 🔶 STEP 2: BASE CASE
        if (nd == target) {
            ans.push_back(path);
        }
        else {
            // 🔶 STEP 3: EXPLORE
            for (auto j : graph[nd]) {
                Back(graph, ans, j, target, path);
            }
        }

        // 🔶 STEP 4: UN-CHOOSE (BACKTRACK)
        path.pop_back();
    }

    // 🔷 MAIN LOGIC FUNCTION
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<vector<int>> ans;
        vector<int> path;

        int target = n - 1; // 🔶 last node

        Back(graph, ans, 0, target, path);

        return ans;
    }
};


// 🔷 MAIN FUNCTION (FOR TESTING)
int main() {

    Solution obj;

    // 🔥 TEST GRAPH
    vector<vector<int>> graph = {
        {1, 2},   // 0
        {3},      // 1
        {3},      // 2
        {}        // 3
    };

    vector<vector<int>> result = obj.allPathsSourceTarget(graph);

    cout << "All Paths from 0 to n-1:\n";

    for (auto &path : result) {
        for (auto node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}