#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int cutRod(vector<int>& price) {

        int n = price.size();

        vector<int> prev(n + 1, 0);
        // Base Row
        for(int j = 0; j <= n; j++) {
            prev[j] = j * price[0];
        }

        for(int i = 1; i < n; i++) {

            for(int j = 0; j <= n; j++) {

                int notTake = prev[j];

                int take = -1e9;

                // current rod length = i + 1
                int rodLength = i + 1;
                if(rodLength <= j) {
                    take = price[i] + prev[j - rodLength];
                }

                prev[j] =
                    max(take, notTake);
            }

        }

        return prev[n];
    }
};

int main() {

    vector<int> price = {2,5,7,8};

    Solution obj;

    cout << obj.cutRod(price);

    return 0;
}