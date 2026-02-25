#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Given tasks[i] = {enqueueTime, processingTime}
Return the order in which CPU processes the tasks.

Rules:
1. If CPU is idle and no task available → jump time forward.
2. If multiple tasks available → pick:
      - smallest processing time
      - if tie → smallest index
*/

class Solution {
public:
    // Pair = {processingTime, index}
    using P = pair<int, int>;

    vector<int> getOrder(vector<vector<int>>& tasks) {

        int n = tasks.size();

        // Store {enqueueTime, processingTime, index}
        vector<array<int, 3>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({tasks[i][0], tasks[i][1], i});
        }

        // Sort tasks by enqueueTime
        sort(arr.begin(), arr.end());

        // Min-heap → smallest processing time first
        priority_queue<P, vector<P>, greater<P>> pq;

        long long current_time = 0;  // Use long long to avoid overflow
        int index = 0;

        vector<int> result;

        // Run while tasks remain OR heap not empty
        while (index < n || !pq.empty()) {

            // If CPU is idle → move time forward
            if (pq.empty() && current_time < arr[index][0]) {
                current_time = arr[index][0];
            }

            // Push all available tasks at current_time
            while (index < n && arr[index][0] <= current_time) {
                pq.push({arr[index][1], arr[index][2]});
                index++;
            }

            // Take task with smallest processing time
            auto topTask = pq.top();
            pq.pop();

            int processingTime = topTask.first;
            int taskIndex = topTask.second;

            current_time += processingTime;
            result.push_back(taskIndex);
        }

        return result;
    }
};

int main() {

    Solution sol;

    // Example Input
    vector<vector<int>> tasks = {
        {1, 2},
        {2, 4},
        {3, 2},
        {4, 1}
    };

    vector<int> order = sol.getOrder(tasks);

    cout << "Execution Order: ";
    for (int x : order) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}