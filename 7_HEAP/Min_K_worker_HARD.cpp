#include <bits/stdc++.h>
using namespace std;

/*
Problem: Minimum Cost to Hire K Workers

There are n workers. 
Each worker has:
- quality[i] → quality of work
- wage[i] → minimum wage expectation

We must hire exactly k workers such that:

1. Every worker in the group is paid in proportion to their quality.
2. Every worker receives at least their minimum wage.

If we choose a group with ratio R (wage per unit quality),
then total cost = R * (sum of qualities of chosen workers)

Goal:
Return the minimum total cost to hire exactly k workers.

Approach:
- Compute ratio = wage[i] / quality[i]
- Sort workers by ratio
- Use a max heap to keep k smallest qualities
- Try each worker as the manager (highest ratio in group)
*/

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {

        vector<pair<double, int>> Work_wage_ratio;
        int n = wage.size();

        // Step 1: Store (ratio, quality)
        for (int i = 0; i < n; i++) {
            double manager_ratio = (double)wage[i] / quality[i];
            Work_wage_ratio.push_back({manager_ratio, quality[i]});
        }

        // Step 2: Sort by ratio
        sort(Work_wage_ratio.begin(), Work_wage_ratio.end());

        // Max heap to keep largest quality at top
        priority_queue<int> pq;

        double quality_sum = 0;

        // Step 3: Take first k workers
        for (int i = 0; i < k; i++) {
            pq.push(Work_wage_ratio[i].second);
            quality_sum += Work_wage_ratio[i].second;
        }

        double result = Work_wage_ratio[k - 1].first * quality_sum;

        // Step 4: Try replacing workers
        for (int i = k; i < n; i++) {

            double manager = Work_wage_ratio[i].first;

            pq.push(Work_wage_ratio[i].second);
            quality_sum += Work_wage_ratio[i].second;

            // Keep only k smallest qualities
            if (pq.size() > k) {
                quality_sum -= pq.top();
                pq.pop();
            }

            result = min(result, manager * quality_sum);
        }

        return result;
    }
};

int main() {

    Solution obj;

    // Example Input
    vector<int> quality = {10, 20, 5};
    vector<int> wage = {70, 50, 30};
    int k = 2;

    double answer = obj.mincostToHireWorkers(quality, wage, k);

    cout << "Minimum cost to hire " << k << " workers: " << answer << endl;

    return 0;
}