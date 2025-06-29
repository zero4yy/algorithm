// https://loj.ac/p/130
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

template<class Info>
struct SegmentTree {

    int n;
    vector<Info> info;

    SegmentTree() {}

    SegmentTree(int n) {
        init(vector<Info>(n, Info()));
    }

    SegmentTree(const vector<Info> &_info) {
        init(_info);
    }

    void init(const vector<Info> &_info) {
        n = _info.size();
        info.assign(4 * n, Info());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r) {
                info[p] = _info[l];
                return;
            }

            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m + 1, r);
            pull(p);
        };
        build(1, 0, n - 1);
    }

    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void apply(int p, int l, int r, int pos, const Info &val) {
        if (l == r) {
            info[p] = val;
            return;
        }

        int m = l + r >> 1;

        if (pos <= m) {
            apply(p * 2, l, m, pos, val);
        } else {
            apply(p * 2 + 1, m + 1, r, pos, val);
        }

        pull(p);
    }

    Info rangeQuery(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return info[p];
        }

        int m = l + r >> 1;
        Info res = Info();

        if (ql <= m) {
            res = res + rangeQuery(p * 2, l, m, ql, qr);
        }

        if (qr > m) {
            res = res + rangeQuery(p * 2 + 1, m + 1, r, ql, qr);
        }

        return res;
    }

    void apply(int pos, const Info &val) {
        apply(1, 0, n - 1, pos, val);
    }

    Info rangeQuery(int ql, int qr) {
        return rangeQuery(1, 0, n - 1, ql, qr);
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
    vector<Info> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i].x;
    }

    SegmentTree<Info> seg(a);

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