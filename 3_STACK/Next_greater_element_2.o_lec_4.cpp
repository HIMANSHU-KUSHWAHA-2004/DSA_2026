#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    
    map<int, int> mp; 
    stack<int> st;

    // Process nums2 from right to left
    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!st.empty() && nums2[i] >= st.top()) {
            st.pop();
        }
        if (st.empty())
            mp[nums2[i]] = -1;
        else
            mp[nums2[i]] = st.top();
        st.push(nums2[i]);
    }

    // Build result for nums1
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++) {
        ans.push_back(mp[nums1[i]]);
    }

    // Print answer
    for (int x : ans) cout << x << " ";
}
