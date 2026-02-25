#include <iostream>
using namespace std;
int main(){
    int arr[8] = {2,5,2,1,9,1,8,9};
    int n = 8;
    for(int i = 0;i<n;i++){
        if(arr[i] != -5);
            for(int j = i+1;j<n;j++){
                if(arr[i] == arr[j])
                    arr[i] = arr[j] = -5;
        }
    }

    for(int i = 0;i<n;i++){
        if(arr[i] > 0)
            cout << arr[i] << "\n ";
    }
} 