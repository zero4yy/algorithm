/*
https://loj.ac/p/139
给定一棵 n 个节点的树，初始时该树的根为 1 号节点，每个节点有一个给定的权值。下面依次进行 m 个操作，操作分为如下五种类型：
1.换根：将一个指定的节点设置为树的新根。
2.修改路径权值：给定两个节点，将这两个节点间路径上的所有节点权值（含这两个节点）增加一个给定的值。
3.修改子树权值：给定一个节点，将以该节点为根的子树内的所有节点权值增加一个给定的值。
4.询问路径：询问某条路径上节点的权值和。
5.询问子树：询问某个子树内节点的权值和。
*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int n, m;

struct SegTree {

    int n;
    vector<int> d, lazy;

    SegTree() {}
    SegTree(int n) {
        this->n = n;
        d = vector<int> (n * 4 + 5);
        lazy = vector<int> (n * 4 + 5);
    }

    void push_down(int p, int l, int r, int m) {
        if (lazy[p] != 0) {
            d[p << 1] += lazy[p] * (m - l + 1);
            d[p << 1 | 1] += lazy[p] * (r - m);
            lazy[p << 1] += lazy[p];
            lazy[p << 1 | 1] += lazy[p];
            lazy[p] = 0;
        }
    }

    void change(int p, int l, int r, int ql, int qr, int v) {
        if (ql <= l && r <= qr) {
            d[p] += (r - l + 1) * v;
            lazy[p] += v;
            return;
        }
        int m = l + r >> 1;
        push_down(p, l, r, m);
        if (ql <= m) {
            change(p << 1, l, m, ql, qr, v);
        }
        if (qr > m) {
            change(p << 1 | 1, m + 1, r, ql, qr, v);
        }
        d[p] = d[p << 1] + d[p << 1 | 1];
    }

    int query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return d[p];
        }
        int m = l + r >> 1;
        int res = 0;
        push_down(p, l, r, m);
        if (ql <= m) {
            res += query(p << 1, l, m, ql, qr);
        }
        if (qr > m) {
            res += query(p << 1 | 1, m + 1, r, ql, qr);
        }
        return res;
    }

    void change(int ql, int qr, int v) {
        if (ql > qr) return;
        change(1, 0, n, ql, qr, v);
    }

    int query(int ql, int qr) {
        if (ql > qr) return 0;
        return query(1, 0, n, ql, qr);
    }

};

struct TreeCut {
    
    int cnt, n, root;
    vector<int> dep;            // dep[i]表示编号为i的节点的深度
    vector<vector<int>> edges;  // 存储边
    vector<int> fa;             // fa[i]表示编号为i的节点的父亲
    vector<int> sz;             // sz[i]表示编号为i为根的子树的节点数
    vector<int> hson;           // hson[i]表示编号为i的节点的重儿子
    vector<int> top;            // top[i]表示编号为i的节点重链中深度最小的节点
    vector<int> dfsn;           // dfsn[i]表示编号为i的节点的进入时间
    vector<int> rdfsn;          // rdfsn[i]表示编号为i的节点的离开时间
    SegTree S;
    
    TreeCut() {}
    TreeCut(int n) {     // 构造函数，传入根节点, 结点数
        this->n = n;
        cnt = 1;
        S = SegTree(n + 5);
        dep.resize(n + 5);
        edges.resize(n + 5);
        fa.resize(n + 5);
        sz.resize(n + 5);
        hson.resize(n + 5);
        top.resize(n + 5);
        dfsn.resize(n + 5);
        rdfsn.resize(n + 5);
    }

    void addEdge(int u, int v) {        // 添加一条u与v相通的边
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    void init(int root) {   // 加边后初始化
        this->root = root;
        top[root] = root;
        dfs1(root, 1);
        dfs2(root);
    }

    void dfs1(int root, int deep) {
        int size = 1, maxv = 0;
        dep[root] = deep;
        for (int nxt : edges[root]) {
            if (!dep[nxt]) {
                dfs1(nxt, deep + 1);
                fa[nxt] = root;
                size += sz[nxt];
                if (sz[nxt] > maxv) {
                    hson[root] = nxt;
                    maxv = sz[nxt];
                }
            }
        }
        sz[root] = size;
    }

    void dfs2(int root) {
        dfsn[root] = cnt++;
        if (hson[root] != 0) {
            top[hson[root]] = top[root];
            dfs2(hson[root]);
        }
        for (int nxt : edges[root]) {
            if (!top[nxt]) {
                top[nxt] = nxt;
                dfs2(nxt);
            }
        }
        rdfsn[root] = cnt - 1;
    }

    int lca(int a, int b) {                     // 求编号为a和b的最近公共祖先
        while (top[a] != top[b]) {
            if (dep[top[a]] > dep[top[b]]) {
                a = fa[top[a]];
            } else {
                b = fa[top[b]];
            }
        }
        return (dep[a] > dep[b] ? b : a);
    }

    void update_path(int x, int y, int val) {   // 链x->y上所有点加上val
        while (top[x] != top[y]) {
            if (dep[top[x]] > dep[top[y]]) {
                S.change(dfsn[top[x]], dfsn[x], val);
                x = fa[top[x]];
            } else {
                S.change(dfsn[top[y]], dfsn[y], val);
                y = fa[top[y]];
            }
        }
        if (dep[x] > dep[y]) {
            S.change(dfsn[y], dfsn[x], val);
        } else {
            S.change(dfsn[x], dfsn[y], val);
        }
    }

    int query_path(int x, int y) {   // 链x->y上所有点的和
        int res = 0;
        while (top[x] != top[y]) {
            if (dep[top[x]] > dep[top[y]]) {
                res += S.query(dfsn[top[x]], dfsn[x]);
                x = fa[top[x]];
            } else {
                res += S.query(dfsn[top[y]], dfsn[y]);
                y = fa[top[y]];
            }
        }
        if (dep[x] > dep[y]) {
            res += S.query(dfsn[y], dfsn[x]);
        } else {
            res += S.query(dfsn[x], dfsn[y]);
        }
        return res;
    }

    int child(int root, int x) {
        while (top[root] != top[x]) {
            root = top[root];
            if (fa[root] == x) return root;
            root = fa[root];
        }
        return hson[x];
    }

    void update_subtree(int x, int val) {   // 以x为根的子树上所有点加上val
        if (x == root) {
            S.change(1, n, val);
        } else if (dfsn[x] <= dfsn[root] && rdfsn[root] <= rdfsn[x]) {
            int c = child(root, x);
            S.change(1, dfsn[c] - 1, val);
            S.change(rdfsn[c] + 1, n, val);
        } else {
            S.change(dfsn[x], rdfsn[x], val);
        }
    }

    int query_subtree(int x) {             // 以x为根的子树上所有点的和
        if (x == root) {
            return S.query(1, n);
        } else if (dfsn[x] <= dfsn[root] && rdfsn[root] <= rdfsn[x]) {
            int c = child(root, x);
            return S.query(1, dfsn[c] - 1) + S.query(rdfsn[c] + 1, n);
        } else {
            return S.query(dfsn[x], rdfsn[x]);
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    TreeCut T(n);
    vector<int> value(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        T.addEdge(i, a);
    }
    T.init(1);
    for (int i = 1; i <= n; i++) {
        T.update_path(i, i, value[i]);
    }
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {          // 换根
            cin >> T.root;
        } else if (op == 2) {   // 修改路径权值
            int u, v, k;
            cin >> u >> v >> k;
            T.update_path(u, v, k);
        } else if (op == 3) {   // 修改子树权值
            int u, k;
            cin >> u >> k;
            T.update_subtree(u, k);
        } else if (op == 4) {   // 询问路径
            int u, v;
            cin >> u >> v;
            cout << T.query_path(u, v) << endl;
        } else {                // 询问子树               
            int u;
            cin >> u;
            cout << T.query_subtree(u) << endl;
        }
    }
}