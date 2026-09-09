class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        // pre[i] = sum of first i elements
        // subarray sum = pre[j] - pre[i]
        vector<long long> pre(n + 1, 0);

        for(int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }

        deque<int> dq;
        int ans = n + 1;

        for(int j = 0; j <= n; j++) {

            // FRONT:
            // If sum >= k, we found a valid subarray.
            // Future j will only make its length bigger,
            // so this i is no longer useful.
            while(!dq.empty() &&
                  pre[j] - pre[dq.front()] >= k) {

                ans = min(ans, j - dq.front());

                dq.pop_front();
            }

            // BACK:
            // If current prefix is smaller/equal than old prefix,
            // old index is useless:
            // current index is later → shorter length
            // current prefix is smaller → better sum
            while(!dq.empty() &&
                  pre[j] <= pre[dq.back()]) {

                dq.pop_back();
            }

            // Store current prefix index
            dq.push_back(j);
        }

        // No valid subarray found
        if(ans == n + 1)
            return -1;

        return ans;
    }
};