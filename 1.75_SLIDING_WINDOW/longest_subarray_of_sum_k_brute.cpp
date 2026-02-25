#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int>& arr, int n, int k) {
    int answer = 0;

    // Try all starting points of subarrays
    for (int i = 0; i < n; i++) {
        int sum = 0;

        // Try all ending points for the subarray starting at index i
        for (int j = i; j < n; j++) {
            sum += arr[j];

            // Check if sum equals K
            if (sum == k) {
                answer = max(answer, j - i + 1);
            }
        }
    }

    return answer;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestSubarrayWithSumK(arr, n, k) << endl;

    return 0;
}
