#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= right)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int k = left; k <= right; k++)
    {
        arr[k] = temp[k - left];
    }
}

void Mergesort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {  
        int mid = left + (right - left) / 2;
        Mergesort(arr, left, mid);
        Mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    vector<int> arr = {5, 8, 6, 1, 0, 12, 3};
    Mergesort(arr, 0, arr.size() - 1);
    for (int i : arr)
    {
        cout << i << " ";
    }
}
