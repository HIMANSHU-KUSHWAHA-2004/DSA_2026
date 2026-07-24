#include <bits\stdc++.h>
using namespace std;
vector<int> lola(vector<int> a)
{
    int n = a.size();
    vector<int> dp(n, 1);
    vector<int> hash(n, 1);
    int lastindex = 0;
    int maxi = 1;//this is for checking the maximum length of the increasing subsequence
    for(int idx = 0; idx < n; idx++)
    {
        hash[idx] = idx;
        //In hash(or the parent array) we know that we will store same as index
        //here we are storing the element as the index without any external loop
        for(int prev = 0; prev < idx; prev++)
        {
            if(a[prev] < a[idx] && 1 + dp[prev] > dp[idx])
            {
                dp[idx] = 1 + dp[prev];
                hash[idx] = prev;
            }
        }
        if(maxi < dp[idx]){
            maxi = dp[idx];
            lastindex = idx;
        }

    }
    vector<int> temp;
    while(hash[lastindex] != lastindex)
    {
        temp.push_back(a[lastindex]);
        lastindex = hash[lastindex];
    }
    temp.push_back(a[lastindex]);
    reverse(temp.begin(), temp.end());
    return temp;

}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int>  boka = lola(a);
    for (auto it : boka)
        cout << it << " ";
}