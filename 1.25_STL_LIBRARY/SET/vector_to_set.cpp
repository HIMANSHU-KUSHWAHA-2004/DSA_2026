#include <bits/stdc++.h>
#include <set>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //YOU CAN JUST DIRECTLY MAKE A SET USING THE ARRAY
    // set<int> hlo(arr.begin(), arr.end());
    // for (auto it : hlo)
    // {
    //     cout << it << " ";
    // }

    //YOU CAN USE THE FOR LOOP TO MAKE A SET
    set<int> hlo_2;
    for (int i = 0; i < n; i++)
    {
        hlo_2.insert(arr[i]);
    }
    hlo_2.erase(6);
    for (auto it : hlo_2)
    {
        cout << it << " ";
    }


    return 0;
}