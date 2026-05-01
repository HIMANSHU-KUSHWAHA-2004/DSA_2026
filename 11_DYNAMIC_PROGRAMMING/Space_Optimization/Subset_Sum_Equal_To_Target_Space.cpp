#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();

        // prev = next row (i+1)
        vector<bool> prev(sum + 1, false);

        // Base case:
        prev[0] = true; // sum 0 always possible

        if (arr[n - 1] <= sum)
            prev[arr[n - 1]] = true;

        // iterate from second last element
        for (int i = n - 2; i >= 0; i--) {

            vector<bool> curr(sum + 1, false);
            curr[0] = true;

            for (int j = 1; j <= sum; j++) {

                bool notake = prev[j];

                bool take = false;
                if (arr[i] <= j) {
                    take = prev[j - arr[i]];
                }

                curr[j] = take || notake;
            }

            prev = curr; // move forward
        }

        return prev[sum];
    }
};