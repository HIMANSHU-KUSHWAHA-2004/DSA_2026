#include <iostream>
#include <vector>
using namespace std;
int max_decreasing_subarray(vector<int> arr)
{
    int current_streak = 1;
    int max_streak = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1] <= arr[i])
            current_streak++;
        else
        {
            max_streak = max(max_streak, current_streak);
            current_streak = 1;
        }
    }
    return max(max_streak, current_streak);
    /*IN CASE IF THE LAST PART OF THE SUB ARRAY IS NON DECREASING TILL THE END SO IT MAY POSSIBLE THAT THE
    MAXIMUM LENGTH OF THE DECREASING SUB ARRAY IS THE CURRENT STREAK or IF WHOLE ARRAY IS NON DECREASING THEN
    THE MAXIMUM LENGTH OF THE DECREASING SUB ARRAY IS THE CURRENT STREAK*/
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> streak(n);
    for (int i = 0; i < n; i++)
    {
        cin >> streak[i];
    }
    int without_x = max_decreasing_subarray(streak);
    int answer = without_x;
    for (int i = 0; i < n; i++)
    {
        int changing = streak[i];
        streak[i] = streak[i]*x;
        answer = max(answer, max_decreasing_subarray(streak));
        streak[i] = changing;
    }
    cout << answer << endl;
    return 0;
}