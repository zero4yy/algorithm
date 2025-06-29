// https://oi-wiki.org/graph/dsu-on-tree/
// https://www.luogu.com.cn/problem/CF741D
#include <bits/stdc++.h>
// #define int long long
#define endl '\n'

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> siz, big, col, L, R, Node, deep;
vector<int> res, pre;
int cnt[1 << 22];
int totdfn, totColor;

void add(int x) {
    cnt[pre[x]] = max(cnt[pre[x]], deep[x]);
}

void del(int x) {
    cnt[pre[x]] = -1e9;
}

int getRes() {
    return totColor;
}

void dfs0(int x, int fa, int v, int dep) {
    deep[x] = dep;
    pre[x] = v;
    L[x] = ++totdfn;
    Node[totdfn] = x;
    for (int y : adj[x]) {
        if (y == fa) continue;
        dfs0(y, x, v ^ col[y], dep + 1);
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
                for (int j = 0; j < 22; j++) {
                    int v = 1 << j;
                    res[x] = max(res[x], cnt[v ^ pre[Node[i]]] + deep[Node[i]] - 2 * deep[x]);
                }
                res[x] = max(res[x], cnt[0 ^ pre[Node[i]]] + deep[Node[i]] - 2 * deep[x]);
            }
            for (int i = L[y]; i <= R[y]; i++) {
                add(Node[i]);
            }
        }
    }
    for (int j = 0; j < 22; j++) {
        int v = 1 << j;
        res[x] = max(res[x], cnt[v ^ pre[x]] - deep[x]);
    }
    res[x] = max(res[x], cnt[0 ^ pre[x]] - deep[x]);
    add(x);
    if (keep == false) {
        for (int i = L[x]; i <= R[x]; i++) {
            del(Node[i]);
        }
    }
}

void dfs2(int x, int fa) {
    for (int y : adj[x]) {
        if (y != fa) {
            dfs2(y, x);
            res[x] = max(res[x], res[y]);
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
    deep = vector<int> (n + 1);
    pre = vector<int> (n + 1);
    adj = vector<vector<int>> (n + 1);
    for (int i = 0; i < (1 << 22); i++) {
        cnt[i] = -1e9;
    }
    for (int i = 2; i <= n; i++) {
        int u;
        char c;
        cin >> u >> c;
        adj[i].push_back(u);
        adj[u].push_back(i);
        col[i] = 1 << (c - 'a');
    }
    dfs0(1, 0, 0, 1);
    dfs1(1, 0, false);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}