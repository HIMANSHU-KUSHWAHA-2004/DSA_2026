#include <bits/stdc++.h>

using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL);
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x, y, n, r;
        cin >> x >> y >> n >> r;
        if (x * n > r)
            cout << -1 << endl;
        else if (y * n <= r)
            cout << 0 << " " << n << endl;
        else {
            long long  n_P = min(n,(r - n*x)/(y - x));
            long long n_N = n - n_P;
            cout << n_N  << " " << n_P << endl;
        }

    }
}
