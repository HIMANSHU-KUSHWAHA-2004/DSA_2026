#include <iostream>
using namespace std;
bool sorrrrted(int *arr, int n)
{
    if (n == 0 || n == 1)
        return true;
    return (arr[n - 2] <= arr[n - 1]) && sorrrrted(arr, n - 1);
}
int main()
{
    int arr[] = {1, 2, 3, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << boolalpha << sorrrrted(arr, n);
}