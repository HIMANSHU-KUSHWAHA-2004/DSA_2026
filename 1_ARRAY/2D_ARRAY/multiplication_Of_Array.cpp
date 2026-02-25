#include <bits/stdc++.h>
using namespace std;
int main()
{

    int row, colm;
    cout << "Enter the rows and column of first matrix : ";
    cin >> row >> colm;
    int arr[row][colm];
    cout << "Enter the matric one : " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colm; j++)
        {
            cin >> arr[i][j];
        }
    }

    int row1, colm1;
    cout << "Enter the rows and column of second matrix : ";
    cin >> row1 >> colm1;
    int arr2[row1][colm1];
    cout << "Enter the matric two : " << endl;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < colm1; j++)
        {
            cin >> arr2[i][j];
        }
    }

    int mult[row][colm1];
    if (colm != row1)
    {
        cout << "Matrix can't be multiplied" << endl;
    }
    else
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < colm1; j++)
            {
                mult[i][j] = 0;
                for (int k = 0; k < row1; k++)
                {
                    mult[i][j] += arr[i][k] * arr2[k][j];
                }
            }
        }
    }
    cout << "Multiplication of two matrix is : " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colm1; j++)
        {
            cout << mult[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
