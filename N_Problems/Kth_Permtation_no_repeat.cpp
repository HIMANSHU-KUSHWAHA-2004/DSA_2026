#include <bits\stdc++.h>
using namespace std;
int main()
{
    string s = "abcd";
    int n = 4;
    int k = 14;
    sort(s.begin(), s.end());
    vector<int> fact(n);
    fact[0] = 1;
    for (int i = 1; i < n; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
    long long total = fact[n - 1] * n;
    if (k > total)
        return 0;
    k--;
    // for 0 based indexing

    vector<char> chars(s.begin(), s.end());
    string ans = "";
    for (int i = n; i >= 1; i--)
    {
        long long block = fact[i - 1];
        int idx = k / block;
        //this will tell you in which block you ar from

        ans += chars[idx];
        chars.erase(chars.begin() + idx);

        k %= block;
        //this will find the particular block in the given block for the next time
    }
    cout << ans << endl;
    return 0;
}