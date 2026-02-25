#include <iostream>
#include <vector>
using namespace std;
int binary_target(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[start] < arr[mid])
        {
            if (target >= arr[start] && target <= arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else
        {
            if (target >= arr[mid] && target <= arr[end])
                start = mid + 1; 
            else
                end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6};
    int target = 5;
    cout << binary_target(arr, target);
}