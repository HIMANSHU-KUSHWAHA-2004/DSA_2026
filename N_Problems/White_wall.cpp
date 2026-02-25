//1400
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        string a = "RGB";
        string b = "RBG";
        string c = "GRB";
        string d = "GBR";
        string e = "BRG";
        string f = "BGR";

        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        int c4 = 0;
        int c5 = 0;
        int c6 = 0;

        for (int i = 0; i < n; i++) {
            if (a[i % 3] != s[i])
                c1++;

            if (b[i % 3] != s[i])
                c2++;

            if (c[i % 3] != s[i])
                c3++;

            if (d[i % 3] != s[i])
                c4++;

            if (e[i % 3] != s[i])
                c5++;

            if (f[i % 3] != s[i])
                c6++;
        }
        int ans = min(c1, min(c2, min(c3, min(c4, min(c5, c6)))));
        cout << ans << endl;

    }
}