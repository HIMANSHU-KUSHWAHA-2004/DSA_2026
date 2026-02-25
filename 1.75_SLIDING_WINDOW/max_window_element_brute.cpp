#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, window;
    cin >> n >> window;
    int arr[n];
    vector<int> answer;
    int maxii = INT_MIN;
    for (int i = 0; i < n ; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i <= n - window; i++)
    {
        for (int j = 0 + i; j < window + i; j++)
        {
            maxii = max(maxii, arr[j]);
            
        }
        answer.push_back(maxii);
        maxii = INT_MIN;
    }
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    return 0;
}