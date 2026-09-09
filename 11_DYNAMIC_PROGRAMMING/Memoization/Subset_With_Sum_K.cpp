#include<bits\stdc++.h>
using namespace std;
int ans(vector<int> &arr, int sum, int n){
    if(sum == 0) return 1;
    if(n == 0) {
        if(arr[0] == sum) return 1;
        else return 0;
    }
    int notake = ans(arr, sum, n-1);
    int take = 0;
    if(arr[n] <= sum) take = ans(arr, sum-arr[n], n-1);
    return take + notake;
}
void printSubset(vector<int>& arr, int sum, int n, vector<int>& path) {
    if(sum == 0) {
        for(int x : path) cout << x << " ";
        cout << endl;
        return;
    }

    if(n < 0) return;

    // NOT TAKE.
    printSubset(arr, sum, n-1, path);

    // TAKE
    if(arr[n] <= sum) {
        path.push_back(arr[n]);              // choose
        printSubset(arr, sum - arr[n], n-1, path);
        path.pop_back();                     // backtrack
    }
}
int main(){
    vector<int> arr = {1, 2, 3, 4};
    int sum = 6;    
    int n = arr.size(); 
    vector<int> path; // to store current subset
    printSubset(arr, sum, n-1, path);
    cout << "The number of subset : "<<ans(arr, sum, n-1);
}