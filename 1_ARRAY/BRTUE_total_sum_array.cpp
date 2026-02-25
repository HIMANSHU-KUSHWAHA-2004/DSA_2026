#include <iostream>
using namespace std;
int main()
{
    /*THIS IS A BRUTE FORCE APPROCH FOR FINDING THE SUB ARRAY SINCE WE ARE USING THE 3 NESTED LOOP SO TIME COMPLEXITY IS O(n^3)
    BUT USING THE KADANES ALGORITHM WE CAN SETTLE IT TO O(n)*/
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};
    int count = 0;
    int maximum_subarraysum = arr[0];
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            int sum = 0;
            for (int i = start; i <= end; i++)
            {
                cout << arr[i];
                sum += arr[i];
            }
            count++;
            maximum_subarraysum = max(maximum_subarraysum, sum);
            cout << "\t";
        }
        cout << endl;
    }
    cout << "Total number of elements printed: " << count << endl;
    cout << "Maximum subarray sum: " << maximum_subarraysum << endl;
}