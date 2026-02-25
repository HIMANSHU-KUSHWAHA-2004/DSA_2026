#include <bits/stdc++.h>
#include <set>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<char> s;
    for (int i = 0; i < n; i++)
    {
        char x;
        cin >> x;
        s.insert(x);
    }
    for (auto it : s)
    {
        cout << it << " ";
    }
}