// https://loj.ac/p/132
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

template <class Info>
struct SegmentTree  {
    int left, right;
    Info info;
    SegmentTree *left_child = NULL, *right_child = NULL;

    SegmentTree(int lb, int rb) {
        left = lb;
        right = rb;
        info = Info();
    }

    void pull() {
        info = left_child->info + right_child->info;
    }

    void extend() {
        int mid = left + right >> 1;

        if (!left_child) {
            left_child = new SegmentTree(left, mid);
        }

        if (!right_child) {
            right_child = new SegmentTree(mid + 1, right);
        }
    }

    void apply(int pos, const Info &val) {
        if (left == right) {
            info = val;
            return;
        }

        extend();
        int m = left + right >> 1;

        if (pos <= m) {
            left_child->apply(pos, val);
        } else {
            right_child->apply(pos, val);
        }

        pull();
    }

    Info rangeQuery(int ql, int qr) {
        if (ql <= left && right <= qr) {
            return info;
        }

        int m = left + right >> 1;
        Info ans = Info();

        if (left_child && ql <= m) {
            ans = ans + left_child->rangeQuery(ql, qr);
        }

        if (right_child && qr > m) {
            ans = ans + right_child->rangeQuery(ql, qr);
        }

        return ans;
    }

};

struct Info {
    int x;

    Info(int x = 0) {
        this->x = x;
    }

};

Info operator+(const Info &a, const Info &b) {
    return Info(a.x + b.x);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n, q;
    cin >> n >> q;

    SegmentTree<Info> seg(0, n);

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        seg.apply(i, {a});
    }

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int i, x;
            cin >> i >> x;
            seg.apply(i, {seg.rangeQuery(i, i).x + x});
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.rangeQuery(l, r).x << endl;
        }
    }

    return 0;
}