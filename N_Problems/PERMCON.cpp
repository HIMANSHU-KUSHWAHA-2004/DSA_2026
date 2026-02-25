#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector < int > p(n + 1);
        if (n % k >= n - k)
            cout << -1 << endl;
        else
        {
            vector < vector < int >> K(n);
            vector < int > answer(n+1);
            for (int i = 1; i <= n; i++) {
                K[i % k].push_back(i);
            }

            for (int i = 0; i < n; i++) {
                int siz = K[i].size();
                for (int j = 0; j < siz; j++) {
                    answer[K[i][j]] = K[i][(j + 1) % siz];
                }
            }

            for (int i = 1; i <= n; i++) {
                cout << answer[i] << " ";
            }
            cout << endl;
        }
    }
}