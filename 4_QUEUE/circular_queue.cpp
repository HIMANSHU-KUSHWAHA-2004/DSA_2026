#include <bits/stdc++.h>
using namespace std;

class Circular_queue {
    int *arr;
    int currsize, cap;
    int frontIndex;
    int rear;

public:
    Circular_queue(int capa) {
        cap = capa;
        arr = new int[cap];
        currsize = 0;
        frontIndex = 0;
        rear = -1;
    }

    void push(int val) {
        if (currsize == cap) {
            cout << "The Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % cap;
        arr[rear] = val;
        currsize++;
    }

    void pop() {
        if (empty()) {
            cout << "The Queue is empty" << endl;
            return;
        }
        cout << arr[frontIndex] << " is popped" << endl;
        frontIndex = (frontIndex + 1) % cap;
        currsize--;
    }

    int front() {
        if (empty()) {
            cout << "The Queue is empty" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    bool empty() {
        return currsize == 0;
    }

    void print() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        int i = frontIndex;
        for (int cnt = 0; cnt < currsize; cnt++) {
            cout << arr[i] << " ";
            i = (i + 1) % cap;
        }
        cout << "\n";
    }
};

int main() {
    Circular_queue obj(5);
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    obj.print();
    obj.pop();
    obj.pop();
    obj.print();
    obj.push(10);
    obj.push(20);    
    obj.push(50);
    obj.print();
    obj.push(60);
    obj.pop();
    obj.push(60);
    obj.print();
    cout<< "The front element of the Queue is : " << obj.front() << endl;

}
