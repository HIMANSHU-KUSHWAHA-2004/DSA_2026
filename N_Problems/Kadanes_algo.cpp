#include <bits/stdc++.h>
using namespace std;
int maxSubArraySum(vector<int> &ar, int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (int num : ar)
    {
        max_ending_here = max(num, max_ending_here + num);
        /*THAT MEANS IF ADDING A NEW ELEMENT DECREASE THE THE SUM OF THE SUB ARRAY EVEN LOWER THEN THE CURRENT ELEMENT
          THEN WE JUST TAKE THE CURRENT ELEMENT TO START A NEW SUB ARRAY*/
        max_so_far = max(max_so_far, max_ending_here);
        /*THIS IS JUST TO STORE THE MAXIMUM SUM OF SUB ARRAY TILL NOW*/
    }
    return max_so_far;
}
int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "sum of maximum subarray in contigunous is " << maxSubArraySum(arr, arr.size());
}