#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& arr) {
    int n = arr.size();

    // 👉 Step 0: Sort ONLY if problem requires
    // LIS → no sort
    // Divisible Subset → sort(arr.begin(), arr.end())
    // String Chain → sort by length

    vector<int> dp(n, 1); 
    // dp[i] = best answer ending at index i
    // initially every element itself is length 1

    vector<int> parent(n, -1); 
    // used to reconstruct path (optional)

    int maxi = 1;       // stores overall best length
    int lastIndex = 0;  // last index of LIS (for path)

    // 👉 Step 1: Fix current index i
    for (int i = 0; i < n; i++) {

        // 👉 Step 2: Check all previous indices
        for (int prev = 0; prev < i; prev++) {

            // 🔥 CORE CONDITION (changes per problem)
            if ((arr[prev], arr[i])) {

                // 👉 Step 3: Take best possible extension
                if (dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;

                    // store parent to track path
                    parent[i] = prev;
                }
            }
        }

        // 👉 Step 4: Track global maximum
        if (dp[i] > maxi) {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    // 🔁 Step 5: Reconstruct path (optional)
    vector<int> path;
    while (lastIndex != -1) {
        path.push_back(arr[lastIndex]);
        lastIndex = parent[lastIndex];
    }
    reverse(path.begin(), path.end());

    // 👉 return either length or actual path
    return maxi;
}