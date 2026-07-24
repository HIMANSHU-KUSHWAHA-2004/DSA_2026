#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long carry = 0;
        bool ok = true;

        for (int i = 0; i < n; i++) {
            long long total = a[i] + carry;

            if (total < i + 1) {
                ok = false;
                break;
            }

            carry = total - (i + 1);
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}