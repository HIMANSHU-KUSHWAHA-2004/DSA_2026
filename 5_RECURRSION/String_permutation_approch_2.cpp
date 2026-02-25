#include <bits\stdc++.h>
using namespace std;
void permu_maker(vector<string> &answer, string st, map<char, bool> &mpp, string &temp)
{
    if (temp.size() == st.size())
    {
        answer.push_back(temp);
        return;
    }
    for (int i = 0; i < st.size(); i++)
    {
        if (!mpp[st[i]])
        {
            mpp[st[i]] = true;
            temp += st[i];
            permu_maker(answer, st, mpp, temp);
            temp.pop_back();
            mpp[st[i]] = false;
        }
    }
}
int main()
{
    string s = "ABC";
    vector<string> answer;
    map<char, bool> mpp;
    string temp = "";
    permu_maker(answer, s, mpp, temp);
    for (string i : answer)
    {
        cout << i << endl;
    }
}