// https://oi-wiki.org/graph/dsu-on-tree/
// https://www.luogu.com.cn/problem/CF1009F
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> siz, big, col, L, R, Node;
vector<int> res, cnt, deep;
int totdfn, tot, nowRes = 1e9;

void add(int x) {
    int dep = deep[x];
    cnt[dep]++;
    if (cnt[dep] > tot || cnt[dep] == tot && dep < nowRes) {
        tot = cnt[dep];
        nowRes = dep;
    }
}

void del(int x) {
    int dep = deep[x];
    cnt[dep]--;
}

int getRes() {
    return nowRes;
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
    res[x] = getRes();
    if (keep == false) {
        tot = 0;
        nowRes = 1e9;
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
    res = vector<int> (n + 1);
    cnt = vector<int> (n + 1);
    deep = vector<int> (n + 1);
    adj = vector<vector<int>> (n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs0(1, 0, 1);
    dfs1(1, 0, false);
    for (int i = 1; i <= n; i++) {
        cout << res[i] - deep[i] << endl;
    }
    return 0;
}