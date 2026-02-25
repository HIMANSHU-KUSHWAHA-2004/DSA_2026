#include <iostream>
#include <vector>
using namespace std;
void permutation(vector<string> &answer, string &s, int i)
{
    if (i == s.size())
    {
        answer.push_back(s);
        return;
    }
    for (int j = i; j < s.size(); j++)
    {
        swap(s[i], s[j]);
        permutation(answer, s, i + 1);
        swap(s[i], s[j]);
    }
}
int main()
{
    string s = "ABC";
    vector<string> answer;
    permutation(answer,s, 0);
    for (auto &it : answer)
    {
        cout << it << endl;
    }
    return 0;
}