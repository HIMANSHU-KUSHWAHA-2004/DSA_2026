#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

void partision(string s, vector<string> &temp, vector<vector<string>> &answer)
{
    if (s.size() == 0)
    {
        answer.push_back(temp);
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        string sub = s.substr(0, i + 1);
        if (isPalindrome(sub,0,i))
        {
            temp.push_back(sub);
            partision(s.substr(i + 1), temp, answer);
            temp.pop_back();
        }
    }
}
int main()
{
    string s = "aaba";
    int n = s.length();
    vector<string> temp;
    vector<vector<string>> ans;
    partision(s, temp, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}