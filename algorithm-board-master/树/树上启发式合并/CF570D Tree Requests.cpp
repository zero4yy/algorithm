// https://oi-wiki.org/graph/dsu-on-tree/
// https://www.luogu.com.cn/problem/CF570D
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int n, q;
vector<vector<int>> adj;
vector<int> siz, big, col, L, R, Node;
vector<int> res, cnt, deep;
int totdfn, totColor;
vector<vector<vector<int>>> querys;

void add(int x) {
    cnt[deep[x]] ^= 1 << col[x];
}

void del(int x) {
    cnt[deep[x]] ^= 1 << col[x];
}

void getRes(int x, int dep, int id) {
    res[id] = cnt[dep];
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
    cin >> n >> q;
    siz = vector<int> (n + 1, 1);
    big = vector<int> (n + 1);
    col = vector<int> (n + 1);
    L = vector<int> (n + 1);
    R = vector<int> (n + 1);
    Node = vector<int> (n + 1);
    res = vector<int> (q + 1);
    cnt = vector<int> (n + 1);
    deep = vector<int> (n + 1);
    adj = vector<vector<int>> (n + 1);
    querys = vector<vector<vector<int>>> (n + 1);
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        col[i] = s[i - 1] - 'a';
    }
    for (int i = 0; i < q; i++) {
        int x, dep;
        cin >> x >> dep;
        querys[x].push_back({dep, i});
    }
    dfs0(1, 0, 1);
    dfs1(1, 0, false);
    for (int i = 0; i < q; i++) {
        int v = res[i] & -res[i];
        if (res[i] > 0) {
            if (res[i] == v) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}