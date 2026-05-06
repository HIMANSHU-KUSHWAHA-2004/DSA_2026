#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> coins = {1,2,3};
    int amount = 4;
    int n = coins.size();

    vector<int> prev(amount + 1, 0);

    for (int j = 0; j <= amount; j++) {
        if (j % coins[0] == 0)
            prev[j] = 1;
    }

    for (int i = 1; i < n; i++) {

        vector<int> curr(amount + 1, 0);

        for (int j = 0; j <= amount; j++) {

            int notake = prev[j];

            int take = 0;
            if (coins[i] <= j) {
                take = curr[j - coins[i]];
            }

            curr[j] = take + notake;
        }

        prev = curr;
    }

    cout << prev[amount] << endl;
}