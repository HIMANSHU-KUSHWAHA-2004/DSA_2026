#include <iostream>
using namespace std;
void InsertionElement(int *arr, int &size, int number, int index)
{
    if (index < 0 || index > size)
    {
        cout << "Invalid position OR Array is full" << endl;
        return;
    }

    for (int i = size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = number;
    size++;
    /*AS YOU CAN SEE THAT WHY WE INCREASE THE SIZE AND WHY WE TAKE IS AS THE REFERENCE BECAUSE IF WE DID NOT TAKE IT
    THEN WILL NOT INCREASE GLOBALLY IT ONLY INCREASE INSIDE THE FUCNTION THAT WHY WE USE THE REFERENCE SO THAT IT 
    INCREASE TO 6 IN THE MAIN FUNCTION*/
}

int main()
{
    int size = 5;
    int number, index;
    int arr[size] = {1, 2, 3, 4, 5};
    cout << "Enter the number and the index where you want to insert it: ";
    cin >> number >> index;
    InsertionElement(arr, size, number, index);
    cout << "Array after insertion: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
