// https://loj.ac/p/132
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

template <class Info, class Tag>
struct LazySegmentTree {
    int left, right;
    Info info;
    Tag tag;
    LazySegmentTree *left_child = NULL, *right_child = NULL;

    LazySegmentTree(int lb, int rb) {
        left = lb;
        right = rb;
        info = Info();
        tag = Tag();
    }

    void apply(const Tag &v) {
        info.apply(v);
        tag.apply(v);
    }

    void push() {
        if (left_child) {
            left_child->apply(tag);
        }

        if (right_child) {
            right_child->apply(tag);
        }

        tag = Tag();
    }

    void pull() {
        info = left_child->info + right_child->info;
    }

    void extend() {
        int mid = left + right >> 1;

        if (!left_child) {
            left_child = new LazySegmentTree(left, mid);
        }

        if (!right_child) {
            right_child = new LazySegmentTree(mid + 1, right);
        }
    }

    void rangeApply(int l, int r, const Tag &v) {
        if (left > r || right < l) {
            return;
        }

        if (l <= left && right <= r) {
            apply(v);
            return;
        }

        extend();
        push();
        left_child->rangeApply(l, r, v);
        right_child->rangeApply(l, r, v);
        pull();
    }

    Info rangeQuery(int l, int r) {
        if (l > right || r < left) {
            return Info();
        }

        if (left >= l && right <= r) {
            return info;
        }

        push();
        Info ans = Info();

        if (left_child) {
            ans = ans + left_child->rangeQuery(l, r);
        }

        if (right_child) {
            ans = ans + right_child->rangeQuery(l, r);
        }

        return ans;
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
    int x;
    int len;

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
    LazySegmentTree<Info, Tag> S(0, n);

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