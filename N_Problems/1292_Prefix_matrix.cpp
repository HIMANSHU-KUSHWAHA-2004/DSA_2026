#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Check if there is a square of size 'size' whose sum <= threshold
    bool Bhola(const vector<vector<int>>& metro, int size, int threshold) {
        int R = metro.size();
        int C = metro[0].size();

        for (int i = size - 1; i < R; i++) {
            for (int j = size - 1; j < C; j++) {

                int toprow = i - size + 1;
                int topcol = j - size + 1;

                // Calculate sum of square using 2D prefix sum
                int sum = metro[i][j]
                          - (toprow > 0 ? metro[toprow - 1][j] : 0)
                          - (topcol > 0 ? metro[i][topcol - 1] : 0)
                          + (toprow > 0 && topcol > 0 ? metro[toprow - 1][topcol - 1] : 0);

                if (sum <= threshold)
                    return true;
            }
        }
        return false;
    }

    // Main function to find maximum side length
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int R = mat.size();
        int C = mat[0].size();
        vector<vector<int>> mat_Prefix = mat;

        // Build row-wise prefix sum
        for (int i = 0; i < R; i++) {
            for (int j = 1; j < C; j++) {
                mat_Prefix[i][j] += mat_Prefix[i][j - 1];
            }
        }

        // Build column-wise prefix sum
        for (int i = 1; i < R; i++) {
            for (int j = 0; j < C; j++) {
                mat_Prefix[i][j] += mat_Prefix[i - 1][j];
            }
        }

        // Binary search over possible square sizes
        int left = 1, right = min(R, C);
        int answer = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (Bhola(mat_Prefix, mid, threshold)) {
                answer = mid;
                left = mid + 1; // try bigger square
            } else {
                right = mid - 1; // try smaller square
            }
        }

        return answer;
    }
};

// Example usage
int main() {
    Solution sol;

    // Example matrix
    vector<vector<int>> mat = {
        {1, 1, 3, 2, 4, 3, 2},
        {1, 1, 3, 2, 4, 3, 2},
        {1, 1, 3, 2, 4, 3, 2}
    };

    int threshold = 8;

    int maxSide = sol.maxSideLength(mat, threshold);
    cout << "Maximum side length of square under threshold " << threshold
         << " is: " << maxSide << endl;

    return 0;
}
