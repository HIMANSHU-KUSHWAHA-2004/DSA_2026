#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumPoints(vector<vector<int>> &mat)
    {
        int n = mat.size();

        // 🟢 Base case (day 0)
        // If we pick task 0, 1, or 2 on day 0,
        // then best score is just that value itself
        int prev0 = mat[0][0]; // best if last task = 0
        int prev1 = mat[0][1]; // best if last task = 1
        int prev2 = mat[0][2]; // best if last task = 2

        // 🔵 Start processing from day 1 to day n-1
        for (int day = 1; day < n; day++)
        {

            // 🔴 If we choose task 0 today,
            // we cannot have done task 0 yesterday
            // so we take max of prev1 and prev2
            int cur0 = mat[day][0] + max(prev1, prev2);

            // 🔴 If we choose task 1 today,
            // we cannot take task 1 from yesterday
            // so we take max of prev0 and prev2
            int cur1 = mat[day][1] + max(prev0, prev2);

            // 🔴 If we choose task 2 today,
            // we cannot take task 2 from yesterday
            // so we take max of prev0 and prev1
            int cur2 = mat[day][2] + max(prev0, prev1);

            // 🟡 Move current day results to previous for next iteration
            prev0 = cur0;
            prev1 = cur1;
            prev2 = cur2;
        }

        // 🟢 Final answer = best among all 3 possible ending states
        return max({prev0, prev1, prev2});
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat = {
        {10, 50, 40},
        {20, 60, 30},
        {30, 20, 70}};
    cout << obj.maximumPoints(mat);
}