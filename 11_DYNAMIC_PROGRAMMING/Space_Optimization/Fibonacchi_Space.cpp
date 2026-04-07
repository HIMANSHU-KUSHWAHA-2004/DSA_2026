#include <bits/stdc++.h>
using namespace std;

int Fibo(int n, vector<int> &Dp)
{
    int prev1 = 0;
    int prev2 = 1;
    int answer = 0;
    for (int i = 2; i < n; i++)
    {
        answer = prev1 + prev2;
        prev1 = prev2;
        prev2 = answer;
    }
    return answer;
}

int main()
{
    int n;
    cin >> n;
    vector<int> Dp(n + 1, -1);

    cout << Fibo(n, Dp) << endl;
    for (auto j : Dp)
    {
        cout << j << " ";
    }
}