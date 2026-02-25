#include <bits/stdc++.h>
using namespace std;
class Heap
{
public:
    vector<int> Max_Heap;

    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left_child(int i)
    {
        return 2 * i + 1;
    }
    int right_child(int i)
    {
        return 2 * i + 2;
    }

    void push_node(int value)
    {
        Max_Heap.push_back(value);
        int last = Max_Heap.size() - 1;
        while (last > 0 && Max_Heap[parent(last)] < Max_Heap[last])
        {
            swap(Max_Heap[parent(last)], Max_Heap[last]);
            last = parent(last);
        }
    }

    void Heapify(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < Max_Heap.size() && Max_Heap[left] > Max_Heap[largest])
            largest = left;
        if (right < Max_Heap.size() && Max_Heap[right] > Max_Heap[largest])
            largest = right;
        if (largest != i)
        {
            swap(Max_Heap[i], Max_Heap[largest]);
            Heapify(largest);
        }
    }

    void Array_to_heap(vector<int> arr)
    {
        Max_Heap = arr;
        int temp = arr.size() / 2 - 1;
        for (int j = temp; j >= 0; j--)
        {
            Heapify(j);
        }
    }
    void Pop_max()
    {
        if (Max_Heap.size() == 0)
            return;

        Max_Heap[0] = Max_Heap.back();
        Max_Heap.pop_back();
        Heapify(0);
    }

    void print()
    {
        for (int i : Max_Heap)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    int maxi()
    {
        return Max_Heap[0];
    }
};
int main()
{
    Heap arr;
    arr.push_node(50);
    arr.push_node(80);
    arr.push_node(40);
    arr.push_node(90);
    arr.push_node(10);
    arr.print();
    arr.Pop_max();
    arr.print();
    Heap nunnu;
    vector<int> boka = {10, 20, 30, 40, 50, 80, 90};
    nunnu.Array_to_heap(boka);
    nunnu.print();
    nunnu.Pop_max();
    nunnu.print();

    return 0;
}