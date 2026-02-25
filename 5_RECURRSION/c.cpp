#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s1,s2,s3;
        vector<string> strings = {s1,s2,s3};
        vector<int> count_0(3,0);
        vector<int> count_1(3,0);
        for(int i = 0;i<n;i++){
            count_0[i] = count(strings[i].begin(),strings[i].end(),'0');
            count_1[i] = n - count_0[i];
        }

    }
}