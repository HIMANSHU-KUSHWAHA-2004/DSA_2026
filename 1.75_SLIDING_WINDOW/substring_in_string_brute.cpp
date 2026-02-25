#include <bits/stdc++.h>
using namespace std;
int anagram(string str, string pattern)
{

    if (str.length() < pattern.length())
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        int count = 0;
        int answer = 0;
        for (int i = 0; i <= str.length() - pattern.length(); i++)
        {
            for (int j = 0 + i; j < pattern.length() + i; j++)
            {
                if (str[j] == pattern[j - i])
                {
                    count++;
                }
            }
            if (count == pattern.length())
            {
                answer++;
            }
            count = 0;
        }
        return answer;
    }
}
int main()
{
    string str, pattern;
    cin >> str >> pattern;
    string pattern2 = pattern;
    reverse(pattern2.begin(),pattern2.end());
    cout << anagram(str, pattern)<< endl;
}