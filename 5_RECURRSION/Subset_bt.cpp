#include <bits\stdc++.h>
using namespace std;
void subset_maker(int idx, vector<int> given, vector<vector<int>> &answer,vector<int> &temp)
{
    if (idx == given.size())
    {
        answer.push_back({temp});
        return;
    }
    temp.push_back(given[idx]);
    subset_maker(idx + 1, given, answer, temp);
    temp.pop_back();
    subset_maker(idx + 1, given, answer, temp);
}
int main()
{
    vector<int> given = {1, 2, 3};
    vector<vector<int>> answer;
    vector<int> temp;
    subset_maker(0,given,answer,temp);
    for (auto i : answer)
    {
        for (auto k : i)
        {
            cout << k << " ";
        }
        cout << endl;
    }
}