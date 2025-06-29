// https://atcoder.jp/contests/abc359/tasks/abc359_g
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int n, m;
int root, mxs, sum;
int res = 0;

vector<int> del, siz, dis, col;
vector<vector<vector<int>>> adj;
map<int, int> val1, val2;
map<int, int> cnt1, cnt2;

void get_root(int x, int fa) {
    siz[x] = 1;
    int s = 0;
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i][0], w = adj[x][i][1];
        if (y == fa || del[y]) continue;
        get_root(y, x);
        siz[x] += siz[y];
        s = max(s, siz[y]);
    }
    s = max(s, sum - siz[x]);
    if (s < mxs) {
        mxs = s;
        root = x;
    }
}

void get_dis(int x, int fa) {
    val1[col[x]] += dis[x];
    cnt1[col[x]]++;
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i][0], w = adj[x][i][1];
        if (y == fa || del[y]) continue;
        dis[y] = dis[x] + w;
        get_dis(y, x);
    }
}

void calc(int x) {
    val2.clear();
    cnt2.clear();
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i][0], w = adj[x][i][1];
        if (del[y]) continue;
        dis[y] = w;
        val1.clear();
        cnt1.clear();
        get_dis(y, x);
        for (auto [v, cnt] : cnt1) {
            if (val2.count(v)) {
                res += val2[v] * cnt;
            }
        }
        for (auto [v, cnt] : val1) {
            if (val2.count(v)) {
                res += cnt * cnt2[v];
            }
        }
        for (auto [v, cnt] : cnt1) {
            cnt2[v] += cnt;
        }
        for (auto [v, cnt] : val1) {
            val2[v] += cnt;
        }
    }
    res += val2[col[x]];
}

void divide(int x) {
    calc(x);
    del[x] = 1;
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i][0], w = adj[x][i][1];
        if (del[y]) continue;
        mxs = sum = siz[y];
        get_root(y, 0);
        divide(root);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    cin >> n;
    del = vector<int> (n + 1);
    siz = vector<int> (n + 1);
    dis = vector<int> (n + 1);
    adj = vector<vector<vector<int>>> (n + 1);
    col = vector<int> (n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v;
        w = 1;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++) {
        cin >> col[i];
    }
    mxs = sum = n;
    get_root(1, 0);
    get_root(root, 0);
    divide(root);
    cout << res << endl;
    return 0;
}
