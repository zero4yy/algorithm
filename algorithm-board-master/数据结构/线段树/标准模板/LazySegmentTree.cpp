// https://loj.ac/p/132
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

template<class Info, class Tag>
struct LazySegmentTree {

    int n;
    vector<Info> info;
    vector<Tag> tag;

    LazySegmentTree() {}

    LazySegmentTree(int n) {
        init(vector<Info>(n, Info()));
    }

    LazySegmentTree(const vector<Info> &_info) {
        init(_info);
    }

    void init(const vector<Info> &_info) {
        n = _info.size();
        info.assign(4 * n, Info());
        tag.assign(4 * n, Tag());
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

    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }

    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l > y || r < x) {
            return;
        }

        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }

        push(p);
        int m = (l + r) / 2;
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m + 1, r, x, y, v);
        pull(p);
    }

    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n - 1, l, r, v);
    }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l > y || r < x) {
            return Info();
        }

        if (l >= x && r <= y) {
            return info[p];
        }

        push(p);
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m + 1, r, x, y);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n - 1, l, r);
    }
};

struct Tag {
    int x;
    Tag(int x = 0) {
        this->x = x;
    }
    void apply(const Tag &t) {
        if (t.x) {
            x += t.x;
        }
    }
};

struct Info {
    int x, len;
    Info(int x = 0, int len = 1) {
        this->x = x;
        this->len = len;
    }
    void apply(const Tag &t) {
        if (t.x) {
            x += t.x * len;
        }
    }
};

Info operator+(const Info &a, const Info &b) {
    return Info(a.x + b.x, a.len + b.len);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n, q;
    cin >> n >> q;
    LazySegmentTree<Info, Tag> S(n + 1);

    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        S.rangeApply(i, i, {v});
    }

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            S.rangeApply(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << S.rangeQuery(l, r).x << endl;
        }
    }

    return 0;
}