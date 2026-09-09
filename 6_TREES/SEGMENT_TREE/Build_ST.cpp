#include <bits\stdc++.h>
using namespace std;
class SegmentTree
{
public:
    vector<int> seg;
    int n;

    SegmentTree(int size)
    {
        n = size;
        seg.resize(4 * n, 0);
    }

    void Build(int idx, int left, int right, vector<int> &arr)
    {
        if (left == right)
        {
            seg[idx] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        Build(2 * idx + 1, left, mid, arr);
        Build(2 * idx + 2, mid + 1, right, arr);
        /*This is the merging part here we can do the things as wee needed as i use minimunm because I need
          the minimum of the the range Left to Right we can even use Max,Sum,or even Function*/
        
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    void print()
    {
        for (int i = 0; i < seg.size(); i++)
        {
            cout << "("<< i<< "," << seg[i] << ") ";
        }
        cout << endl;
    }
    //this is for the minimum of the range left to right we can even use max,sum,or even function
    int Query(int idx,int left,int right,int l,int r){
        if(l>right || r<left){
            return INT_MAX;
        }
        if(left>=l && right<=r){
            return seg[idx];
        }

        int mid=(left+right)/2;
        int left_min = Query(2*idx+1,left,mid,l,r);
        int right_min = Query(2*idx+2,mid+1,right,l,r);
        return min(left_min, right_min);
    }
    // this is also for the minimum of the range left to right we can even use max,sum,or even function
    void Update(int idx,int left, int right,int pos,int val){
        if(left == right){
            seg[idx] = val;
            return;
        }
        int mid = (left+right)/2;
        if(pos<=mid){
            Update(2*idx+1,left,mid,pos,val);
        }else{
            Update(2*idx+2,mid+1,right,pos,val);
        }
        //According to the function we can do the things as we needed as i use minimunm because I need
        //the minimum of the the range Left to Right we can even use Max,Sum,or even Function
        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    }
};
int main()
{
    vector<int> arr = {1, 3, 2, -5, 6, 4};
    SegmentTree st(arr.size());
    st.Build(0, 0, arr.size() - 1, arr);
    // st.print();
    cout << st.Query(0,0,arr.size()-1,1,4) << endl;
    st.print();

}