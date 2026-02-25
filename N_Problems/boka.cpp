#include <bits/stdc++.h>
using namespace std;

bool is_sorted(vector<int> arr) {
    int s = arr.size();
    for (int i = 1; i < s; i++) {
        if (arr[i - 1] > arr[i])
            return false;
    }
    return true;
}

void printArray(vector<int> arr) {
    cout << "[ ";
    for (int x : arr) cout << x << " ";
    cout << "]\n";
}

int minimumPairRemoval(vector<int>& nums) {
    int count = 0;
    cout << "Initial array: ";
    printArray(nums);

    while (!is_sorted(nums)) {
        int idx = 0;
        int mini = INT_MAX;

        cout << "\nLoop start, n = "  << endl;

        for (int i = 1; i < nums.size(); i++) {
            cout << "Checking pair: "
                 << nums[i - 1] << " + " << nums[i]
                 << " = " << nums[i - 1] + nums[i] << endl;

            if (mini > (nums[i - 1] + nums[i])) {
                mini = nums[i - 1] + nums[i];
                idx = i;
            }
        }

        cout << "Chosen index idx = " << idx
             << ", sum = " << mini << endl;

        nums[idx] = mini;
        nums.erase(nums.begin() + idx + 1);

        cout << "Array after merge: ";
        printArray(nums);

        count++;
    }

    return count;
}

int main() {
    vector<int> nums = {5, 2, 3, 1};

    int result = minimumPairRemoval(nums);

    cout << "\nFinal array: ";
    printArray(nums);

    cout << "Total operations: " << result << endl;
    return 0;
}
