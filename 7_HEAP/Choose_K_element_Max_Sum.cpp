#include <bits/stdc++.h>
using namespace std;

/*
Dry-run demo for:
nums1 = [4,1,1,5,3]
nums2 = [10,20,30,40,50]
k = 2

Goal (common version): for each index idx,
answer[idx] = sum of top-k nums2 values among elements with nums1 < nums1[idx].
*/

class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<array<int, 3>> Concat;
        int n = (int)nums1.size();
        vector<long long> answer(n, 0);

        for (int i = 0; i < n; i++) {
            Concat.push_back({nums1[i], i, nums2[i]}); // {nums1, original_index, nums2}
        }

        sort(Concat.begin(), Concat.end());

        priority_queue<int, vector<int>, greater<int>> Hipo; // min-heap
        long long sum = 0;

        cout << "---- Sorted Concat: (nums1, idx, nums2) ----\n";
        for (int p = 0; p < n; p++) {
            cout << p << ": (" << Concat[p][0] << ", " << Concat[p][1] << ", " << Concat[p][2] << ")\n";
        }
        cout << "-------------------------------------------\n\n";

        int i = 0;
        while (i < n) {

            // find group end j
            int j = i;
            while (j < n && Concat[j][0] == Concat[i][0]) {
                j++;
            }

            cout << "GROUP: nums1 = " << Concat[i][0] << "  i=" << i << "  j=" << j
                 << "  (indices " << i << " to " << (j - 1) << ")\n";
            cout << "Current sum(before assigning answers) = " << sum << "\n";

            // Step 1: assign answers for this group
            for (int t = i; t < j; t++) {
                int originalIndex = Concat[t][1];
                answer[originalIndex] = sum;
                cout << "  t=" << t << " -> answer[" << originalIndex << "] = " << sum << "\n";
            }

            // Step 2: push nums2 of this group into heap and maintain size k
            cout << "Now pushing this group's nums2 into heap:\n";
            for (int t = i; t < j; t++) {
                int val = Concat[t][2];

                Hipo.push(val);
                sum += val;

                cout << "  push " << val << "  => sum=" << sum;

                if ((int)Hipo.size() > k) {
                    int removed = Hipo.top();
                    Hipo.pop();
                    sum -= removed;
                    cout << "  | size>" << k << " so pop " << removed << " => sum=" << sum;
                }

                cout << "\n";
            }

            // print heap content (copy heap to show)
            {
                priority_queue<int, vector<int>, greater<int>> temp = Hipo;
                cout << "Heap now contains: { ";
                while (!temp.empty()) {
                    cout << temp.top() << " ";
                    temp.pop();
                }
                cout << "}  (min-heap, kept top " << k << " largest nums2)\n";
            }

            cout << "End of group. sum=" << sum << "\n\n";

            i = j; // next group
        }

        cout << "---- Final answer in original index order ----\n";
        for (int idx = 0; idx < n; idx++) {
            cout << "answer[" << idx << "] = " << answer[idx] << "\n";
        }
        cout << "---------------------------------------------\n";

        return answer;
    }
};

int main() {
    vector<int> nums1;
    vector<int> nums2;
    int k = 2;

    // Example
    nums1.push_back(4);
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(5);
    nums1.push_back(3);

    nums2.push_back(10);
    nums2.push_back(20);
    nums2.push_back(30);
    nums2.push_back(40);
    nums2.push_back(50);

    Solution sol;
    vector<long long> ans = sol.findMaxSum(nums1, nums2, k);

    // Print final vector in one line too
    cout << "\nAnswer vector: [";
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i];
        if (i + 1 < (int)ans.size()) cout << ", ";
    }
    cout << "]\n";

    return 0;
}