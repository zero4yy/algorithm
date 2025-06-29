// https://oi-wiki.org/graph/dsu-on-tree/
// https://www.luogu.com.cn/problem/U41492
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

// siz: 子树大小
// big: 重儿子
// col: 结点颜色
// L[u]: 结点 u 的 DFS 序
// R[u]: 结点 u 子树中结点的 DFS 序的最大值
// Node[i]: DFS 序为 i 的结点
// res: 存答案
// cnt[i]: 颜色为 i 的结点个数
// totColor: 目前出现过的颜色个数
// adj[u]: 存储与 u 相邻的结点

int n;
vector<vector<int>> adj;
vector<int> siz, big, col, L, R, Node;
vector<int> res, cnt;
int totdfn, totColor;

void add(int x) {
    if (cnt[col[x]] == 0) ++totColor;
    cnt[col[x]]++;
}

void del(int x) {
    cnt[col[x]]--;
    if (cnt[col[x]] == 0) --totColor;
}

int getRes() {
    return totColor;
}

void dfs0(int x, int fa) {
    L[x] = ++totdfn;
    Node[totdfn] = x;
    for (int y : adj[x]) {
        if (y == fa) continue;
        dfs0(y, x);
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
    adj = vector<vector<int>> (n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> col[i];
    }
    dfs0(1, 0);
    dfs1(1, 0, false);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << res[x] << endl;
    }
    return 0;
}
