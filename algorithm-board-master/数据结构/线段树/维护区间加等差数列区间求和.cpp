#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct SegTree {

    int n;
    vector<int> lazy_a0, lazy_d, lazy_op; // 三个懒标记, 首项、公差、有没有懒标记要下传
    vector<int> sum;

    SegTree() {}
    SegTree(int n) {
        this->n = n;
        lazy_a0 = vector<int> (n * 4 + 5);
        lazy_d = vector<int> (n * 4 + 5);
        lazy_op = vector<int> (n * 4 + 5);
        sum = vector<int> (n * 4 + 5);
    }

    void push_down(int p, int l, int r, int m) {
        if (lazy_op[p] != 0) {
            int a0l = lazy_a0[p], anl = lazy_a0[p] + (m - l) * lazy_d[p];
            int a0r = lazy_a0[p] + (m - l + 1) * lazy_d[p], anr = lazy_a0[p] + (r - l) * lazy_d[p];
            int d = lazy_d[p];;
            lazy_a0[p << 1] += a0l;
            lazy_a0[p << 1 | 1] += a0r;
            lazy_d[p << 1] += d;
            lazy_d[p << 1 | 1] += d;
            lazy_op[p << 1] = 1;
            lazy_op[p << 1 | 1] = 1;
            sum[p << 1] += (a0l + anl) * (m - l + 1) / 2;
            sum[p << 1 | 1] += (a0r + anr) * (r - m) / 2;
            lazy_a0[p] = 0;
            lazy_d[p] = 0;
            lazy_op[p] = 0;
        }
    }

    void change(int p, int l, int r, int ql, int qr, int a0, int d) {
        if (ql <= l && r <= qr) {
            int a00 = a0 + (l - ql) * d;
            int an = a0 + (r - ql) * d;
            lazy_a0[p] += a00;
            lazy_d[p] += d;
            lazy_op[p] = 1;
            sum[p] += (a00 + an) * (r - l + 1) / 2;
            return;
        }
        int m = l + r >> 1;
        push_down(p, l, r, m);
        if (ql <= m) {
            change(p << 1, l, m, ql, qr, a0, d);
        }
        if (qr > m) {
            change(p << 1 | 1, m + 1, r, ql, qr, a0, d);
        }
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
    }

    int query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return sum[p];
        }
        int m = l + r >> 1;
        push_down(p, l, r, m);
        int res = 0;
        if (ql <= m) {
            res += query(p << 1, l, m, ql, qr);
        }
        if (qr > m) {
            res += query(p << 1 | 1, m + 1, r, ql, qr);
        }
        return res;
    }

    void change(int ql, int qr, int a0, int d) {
        change(1, 0, n, ql, qr, a0, d);
    }

    int query(int ql, int qr) {
        return query(1, 0, n, ql, qr);
    }

};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n, m;
    cin >> n;
    SegTree S(n);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        S.change(i, i, a, 0);
    }
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, a0, d;
            cin >> l >> r >> a0 >> d;
            S.change(l, r, a0, d);  // 在区间[l, r]上加上一个首项为a0, 公差为d的等差数列
        } else {
            int l, r, mod;
            cin >> l >> r >> mod;
            cout << S.query(l, r) % mod << endl; // 询问区间[l,r]的和, 并且对mod取模。
        }
    }
    return 0;
}
