#include <bits/stdc++.h>
using namespace std;

int Fibo(int n, vector<int> &Dp)
{
    Dp[0] = 0;
    Dp[1] = 1;
    for (int i = 2; i < n; i++)
    {
        Dp[i] = Dp[i - 1] + Dp[i - 2];
    }
    return Dp[n - 1];
    // THE LAST VALUE OF THE DP ARRAY WILL CONTAIN THE VALUE OF THE Nth VALUE
}

int main()
{
    int n;
    cin >> n;
    vector<int> Dp(n, -1);

    cout << Fibo(n, Dp) << endl;
    for (auto j : Dp)
    {
        cout << j << " ";
    }
}