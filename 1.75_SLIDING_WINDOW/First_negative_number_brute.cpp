#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    /*AS WE KNOW HERE WE HAVE TO FIND MAXIMUM SUM OF THE SUBARRAY WHOSE LENTH = 4*/
    int arr[] = {12, -1, -2, 5, -6, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int window = 3;
    for (int i = 0; i < n - window + 1; i++)
    /*WE MINUS WINDOW SIZE FROM THE n HERE TO AVOID INDEX OUT OF BOUND ERROR IN THE NEXT FOR LOOP*/
    {
        bool flag = false;
        for (int j = 0 + i; j < window + i; j++)
        // HERE WE ARE MOVING BOTH BY THE WINDOW SIZE AND THE INDEX OF THE CURRENT ELEMENT THAT IS BY i
        {
            if (arr[j] < 0)
            {
                cout << arr[j] << " ";
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            cout << "0 ";
        }
    }
    vector<int> v;
    int i = 0;
    int j = 0;
    int k = 3;
    while (j < n)
    {
        if (arr[j] < 0 && j - i + 1 < k)
        {
            v.push_back(arr[j]);
            j++;
        }
        else
        {
            if(v.size() == 0)
                cout << 0;
            else{
                cout << v.front();
                v.erase(v.begin());
            }
            i++;
            j++;
        }
        return 0;
    }
}