#include <bits/stdc++.h>
const int Max_size = 10;
using namespace std;

void Delete_element(int *arr, int &size, int element)
{
    bool flag = true;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            flag = false;
            for (int j = i; j < size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
        }
    }
    if (flag)
        cout << "The element is not present in the array";
    size--;
}

int main()
{
    int size = 5;
    int arr[Max_size] = {1, 2, 3, 4, 5};
    int element;
    cout << "Enter the element you wanna delete : ";
    cin >> element;
    Delete_element(arr, size, element);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}