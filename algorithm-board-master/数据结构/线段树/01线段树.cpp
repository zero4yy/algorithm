/*
https://www.luogu.com.cn/problem/P2572
0 l r 把 [l, r] 区间内的所有数全变成 0
1 l r 把 [l, r] 区间内的所有数全变成 1
2 l r 把 [l,r] 区间内的所有数全部取反，也就是说把所有的 0 变成 1，把所有的 1 变成 0
3 l r 询问 [l, r] 区间内总共有多少个 1
4 l r 询问 [l, r] 区间内最多有多少个连续的 1
*/

#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;


// b:区间1的个数,      c:区间0的个数
//lb:区间左起1的长度, lc:区间左起0的长度
//rb:区间右起1的长度, rc:区间右起0的长度
//mb:区间1的最长长度, mc:区间0的最长长度
//len:区间的长度
//tag:区间赋值标记,无标记:-1,有标记:0或1
//rev:区间取反标记,无标记: 0,有标记:1

struct node {
    int l, r;
    int b, lb, rb, mb, c, lc, rc, mc;
    int len, tag, rev;
};

struct SegTree {

    vector<node> tr;

    SegTree() {}
    SegTree(int n) {
        tr = vector<node> (n * 4 + 5);
    }

    void pushup(node &u, node l, node r) { //上传
        u.b = l.b + r.b;
        u.lb = l.c ? l.lb : l.b + r.lb;
        u.rb = r.c ? r.rb : r.b + l.rb;
        u.mb = max({l.mb, r.mb, l.rb + r.lb});
        u.c = l.c + r.c;
        u.lc = l.b ? l.lc : l.c + r.lc;
        u.rc = r.b ? r.rc : r.c + l.rc;
        u.mc = max({l.mc, r.mc, l.rc + r.lc});
    }

    void pd(int u, int opt) { //操作区间
        node &t = tr[u];

        if (opt == 0) { //区间赋值为0
            t.b = t.lb = t.rb = t.mb = 0;
            t.c = t.lc = t.rc = t.mc = t.len;
            t.tag = 0;
            t.rev = 0;
        }

        if (opt == 1) { //区间赋值为1
            t.b = t.lb = t.rb = t.mb = t.len;
            t.c = t.lc = t.rc = t.mc = 0;
            t.tag = 1;
            t.rev = 0;
        }

        if (opt == 2) { //区间取反
            swap(t.b, t.c);
            swap(t.lb, t.lc);
            swap(t.rb, t.rc);
            swap(t.mb, t.mc);
            t.rev ^= 1;
        }
    }

    void pushdown(int u) { //下传
        node &t = tr[u];

        if (t.tag == 0)
            pd(u << 1, 0), pd(u << 1 | 1, 0);

        if (t.tag == 1)
            pd(u << 1, 1), pd(u << 1 | 1, 1);

        if (t.rev)
            pd(u << 1, 2), pd(u << 1 | 1, 2);

        t.tag = -1;
        t.rev = 0;
    }

    void build(int u, int l, int r) { //建树
        tr[u] = {l, r, 0, 0, 0, 0, 1, 1, 1, 1, r - l + 1, -1, 0};

        if (l == r)
            return;

        int m = l + r >> 1;
        build(u << 1, l, m);
        build(u << 1 | 1, m + 1, r);
        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }

    void change(int u, int x, int y, int k) { //区修
        if (y < tr[u].l || tr[u].r < x)
            return;

        if (x <= tr[u].l && tr[u].r <= y) {
            pd(u, k);
            return;
        }

        pushdown(u);
        change(u << 1, x, y, k);
        change(u << 1 | 1, x, y, k);
        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }
    
    node query(int u, int x, int y) { //区查
        if (x > tr[u].r || y < tr[u].l)
            return {};

        if (x <= tr[u].l && tr[u].r <= y)
            return tr[u];

        pushdown(u);
        node T; //开一个临时节点，存储拼凑结果
        pushup(T, query(u << 1, x, y), query(u << 1 | 1, x, y));
        return T;
    }

};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n, m;
    cin >> n >> m;
    SegTree S(n);
    S.build(1, 0, n);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        S.change(1, i, i, a);
    }

    for (int i = 1; i <= m; i++) {
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 0) {          // 把 [l, r] 区间内的所有数全变成 0
            S.change(1, l, r, 0);
        } else if (op == 1) {   // 把 [l, r] 区间内的所有数全变成 1
            S.change(1, l, r, 1);
        } else if (op == 2) {   // 把 [l,r] 区间内的所有数全部取反，也就是说把所有的 0 变成 1，把所有的 1 变成 0
            S.change(1, l, r, 2);
        } else if (op == 3) {   // 询问 [l, r] 区间内总共有多少个 1
            node res = S.query(1, l, r);
            cout << res.b << endl;
        } else {                // 询问 [l, r] 区间内最多有多少个连续的 1
            node res = S.query(1, l, r);
            cout << res.mb << endl;
        }
    }

    return 0;
}