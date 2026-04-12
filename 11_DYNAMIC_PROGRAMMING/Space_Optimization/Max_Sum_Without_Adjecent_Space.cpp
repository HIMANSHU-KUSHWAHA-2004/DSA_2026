#include <bits/stdc++.h>
using namespace std;

int findMaxSum(vector<int>& arr) {
    int n = arr.size();

    if(n == 1) return arr[0];

    // 🔷 Correct initialization
    int prev2 = arr[0];                 // dp[0]
    int prev1 = max(arr[0], arr[1]);    // dp[1]

    for(int i = 2; i < n; i++){
        int pick = arr[i] + prev2;   // dp[i-2]
        int notPick = prev1;         // dp[i-1]

        int curr = max(pick, notPick);

        // 🔷 shift values
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){
    vector<int> arr = {2,1,4,9};
    cout << findMaxSum(arr);
}