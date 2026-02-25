#include <bits/stdc++.h>
using namespace std;

void Heapify(vector<int> &a, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && a[left] > a[largest]) largest = left;
    if(right < n && a[right] > a[largest]) largest = right;

    if(largest != i){
        swap(a[i], a[largest]);
        Heapify(a, n, largest);
    }
}

void HeapSort(vector<int> &a){
    int n = (int)a.size();    

    // build max heap
    for(int i = n/2 - 1; i >= 0; i--){
        Heapify(a, n, i);
    }

    for(int i : a){
        cout << i << " ";
    }
    cout << "\nThis is the Max heap" << endl;
    // sorting
    for(int i = n - 1; i > 0; i--){
        swap(a[0], a[i]);    
        Heapify(a, i, 0);      
       }
}

int main(){
    vector<int> boka = {9,5,1,3,7,6,2};
    HeapSort(boka);

    for(int x : boka) cout << x << " ";
}
