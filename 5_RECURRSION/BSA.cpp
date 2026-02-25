#include <iostream>
using namespace std;
int Binary_find(int *arr, int target, int low, int high)
{
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return Binary_find(arr, target, mid + 1, high);
    else
        return Binary_find(arr, target, low, mid - 1);

    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;
    int low = 0;
    int high = n - 1;
    cout << Binary_find(arr, target, low, high);
}