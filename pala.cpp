#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "000";
    string s1 = "";
    string s2 = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0)
        {
            s1 = s1 + '0';
            s2 = s2 + '1';
        }
        else
        {
            s2 = s2 + '0';
            s1 = s1 + '1';
        }
    }
    cout << s1 << endl;
    cout << s2 << endl;
}
