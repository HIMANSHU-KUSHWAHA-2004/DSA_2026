#include <bits/stdc++.h>

using namespace std;
int main()
{
    map<int, int> mp;
    mp[1] = 1;
    mp[2] = 2;
    mp[3] = 3;
    mp[4] = 4;
    mp[5] = 5;
    map<int, string> mp2;
    mp2[1] = "one";
    mp2[2] = "two";
    mp2[3] = "three";
    mp2[4] = "four";
    mp2[5] = "five";
    for (auto it : mp2)
    {
        cout << it.first << "-->" << it.second << endl;
    }
    cout << endl;
    for (auto k : mp)
    {
        cout << k.first << "-->" << k.second << endl;
    }
}