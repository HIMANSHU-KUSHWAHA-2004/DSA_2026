#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n;
    cin >> n;
    map<char, int> freq;
    for (int i = 0; i < n.size(); i++)
    {
        freq[n[i]]++;
    }
    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}
