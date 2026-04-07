#include <bits/stdc++.h>
using namespace std;

int Fibo(int n, vector<int> &Dp)
{
    if (n <= 1)
        return Dp[n] = n;

    if (Dp[n] != -1)
        return Dp[n];

    return Dp[n] = Fibo(n - 1, Dp) + Fibo(n - 2, Dp);
    //THIS WILL STORE THE VALUE OF n WITH THE HELP OF THE PREVIOUS VALUES
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