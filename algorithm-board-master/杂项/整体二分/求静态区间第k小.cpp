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
    int p, x;
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
            B.add(ops[i].p, 1);
        } else {
            ops2.push_back(ops[i]);
        }
    }
    for (int i = 0; i < qs.size(); i++) {
        int t = B.ask_range(qs[i].l, qs[i].r);
        if (qs[i].k <= t) {
            qs1.push_back(qs[i]);
        } else {
            qs[i].k -= t;
            qs2.push_back(qs[i]);
        }
    }
    for (int i = 0; i < ops.size(); i++) {
        if (ops[i].x <= m) {
            B.add(ops[i].p, -1);
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
    res = vector<int> (m);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ops.push_back({i, a});
    }
    for (int i = 0; i < m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;
        qs.push_back({l, r, k, i});
    }
    solve(0, 1e9, ops, qs);
    for (int i = 0; i < m; i++) {
        cout << res[i] << endl;
    }
    return 0;
}
