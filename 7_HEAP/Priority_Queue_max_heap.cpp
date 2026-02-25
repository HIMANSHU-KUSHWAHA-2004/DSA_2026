#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> maxHeap;

    maxHeap.push(10);
    maxHeap.push(70);
    maxHeap.push(150);
    maxHeap.push(90);

    cout << "Size: " << maxHeap.size() << endl;
    cout << "Elements in priority queue:" << endl;

    while(!maxHeap.empty()){
        cout << maxHeap.top() << endl;
        maxHeap.pop();
    }

     priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(10);
    minheap.push(70);
    minheap.push(150);
    minheap.push(90);

    cout << "Size: " << minheap.size() << endl;

    cout << "Elements in Min Heap order:" << endl;

    while(!minheap.empty()){
        cout << minheap.top() << endl;
        minheap.pop();
    }

    
    return 0;
}
