#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y, z, a, b, c;
        cin >> x >> y >> z >> a >> b >> c;
        int total = 0;
        int aa = min(x, a);
        x -= aa;
        a -= aa;
        total += aa;
        int bb = min(y, b);
        y -= bb;
        b -= bb;
        total += bb;
        int cc = min(z, c);
        z -= cc;
        c -= cc;
        total += cc;
        
        int convertLXtoL = min(b,z);
        z -= convertLXtoL;
        b -= convertLXtoL;
        total += convertLXtoL;
        
        int convertXLtoS = min(a,z);
        z -= convertXLtoS;
        a -= convertXLtoS;
        total += convertXLtoS;
    
        int convertLtoS = min(a,y);
        a -= convertLtoS;
        y -= convertLtoS;
        total += convertLtoS;
    
    cout << total << endl;

    }
}