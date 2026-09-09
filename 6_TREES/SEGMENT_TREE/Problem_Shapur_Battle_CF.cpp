#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> seg;

    SegTree(int n) : n(n) {
        seg.assign(4*n, 0);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if(l == r) {
            seg[idx] += val;
            return;
        }
        int mid = (l + r) / 2;
        if(pos <= mid) update(2*idx+1, l, mid, pos, val);
        else update(2*idx+2, mid+1, r, pos, val);

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return seg[idx];

        int mid = (l + r) / 2;
        return query(2*idx+1, l, mid, ql, qr)
             + query(2*idx+2, mid+1, r, ql, qr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    // compression
    vector<int> temp = a;
    sort(temp.begin(), temp.end());
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++) mp[temp[i]] = i;

    SegTree leftTree(n), rightTree(n);

    // put all in RIGHT
    for(int i = 0; i < n; i++) {
        rightTree.update(0, 0, n-1, mp[a[i]], +1);
    }

    long long ans = 0;

    for(int j = 0; j < n; j++) {
        int x = mp[a[j]];

        // remove current
        rightTree.update(0, 0, n-1, x, -1);

        // right smaller
        int rightSmaller = (x > 0) ? rightTree.query(0, 0, n-1, 0, x-1) : 0;

        // left greater
        int leftGreater = (x < n-1) ? leftTree.query(0, 0, n-1, x+1, n-1) : 0;

        ans += 1LL * leftGreater * rightSmaller;

        // add to left
        leftTree.update(0, 0, n-1, x, +1);
    }

    cout << ans << "\n";
}