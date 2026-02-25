#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total_area = 0.0;
        double min_y = 1e9;
        double max_y = -1e9;

        // Step 1: total area and y-range
        for (auto &sq : squares) {
            double y = sq[1];
            double side = sq[2];

            total_area += side * side;
            min_y = min(min_y, y);
            max_y = max(max_y, y + side);
        }

        double half_area = total_area / 2.0;

        // Step 2: Binary search on y
        while (max_y - min_y > 1e-6) {
            double mid = (min_y + max_y) / 2.0;
            double area_below = 0.0;

            // Step 3: calculate area below mid
            for (auto &sq : squares) {
                double y = sq[1];
                double side = sq[2];
                double top = y + side;

                if (mid >= top) {
                    // fully below
                    area_below += side * side;
                }
                else if (mid > y) {
                    // partially below
                    area_below += (mid - y) * side;
                }
            }

            // Step 4: adjust binary search
            if (area_below < half_area)
                min_y = mid;
            else
                max_y = mid;
        }

        return min_y;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> squares = {
        {0, 0, 2},
        {1, 1, 1}
    };

    double answer = sol.separateSquares(squares);

    cout << fixed << setprecision(5) << answer << endl;

    return 0;
}
