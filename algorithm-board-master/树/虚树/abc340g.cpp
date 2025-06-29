// https://www.luogu.com.cn/problem/AT_abc340_g
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct LCA {

    int T;
    vector<int> depth, dfn;
    vector<vector<int>> g, fa;

    LCA() {}
    LCA(int n) {    // 构造函数,传入点数
        T = 1;
        depth = vector<int> (n + 5, 1e9);
        dfn = vector<int> (n + 5);
        g = vector<vector<int>> (n + 5);
        fa = vector<vector<int>> (n + 5);
    }

    void add(int u, int v) {    // 添加一条无向边
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void init(int x, int f, vector<int>& path, int deep) {    // 传入root, -1, {}, 1
        dfn[x] = T++;
        depth[x] = deep;
        for (int i = 1; i <= path.size(); i *= 2) {
            fa[x].push_back(path[path.size() - i]);
        }
        path.push_back(x);
        for (int y : g[x]) {
            if (y == f) continue;
            init(y, x, path, deep + 1);
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

struct VirtualTree {

    int n;
    LCA L;
    vector<int> siz;    // siz[i] > 0表示i是关键点
    vector<vector<vector<int>>> adj;    // 虚树
    vector<int> all;    // 虚树上的所有点

    VirtualTree() {}
    VirtualTree(int n) {
        this->n = n;
        L = LCA(n);
        siz = vector<int> (n + 1);
        adj = vector<vector<vector<int>>> (n + 1);
    }

    void add(int u, int v) {    // 添加一条无向边, 预处理lca用
        L.add(u, v);
    }

    // vector<int> point;  // 关键点
    void build_virtual_tree(vector<int>& point) {
        point.push_back(1); // 根节点入栈, 保证图联通
        sort(point.begin(), point.end(), [&](int x, int y) {    // 把关键点按照 dfn 序排序
            return L.dfn[x] < L.dfn[y];
        });
        for (int i = 0; i < (int)point.size() - 1; i++) {
            all.push_back(point[i]);
            all.push_back(L.lca(point[i], point[i + 1]));         // 插入 lca
        }
        all.push_back(point.back());
        sort(all.begin(), all.end(), [&](int x, int y) {            // 把所有虚树上的点按照 dfn 序排序
            return L.dfn[x] < L.dfn[y];
        });
        all.erase(unique(all.begin(), all.end()), all.end());
        for (int i = 0; i < (int)all.size() - 1; i++) {
            int lc = L.lca(all[i], all[i + 1]);
            int w = 1;  // 如有边权, 先算边权
            adj[lc].push_back({all[i + 1], w});
            adj[all[i + 1]].push_back({lc, w});
        }
    }

    void clear() {
        for (int i = 0; i < all.size(); i++) {
            siz[all[i]] = 0;
            adj[all[i]].clear();
        }
        all.clear();
    }
};

VirtualTree V;

int res = 0, mod = 998244353;

int dfs(int x, int fa) {
    vector<int> cnt;
    for (int i = 0; i < V.adj[x].size(); i++) {
        int y = V.adj[x][i][0], w = V.adj[x][i][1];
        if (y == fa) continue;
        cnt.push_back(dfs(y, x));
    }
    if (V.siz[x]) { // 是关键点
        int t = (cnt.size() ? cnt[0] + 1 : 1);
        for (int i = 1; i < cnt.size(); i++) {
            t = t * (cnt[i] + 1) % mod;
        }
        res = (res + t) % mod;
        return t;
    } else {        // 不是关键点
        if (cnt.size() >= 1) {
            int t = cnt[0] + 1;
            for (int i = 1; i < cnt.size(); i++) {
                t = t * (cnt[i] + 1) % mod;
            }
            for (int x : cnt) {
                t = (t - x) % mod;
            }
            t--;
            res = (res + t) % mod;
            for (int x : cnt) {
                t = (t + x) % mod;
            }
            return t;
        } else {
            return 0;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    V = VirtualTree(n);
    vector<vector<int>> c2p(n + 1);
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        c2p[c].push_back(i);
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        V.add(u, v);
    }
    vector<int> path;
    V.L.init(1, -1, path, 1);
    for (int i = 1; i <= n; i++) {
        if (c2p[i].size()) {
            for (int j = 0; j < c2p[i].size(); j++) {
                V.siz[c2p[i][j]] = 1;
            }
            V.build_virtual_tree(c2p[i]);
            dfs(1, -1);
            V.clear();
        }
    }
    cout << (res % mod + mod) % mod << endl;
    return 0;
}
