// https://www.luogu.com.cn/problem/CF292E
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int> a, b;

struct SegTree {

    int n;
    vector<int> d, lazy;

    SegTree() {}
    SegTree(int n) {
        this->n = n;
        d = vector<int> (n * 4 + 5, -1);
        lazy = vector<int> (n * 4 + 5, -1);
    }

    void push_down(int p, int l, int r, int m) {
        if (lazy[p] != -1) {
            d[p << 1] = lazy[p];
            d[p << 1 | 1] = lazy[p] + m + 1 - l;
            lazy[p << 1] = lazy[p];
            lazy[p << 1 | 1] = lazy[p] + m + 1 - l;
            lazy[p] = -1;
        }
    }

    void change(int p, int l, int r, int ql, int qr, int v) {
        if (ql <= l && r <= qr) {
            d[p] = l - ql + v;
            lazy[p] = l - ql + v;
            return;
        }
        int m = l + r >> 1;
        push_down(p, l, r, m);
        if (ql <= m) {
            change(p << 1, l, m, ql, qr, v);
        }
        if (qr > m) {
            change(p << 1 | 1, m + 1, r, ql, qr, v);
        }
    }

    int query(int p, int l, int r, int pos) {
        if (l == r) {
            return d[p] == -1 ? b[pos] : a[d[p]];
        }
        int m = l + r >> 1;
        push_down(p, l, r, m);
        if (pos <= m) {
            return query(p << 1, l, m, pos);
        } else {
            return query(p << 1 | 1, m + 1, r, pos);
        }
    }

    void change(int ql, int qr, int v) {
        change(1, 0, n, ql, qr, v);
    }

    int query(int pos) {
        return query(1, 0, n, pos);
    }

};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n, m;
    cin >> n >> m;
    a = vector<int> (n + 1);
    b = vector<int> (n + 1);
    SegTree S(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            S.change(y, y + k - 1, x);
        } else {
            int x;
            cin >> x;
            cout << S.query(x) << endl;
        }
    }
    return 0;
}
