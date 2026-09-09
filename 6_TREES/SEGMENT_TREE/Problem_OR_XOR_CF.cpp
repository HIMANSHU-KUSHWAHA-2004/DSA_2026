#include <bits/stdc++.h>
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
    void Build_OR_XOR(int idx, int left, int right, vector<int> &arr, int flag)
    {
        if (left == right)
        {
            seg[idx] = arr[left];
            return;
        }
        int mid = (left + right) / 2;

        Build_OR_XOR(2 * idx + 1, left, mid, arr, !flag);
        Build_OR_XOR(2 * idx + 2, mid + 1, right, arr, !flag);
        if (flag == 1)
        {
            seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
        }
        else
        {
            seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
        }
    }
    void Update_OR_XOR(int idx, int left, int right, int pos, int val, int flag)
    {
        if (left == right)
        {
            seg[idx] = val;
            return;
        }
        int mid = (left + right) / 2;
        if (pos <= mid)
        {
            Update_OR_XOR(2 * idx + 1, left, mid, pos, val, !flag);
        }
        else
        {
            Update_OR_XOR(2 * idx + 2, mid + 1, right, pos, val, !flag);
        }
        if (flag == 1)
        {
            seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
        }
        else
        {
            seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
        }
    }
    int Query_OR_XOR(int idx, int left, int right, int l, int r, int flag)
    {
        if (l > right || r < left)
        {
            return 0;
        }
        if (left >= l && right <= r)
        {
            return seg[idx];
        }
        int mid = (left + right) / 2;
        int left_ans = Query_OR_XOR(2 * idx + 1, left, mid, l, r, !flag);
        int right_ans = Query_OR_XOR(2 * idx + 2, mid + 1, right, l, r, !flag);
        if (flag == 1)
        {
            return left_ans | right_ans;
        }
        else
        {
            return left_ans ^ right_ans;
        }
    }
};
int main()
{
    int n, q;
    cin >> n >> q;

    int size = 1 << n;

    int flag = (n % 2 == 0) ? 0 : 1;

    SegmentTree st(size);

    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    st.Build_OR_XOR(0, 0, size - 1, arr, flag);

    while (q--)
    {
        int idx, val;
        cin >> idx >> val;
        idx--; // IMPORTANT
        st.Update_OR_XOR(0, 0, size - 1, idx, val, flag);
        cout << st.seg[0] << endl; 
    }
}