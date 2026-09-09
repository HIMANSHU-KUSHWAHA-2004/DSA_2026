#include <bits\stdc++.h>
using namespace std;
class SegmentTree
{
public:
    vector<int> seg;
    vector<int> lazy;
    int n;

    SegmentTree(int size)
    {
        n = size;
        seg.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void build_sum(int idx, int left, int right, vector<int> &arr)
    {
        if (left == right)
        {
            seg[idx] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        build_sum(2 * idx + 1, left, mid, arr);
        build_sum(2 * idx + 2, mid + 1, right, arr);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void push(int idx, int left, int right)
    {
        if (lazy[idx] != 0)
        {
            seg[idx] += (right - left + 1) * lazy[idx];
            if (left != right)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }

            lazy[idx] = 0;
        }
    }

    void update_sum_range(int idx, int left, int right, int l, int r, int val)
    {
        push(idx, left, right);

        if (right < l || left > r)
        {
            return;
        }

        if (left >= l && right <= r)
        {
            lazy[idx] += val;
            push(idx, left, right);
            return;
        }
        int mid = (left + right) / 2;

        update_sum_range(2 * idx + 1, left, mid, l, r, val);
        update_sum_range(2 * idx + 2, mid + 1, right, l, r, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    long long query(int idx, int left, int right,
                    int l, int r)
    {

        // apply pending update
        push(idx, left, right);

        // No overlap
        if (right < l || left > r)
            return 0;

        // Complete overlap
        if (left >= l && right <= r)
            return seg[idx];

        // Partial overlap
        int mid = (left + right) / 2;

        long long leftAns = query(2 * idx + 1, left, mid, l, r);

        long long rightAns = query(2 * idx + 2, mid + 1, right, l, r);

        return leftAns + rightAns;
    }
};
int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};

    SegmentTree st(arr.size());

    st.build_sum(0, 0, arr.size() - 1, arr);

    // add 10 to range [1,3]
    st.update_sum_range(0, 0, arr.size() - 1, 1, 3, 10);

    // query sum [1,3]
    cout << st.query(0, 0, arr.size() - 1, 1, 3);
}