#include <bits\stdc++.h>
using namespace std;
int Partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    // Do not use the Pivot to swap because it will just swap in the variable that is pivot = 5 Not the array
    swap(arr[i], arr[right]);
    return i;
}
int Quick_Select(vector<int> &arr, int L, int R, int K)
{
    int Pivot_Index = Partition(arr, L, R);
    if(Pivot_Index == K)
        return arr[Pivot_Index];
    if(Pivot_Index < K)
        return Quick_Select(arr,Pivot_Index + 1,R,K);
    else
        return Quick_Select(arr,L,Pivot_Index - 1,K);

}
int main()
{
    vector<int> Arr = {7, 1, 1, 6, 4, 6, 3, 4};
    vector<int> sortarr(Arr.begin(),Arr.end());
    sort(sortarr.begin(),sortarr.end());
    for(int i : sortarr){
        cout << i << " ";
    }
    cout << endl;
    // sort = {1,2,3,4,5,6,7,8}
    int n = Arr.size();
    int k = 3; // that means we need the 3rd largest number in the array
    int idx = n - k; // means this is the array index on which the 3rd largest element would be form the front
    cout << Quick_Select(Arr,0,n-1,idx);
}
