#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    // vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i = 0;
    int j = 0;
    int sum = 0;
    int answer = 0;
    while (j < n)
    {
        sum += a[j];
        while (sum > k && i <= j)
        {
            sum -= a[i];
            i++;
        }
        if (sum == k)
        {
            answer = max(answer, j - i + 1);
        }

        j++;
    }
    cout << answer << endl;
}