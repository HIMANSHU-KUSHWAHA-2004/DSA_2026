#include <bits\stdc++.h>
using namespace std;
vector<int> sortByBits(vector<int> &arr)
{
    multiset<pair<int, int>> ans;
    vector<int> boka;
    for (int i : arr)
    {
        int temp = i;
        int bits = 0;
        while (temp > 0)
        {
            if (temp % 2 == 0)
                bits++;
            temp /= 2;
        }
        ans.insert({bits, i});
    }
    for (auto i : ans)
    {
        boka.push_back(i.second);
    }
    return boka;
}
int main()
{
}
