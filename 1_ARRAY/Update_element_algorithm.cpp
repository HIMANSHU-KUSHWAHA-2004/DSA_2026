#include <bits/stdc++.h>
using namespace std;
void update_number(int *arr, int &size, int inarr, int number)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == inarr)
        {
            arr[i] = number;
        }
    }
}

int main()
{
    int size = 5;
    int arr[size] = {1, 2, 3, 4, 5};
    int inarr, number;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter the number you wanna update : ";
    cin >> inarr;
    cout << "Enter the updated number : ";
    cin >> number;
    update_number(arr, size, inarr, number);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
        }
}
