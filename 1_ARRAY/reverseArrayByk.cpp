#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n); 
    
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; // Input each element
    }
    cout << "Enter the number you wanna reverse the array : " ;
    cin >> k;
    if(k>n)
        k = k%n;
    
    reverse(arr.begin(), arr.end()); 
    reverse(arr.begin(),arr.begin() + k);
    reverse(arr.begin() + k,arr.end());
    
    cout << "Reversed vector:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";

    }
    return 0;
}
