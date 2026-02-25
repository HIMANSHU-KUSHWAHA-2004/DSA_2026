#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> streak(n);
    for (int i = 0; i < n; i++)
    {
        cin >> streak[i];
    }
    int max_streak = 1;
    int left = 0;
    bool already_used = false;
    for (int right = 1; right < streak.size(); right++)
    {
        if (streak[right - 1] >= streak[right])
        {
            if (already_used == false)
            {
                if (streak[right] * x >= streak[right - 1])
                {
                    already_used = true;
                }
                else if (streak[right] <= x * streak[right - 1])
                {
                    already_used = true;
                    streak[right - 1] = x * streak[right - 1];
                }
                else
                {
                    left = right;
                    already_used = false;
                }
            }
            else
            {
                left = right;
                already_used = false;
            }
        }
        max_streak = max(max_streak, right - left + 1);
    }
    cout << max_streak << endl;
}