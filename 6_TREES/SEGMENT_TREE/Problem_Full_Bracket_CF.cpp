#include <bits/stdc++.h>
using namespace std;

struct Node {
    int open = 0;
    int close = 0;
    int full = 0;
};

class SegmentTree {
public:
    vector<Node> seg;
    int n;

    SegmentTree(int size) {
        n = size;
        seg.resize(4 * n);
    }

    void Build_For_Brackets(int idx, int left, int right, string &s) {

        if (left == right) {
            if (s[left] == '(')
                seg[idx] = {1, 0, 0};
            else
                seg[idx] = {0, 1, 0};
            return;
        }

        int mid = (left + right) / 2;

        Build_For_Brackets(2*idx + 1, left, mid, s);
        Build_For_Brackets(2*idx + 2, mid + 1, right, s);

        Node L = seg[2*idx + 1];
        Node R = seg[2*idx + 2];

        int match = min(L.open, R.close);

        seg[idx].full  = L.full + R.full + match;
        seg[idx].open  = L.open + R.open - match;
        seg[idx].close = L.close + R.close - match;
    }

    Node Query_For_Bracket(int idx, int left, int right, int l, int r) {

        // no overlap
        if (l > right || r < left)
            return {0, 0, 0};

        // complete overlap
        if (left >= l && right <= r)
            return seg[idx];

        int mid = (left + right) / 2;

        Node L = Query_For_Bracket(2*idx + 1, left, mid, l, r);
        Node R = Query_For_Bracket(2*idx + 2, mid + 1, right, l, r);

        int match = min(L.open, R.close);

        Node res;
        res.full  = L.full + R.full + match;
        res.open  = L.open + R.open - match;
        res.close = L.close + R.close - match;

        return res;
    }
};

int main() {
    string s;
    cin >> s;

    int m;
    cin >> m;

    int n = s.size();

    SegmentTree st(n);
    st.Build_For_Brackets(0, 0, n-1, s);

    while (m--) {
        int l, r;
        cin >> l >> r;

        Node ans = st.Query_For_Bracket(0, 0, n-1, l-1, r-1);

        cout << 2 * ans.full << endl;
    }

    return 0;
}