// https://oi-wiki.org/graph/dsu-on-tree/
// https://www.luogu.com.cn/problem/CF246E
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> siz, big, col, L, R, Node;
vector<int> res, deep;
map<pair<int, int>, int> cnt;
vector<int> dep_cnt;
int totdfn, totColor;
vector<vector<vector<int>>> querys;

void add(int x) {
    int dep = deep[x];
    if (cnt[{dep, col[x]}] == 0) ++dep_cnt[dep];
    cnt[{dep, col[x]}]++;
}

void del(int x) {
    int dep = deep[x];
    cnt[{dep, col[x]}]--;
    if (cnt[{dep, col[x]}] == 0) --dep_cnt[dep];
}

void getRes(int x, int k, int id) {
    int dep = deep[x] + k;
    if (dep >= dep_cnt.size()) {
        res[id] = 0;
    } else {
        res[id] = dep_cnt[dep];
    }
}

void dfs0(int x, int fa, int dep) {
    L[x] = ++totdfn;
    Node[totdfn] = x;
    deep[x] = dep;
    for (int y : adj[x]) {
        if (y == fa) continue;
        dfs0(y, x, dep + 1);
        siz[x] += siz[y];
        if (!big[x] || siz[big[x]] < siz[y]) {
            big[x] = y;
        }
    }
    R[x] = totdfn;
}

void dfs1(int x, int fa, bool keep) {
    // 计算轻儿子的答案
    for (int y : adj[x]) {
        if (y != fa && y != big[x]) {
            dfs1(y, x, false);
        }
    }
    // 计算重儿子答案并保留计算过程中的数据（用于继承）
    if (big[x]) {
        dfs1(big[x], x, true);
    }
    for (int y : adj[x]) {
        if (y != fa && y != big[x]) {
            // 子树结点的 DFS 序构成一段连续区间，可以直接遍历
            for (int i = L[y]; i <= R[y]; i++) {
                add(Node[i]);
            }
        }
    }
    add(x);
    while (querys[x].size()) {
        getRes(x, querys[x].back()[0], querys[x].back()[1]);
        querys[x].pop_back();
    }
    if (keep == false) {
        for (int i = L[x]; i <= R[x]; i++) {
            del(Node[i]);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    cin >> n;
    siz = vector<int> (n + 1, 1);
    big = vector<int> (n + 1);
    col = vector<int> (n + 1);
    L = vector<int> (n + 1);
    R = vector<int> (n + 1);
    Node = vector<int> (n + 1);
    dep_cnt = vector<int> (n + 1);
    deep = vector<int> (n + 1);
    adj = vector<vector<int>> (n + 1);
    querys = vector<vector<vector<int>>> (n + 1);
    map<string, int> s2v;
    set<int> root;
    int id = 1;
    for (int i = 1; i <= n; i++) {
        string s;
        int p;
        cin >> s >> p;
        if (p == 0) {
            root.insert(i);
        }
        if (s2v.count(s) == 0) {
            s2v[s] = id++;
        }
        col[i] = s2v[s];
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    int q;
    cin >> q;
    res = vector<int> (q + 1);
    for (int i = 0; i < q; i++) {
        int v, k;
        cin >> v >> k;
        querys[v].push_back({k, i});
    }
    for (int r : root) {
        dfs0(r, 0, 1);
        dfs1(r, 0, false);
    }
    for (int i = 0; i < q; i++) {
        cout << res[i] << endl;
    }
    return 0;
}