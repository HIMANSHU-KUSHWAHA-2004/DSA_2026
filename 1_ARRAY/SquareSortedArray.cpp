#include <bits/stdc++.h>
using namespace std;
/*THE QUESTION IS TO RETURN A ARRAY WHICH IS SORTED BUT WITH THE SQUARE OF THE ELEMENT OF THE FIRST ARRAY*/
void InsertionSorting(int *arr,int n){
    for(int i = 1;i<n;i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

}


void squarearrray(int *arrayrecieve,int n){
    for(int i =0;i<n;i++){
        *(arrayrecieve + i) = *(arrayrecieve + i) * *(arrayrecieve + i);
    }
    cout << "Squared array before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << *(arrayrecieve + i) << " ";
    }
    cout << endl;
InsertionSorting(arrayrecieve,n);
}

int main(){
    int n;
    int arr[] = {-10,-8,-5,-3,0,1,2,6,9,11};
    n = sizeof(arr)/sizeof(arr[0]);
    squarearrray(arr,n);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}