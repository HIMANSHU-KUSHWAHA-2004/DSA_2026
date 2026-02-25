#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    int arr[] = {12, -1, -2, 5, -6, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    int i = 0;
    int j = 0;
    int k = 3;
    while (j < n)
    {
        if (arr[j] < 0)        // THE CONDITION WHICH WAS GIVIN IN THE QUESTION 
        {
            v.push_back(arr[j]);
        }
        if (j - i + 1 < k) //THIS IS FOR CREATING THE FIRST WINDOW 
            j++;
        else
        {
            if (v.size() == 0)
                cout << " 0";
            else
            {
                cout << v.front();
                if (arr[i] == v.front())
                {
                    v.erase(v.begin());
                }
            }
            i++;
            j++;
        }
    }
    return 0;
}