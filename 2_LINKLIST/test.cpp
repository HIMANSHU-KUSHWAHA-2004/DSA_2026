#include <bits/stdc++.h>
using namespace std;

void numberOfWays(int n, int x) {
    const int MOD = 1000000007;
    vector<int> power;

    int i = 1;
    while (true) {
        long long val = 1;
        for (int j = 0; j < x; j++) {
            val = (val * i) % MOD;  // avoid overflow
        }

        if (val > n) break;

        power.push_back((int)val);
        i++;
    }

    for (auto &a : power) {
        cout << a << " ";
    }
}

int main() {
    int n = 26, x = 2;
    numberOfWays(n, x);
}
