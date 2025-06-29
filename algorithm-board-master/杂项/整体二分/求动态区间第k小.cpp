// https://www.luogu.com.cn/problem/P2617
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct BIT {

    int n;
    vector<int> t;

    BIT(int _n) {
        n = _n + 4;
        t.resize(_n + 5);
    }

    void add(int x, int v) {
        x++;
        for (; x <= n; x += x & -x) t[x] += v;
    }

    int ask(int x) {
        x++;
        int res = 0;
        for (; x > 0; x -= x & -x) res += t[x];
        return res;
    }

    int ask_range(int l, int r) {return ask(r) - ask(l - 1);}
};

struct op {
    int p, x, id, opt;
};

struct query {
    int l, r, k, id;
};

BIT B(200005);
vector<int> res;
vector<op> ops;
vector<query> qs;

void solve(int l, int r, vector<op>& ops, vector<query>& qs) {
    if (l == r) {
        for (int i = 0; i < qs.size(); i++) {
            res[qs[i].id] = l;
        }
        return;
    }
    int m = l + r >> 1;
    vector<op> ops1, ops2;
    vector<query> qs1, qs2;
    for (int i = 0; i < ops.size(); i++) {
        if (ops[i].x <= m) {
            ops1.push_back(ops[i]);
        } else {
            ops2.push_back(ops[i]);
        }
    }
    int idx = 0;
    for (int i = 0; i < qs.size(); i++) {
        while (idx < ops.size() && ops[idx].id <= qs[i].id) {
            if (ops[idx].x <= m) {
                B.add(ops[idx].p, ops[idx].opt);
            }
            idx++;
        }
        int t = B.ask_range(qs[i].l, qs[i].r);
        if (qs[i].k <= t) {
            qs1.push_back(qs[i]);
        } else {
            qs[i].k -= t;
            qs2.push_back(qs[i]);
        }
    }
    // rollback
    idx = 0;
    for (int i = 0; i < qs.size(); i++) {
        while (idx < ops.size() && ops[idx].id <= qs[i].id) {
            if (ops[idx].x <= m) {
                B.add(ops[idx].p, -ops[idx].opt);
            }
            idx++;
        }
    }
    if (!qs1.empty()) solve(l, m, ops1, qs1);
    if (!qs2.empty()) solve(m + 1, r, ops2, qs2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n, m;
    cin >> n >> m;
    res = vector<int> (m, -1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ops.push_back({i, a[i], -1, 1});
    }
    for (int i = 0; i < m; i++) {
        char op;
        cin >> op;
        if (op == 'Q') {
            int l, r, k;
            cin >> l >> r >> k;
            qs.push_back({l, r, k, i});
        } else {
            int x, y;
            cin >> x >> y;
            ops.push_back({x, a[x], i, -1});
            ops.push_back({x, a[x] = y, i, 1});
        }
    }
    solve(0, 1e9, ops, qs);
    for (int i = 0; i < m; i++) {
        if (res[i] != -1) {
            cout << res[i] << endl;
        }
    }
    return 0;
}