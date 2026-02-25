#include <bits/stdc++.h>
using namespace std;
int partision(vector<int> &arr, int left, int right)
{
    int idx = left - 1;
    int pivot = arr[right];
    for (int i = left; i < right; i++)
    {
        if (arr[i] <= pivot)
        {
            idx++;
            swap(arr[idx], arr[i]);
        }
    }
    idx++;
    swap(arr[idx], arr[right]);
    return idx;
}
void QuickSort(vector<int> &arr, int left, int right)
{
    if (left <= right)
    {
        int pivot = partision(arr, left, right);
        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);
    }
}
int main()
{
    vector<int> arr = {1, 5, 2, 9, 7, 6};
    int n = arr.size();
    QuickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
