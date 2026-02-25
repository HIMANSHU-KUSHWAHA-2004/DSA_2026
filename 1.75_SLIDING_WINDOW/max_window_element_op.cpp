#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, window;
    cin >> n >> window;
    int arr[n];
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 0;
    int j = 0;
    int maxii = INT_MIN;
    while (j < n)
    {
        maxii = max(maxii, arr[j]);
        if (j - i + 1 < window)
        {
            j++;
        }
        else
        {
            answer.push_back(maxii);
            if (maxii <= arr[j])
            {
                maxii = arr[j];
            }
            i++;
            j++;
        }
    }
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    return 0;
}