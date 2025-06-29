// https://www.luogu.com.cn/problem/P3899
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct LCA {

    vector<int> depth, siz;
    vector<vector<int>> g, fa;

    LCA() {}
    LCA(int n) {    // 构造函数,传入点数
        depth = vector<int> (n + 5);
        g = vector<vector<int>> (n + 5);
        fa = vector<vector<int>> (n + 5);
        siz = vector<int> (n + 5);
    }

    void add(int u, int v) {    // 添加一条无向边
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void init(int x, int f, vector<int>& path, int deep) {    // 传入root, -1, {}, 1
        siz[x] = 1;
        depth[x] = deep;
        for (int i = 1; i <= path.size(); i *= 2) {
            fa[x].push_back(path[path.size() - i]);
        }
        path.push_back(x);
        for (int y : g[x]) {
            if (y == f) continue;
            init(y, x, path, deep + 1);
            siz[x] += siz[y];
        }
        path.pop_back();
    }

    int lca(int a, int b) { // 获取a和b的最近公共祖先
        if (depth[a] < depth[b]) swap(a, b);
        for (int i = 20; i >= 0; i--) {
            if (i < fa[a].size() && depth[fa[a][i]] >= depth[b]) {
                a = fa[a][i];
            }
        }
        if (a == b) return a;
        for (int i = 20; i >= 0; i--) {
            if (i < fa[a].size() && i < fa[b].size() && fa[a][i] != fa[b][i]) {
                a = fa[a][i];
                b = fa[b][i];
            }
        }
        return fa[a][0];
    }

    int getDist(int a, int b) { // 获取a和b之间的距离
        int lca_ab = lca(a, b);
        return depth[a] + depth[b] - 2 * depth[lca_ab];
    }

    int getKthAncestor(int x, int k) {  // 返回结点x的第k个祖先
        for (int i = 0; i < 20; i++) {
            if (k & (1 << i) && i < fa[x].size()) {
                x = fa[x][i];
                k -= 1 << i;
            }
        }
        if (k != 0) return -1;
        return x;
    }
};

struct SegTree {
    
    int cnt;
    vector<int> root, lson, rson, v;

    SegTree() {}
    SegTree(int root_cnt, int node_cnt) {    // 传入根节点个数和总节点个数
        cnt = 1;
        root = vector<int> (root_cnt + 5);
        for (int i = 1; i <= root_cnt; i++) { // 初始化根
            root[i] = cnt++;
        }
        lson = vector<int> (node_cnt + 5);
        rson = vector<int> (node_cnt + 5);
        v = vector<int> (node_cnt + 5);
    }

    void pushup(int p) {
        v[p] = v[lson[p]] + v[rson[p]];
    }

    void change(int p, int l, int r, int pos, int val) {
        if (l == r) {
            v[p] += val;
            return;
        }
        int m = l + r >> 1;
        if (pos <= m) {
            if (lson[p] == 0) lson[p] = cnt++;
            change(lson[p], l, m, pos, val);
        } else {
            if (rson[p] == 0) rson[p] = cnt++;
            change(rson[p], m + 1, r, pos, val);
        }
        pushup(p);
    }

    int merge(int r1, int r2, int l, int r) {   // 把r2合并到r1上
        if (!r1) return r2;
        if (!r2) return r1;
        int cur = cnt++;    // 每次重新开点, 防止父亲的修改操作影响儿子
        if (l == r) {
            v[cur] = v[r1] + v[r2];
            return cur;
        }
        int m = l + r >> 1;
        lson[cur] = merge(lson[r1], lson[r2], l, m);
        rson[cur] = merge(rson[r1], rson[r2], m + 1, r);
        pushup(cur);
        return cur;
    }

    int kth(int p, int l, int r, int k) {
        if (l == r) {
            return v[p] >= k ? l : 0;
        }
        int m = l + r >> 1;
        if (v[lson[p]] >= k) {
            return kth(lson[p], l, m, k);
        } else {
            return kth(rson[p], m + 1, r, k - v[lson[p]]);
        }
    }

    int query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return v[p];
        }
        int res = 0;
        int m = l + r >> 1;
        if (ql <= m) {
            res += query(lson[p], l, m, ql, qr);
        }
        if (qr > m) {
            res += query(rson[p], m + 1, r, ql, qr);
        }
        return res;
    }
};

int n, m;
LCA L;
SegTree S;

void dfs(int x, int fa) {
    for (int y : L.g[x]) {
        if (y == fa) continue;
        dfs(y, x);
        S.root[x] = S.merge(S.root[x], S.root[y], 1, n);
    }
    S.change(S.root[x], 1, n, L.depth[x], L.siz[x] - 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    cin >> n >> m;
    L = LCA(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        L.add(x, y);
    }
    vector<int> path;
    L.init(1, -1, path, 1);
    S = SegTree(n, n * 50);
    dfs(1, -1);
    for (int i = 1; i <= m; i++) {
        int a, k;
        cin >> a >> k;
        int res = min(k, L.depth[a] - 1) * (L.siz[a] - 1);
        res += S.query(S.root[a], 1, n, L.depth[a] + 1, min(L.depth[a] + k, n));
        cout << res << endl;
    }
    return 0;
}